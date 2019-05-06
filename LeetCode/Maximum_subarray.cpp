#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
       int current_max = nums[0];
       int global_max = nums[0];
       for(int i=1; i<nums.size(); i++){
          current_max = std::max(nums[i], current_max + nums[i]);
          if(current_max > global_max) global_max = current_max;
       }
       return global_max; 
    } 
};

int main(){
   int n = 0;
   std::cin >> n;
   std::vector<int> nums(n);
   for(int& input: nums) std::cin >> input;
   Solution sol;
   std::cout << sol.maxSubArray(nums) << std::endl;
}
