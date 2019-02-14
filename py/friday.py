"""
ID: yaagnto2
LANG: PYTHON3
TASK: friday
"""


def is_leap_year(year: int) -> bool:
    if year % 100 == 0:
        return year % 400 == 0
    else:
        return year % 4 == 0


def get_months(year) -> list:
    months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    months[2] = 29 if is_leap_year(year) else 28
    return months


def get_offset(year, month, day) -> int:
    assert year >= 1900
    months = get_months(year)
    return sum(map(lambda x: 366 if is_leap_year(x) else 365, range(1900, year))) + sum(
        map(lambda x: months[x], range(1, month))) + day - 1


with open('friday.in', 'r') as fin:
    with open('friday.out', 'w') as fout:
        n = int(fin.readline().strip())
        res = {w: 0 for w in range(7)}
        y, m, d = (1900, 1, 13)
        offset = get_offset(y, m, d)
        w = offset % 7
        mns = get_months(y)
        limit = 1900 + n

        for _ in range(400 * 12):
            if y >= limit:
                break

            res[w] += 1

            offset += mns[m]
            w = offset % 7
            if m != 12:
                m += 1
            else:
                m = 1
                y += 1
                mns = get_months(y)
        fout.write(' '.join(map(lambda x: str(res[x]), [5, 6, 0, 1, 2, 3, 4])) + '\n')
