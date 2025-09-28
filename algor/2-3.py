def f(list):
    first = 0
    count_otr = 0
    last = len(list) - 1
    # если список пустой
    if len(list) == 0:
        return 0, 0
    while first <= last:
        mid = first + (last - first) // 2 # находим индекс середины массива
        midv = list[mid] # берем значение по индексу mid
        if midv > 0: #Если найден положительный элемент
        # Запоминаем его индекс как потенциальную границу между отрицательными и положительными
            count_otr = mid
            last = mid - 1
        else:
            first = mid + 1
    count_pol = len(list) - count_otr # положительные числа
    count_otr -= list.count(0) #убираем лишние нули при подсчете отрицательных чисел
    if (len(list) - count_otr) > count_otr:
        return "Больше положительных чисел", count_pol
    elif (len(list) - count_otr) > count_otr:
        return "Количество положительных и отрицательных чисел равно", count_otr
    else:
        return "Больше отрицательных чисел", count_otr
a = [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
print(f(sorted(a)))
