def fibo(n):
    list = [0, 1]
    if n < 2:
        return list[n]
    else:
        for i in range(2, n+1):
            list.append(list[i - 1] + list[i - 2])
        return list[n]
    
print(fibo(15))
