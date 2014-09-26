#ifndef DATEPICKERSTANDARDFORMATER_H
#define DATEPICKERSTANDARDFORMATER_H

#include "datepicker/datepicker_common.h"
#include "datepicker/datepickerabstractformater.h"

class DatePickerStandardFormaterPrivate;

class DATEPICKER_EXPORT DatePickerStandardFormater : public DatePickerAbstractFormater {
    Q_DECLARE_PRIVATE(DatePickerStandardFormater)

    DatePickerStandardFormaterPrivate * const d_ptr;
public:
    DatePickerStandardFormater();
    ~DatePickerStandardFormater();

    QString format(const QDate &date) const;
    QString format(const QDate &begin, const QDate &end) const;

    QString formatTemplate() const;
    void setFormatTemplate(const QString &format_template);
};

#endif // DATEPICKERSTANDARDFORMATER_H
