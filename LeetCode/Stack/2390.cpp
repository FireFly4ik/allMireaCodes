#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int i = s.length() - 1;
        int remove = 0;
        for (; i >= 0;) {
            if (s[i] == '*') {
                remove++;
            } else {
                if (remove == 0) {
                    st.push(s[i]);
                } else {
                    remove--;
                }
            }
            i--;
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main(){
    string s = "leet**cod*e";
    Solution solution;
    cout << solution.removeStars(s) << endl;
    return 0;
}