#include <iostream>
#include <vector>

using namespace std;

      void Print(const vector<int>& v){
         for(const int& output:v) cout << output << " ";
         cout << endl;
      }      
      
      int search_mid(const vector<int>& a, int left, int right, const int& target) {
         while(left<=right){
            int mid = left + (right-left)/2;
            if(a[mid] == target) return mid;
            else if(a[mid] > target) right = mid-1;
            else left  = mid+1;
         }
         return -1;
      }
      
      int search_right(const vector<int>& nums, const int& target){
         int mid = search_mid(nums, 0, nums.size()-1, target);
         //cout << "Mid: " << mid << endl;
         int res_r = mid;
         if(mid<0) return -1;
         else{
            int left = mid;
            int right = nums.size()-1;
            while(true){
               left = search_mid(nums, left+1, right, target);
               //cout << "Left: " << left << endl;
               if(left>=0) res_r=left;
               else break;
            }
         }
         return res_r;
      }

      int search_left(const vector<int>& nums, const int& target){
         int mid = search_mid(nums, 0, nums.size()-1, target);
         //cout << "Mid: " << mid << endl;
         int res_l = mid;
         if(mid<0) return -1;
         else{
            int right = mid;
            int left = 0;
            while(true){
               right = search_mid(nums, left, right-1, target);
               //cout << "Right: " << right << endl;
               if(right>=0) res_l=right;
               else break;
            }
         }
         return res_l;
      }
 
      vector<int> solution(const vector<int>& nums, const int& target){
         vector<int> result(2);
         //cout << "Searching the left one: " << endl;
         int resl = search_left(nums, target);
         //cout << "Searching the right one: " << endl;
         int resr = search_right(nums, target);
         result[0] = resl;
         result[1] = resr;
         return result;
      }

int main(){
   int n = 0;
   int target = 0;
   cin >> n;
   vector<int> nums(n);
   for(int& input:nums) cin >> input;
   cin >> target;
   vector<int> result = solution(nums, target);
   //cout << "Output: " << endl;
   Print(result);
}
