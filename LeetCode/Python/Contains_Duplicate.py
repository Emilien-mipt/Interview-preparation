class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        help_dict = Counter(nums)
        result = False
        for value in help_dict.values():
            if value > 1:
                result = True
                break
        return result
