#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int D = 0;
        int N = A[0].size();
        for(int i=0; i<N; i++){
            for(int j=0; j<A.size()-1; j++){
                if(A[j][i] > A[j+1][i]){
                    D++;
                    break;
                }
            }
        }
        return D;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> v;
    string s;
    int N = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s;
        v.push_back(s);
    }
    Solution sol;
    cout << sol.minDeletionSize(v) << endl;
    return 0;
}