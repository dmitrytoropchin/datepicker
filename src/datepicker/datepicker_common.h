#ifndef DATEPICKER_COMMON_H
#define DATEPICKER_COMMON_H

#include <QtGlobal>

class QApplication;

void init_datepicker(QApplication *app);


enum DatePickerView {
    MonthView,
    YearView,
    DecadeView
};

enum DatePickerType {
    DayType = 0x0001,
    PeriodType = 0x0002
};


Q_DECLARE_FLAGS(DatePickerTypes, DatePickerType)
Q_DECLARE_OPERATORS_FOR_FLAGS(DatePickerTypes)


#if defined(DATEPICKER_LIBRARY)
#  define DATEPICKER_EXPORT Q_DECL_EXPORT
#else
#  define DATEPICKER_EXPORT Q_DECL_IMPORT
#endif

#endif // DATEPICKER_COMMON_H
