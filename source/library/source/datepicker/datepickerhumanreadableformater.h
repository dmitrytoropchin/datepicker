#ifndef DATEPICKERHUMANREADABLEFORMATER_H
#define DATEPICKERHUMANREADABLEFORMATER_H

#include "datepicker/datepicker_common.h"
#include "datepicker/datepickerabstractformater.h"

class DatePickerHumanReadableFormaterPrivate;

class DATEPICKER_EXPORT DatePickerHumanReadableFormater : public DatePickerAbstractFormater {
    Q_DECLARE_PRIVATE(DatePickerHumanReadableFormater)

    DatePickerHumanReadableFormaterPrivate * const d_ptr;
public:
    DatePickerHumanReadableFormater();
    ~DatePickerHumanReadableFormater();

    QString format(const QDate &date) const;
    QString format(const QDate &begin, const QDate &end) const;

    QString format(const QDateTime &date_time) const;
    QString format(const QDateTime &begin, const QDateTime &end) const;

    QString fromWord() const;
    void setFromWord(const QString &word);

    QString toWord() const;
    void setToWord(const QString &word);
};

#endif // DATEPICKERHUMANREADABLEFORMATER_H
