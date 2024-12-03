#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, nulls = 0, maximum = 0;
        while (r < nums.size()){
            if (nums[r] == 0){
                if (nulls == 1){
                    maximum = max(maximum, r - l - 1);
                    while(nulls != 0){
                        if (nums[l] == 0){
                            nulls--;
                        }
                        l++;
                    }
                    nulls ++;
                } else {
                    nulls ++;
                }
            }
            r++;
        }
        maximum = max(maximum, r - l - 1);
        return maximum;
    }
};

int main(){
    vector<int> test = {1,1,0,1};
    Solution solution;
    cout << solution.longestSubarray(test) << endl;
    test = {0,1,1,1,0,1,1,0,1};
    cout << solution.longestSubarray(test) << endl;
    test = {1,1,1};
    cout << solution.longestSubarray(test) << endl;
    return 0;
}