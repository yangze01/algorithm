# coding=utf-8
import sys
reload(sys)
sys.setdefaultencoding('utf8')
def quicksort(array):
    if not array or len(array) == 1:
        return array
    base = array[-1]
    left_array,right_array = [],[]
    for i in array[:-1]:
        if i >= base:
            right_array.append(i)
        else:
            left_array.append(i)
    left_array = quicksort(left_array)
    right_array = quicksort(right_array)
    return left_array + [base] + right_array

if __name__ == "__main__":
    test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
    print quicksort(test)
