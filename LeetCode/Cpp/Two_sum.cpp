#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
   public: 
      std::vector<int> twoSum_1(std::vector<int>& nums, int target) {
           std::vector<int> res(2);
           fill_map(nums, table);
           for(int j=0; j<nums.size(); j++){
              int search = target - nums[j];
              if(table.count(search) && table[search] != j){
                 res = {j, table[search]};   
                 break;
              }
           }
           return res;
      }

      std::vector<int> twoSum_2(std::vector<int>& nums, int target) {
           std::vector<int> res(2);
           for(int j=0; j<nums.size(); j++){
              int search = target - nums[j];
              if(table.count(search)){
                 return {j, table[search]};
              }
              table[nums[j]] = j;
           }
           //The index of elements can't be negative, so we return negative, 
           // when there are no two numbers such that they add up to a specific target
           return {-1, -1};
      }

   private:
      std::unordered_map<int, int> table;
      
      void fill_map(const std::vector<int>& nums, std::unordered_map<int, int>& table){
         for(int i=0; i<nums.size(); i++) table[nums[i]] = i;
      }
};

int main(){
   int n=0;
   std::cin >> n;
   std::vector<int> arr(n);
   for(int& input:arr) std::cin >> input;
   int t=0;
   std::cin >> t;
   Solution sol;
   std::cout << sol.twoSum_1(arr, t)[0] << "-" << sol.twoSum_1(arr, t)[1] << std::endl;
   std::cout << sol.twoSum_2(arr, t)[0] << "-" << sol.twoSum_2(arr, t)[1] << std::endl;
   return 0;
}
