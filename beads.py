"""
ID: yaagnto2
LANG: PYTHON3
TASK: beads
"""


def beads(lh, s):
    s = s * 2

    ans = 0
    for i in range(lh):
        cur = 0
        flag = True
        sign = 'w'
        for c in s[i:]:
            if c == 'w' or c == sign:
                cur += 1
            elif sign == 'w':
                sign = c
                cur += 1
            elif flag:
                sign = c
                cur += 1
                flag = not flag
            else:
                break
        ans = max(cur, ans)

    return ans if ans < lh else lh


with open('beads.in', 'r') as fin:
    with open('beads.out', 'w') as fout:
        n = int(fin.readline().strip())
        neck = fin.readline().strip()
        fout.write('{}\n'.format(beads(n, neck)))
