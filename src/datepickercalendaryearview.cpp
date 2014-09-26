#include "datepicker/datepickercalendaryearview.h"
#include <QHeaderView>


DatePickerCalendarYearView::DatePickerCalendarYearView(QWidget *parent) :
    QTableWidget(parent)
{
    setRowCount(3);
    setColumnCount(4);

    QTableWidgetItem *item = 0;
    for (int i = 0; i < 12; ++ i) {
        item = new QTableWidgetItem(QDate::shortMonthName(i + 1, QDate::StandaloneFormat));
        item->setTextAlignment(Qt::AlignCenter);
        item->setBackgroundColor(Qt::white);
        setItem(i / 4, i % 4, item);
    }

    verticalHeader()->hide();
    verticalHeader()->setResizeMode(QHeaderView::Stretch);

    horizontalHeader()->hide();
    horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    setFrameStyle(QFrame::NoFrame);

    setShowGrid(false);

    connect(this, SIGNAL(cellClicked(int,int)), SLOT(onCellClicked(int,int)));
}

DatePickerCalendarYearView::~DatePickerCalendarYearView()
{
}

void DatePickerCalendarYearView::setDate(const QDate &date)
{
    setCurrentCell((date.month() - 1) / 4, (date.month() - 1) % 4, QItemSelectionModel::SelectCurrent);
}

void DatePickerCalendarYearView::onCellClicked(int row, int column)
{
    emit monthClicked(row * 4 + column + 1);
}
