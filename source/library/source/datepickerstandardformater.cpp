#include "datepicker/datepickerstandardformater.h"


class DatePickerStandardFormaterPrivate {
    Q_DECLARE_PUBLIC(DatePickerStandardFormater)

    DatePickerStandardFormater *q_ptr;
    QString format_template;

    DatePickerStandardFormaterPrivate(DatePickerStandardFormater *q) :
        q_ptr(q), format_template("d MMMM yyyy") {}
    ~DatePickerStandardFormaterPrivate() {}
};

DatePickerStandardFormater::DatePickerStandardFormater() :
    DatePickerAbstractFormater(),
    d_ptr(new DatePickerStandardFormaterPrivate(this))
{
}

DatePickerStandardFormater::~DatePickerStandardFormater()
{
    delete d_ptr;
}

QString DatePickerStandardFormater::format(const QDate &date) const
{
    Q_D(const DatePickerStandardFormater);
    return date.toString(d->format_template);
}

QString DatePickerStandardFormater::format(const QDate &begin, const QDate &end) const
{
    Q_D(const DatePickerStandardFormater);
    return QString("%1 - %2"
                   ).arg(begin.toString(d->format_template)).arg(end.toString(d->format_template));
}

QString DatePickerStandardFormater::formatTemplate() const
{
    Q_D(const DatePickerStandardFormater);
    return d->format_template;
}

void DatePickerStandardFormater::setFormatTemplate(const QString &format_template)
{
    Q_D(DatePickerStandardFormater);
    d->format_template = format_template;
}
