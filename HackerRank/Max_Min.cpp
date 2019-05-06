#include <iostream>
#include <vector>

using namespace std;

// Complete the maxMin function below.
      inline int max_subarr(const std::vector<int>& arr, const int& begin, const int& end){
         return arr[end];
      }

      inline int min_subarr(const std::vector<int>& arr, const int& begin, const int& end){
         return arr[begin];
      }

      int maxMin(int k, std::vector<int> arr) {
         std::sort(arr.begin(), arr.end());
         int res = max_subarr(arr, 0, k-1) - min_subarr(arr, 0, k-1);
         for(int i=1; (i+k-1)<arr.size(); i++){
            //std::cout << "Max: " << max_subarr_new(arr, i, i+k-1) << std::endl;
            //std::cout << "Min: " << min_subarr_new(arr, i, i+k-1) << std::endl;
            //std::cout << "Res: " << max_subarr_new(arr, i, i+k-1) - min_subarr_new(arr, i, i+k-1) << std::endl;
            if((max_subarr(arr, i, i+k-1) - min_subarr(arr, i, i+k-1)) <= res) {
               res = (max_subarr(arr, i, i+k-1) - min_subarr(arr, i, i+k-1));
            }
         }
         return res;
      }



int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    cout << result << "\n";

    return 0;
}

