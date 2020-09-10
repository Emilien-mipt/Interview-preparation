from typing import List, Dict
from collections import Counter

class Solution:
    def _count_elements(self, input_arr: List[int]) -> Dict[int, int]:
        return Counter(input_arr)

    def _sum_values(self, input_dict: Dict[int, int]) -> int:
        sum = 0
        for value in input_dict.values():
            sum += value
        return sum

    def minSetSize(self, arr: List[int]) -> int:
        # Fill the dictionary with number of elements
        counted_dict = self._count_elements(arr)
        n_of_elements = self._sum_values(counted_dict)
        assert(len(arr) == n_of_elements)
        # Apply greedy algorithm
        count_sum = 0
        result_set_size = 0
        for value in sorted(counted_dict.values(), reverse = True):
            count_sum += value
            result_set_size += 1
            if count_sum >= n_of_elements/2:
                break
        return result_set_size
  
            
        
 
def main():
    arr = [int(n) for n in input().split()]
    sol = Solution()
    result = sol.minSetSize(arr)
    print(result)

if __name__ == "__main__":
    main()
