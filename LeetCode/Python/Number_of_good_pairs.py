from typing import List, Dict
from collections import Counter

class Solution:
    def _count_pairs(self, input_list: List) -> int:
        result_count = 0
        for i in range(len(input_list)-1):
            result_count += len(input_list[i+1:])
        return result_count

    def _create_dict(self, input_list: List) -> Dict[int, int]:
        result_dict = {}
        for i in range(len(input_list)):
            if input_list[i] not in result_dict.keys():
                result_dict[input_list[i]] = [i]
            else:
                result_dict[input_list[i]].append(i)
        return result_dict

    def numIdenticalPairs(self, nums: List[int]) -> int:
        count_dict = self._create_dict(nums)
        result_count = 0 
        for key, value in count_dict.items():
            if len(value) == 1:
                continue
            else:
                result_count += self._count_pairs(value)
        return result_count

class Easy_Solution:
    def _count_pairs(self, n: int) -> int:
        sum = 0
        for i in range(1, n):
            sum += i
        return sum
    
    def _create_dict(self, input_list: List) -> Dict[int, int]:
        return Counter(input_list)
    
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count_dict = self._create_dict(nums)
        result = 0
        for value in count_dict.values():
            result += self._count_pairs(value)
        return result    

class SuperEasySolution:
        
    # search for duplicate numbers
    def numIdenticalPairs(self, nums: List[int]) -> int:
        
        # number of good pairs
        repeat = {}
        num = 0
        
        # for every element in nums
        for v in nums:
            
            # number of repeated digits
            if v in repeat:
                
                # count number of pairs based on duplicate values
                if repeat[v] == 1:
                    num += 1
                else:
                    num += repeat[v]
                
                # increment the number of counts
                repeat[v] += 1
            # number has not been seen before
            else:
                repeat[v] = 1
        # return
        return num

def test():
    sol = Solution()
    easy_sol = Easy_Solution()
    assert(sol.numIdenticalPairs([1, 2, 3, 1, 1, 3]) == easy_sol.numIdenticalPairs([1, 2, 3, 1, 1, 3]) == 4)
    assert(sol.numIdenticalPairs([1, 1, 1, 1]) == easy_sol.numIdenticalPairs([1, 1, 1, 1]) == 6)
    assert(sol.numIdenticalPairs([1, 2, 3]) == easy_sol.numIdenticalPairs([1, 2, 3]) == 0)

def main():
    test()


if __name__ == "__main__":
    main()
