from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for x in nums1:
            temp_list = nums2[nums2.index(x):]  
            temp_result = []
            
            for n in temp_list:
                if n>x:
                    result.append(n)
                    temp_result.append(n)
                    break
            if temp_result == []:
                result.append(-1)
        return result
