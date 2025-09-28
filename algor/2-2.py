def f(list):
    if len(list) < 3:
        return "Нет"
    first = 0
    last = len(list) - 1
    while first <= last:
        mid = first + (last - first) // 2
        # Проверяем, является ли mid пиком
        if 0 < mid < len(list) - 1 and list[mid - 1] < list[mid] > list[mid + 1]:
            # Нашли пик, но нужно проверить, есть ли пики левее
            # Ищем первый пик в левой части
            left = 1
            while left < mid:
                if list[left - 1] < list[left] > list[left + 1]:
                    return left
                left += 1
            return mid
        # пик в правой половине
        if 0 < mid < len(list) - 1 and list[mid] < list[mid + 1]:
            first = mid + 1
        # пик в левой половине
        elif 0 < mid < len(list) - 1 and list[mid] > list[mid + 1]:
            last = mid - 1
    return "Нет"


a = [2, 4, 3, 1, 2, 6, 3, 8, 4, 5, 4]
print(f(a))

