from collections import Counter
from typing import List

class Solution:
    def __init__(self, word_list, char_list):
        self.words = word_list
        self.chars = char_list
    
    def _check_common(self, word: str) -> bool:
        chars_dict = Counter(self.chars)
        word_dict = Counter(word)
        for key, value in word_dict.items():
            if key not in chars_dict:
                return False
            elif chars_dict[key] < word_dict[key]:
                return False
        return True      


    def countCharacters(self) -> int:
        result_length = 0
        for word in self.words:
            if self._check_common(word):
                #print("YES")
                result_length += len(word)
                #print(len(word))
        return result_length
            

def main():
    words = [s for s in input().split()]
    chars = input()
    sol = Solution(words, chars)
    result = sol.countCharacters()
    print(result)
    
if __name__ == "__main__":
    main()
