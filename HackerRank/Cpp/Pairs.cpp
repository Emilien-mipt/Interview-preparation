#include <iostream>
#include <vector>

using namespace std;

void Print_v(const vector<int>& v){
   for(int n:v) cout << n << " ";
   cout << endl;
}

int binary_search(const vector<int>& arr, const int& x){
    int left = 0;
    int right = arr.size();
    while(left<=right){
        int mid = left + (right-left)/2;
        //cout << "mid: " << mid << endl;
        if(arr[mid] == x) return mid;
        else
            if(arr[mid] > x) right = mid-1;
            else left = mid+1;
    }
    return -1;
}

int count_bin(vector<int> arr, const int& x, int& count){
   while(true){
      int pos = binary_search(arr, x);
      if(pos>=0){
         count++;
         //cout << "Found " << arr[pos] << endl;
         arr.erase(arr.begin()+pos);
         //cout << "Deleted it!" << endl;
         //Print_v(arr);
      }
      else{
         //cout << "Didn't find it! Go on" << endl;
         break; 
      }
   }
   return count;
}

// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
    vector<int> search_arr;
    int count = 0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        search_arr.push_back(arr[i]);
        //cout << "Step " << i << ": "<< arr[i] << endl;
        if(arr[i] <= k) {
	   //cout << "Less than k, go on!" << endl;
	   continue;
	}
        else{
            int diff = arr[i] - k;
            //cout << "Diff: " << diff << endl;
 	    count = count_bin(search_arr, diff, count);
        } 
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& a:arr) cin >> a;
    
    cout << pairs(k, arr); 
    //Print_v(arr);
    return 0;
}

