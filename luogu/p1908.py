from cyaron import *
import random

if __name__ == '__main__':
    for i in range(3):
        case = IO(file_prefix='p1908', data_id=i)
        n = random.randint(1, 5e5)
        case.input_writeln(n)
        a = [random.randint(1, 1e9) for _ in range(n)]
        case.input_write(a)
        print(n, a)
