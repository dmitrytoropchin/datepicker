#ifndef DATEPICKERCALENDARDECADEVIEW_H
#define DATEPICKERCALENDARDECADEVIEW_H

#include <QDate>
#include <QTableWidget>

class DatePickerCalendarDecadeView : public QTableWidget {
    Q_OBJECT
public:
    explicit DatePickerCalendarDecadeView(QWidget *parent = 0);
    ~DatePickerCalendarDecadeView();
signals:
    void yearClicked(int year);
public slots:
    void setDate(const QDate &date);
private slots:
    void onCellClicked(int row, int column);
};

#endif // DATEPICKERCALENDARDECADEVIEW_H
