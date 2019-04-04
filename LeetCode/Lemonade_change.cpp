#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int sum_v(const vector<int>& v){
        int sum = 0;
        for(int q:v) sum += q;
        return sum;
    }
    
    bool lemonadeChange(vector<int>& bills) {
        bool res = true;
        if(bills[0] != 5) res = false;
        else{
            vector<int> five;
            vector<int> ten;
            five.push_back(5);
            for(int i=1; i<bills.size(); i++){
                if(bills[i] == 5) five.push_back(5);
                if(bills[i] == 10){
                    ten.push_back(10);
                    if(five.size()>0) five.pop_back();
                    else res = false;
                }
                if(bills[i] == 20){
                    if(sum_v(ten) >= 10){
                        ten.pop_back();
                        if(five.size() > 0) five.pop_back();
                        else res = false;
                    }
                    else{
                        if(sum_v(five) >= 15) {
                            five.pop_back();
                            five.pop_back();
                            five.pop_back();
                        }
                        else res = false;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
   int n = 0;
   cin >> n;
   vector<int> bills(n);
   for(int& cash:bills) cin >> cash;
   Solution sol;
   cout << sol.lemonadeChange(bills);
}
