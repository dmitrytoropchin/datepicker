#include "datepicker/datepickercalendardecadeview.h"
#include <QHeaderView>


DatePickerCalendarDecadeView::DatePickerCalendarDecadeView(QWidget *parent) :
    QTableWidget(parent)
{
    setRowCount(3);
    setColumnCount(4);

    QTableWidgetItem *item = 0;
    for (int i = 0; i < 12; ++ i) {
        item = new QTableWidgetItem();
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

DatePickerCalendarDecadeView::~DatePickerCalendarDecadeView()
{
}

void DatePickerCalendarDecadeView::setDate(const QDate &date)
{
    for (int i = 0; i < 12; ++ i)
        item(i / 4, i % 4)->setText(date.addYears(i - 5).toString("yyyy"));
    setCurrentCell(1, 1, QItemSelectionModel::SelectCurrent);
}

void DatePickerCalendarDecadeView::onCellClicked(int row, int column)
{
    emit yearClicked(QDate::fromString(item(row, column)->text(), "yyyy").year());
}
