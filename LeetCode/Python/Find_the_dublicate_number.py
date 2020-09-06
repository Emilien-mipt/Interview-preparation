class Solution:
    def __init__(self, input_list):
        self.nums = input_list

    def _binary_search(self, left, target):
        right = len(self.nums)-1
        while left <= right:
           mid = left + (right - left)//2
           if self.nums[mid] == target:
               return mid
           elif self.nums[mid] < target:
               left = mid + 1
           else: 
               right = mid - 1
        return -1   

    def find_duplicate(self):
        for i in range(len(self.nums)):
            t = self.nums[i]
            res = self._binary_search(i+1, t)
            if res >= 0:
                break
        return self.nums[res]

def main():
    input_array = [int(s) for s in input().split()]
    input_array.sort()
    sol = Solution(input_array)
    result = sol.find_duplicate()
    print(result)

if __name__ == "__main__":
    main()
