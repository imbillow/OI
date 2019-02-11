import unittest

from beads import beads

data = [
    (
        6,
        'rwbrwb',
        4
    ),
    (
        29,
        'wwwbbrwrbrbrrbrbrwrwwrbwrwrrb',
        11
    ),
    (
        3,
        'rrr',
        3
    )
]


class TestBeads(unittest.TestCase):
    def test_beads(self):
        for (lh, text, exp) in data:
            self.assertEqual(exp, beads(lh, text))
