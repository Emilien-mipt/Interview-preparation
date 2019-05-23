#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>

class Solution{
   public:
      std::vector<int> findErrorNums(std::vector<int>& nums) {
         int dupl = 0, mis = 0;
         for(int& n:nums) hash[n]++;
         for(int n=1; n<=nums.size(); n++){
            if(hash.count(n)){
               if(hash[n] == 2){
                  dupl = n;
               }
            }
            else{
               mis = n;
            } 
         }
         return {dupl, mis};  
      }
   private:
      std::unordered_map<int, int> hash;
};

int main(){
   int n=0;
   std::cin >> n;
   std::vector<int> arr(n);
   for(int& input:arr) std::cin >> input;
   Solution sol;
   std::vector<int> res(2);
   res = sol.findErrorNums(arr);
   for(int& n:res) std::cout << n << " ";
   std::cout << std::endl; 
   return 0;
}
