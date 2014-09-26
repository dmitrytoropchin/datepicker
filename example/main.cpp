#include <QApplication>
#include <datepicker/datepicker.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    init_datepicker(&app);

    DatePicker picker;
    picker.setAllowedPickerTypes(PeriodType | DayType);
    picker.setDate(QDate::currentDate());
    picker.show();

    return app.exec();
}
