#include "datepicker/datepicker_common.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>


void init_datepicker(QApplication *app)
{
    Q_INIT_RESOURCE(datepicker_resources);

    QTranslator *datepicker_translator = new QTranslator(app);
    if (!datepicker_translator->load(":/datepicker_translations/ru"))
        qDebug() << "failed to load datepicker lib translations";

    app->installTranslator(datepicker_translator);
}
