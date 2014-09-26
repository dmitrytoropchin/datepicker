#include <QApplication>
#include <datepicker/datepicker.h>
#include <datepicker/datepickerhumanreadableformater.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    init_datepicker(&app);

    DatePicker picker;

    picker.setAllowedPickerTypes(PeriodType | DayType);         // is default
    picker.setEditable(true);                                   // is default
    picker.setFormater(new DatePickerHumanReadableFormater());  // is default (formater will be deleted in picker destructor)

    Q_UNUSED(picker.label());                                   // date label can be customized in usual way

    picker.setDate(QDate::currentDate());

    picker.show();

    return app.exec();
}
