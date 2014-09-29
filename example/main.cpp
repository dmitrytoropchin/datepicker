#include <QApplication>
#include <datepicker/datepicker.h>
#include <datepicker/datepickerhumanreadableformater.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    init_datepicker(&app);                                      // initilize library resources (needed for translations)

    DatePicker picker;                                          // create date picker widget

    picker.setAllowedPickerTypes(PeriodType | DayType);         // is default
    picker.setEditable(true);                                   // is default
    picker.setFormater(new DatePickerHumanReadableFormater());  // is default (formater will be deleted in picker destructor)

    Q_UNUSED(picker.label());                                   // date picker label can be customized in usual way

    picker.setDate(QDate::currentDate());                       // set initial date or period
    // picker.setPeriod(QDate::currentDate(), QDate::currentDate().addDays(1));

    picker.show();

    // wait for signal DatePicker::editingFinished()
    // use picker.pickerType() to obtain input format (day or period)
    // based on obtained input format extract selected date or period by
    // picker.selectedDate() or
    // picker.selectedPeriodBegin() and picker.selectedPeriodEnd()

    return app.exec();
}
