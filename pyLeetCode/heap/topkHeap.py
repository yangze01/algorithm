import heapq
import random

class TopkHeap(object):
    def __init__(self, k):
        self.k = k
        self.data = []

    def Push(self, elem):
        if len(self.data) < self.k:
            heapq.heappush(self.data, elem)
        else:
            topk_small =self.data[0]
            if elem[0] > topk_small[0]:
                heapq.heapreplace(self.data, elem)
    def Tok(self):
        return [x[1] for x in reversed([heapq.heappop(self.data) for x in range(len(self.data))])]


if __name__ == "__main__":
    test = [1, 2, 3, 2, 2, 2, 4, 5, 6, 6, 1]
    my_dict = dict()
    for i in test:
        if i in my_dict:
            my_dict[i] += 1
        else:
            my_dict[i] = 1
    print(my_dict)
    th = TopkHeap(3)
    for key, value in my_dict.items():
        th.Push((value, key))
    print(th.Tok())
