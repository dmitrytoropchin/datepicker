#ifndef DATEPICKERCALENDARMONTHVIEW_H
#define DATEPICKERCALENDARMONTHVIEW_H

#include <QCalendarWidget>

class DatePickerCalendarMonthView : public QCalendarWidget {
    Q_OBJECT
public:
    explicit DatePickerCalendarMonthView(QWidget *parent = 0);
    ~DatePickerCalendarMonthView();

    QSize minimumSizeHint() const;
signals:
    void dateClicked(const QDate &date);
public slots:
    void setDate(const QDate &date);
    void setPeriod(const QDate &begin, const QDate &end, bool shows_begin = true);
};

#endif // DATEPICKERCALENDARMONTHVIEW_H
