from typing import List

class Solution:
    def binary_iterative_search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            mid = left + (right-left)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
        return -1

def main():
    print("Input sorted array: ")
    arr = [int(i) for i in input().split()]
    print("Input target: ")
    t = int(input())
    sol = Solution()
    print(sol.binary_iterative_search(arr, t))

if __name__ == "__main__":
    main()
