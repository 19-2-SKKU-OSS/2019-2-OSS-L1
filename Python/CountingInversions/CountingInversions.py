'''
Counting Inversions
Counting inversions is getting list of descending pair
(descending pair is inversion of sorted list by ascending order )
This algorithm used to study simple algorithms.
'''


#  countingInversions function
#  Double loop can get all pair which is inverse order
#  Outer loop check all number except last number
#  Inner loop compare number between outer number and inner number
def countingInversions(list):
    result = []
    list_length = len(list)
    for i in range(list_length - 1):
        for j in range(i + 1, list_length):
            if (list[i]>list[j]):
                result.append([list[i], list[j]])
    return result


# Main
input = [6, 7, 2, 5, 1, 4, 3]
print(countingInversions(input))
