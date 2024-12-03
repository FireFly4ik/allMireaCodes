#include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, nulls = 0, maximum = 0;
        while(r < nums.size()){
            if (nums[r] == 0){
                nulls++;
                if (nulls == k + 1 and k != 0){
                    while (nums[r] == 1){
                        r++;
                    }
                    maximum = max(maximum, r - l);
                    while (nulls != k - 1){
                        if (nums[l] == 0){
                            nulls--;
                        }
                        l++;
                    }
                } else if (nulls == k + 1 and k == 0){
                    maximum = max(maximum, r - l);
                    l = r = r + 1;
                    nulls--;
                    continue;
                }
                if (nulls == k and nums[r + 1] == 0){
                    maximum = max(maximum, r - l + 1);
                    while (nulls != k - 1){
                        if (nums[l] == 0){
                            nulls--;
                        }
                        l++;
                    }
                } else if (nulls == k and nums[r + 1] == 1){
                    while (r < nums.size() - 1 and nums[r + 1] == 1){
                        r++;
                    }
                    maximum = max(maximum, r - l + 1);
                    while (nulls != k - 1){
                        if (nums[l] == 0){
                            nulls--;
                        }
                        l++;
                    }
                }
            
            }
            r++;
        }
        maximum = max(maximum, r - l); 
        return maximum;
    }
};

int main(){
    vector<int> test = {0};
    Solution solution;
    cout << solution.longestOnes(test, 1) << endl;
    // test = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    // cout << solution.longestOnes(test, 3) << endl;
    return 0;
}