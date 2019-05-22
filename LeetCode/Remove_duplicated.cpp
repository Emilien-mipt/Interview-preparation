#include <iostream>
#include <vector>

class Solution {
public:
    void Print(const std::vector<int>& nums){
       for(const int&n: nums) std::cout << n << " ";
       std::cout << std::endl;
    }

    int bin_search(const std::vector<int>& nums, int left, int right, int target){
        while(left<=right){
           int mid = left + (right-left)/2;
           if(nums[mid] == target) return mid;
           else{
              if(target > nums[mid]) left = mid+1;
              else right = mid-1;
           }
        }
        return -1;
    }

    int removeDuplicates(std::vector<int>& nums) {
       if(nums.size()==0) return 0;
       else if(nums.size()==1) return 1;
       else if(nums.size()==2){
          if(nums[0] == nums[1]) return 1;
          else return 2;
       }
       else{
          for(int i=0; i<nums.size()-1; i++){
             while(bin_search(nums, i+1, nums.size()-1, nums[i]) >= 0){
                int position = bin_search(nums, i+1, nums.size()-1, nums[i]);
                //std::cout << "Position: " << position << std::endl;
                nums.erase(nums.begin() + position);
                //Print(nums);
             }
          }
       return nums.size(); 
       }
    }
};

int main(){
   int n = 0;
   std::cin >> n;
   std::vector<int> nums(n);
   for(int& num:nums) std::cin >> num;
   Solution sol;
   //sol.Print(nums);
   std::cout << sol.removeDuplicates(nums) << std::endl;
   return 0;
}
