def merge(l, r):
    i = 0
    j = 0
    k = []

    while(i < len(l)) & (j < len(r)):
        if l[i] < r[j]:
            k.append(l[i])
            i += 1
        else:
            k.append(r[j])
            j += 1

    while(i < len(l)):
        k.append(l[i])
        i += 1

    while(j < len(r)):
        k.append(r[j])
        j += 1

    return k

        
def merge_sort(list):
    if len(list) <= 1:
        return list
    mid = len(list) // 2
    left = list[:mid]
    right = list[mid:]

    l = merge_sort(left)
    r = merge_sort(right)
    return merge(l, r)


array = [1, 5, 65, 23, 57, 1232, -1, -5, -2, 242, 100,
         4, 423, 2, 564, 9, 0, 10, 43, 64, 32, 1, 999]
print(array)
print(merge_sort(array))
