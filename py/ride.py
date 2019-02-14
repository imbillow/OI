"""
ID: yaagnto2
LANG: PYTHON3
TASK: ride
"""
import functools

with open('ride.in', 'r') as fin:
    lns = map(lambda x: map(lambda n: ord(n) - 64, list(x.strip())), fin.readlines())
    par = [functools.reduce(lambda x, y: x * y, ln) for ln in lns]
    with open('ride.out', 'w') as fout:
        a, b = [x % 47 for x in par]
        fout.write('{}\n'.format('GO' if a == b else 'STAY'))
