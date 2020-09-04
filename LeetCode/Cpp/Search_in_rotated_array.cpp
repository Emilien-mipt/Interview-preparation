#include <vector>
#include <iostream>


class Solution {
public:
   int search(std::vector<int>& a, int left, int right, int x){
        int mid = left + (right-left)/2;
        //Base cases
        if(a[mid] == x) return mid;
        if(right < left) return -1;
        
        //Ищем, какая часть отсортирована
        if(a[mid] > a[left]){ //Значит отсортирована левая часть
            if(x >= a[left] && x <= a[mid]) return search(a, left, mid-1, x); //Ищем в левой части
            else return search(a, mid+1, right,  x);
        }
        else if(a[mid] < a[left]){ //Значит, правая часть отсортирована
            if(x >= a[mid] && x <= a[right]) return search(a, mid+1, right, x); //Ищем в правой части
            else return search(a, left, mid-1,  x);
        }
        else if(a[left] == a[mid]){
            if(a[mid] != a[right]) return search(a, mid+1, right, x);
        }
        return -1;
   }
};


int main(){
int t = 0; //target
std::cin >> t;

int n = 0; //Size of an array
std::cin >> n;
std::vector<int> arr(n);
for(int i=0; i<n; i++){
   int input = 0;
   std::cin >> input;
   arr[i] = input;
}

Solution sol;
int result = sol.search(arr, t);
std::cout << result << std::endl;
return 0;
}
