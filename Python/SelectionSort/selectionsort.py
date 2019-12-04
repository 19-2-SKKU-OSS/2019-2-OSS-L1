def selection_sort(list):
    for i in range(len(list)-1):
        mini = i
        for j in range(i + 1, len(list)):
            if list[j] < list[mini]:
                mini = j
        list[i], list[mini] = list[mini], list[i]

    return list




array = [1, 5, 65, 23, 57, 1232, -1, -5, -2, 242, 100,
         4, 423, 2, 564, 9, 0, 10, 43, 64, 32, 1, 999]
print(array)
selection_sort(array)
print(array)
