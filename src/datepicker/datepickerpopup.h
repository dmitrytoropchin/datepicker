#ifndef DATEPICKERPOPUP_H
#define DATEPICKERPOPUP_H

#include <QDate>
#include <QWidget>
#include "datepicker_common.h"

class DatePickerPopupPrivate;

class DatePickerPopup : public QWidget {
    Q_OBJECT
    Q_DECLARE_PRIVATE(DatePickerPopup)

    DatePickerPopupPrivate * const d_ptr;
public:
    explicit DatePickerPopup(QWidget *parent = 0);
    ~DatePickerPopup();
signals:
    void dateSelected(const QDate &date);
    void periodSelected(const QDate &begin, const QDate &end);
public slots:
    void setDate(const QDate &date);
    void setPeriod(const QDate &begin, const QDate &end);
    void setDatePickerType(DatePickerType picker_type);
    void setAllowedPickerTypes(DatePickerTypes picker_types);

    void reset();
private slots:
    void onCalendar1DateSelected(const QDate &date);
    void onCalendar1Scrolled(const QDate &date);
    void onCalendar2DateSelected(const QDate &date);
    void onCalendar2Scrolled(const QDate &date);
private:
    void paintEvent(QPaintEvent *event);
};

#endif // DATEPICKERPOPUP_H
