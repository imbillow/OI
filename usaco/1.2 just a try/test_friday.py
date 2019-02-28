from unittest import TestCase

from friday import is_leap_year, get_offset
import calendar
import datetime
import random


def add_one_day(date: datetime.date) -> datetime.date:
    return date + datetime.timedelta(days=1)


class TestFriday(TestCase):
    def test_is_leap_year(self):
        for i in range(1799, 1799 + 400):
            is_leap = is_leap_year(i)
            self.assertEqual(is_leap, calendar.isleap(i))

    def test_get_weekday(self):
        date = datetime.datetime(1900, 1, 1)
        for _ in range(3000):
            date += datetime.timedelta(days=random.randint(1, 10))
            act = get_offset(date.year, date.month, date.day) % 7
            exp = calendar.weekday(date.year, date.month, date.day)
            self.assertEqual(exp, act)
