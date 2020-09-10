from typing import List
 
class Solution:
    def __init__(self, input_array, k):
        self.arr = input_array
        self.k = k

    def _get_median(self) -> int:
        mid = (len(self.arr)-1)//2
        return sorted(self.arr)[mid]

    def getStrongest(self) -> List[int]:
       return sorted(self.arr, reverse = True, key = lambda x: (abs(x-self._get_median()), x))[:self.k]
       
def main():
    k = int(input())
    arr = [int(i) for i in input().split()]
    sol = Solution(arr, k)
    result = sol.getStrongest()
    print(result)

if __name__ == "__main__":
    main()
