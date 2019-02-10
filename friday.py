"""
ID: yaagnto2
LANG: PYTHON3
TASK: friday
"""
from collections import Iterable
from typing import Iterator


def is_leap_year(year: int) -> bool:
    if year % 100 == 0:
        return year % 400 == 0
    else:
        return year % 4 == 0


class Date(Iterable):
    Mouths = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    Week = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

    def __init__(self):
        self.y = 1900
        self.m = 1
        self.d = 1
        self.mouths = Date.Mouths.copy()
        self.w = 0

    def __iter__(self) -> Iterator:
        return self

    def __next__(self):
        if self.w != 6:
            self.w += 1
        else:
            self.w = 0
        if self.d != self.mouths[self.m]:
            self.d += 1
        else:
            self.d = 1
            if self.m != 12:
                self.m += 1
            else:
                self.m = 1
                self.y += 1
                self.mouths[2] = 29 if is_leap_year(self.y) else 28
        return self

    def __str__(self) -> str:
        return '{}-{}-{}, {}'.format(self.y, self.m, self.d, Date.Week[self.w])


with open('friday.in', 'r') as fin:
    with open('friday.out', 'w') as fout:
        n = int(fin.readline().strip())
        res = {w: 0 for w in range(7)}
        for date in Date():
            if date.y >= n + 1900:
                break
            if date.d == 13:
                res[date.w] += 1
        fout.write(' '.join(map(lambda x: str(res[x]), [5, 6, 0, 1, 2, 3, 4])) + '\n')
