def downheap(i, size):
    while 2*i <= size:
        k = 2*i
        if k < size and array[k] < array[k+1]:
            k += 1
        if array[i] >= array[k]:
            break
        array[i], array[k] = array[k], array[i]
        i = k

def create_heap(array):
    hsize = len(array) - 1
    for i in reversed(range(1, hsize//2 + 1)):
        downheap(i, hsize)

def heap_sort(array):
    N = len(array) - 1
    for i in range(N):
        array[1], array[N] = array[N], array[1]
        downheap(1, N-1)
        N -= 1



array = [-17, 5, 65, 23, 57, 1232, -1, -5, -2, 242, 100,
         4, 423, 2, 564, 9, 0, 10, 43, 64, 32, 1, 999]
print(array)
create_heap(array)
heap_sort(array)
print(array)
