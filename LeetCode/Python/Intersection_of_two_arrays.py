from typing import List

class Solution:
    def __init__(self):
        self.intersection_set = set()
        self.intersection_list = []
        
    def _list_to_set(self, num: List[int]):
        return set(num)
    
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1_set = self._list_to_set(nums1)
        nums2_set = self._list_to_set(nums2)
        print(nums1_set)
        print(nums2_set)
        self.intersection_set = nums1_set & nums2_set
        print(self.intersection_set)
        self.intersection_list = list(self.intersection_set)
        return self.intersection_list

def main():
    print("Input first array: ")
    a = [int(s) for s in input().split()]
    
    print("Input second array: ")
    b = [int(s) for s in input().split()]
    
    sol = Solution()
    print(sol.intersection(a, b))

if __name__== "__main__":
    main()
