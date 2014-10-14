#include "datepicker/datepicker.h"
#include <QDate>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QVBoxLayout>
#include <QLabel>
#include "datepicker/datepickerpopup.h"
#include "datepicker/datepickerabstractformater.h"
#include "datepicker/datepickerhumanreadableformater.h"


class DatePickerPrivate {
    Q_DECLARE_PUBLIC(DatePicker)

    DatePicker *q_ptr;
    bool is_editable;
    DatePickerType picker_type;
    QDate date_begin;
    QDate date_end;
    QTime time_begin;
    QTime time_end;
    QLabel *date_label;
    DatePickerPopup *popup;
    DatePickerAbstractFormater *formater;
private:
    DatePickerPrivate(DatePicker *q) :
        q_ptr(q), is_editable(true), picker_type(DayType), date_label(0), popup(0), formater(0) {}

    ~DatePickerPrivate()
    {
        delete popup;

        if (formater != 0)
            delete formater;
    }

    void initUi()
    {
        Q_Q(DatePicker);

        formater = new DatePickerHumanReadableFormater();

        date_label = new QLabel(q);
        date_label->setObjectName("datepicker_label");

        date_label->installEventFilter(q);
        date_label->setCursor(Qt::PointingHandCursor);

        popup = new DatePickerPopup(q);
        popup->installEventFilter(q);

        q->setLayout(new QVBoxLayout(q));
        q->layout()->setContentsMargins(QMargins());
        q->layout()->addWidget(date_label);

        q->setWindowTitle(QObject::tr("Date Picker"));
    }

    void adjustPopupPosition()
    {
        Q_Q(DatePicker);
        popup->move(q->mapToGlobal(q->rect().bottomLeft()));
    }
};

DatePicker::DatePicker(QWidget *parent) :
    QWidget(parent),
    d_ptr(new DatePickerPrivate(this))
{
    Q_D(DatePicker);
    d->initUi();

    connect(d->popup, SIGNAL(dateSelected(QDate)), SLOT(setDate(QDate)));
    connect(d->popup, SIGNAL(datePeriodSelected(QDate,QDate)), SLOT(setDatePeriod(QDate,QDate)));
    connect(d->popup, SIGNAL(timePeriodSelected(QTime,QTime)), SLOT(setTimePeriod(QTime,QTime)));

    d->date_begin = QDate::currentDate();
    d->date_end = QDate::currentDate();

    d->time_begin = QTime(0, 0, 0);
    d->time_end = QTime(23, 59, 59);
}

DatePicker::~DatePicker()
{
    delete d_ptr;
}

QLabel *DatePicker::label() const
{
    Q_D(const DatePicker);
    return d->date_label;
}

QWidget *DatePicker::popup() const
{
    Q_D(const DatePicker);
    return d->popup;
}

bool DatePicker::isEditable() const
{
    Q_D(const DatePicker);
    return d->is_editable;
}

bool DatePicker::isTimeEditable() const
{
    Q_D(const DatePicker);
    return d->popup->isTimeEditable();
}

QString DatePicker::timeInputFormat() const
{
    Q_D(const DatePicker);
    return d->popup->timeInputFormat();
}

DatePickerAbstractFormater *DatePicker::formater() const
{
    Q_D(const DatePicker);
    return d->formater;
}

void DatePicker::setFormater(DatePickerAbstractFormater *formater)
{
    Q_D(DatePicker);

    if (d->formater != 0) {
        delete d->formater;
        d->formater = 0;
    }

    d->formater = formater;

    if (d->formater != 0) {
        if (d->picker_type == DayType) {
            setDate(d->date_begin);
        }
        if (d->picker_type == PeriodType) {
            setDatePeriod(d->date_begin, d->date_end);
            if (isTimeEditable())
                setTimePeriod(d->time_begin, d->time_end);
        }
    }
}

DatePickerType DatePicker::pickerType() const
{
    Q_D(const DatePicker);
    return d->picker_type;
}

QDate DatePicker::date() const
{
    Q_D(const DatePicker);
    return d->date_begin;
}

QDate DatePicker::datePeriodBegin() const
{
    Q_D(const DatePicker);
    return d->date_begin;
}

QDate DatePicker::datePeriodEnd() const
{
    Q_D(const DatePicker);
    return d->date_end;
}

QTime DatePicker::timePeriodBegin() const
{
    Q_D(const DatePicker);
    return d->time_begin;
}

QTime DatePicker::timePeriodEnd() const
{
    Q_D(const DatePicker);
    return d->time_end;
}

QDateTime DatePicker::dateTimePeriodBegin() const
{
    Q_D(const DatePicker);
    return QDateTime(d->date_begin, d->time_begin);
}

QDateTime DatePicker::dateTimePeriodEnd() const
{
    Q_D(const DatePicker);
    return QDateTime(d->date_end, d->time_end);
}

void DatePicker::setEditable(bool on)
{
    Q_D(DatePicker);
    d->is_editable = on;
    d->date_label->setCursor(on ? Qt::PointingHandCursor : Qt::ArrowCursor);
}

