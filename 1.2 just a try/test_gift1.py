import unittest


class MyTestCase(unittest.TestCase):
    def test_something(self):
        with open('gift1.out') as f:
            lns = [ln.strip() for ln in f.readlines()]
            scores = map(lambda x: int(x.split()[1]), lns)
            self.assertEqual(sum(scores), 0)


if __name__ == '__main__':
    unittest.main()
