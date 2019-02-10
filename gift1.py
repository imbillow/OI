"""
ID: yaagnto2
LANG: PYTHON3
TASK: gift1
"""
import sys

with open('gift1.in', 'r') as fin:
    with open('gift1.out', 'w') as fout:
        lines = [line.strip() for line in fin.readlines()]
        n = int(lines[0])
        names = lines[1:n + 1]
        data = {k: 0 for k in names}
        idx = n + 1
        for _ in names:
            name = lines[idx]
            amount, m = map(int, lines[idx + 1].split())
            if m > 0:
                ave = amount // m
                real_amount = ave * m
                data[name] -= real_amount
                keys = lines[idx + 2:idx + 2 + m]
                sys.stderr.write('{} giving {} {}\n'.format(name, keys, real_amount))
                for k in keys:
                    data[k] += ave
                sys.stderr.write('{}\n'.format(data))
            idx += m + 2
        for name in names:
            fout.write('{} {}\n'.format(name, data[name]))
