#include <QApplication>
#include <datepicker/datepicker.h>
#include <datepicker/datepickerstandardformater.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    init_datepicker(&app);

    DatePickerStandardFormater formater;

    DatePicker picker;
    picker.setAllowedPickerTypes(PeriodType | DayType);
    picker.setDate(QDate::currentDate());
    picker.setFormater(&formater);
    picker.show();


    return app.exec();
}
