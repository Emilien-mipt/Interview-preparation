#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
   void print_hash(const std::unordered_map<int, int>& hash){
      for(auto h:hash) std::cout << h.first << "-" << h.second << std::endl;
   }

   int singleNumber(std::vector<int>& nums) {
      int res = 0;
      fill_hash(nums, hash);
      //print_hash(hash);
      for(auto h:hash){
         if(h.second == 1){ 
            res = h.first;
            break;
         }
      }     
      return res;
   }

private:
   std::unordered_map<int, int> hash;
   void fill_hash(const std::vector<int>& nums, std::unordered_map<int, int>& hash){
      for(int n:nums) hash[n]+=1;
   }        
};

int main(){
   int n=0; 
   std::cin >> n;
   std::vector<int> arr(n);
   for(int& input:arr) std::cin >> input; 
   Solution sol;
   std::cout << sol.singleNumber(arr) << std::endl;
}
