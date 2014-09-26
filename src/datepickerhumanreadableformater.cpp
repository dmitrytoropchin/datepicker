#include "datepicker/datepickerhumanreadableformater.h"
#include <QObject>
#include <QMap>


class DatePickerHumanReadableFormaterPrivate {
    Q_DECLARE_PUBLIC(DatePickerHumanReadableFormater)

    DatePickerHumanReadableFormater *q_ptr;

    QMap<int, QString> month_name; // с падежом

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
        if (date.year() == current_date.year()) {
            human_readable_str =
                    QString("%1 %2")
                    .arg(date.day())
                    .arg(d->month_name.value(date.month()));
        }
        else {
            human_readable_str =
                    QString("%1 %2 %3")
                    .arg(date.day())
                    .arg(d->month_name.value(date.month()))
                    .arg(date.year());
        }
    }

    return human_readable_str;
}

QString DatePickerHumanReadableFormater::format(const QDate &begin, const QDate &end) const
{
    QString human_readable_begin_str = begin.toString("d MMMM yyyy");
    QString human_readable_end_str = end.toString("d MMMM yyyy");

    return QString("%1 - %2").arg(human_readable_begin_str).arg(human_readable_end_str);
}
