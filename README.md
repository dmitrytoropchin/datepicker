Виджет выбора даты/периода
==========================

Подробный пример использования можно найти [здесь](http://gitlab.orion.org/jericho/datepicker/blob/master/source/unit-test/main.cpp)

Основный классы
---------------

*	[DatePicker](http://gitlab.orion.org/jericho/datepicker/blob/master/source/library/source/datepicker/datepicker.h)

	Виджет выбора даты/периода при помощи выпадающего календаря

*	[DatePickerStandardFormater](http://gitlab.orion.org/jericho/datepicker/blob/master/source/library/source/datepicker/datepickerstandardformater.h)

	Класс для вывода дат на экран на основе метода `QDate::toString(const QString &format)`.

*	[DatePickerHumanReadableFormater](http://gitlab.orion.org/jericho/datepicker/blob/master/source/library/source/datepicker/datepickerhumanreadableformater.h)

	Класс вывода дат в удобном для чтения формате.

*	[DatePickerAbstractFormater](http://gitlab.orion.org/jericho/datepicker/blob/master/source/library/source/datepicker/datepickerabstractformater.h)

	Базовый класс для написания собственных преобразователей дат в строку.
