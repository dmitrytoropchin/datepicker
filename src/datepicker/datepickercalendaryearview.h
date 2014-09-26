#ifndef DATEPICKERCALENDARYEARVIEW_H
#define DATEPICKERCALENDARYEARVIEW_H

#include <QDate>
#include <QTableWidget>

class DatePickerCalendarYearView : public QTableWidget {
    Q_OBJECT
public:
    explicit DatePickerCalendarYearView(QWidget *parent = 0);
    ~DatePickerCalendarYearView();
signals:
    void monthClicked(int month);
public slots:
    void setDate(const QDate &date);
private slots:
    void onCellClicked(int row, int column);
};

#endif // DATEPICKERCALENDARYEARVIEW_H
