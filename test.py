"""
ID: yaagnto2
LANG: PYTHON3
TASK: test
"""
with open('test.in', 'r') as fin:
    x, y = map(int, fin.readline().split())
    with open('test.out', 'w') as fout:
        fout.write('{}\n'.format(x + y))
