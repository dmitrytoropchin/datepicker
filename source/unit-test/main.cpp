#include <QApplication>
#include <datepicker/datepicker.h>
#include <datepicker/datepickerhumanreadableformater.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    init_datepicker(&app/*, QLocale::system()*/);               // initilize library resources (needed for translations)

    DatePicker picker;                                          // create date picker widget
    
    DatePickerHumanReadableFormater *formater = new DatePickerHumanReadableFormater();
//    formater->setFromWord(QString::null);                     // setup period delimeters
//    formater->setToWord("-");                                 // produces "5 - 9 october 2014"

    picker.setAllowedPickerTypes(PeriodType | DayType);         // is default
    picker.setEditable(true);                                   // is default
    picker.setFormater(formater);                               // is default (formater will be deleted in picker destructor)

    Q_UNUSED(picker.label());                                   // date picker label can be customized in usual way

//    picker.setDate(QDate::currentDate());                       // set initial date or period
     picker.setPeriod(QDate::currentDate(), QDate::currentDate().addDays(1));

//    picker.setMinimumDate(QDate(2013, 4, 23));
//    picker.setMaximumDate(QDate(2015, 9, 13));
    picker.setRange(QDate(2013, 4, 23), QDate(2015, 9, 13));


    picker.show();

    // wait for signal DatePicker::editingFinished()
    // use picker.pickerType() to obtain input format (day or period)
    // based on obtained input format extract selected date or period by
    // picker.selectedDate() or
    // picker.selectedPeriodBegin() and picker.selectedPeriodEnd()

    return app.exec();
}
