from unittest import TestCase

from friday import is_leap_year, Date
import calendar
import datetime


def add_one_day(date: datetime.date) -> datetime.date:
    return date + datetime.timedelta(days=1)


class TestFriday(TestCase):
    def test_is_leap_year(self):
        for i in range(1799, 1799 + 400):
            is_leap = is_leap_year(i)
            self.assertEqual(is_leap, calendar.isleap(i))

    def test_date(self):
        date = Date()
        date2 = datetime.date(1900, 1, 1)
        for i in range(365 * 400):
            date2 = add_one_day(date2)
            date = date.__next__()
            self.assertEqual(date.y, date2.year)
            self.assertEqual(date.m, date2.month,
                             'date\' mouths:{}, date1:{}  date2:{}'.format(date.mouths, date, date2))
            self.assertEqual(date.d, date2.day)
            self.assertEqual(date.w, date2.weekday())
