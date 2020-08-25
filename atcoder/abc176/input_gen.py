import random

if __name__ == '__main__':
    with open("sample.out", "w+") as fd:
        h = random.randint(1, 1000)
        w = random.randint(1, 1000)
        ch = random.randint(1, h)
        dh = random.randint(1, h)
        cw = random.randint(1, w)
        dw = random.randint(1, w)
        fd.write("{} {}\n".format(h, w))
        fd.write("{} {}\n".format(ch, cw))
        fd.write("{} {}\n".format(dh, dw))
        for y in range(h):
            maze_row = []
            for x in range(w):
                maze_row.append(random.choice(['#', '.']))
            fd.write(" ".join(maze_row))
            fd.write("\n")
