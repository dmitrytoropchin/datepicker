#include "datepicker/datepickercalendarmonthview.h"
#include <QTextCharFormat>
#include <QTableView>
#include <QHeaderView>


DatePickerCalendarMonthView::DatePickerCalendarMonthView(QWidget *parent) :
    QCalendarWidget(parent)
{
    setDateEditEnabled(false);
    setNavigationBarVisible(false);
    setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    setFirstDayOfWeek(Qt::Monday);

    QTableView *calendar_view = findChild<QTableView *>("qt_calendar_calendarview");
    if (calendar_view) {
        calendar_view->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
        calendar_view->horizontalHeader()->setDefaultSectionSize(32);
        calendar_view->verticalHeader()->setResizeMode(QHeaderView::Fixed);
        calendar_view->verticalHeader()->setDefaultSectionSize(25);
    }

    QTextCharFormat cell_text_format = headerTextFormat();
    cell_text_format.setBackground(QBrush(Qt::white));
    cell_text_format.setForeground(palette().windowText());

    QTextCharFormat header_text_format = cell_text_format;
    header_text_format.setFontWeight(QFont::Bold);

    setHeaderTextFormat(header_text_format);
    setWeekdayTextFormat(Qt::Monday, cell_text_format);
    setWeekdayTextFormat(Qt::Tuesday, cell_text_format);
    setWeekdayTextFormat(Qt::Wednesday, cell_text_format);
    setWeekdayTextFormat(Qt::Thursday, cell_text_format);
    setWeekdayTextFormat(Qt::Friday, cell_text_format);
    setWeekdayTextFormat(Qt::Saturday, cell_text_format);
    setWeekdayTextFormat(Qt::Sunday, cell_text_format);

    connect(this, SIGNAL(clicked(QDate)), SIGNAL(dateClicked(QDate)));
}

DatePickerCalendarMonthView::~DatePickerCalendarMonthView()
{
}

QSize DatePickerCalendarMonthView::minimumSizeHint() const
{
    return QSize(32 * 7, 25 * 7);
}

void DatePickerCalendarMonthView::setDate(const QDate &date)
{
    setCurrentPage(date.year(), date.month());
    setSelectedDate(date);

    setDateTextFormat(QDate(), QTextCharFormat());
}

void DatePickerCalendarMonthView::setPeriod(const QDate &begin, const QDate &end, bool shows_begin)
{
    QDate shown_date = shows_begin ? begin : end;

    setCurrentPage(shown_date.year(), shown_date.month());
    setSelectedDate(shown_date);

    setDateTextFormat(QDate(), QTextCharFormat());

    QTextCharFormat highlight_date_format;
    highlight_date_format.setBackground(QBrush(QColor(0xd3, 0xdd, 0xe5)));

    for (QDate date_idx = begin; date_idx <= end; date_idx = date_idx.addDays(1))
        setDateTextFormat(date_idx, highlight_date_format);
}
