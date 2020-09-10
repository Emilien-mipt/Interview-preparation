from collections import Counter
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        help_dict = Counter(nums)
        count_k = 0
        result_list = []
        for key, value in sorted(help_dict.items(), key = lambda x: x[1], reverse = True):
            count_k += 1
            if count_k <= k:
                result_list.append(key)
            else:
                break
        return result_list  

def main():
    k = int(input())
    arr = [int(n) for n in input().split()]
    sol = Solution()
    print(sol.topKFrequent(arr, k))

if __name__=="__main__":
    main()
