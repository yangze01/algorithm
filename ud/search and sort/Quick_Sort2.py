# coding=utf-8
import sys
reload(sys)
sys.setdefaultencoding('utf8')
def quicksort(array,left,right):
    if left >= right:
        return array
    else:
        key = array[left]
        low = left
        high = right
        while(low < high):
            while low < high and array[high] >= key:
                high -= 1
            array[low] = array[high]
            while low < high and array[low] <= key:
                low += 1
            array[high] = array[low]
        array[low] = key
        quicksort(array,left,low-1)
        quicksort(array,low+1,right)
        return array
if __name__ == "__main__":
    test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
    print quicksort(test,0,len(test)-1)
