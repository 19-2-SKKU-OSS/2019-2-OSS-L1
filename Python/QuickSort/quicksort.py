def qsort(list, low, high):
    if low < high:
        pivot = partition(list, low, high)
        qsort(list, low, pivot-1)
        qsort(list, pivot+1, high)

def partition(list, pivot, high):
    i = pivot + 1
    j = high
    while True:
        while i < high and list[i] < list[pivot]:
            i += 1
        while j > pivot and list[j] > list[pivot]:
            j -= 1
        if j <= i:
            break
        list[i], list[j] = list[j], list[i]
        i += 1
        j -= 1

    list[pivot], list[j] = list[j], list[pivot]
    return j

array = [1, 5, 65, 23, 57, 1232, -1, -5, -2, 242, 100,
         4, 423, 2, 564, 9, 0, 10, 43, 64, 32, 1, 999]
print(array)
qsort(array, 0, len(array) - 1)
print(array)
