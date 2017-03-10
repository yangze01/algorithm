class Solution(object):
    """
    @param A: An integer array.
    @param B: An integer array.
    @return: a double whose format is *.5 or *.0
    """
    def findMedianSortedArrays(self, nums1, nums2):
        n = len(nums1) + len(nums2)
        if n % 2 == 1:
            return self.findKth(nums1, nums2, n / 2 + 1)
        else:
            smaller = self.findKth(nums1, nums2, n / 2)
            bigger = self.findKth(nums1, nums2, n / 2 + 1)
            return (smaller + bigger) / 2.0

    def findKth(self, A, B, k):
        if len(A) == 0:
            return B[k - 1]
        if len(B) == 0:
            return A[k - 1]
        if k == 1:
            return min(A[0], B[0])

        a = A[int(k / 2 - 1)] if len(A) >= k / 2 else None
        b = B[int(k / 2 - 1)] if len(B) >= k / 2 else None

        if b is None or (a is not None and a < b):
            return self.findKth(A[int(k / 2):], B, int(k - k / 2))
        return self.findKth(A, B[int(k / 2):], int(k - k / 2))
if __name__ == "__main__":
    solution = Solution()
    A = [1,4,6,8]
    B = [2,5,7]
    ret = solution.findMedianSortedArrays(A,B)
    print(ret)
