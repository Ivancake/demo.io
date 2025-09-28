def f(list, key):
    first = 0
    flag = 0
    last = len(list) - 1
    # если список пустой
    if len(list) == 0:
        list.append(key)
        return 0, list
    while first <= last:
        mid = first + (last - first) // 2 # находим индекс середины массива
        midv = list[mid] # берем значение по индексу mid
        if midv == key: #нашли значение, выводим индекс и меняем значение flag
            flag = 1
            return mid, list
        if midv > key: # ищем в левой половине
            last = mid - 1
        else:
            first = mid + 1 # ищем в правой половине
    if flag == 0: #если не нашли элемент в списке
        if midv > key:
            list.insert(mid, key)
            return mid, list
        else:
            list.insert(mid + 1, key)
            return mid + 1, list
a = [1, 2, 4, 5, 6, 7]
b = [1, 2, 3, 4, 5, 6, 7]
print(f(sorted(a), 3))
print(f(sorted(b), 4))
