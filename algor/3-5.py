def f(n):
    n = str(n ** 2)
    # если длина строки нечетная
    if len(n) % 2 != 0:
        n = '0' + n
    mid_ind = len(n) // 2
    st_ind = mid_ind - 2
    end_ind = mid_ind + 3
    return int(n[st_ind:end_ind])
a = int(input())
for i in range(10):
    print(str(a).ljust(5, '0'), end=' ')
    a = f(a)