#include <unordered_map>
#include <iostream>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    string res = "";
    unordered_map<char, int> hash; 
    for(char s_1:s1) hash[s_1]++;
    for(char s_2:s2){
        if(hash[s_2]>0){
            res = "YES";
            break;
        }
        else res = "NO";
    }
    return res;
}

int main()
{
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }
    return 0;
}


