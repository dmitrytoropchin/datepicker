#include "datepicker/datepickerhumanreadableformater.h"
#include <QObject>
#include <QMap>
#include <QDebug>


class DatePickerHumanReadableFormaterPrivate {
    Q_DECLARE_PUBLIC(DatePickerHumanReadableFormater)

    DatePickerHumanReadableFormater *q_ptr;

    QMap<int, QString> month_name; // с падежом

    QString from_word;
    QString to_word;

    DatePickerHumanReadableFormaterPrivate(DatePickerHumanReadableFormater *q) :
        q_ptr(q)
    {
        month_name.insert(1, QObject::tr("january"));
        month_name.insert(2, QObject::tr("february"));
        month_name.insert(3, QObject::tr("march"));
        month_name.insert(4, QObject::tr("april"));
        month_name.insert(5, QObject::tr("may"));
        month_name.insert(6, QObject::tr("june"));
        month_name.insert(7, QObject::tr("july"));
        month_name.insert(8, QObject::tr("august"));
        month_name.insert(9, QObject::tr("september"));
        month_name.insert(10, QObject::tr("october"));
        month_name.insert(11, QObject::tr("november"));
        month_name.insert(12, QObject::tr("december"));

        from_word = QObject::tr("from");
        to_word = QObject::tr("to");
    }

    ~DatePickerHumanReadableFormaterPrivate() {}
};

DatePickerHumanReadableFormater::DatePickerHumanReadableFormater() :
    DatePickerAbstractFormater(),
    d_ptr(new DatePickerHumanReadableFormaterPrivate(this))
{
}

DatePickerHumanReadableFormater::~DatePickerHumanReadableFormater()
{
    delete d_ptr;
}

QString DatePickerHumanReadableFormater::format(const QDate &date) const
{
    Q_D(const DatePickerHumanReadableFormater);

    QString human_readable_str;

    QDate current_date = QDate::currentDate();
    int day_difference = current_date.daysTo(date);

    if (day_difference == 0) {
        human_readable_str = QObject::tr("today");
    }
    else if (day_difference == -1) {
        human_readable_str = QObject::tr("yesterday");
    }
    else if (day_difference == 1) {
        human_readable_str = QObject::tr("tomorrow");
    }
    else {
        human_readable_str = QObject::tr("%1 %2 %3")
                             .arg(date.day())
                             .arg(d->month_name.value(date.month()))
                             .arg(date.year());
    }

    return human_readable_str;
}

QString DatePickerHumanReadableFormater::format(const QDate &begin, const QDate &end) const
{
    Q_D(const DatePickerHumanReadableFormater);

    if (begin == end)
        return format(begin);

    QString human_readable_begin_str;
    QString human_readable_end_str;

    if (begin.year() == end.year()) {
        if (begin.month() == end.month()) {
            human_readable_begin_str = begin.toString("d");
        }
        else {
            human_readable_begin_str = QString("%1 %2")
                                       .arg(begin.day())
                                       .arg(d->month_name.value(begin.month()));
        }
    }
    else {
        human_readable_begin_str = QObject::tr("%1 %2 %3")
                                   .arg(begin.day())
                                   .arg(d->month_name.value(begin.month()))
                                   .arg(begin.year());
    }

    human_readable_end_str = QObject::tr("%1 %2 %3")
                             .arg(end.day())
                             .arg(d->month_name.value(end.month()))
                             .arg(end.year());

    return QObject::tr("%1 %2 %3 %4")
            .arg(d->from_word)
            .arg(human_readable_begin_str)
            .arg(d->to_word)
            .arg(human_readable_end_str).simplified();
}

QString DatePickerHumanReadableFormater::format(const QDateTime &date_time) const
{
    // FIXME: implement datetime formating
    qDebug() << "invoking mockup format method" << date_time;
    return format(date_time.date());
}

QString DatePickerHumanReadableFormater::format(const QDateTime &begin, const QDateTime &end) const
{
    // FIXME: implement datetime period formating
    qDebug() << "invoking mockup format method" << begin << end;
    return format(begin.date(), end.date());
}

QString DatePickerHumanReadableFormater::fromWord() const
{
    Q_D(const DatePickerHumanReadableFormater);
    return d->from_word;
}

void DatePickerHumanReadableFormater::setFromWord(const QString &word)
{
    Q_D(DatePickerHumanReadableFormater);
    d->from_word = word;
}

QString DatePickerHumanReadableFormater::toWord() const
{
    Q_D(const DatePickerHumanReadableFormater);
    return d->to_word;
}

void DatePickerHumanReadableFormater::setToWord(const QString &word)
{
    Q_D(DatePickerHumanReadableFormater);
    d->to_word = word;
}
