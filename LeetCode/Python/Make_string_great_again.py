from typing import List

class Solution:
    def _check(self, char_1: str, char_2: str) -> bool:
        char_1_lower = char_1.islower()
        char_1_upper = char_1.isupper()
        char_2_lower = char_2.islower()
        char_2_upper = char_2.isupper()
        if char_1_lower and char_2_upper:
            if char_1 == char_2.lower():
                return True
        elif char_1_upper and char_2_lower:
            if char_1.lower() == char_2:
                return True         
        else: 
            return False        

    def makeGood(self, s: str) -> str:
        my_stack = []
        for char in s:
            my_stack.append(char)
            try:
                if self._check(my_stack[-1], my_stack[-2]):
                    my_stack.pop()
                    my_stack.pop()
            except:
                continue
        return ''.join(my_stack)
    
    def makeGood_elegant(self, s: str) -> str:
        result = []
        for c in s:
            if not result:
                result.append(c)
            elif result[-1].isupper() and result[-1].lower() == c:
                result.pop()
            elif result[-1].islower() and result[-1].upper() == c:
                result.pop()
            else:
                result.append(c)
        return ''.join(result)

    def tests(self):
        assert(self.makeGood_elegant("leEeetcode") ==  "leetcode")
        assert(self.makeGood_elegant("aAbBcC") == "")
        assert(self.makeGood_elegant("s") ==  "s")


def main():
    s = input()
    sol = Solution()
    sol.tests()
    print("Passed tests, OK!")
    print(sol.makeGood(s))

if __name__ == "__main__":
    main()
