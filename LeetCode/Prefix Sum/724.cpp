#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); i++){
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        prefix.push_back(0);
        prefix.emplace(prefix.begin(), 0);
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < prefix.size(); i++){
            if (i == 0 and prefix[prefix.size() - 2] == 0){
                return 0;
            } else if (i == prefix.size() - 1 and prefix[prefix.size() - 2] == 0){
                return i;
            } else  if (i != 0 and i != prefix.size() - 1){
                if (prefix[i] == prefix[prefix.size() - 2] - prefix[i + 1]){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> test = {1,2,3};
    Solution solution;
    cout << solution.pivotIndex(test) << endl;
    return 0;
}
