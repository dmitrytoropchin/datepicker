#ifndef DATEPICKER_H
#define DATEPICKER_H

#include <QDate>
#include <QWidget>
#include "datepicker_common.h"

class QLabel;

class DatePickerAbstractFormater;

class DatePickerPrivate;

class DATEPICKER_EXPORT DatePicker : public QWidget {
    Q_OBJECT
    Q_DECLARE_PRIVATE(DatePicker)
private:
    DatePickerPrivate * const d_ptr;
public:
    explicit DatePicker(QWidget *parent = 0);
    ~DatePicker();

    QLabel *label() const;
    QWidget *popup() const;

    bool isEditable() const;

    DatePickerAbstractFormater *formater() const;
    void setFormater(DatePickerAbstractFormater *formater);

    DatePickerType pickerType() const;

    QDate selectedDate() const;
    QDate selectedPeriodBegin() const;
    QDate selectedPeriodEnd() const;
signals:
    void editingFinished();
public slots:
    void setEditable(bool on);

    void setAllowedPickerTypes(DatePickerTypes picker_types);

    void setMinimumDate(const QDate &date);
    void setMaximumDate(const QDate &date);
    void setRange(const QDate &minimum, const QDate &maximum);

    void setDate(const QDate &date);
    void setPeriod(const QDate &begin, const QDate &end);
private:
    bool eventFilter(QObject *object, QEvent *event);
    void moveEvent(QMoveEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // DATEPICKER_H