void DatePicker::setAllowedPickerTypes(DatePickerTypes picker_types)
{
    Q_D(DatePicker);
    d->popup->setAllowedPickerTypes(picker_types);
}

void DatePicker::setTimeEditable(bool on)
{
    Q_D(DatePicker);
    d->popup->setTimeEditable(on);
}

void DatePicker::setTimeInputFormat(const QString &format)
{
    Q_D(DatePicker);
    d->popup->setTimeInputFormat(format);
}

void DatePicker::setMinimumDate(const QDate &date)
{
    Q_D(DatePicker);
    d->popup->setMinimumDate(date);
}

void DatePicker::setMaximumDate(const QDate &date)
{
    Q_D(DatePicker);
    d->popup->setMaximumDate(date);
}

void DatePicker::setRange(const QDate &minimum, const QDate &maximum)
{
    Q_D(DatePicker);
    d->popup->setMinimumDate(minimum);
    d->popup->setMaximumDate(maximum);
}

void DatePicker::setDate(const QDate &date)
{
    Q_D(DatePicker);

    d->picker_type = DayType;

    d->date_begin = date;
    d->date_end = date;

    d->popup->setDate(date);

    if (d->formater != 0)
        d->date_label->setText(d->formater->format(date));
    else
        d->date_label->clear();
}

void DatePicker::setDatePeriod(const QDate &begin, const QDate &end)
{
    Q_D(DatePicker);

    d->picker_type = PeriodType;

    d->date_begin = begin;
    d->date_end = end;

    d->popup->setDatePeriod(begin, end);

    if (d->formater != 0) {
        d->date_label->setText(
                    isTimeEditable()
                    ? d->formater->format(dateTimePeriodBegin(), dateTimePeriodEnd())
                    : d->formater->format(begin, end));
    }
    else {
        d->date_label->clear();
    }
}

void DatePicker::setTimePeriod(const QTime &begin, const QTime &end)
{
    Q_D(DatePicker);

    d->picker_type = PeriodType;

    d->time_begin = begin;
    d->time_end = end;

    d->popup->setTimePeriod(begin, end);

    if (d->formater != 0)
        d->date_label->setText(d->formater->format(dateTimePeriodBegin(), dateTimePeriodEnd()));
    else
        d->date_label->clear();
}

void DatePicker::setDateTimePeriod(const QDateTime &begin, const QDateTime &end)
{
    Q_D(DatePicker);

    d->date_begin = begin.date();
    d->date_end = end.date();

    d->time_begin = begin.time();
    d->time_end = end.time();

    d->popup->setDatePeriod(begin.date(), end.date());
    d->popup->setTimePeriod(begin.time(), end.time());

    if (d->formater != 0)
        d->date_label->setText(d->formater->format(dateTimePeriodBegin(), dateTimePeriodEnd()));
    else
        d->date_label->clear();
}

bool DatePicker::eventFilter(QObject *object, QEvent *event)
{
    Q_D(DatePicker);

    if (!d->is_editable)
        return QWidget::eventFilter(object, event);

    if ((object == d->date_label) && (event->type() == QEvent::MouseButtonPress)) {
        QMouseEvent *mouse_event = dynamic_cast<QMouseEvent *>(event);
        if (!mouse_event)
            return QWidget::eventFilter(object, event);

        if (mouse_event->button() != Qt::LeftButton)
            return QWidget::eventFilter(object, event);

        if (!d->popup->isVisible()) {
            d->popup->reset();

            if (d->picker_type == DayType) {
                d->popup->setDate(d->date_begin);
            }
            if (d->picker_type == PeriodType) {
                d->popup->setDatePeriod(d->date_begin, d->date_end);
                if (d->popup->isTimeEditable())
                    d->popup->setTimePeriod(d->time_begin, d->time_end);
            }

            d->popup->show();
        }
    }

    if ((object == d->popup) && (event->type() == QEvent::WindowDeactivate)) {
        if (d->popup->isVisible())
            d->popup->close();
    }

    if ((object == d->popup) && (event->type() == QEvent::Close)) {
        if (d->popup->isVisible())
            emit editingFinished();
    }

    return QWidget::eventFilter(object, event);
}

void DatePicker::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    Q_D(DatePicker);
    d->adjustPopupPosition();
}

void DatePicker::hideEvent(QHideEvent *event)
{
    Q_D(DatePicker);
    d->popup->hide();
    QWidget::hideEvent(event);
}

void DatePicker::closeEvent(QCloseEvent *event)
{
    Q_D(DatePicker);
    d->popup->close();
    QWidget::closeEvent(event);
}

void DatePicker::moveEvent(QMoveEvent *event)
{
    QWidget::moveEvent(event);

    Q_D(DatePicker);
    d->adjustPopupPosition();
}

void DatePicker::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    Q_D(DatePicker);
    d->adjustPopupPosition();
}
