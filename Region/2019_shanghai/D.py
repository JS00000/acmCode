from __future__ import division
from sympy.utilities.iterables import combinations_with_replacement
from operator import mul
from functools import reduce
from math import factorial

def A297815(n):
    f = factorial(n)
    return sum(f//reduce(mul, (factorial(d.count(a)) for a in set(d))) for d in combinations_with_replacement(range(1, max(10, n)), n) if reduce(mul, d) == sum(d))



for n in range(1, 24):
    print(n, A297815(n))