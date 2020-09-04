#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

int main(){
   int n, k = 0;
   std::cin >> n >> k;
   std::vector<int> nums(n);
   for(int&n: nums) std::cin>>n;
   Solution Sol;
   std::cout << Sol.findKthLargest(nums, k) << std::endl;
}
