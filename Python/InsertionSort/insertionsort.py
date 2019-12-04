def insertion_sort(list):
    i = 1
    for i in range(i, len(list)):
        k = list[i]
        j = i - 1
        while j >= 0 and list[j] > k:
            list[j+1] = list[j]
            j = j - 1
        list[j+1] = k


    return list




array = [1, 5, 65, 23, 57, 1232, -1, -5, -2, 242, 100,
         4, 423, 2, 564, 9, 0, 10, 43, 64, 32, 1, 999]
print(array)
insertion_sort(array)
print(array)
