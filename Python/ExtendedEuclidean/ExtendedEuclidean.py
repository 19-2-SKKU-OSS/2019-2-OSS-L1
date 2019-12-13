'''
Extended Euclidean algorithm
'''


def ExtendedEuclidean(a, b):
    if a == 0:
        return b

    gcd = ExtendedEuclidean(b % a, a)
    return gcd


a = 14
b = 35
g = ExtendedEuclidean(a, b)
print(a, b, g)
