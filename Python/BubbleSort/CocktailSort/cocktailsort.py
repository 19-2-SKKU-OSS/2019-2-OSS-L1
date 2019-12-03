"""
Cocktail sort
cocktail sort is modified version of bubble sort.
1. check first and second member of unsorted numbers.
2. compare them and change position if first member bigger than second member.
3. repeat 1-2 process before comparing all number done.
4. repeat 1-3 process in the opposite direction (last number to first number)
5. repeat 3-4 process as many times as the number to sort

Time complexity: T(n) = O(n^2)

Advantage
1. easy to implement
2. usually used to teach algorithms
Disadvantage
1. very slow
2. swap process is more difficult than move process
"""

def cocktail(list):
    # bidirectional bubble sort
    for i in range(len(list)//2):
        # right direction bubble sort
        for j in range(1+i, len(list)-i):
            if list[j] < list[j-1]:
                list[j], list[j-1] = list[j-1], list[j]
        # left direction bubble sort
        for j in range(len(list)-i-1, i, -1):
            if list[j] < list[j - 1]:
                list[j], list[j-1] = list[j-1], list[j]

input = [3, 1, 9, 7, 5, 6, 8, 2, 4]
print("Before: ", input)
cocktail(input)
print("After:  ", input)
