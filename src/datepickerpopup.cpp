#include "datepicker/datepickerpopup.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include "datepicker/datepickercalendar.h"
#include "datepicker/datepickerpopupfooter.h"


class DatePickerPopupPrivate {
    Q_DECLARE_PUBLIC(DatePickerPopup)

    DatePickerPopup *q_ptr;
    DatePickerCalendar *calendar_widget_1;
    DatePickerCalendar *calendar_widget_2;
    DatePickerPopupFooter *footer;

    DatePickerPopupPrivate(DatePickerPopup *q) : q_ptr(q) {}
    ~DatePickerPopupPrivate() {}

    void initUi()
    {
        Q_Q(DatePickerPopup);

        calendar_widget_1 = new DatePickerCalendar(q);
        calendar_widget_2 = new DatePickerCalendar(q);

        footer = new DatePickerPopupFooter(q);

        QHBoxLayout *calendars_layout = new QHBoxLayout();
        calendars_layout->setContentsMargins(QMargins());
        calendars_layout->setSpacing(10);
        calendars_layout->setSizeConstraint(QLayout::SetFixedSize);
        calendars_layout->addWidget(calendar_widget_1);
        calendars_layout->addWidget(calendar_widget_2);

        QVBoxLayout *main_layout = new QVBoxLayout(q);
        main_layout->setContentsMargins(QMargins(15, 10, 15, 10));
        main_layout->setSizeConstraint(QLayout::SetFixedSize);
        main_layout->setSpacing(0);
        main_layout->addLayout(calendars_layout, 1);
        main_layout->addWidget(footer);

        q->setLayout(main_layout);

        q->setDatePickerType(footer->pickerType());

        q->setAttribute(Qt::WA_TranslucentBackground);

        QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(q);
        shadow_effect->setBlurRadius(10.0);
        shadow_effect->setOffset(2.0);
        q->setGraphicsEffect(shadow_effect);

        QFont font = q->font();
        font.setPointSize(9);

        q->setFont(font);

        q->setWindowTitle(QObject::tr("Date Picker"));

        q->setWindowFlags(Qt::FramelessWindowHint |
                          Qt::WindowStaysOnTopHint |
                          Qt::X11BypassWindowManagerHint);
    }
};


DatePickerPopup::DatePickerPopup(QWidget *parent) :
    QWidget(parent),
    d_ptr(new DatePickerPopupPrivate(this))
{
    Q_D(DatePickerPopup);
    d->initUi();

    connect(d->calendar_widget_1, SIGNAL(dateSelected(QDate)),
            SLOT(onCalendar1DateSelected(QDate)));
    connect(d->calendar_widget_1, SIGNAL(scrolledTo(QDate)),
            SLOT(onCalendar1Scrolled(QDate)));

    connect(d->calendar_widget_2, SIGNAL(dateSelected(QDate)),
            SLOT(onCalendar2DateSelected(QDate)));
    connect(d->calendar_widget_2, SIGNAL(scrolledTo(QDate)),
            SLOT(onCalendar2Scrolled(QDate)));

    connect(d->footer, SIGNAL(datePickerTypeChanged(DatePickerType)),
            SLOT(setDatePickerType(DatePickerType)));
}

DatePickerPopup::~DatePickerPopup()
{
    delete d_ptr;
}

void DatePickerPopup::setDatePickerType(DatePickerType picker_type)
{
    Q_D(DatePickerPopup);
    bool is_period_type = (picker_type == PeriodType);
    d->calendar_widget_2->setVisible(is_period_type);
}

void DatePickerPopup::setAllowedPickerTypes(DatePickerTypes picker_types)
{
    Q_D(DatePickerPopup);
    d->footer->setAllowedPickerTypes(picker_types);
}

void DatePickerPopup::reset()
{
    Q_D(DatePickerPopup);
    d->calendar_widget_1->reset();
    d->calendar_widget_2->reset();
}

void DatePickerPopup::onCalendar1DateSelected(const QDate &date)
{
    Q_D(DatePickerPopup);

    if (d->footer->pickerType() == DayType)
        emit dateSelected(date);
    if (d->footer->pickerType() == PeriodType)
        emit periodSelected(date, d->calendar_widget_2->selectedDate());
}

void DatePickerPopup::onCalendar1Scrolled(const QDate &date)
{
    Q_D(DatePickerPopup);

    if (d->footer->pickerType() == PeriodType)
        setPeriod(date, d->calendar_widget_2->selectedDate());
}

void DatePickerPopup::onCalendar2DateSelected(const QDate &date)
{
    Q_D(DatePickerPopup);

    if (d->footer->pickerType() == PeriodType)
        emit periodSelected(d->calendar_widget_1->selectedDate(), date);
}

void DatePickerPopup::onCalendar2Scrolled(const QDate &date)
{
    Q_D(DatePickerPopup);

    if (d->footer->pickerType() == PeriodType)
        setPeriod(d->calendar_widget_1->selectedDate(), date);
}

void DatePickerPopup::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect bacground_rect = rect().adjusted(10, 10, -10, -10);;

    QPainterPath background_path(QPoint(30, 10));
    background_path.lineTo(50, 10);
    background_path.lineTo(40, 0);
    background_path.addRoundedRect(bacground_rect, 10, 10);

    painter.fillPath(background_path, Qt::white);

    event->accept();
}

void DatePickerPopup::setDate(const QDate &date)
{
    Q_D(DatePickerPopup);
    d->calendar_widget_1->setDate(date);
    d->calendar_widget_2->setDate(date);
    d->footer->setPickerType(DayType);
}

void DatePickerPopup::setPeriod(const QDate &begin, const QDate &end)
{
    Q_D(DatePickerPopup);
    d->calendar_widget_1->setPeriod(begin, end, true);
    d->calendar_widget_2->setPeriod(begin, end, false);
    d->footer->setPickerType(PeriodType);
}
