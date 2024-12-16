#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix = {nums[0]};
        for (int i = 1; i < nums.size(); i++){
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        prefix.emplace(prefix.begin(), 0);
        int leftSum = 0, rightSum = 0;
        for (int i = 1; i < prefix.size(); i++){
            if (i != prefix.size() - 1 and prefix[i - 1] == prefix[prefix.size() - 1] - prefix[i]){
                return i - 1;
            } else if (i == prefix.size() - 1 and prefix[i - 1] == 0){
                return i - 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> test = {1,7,3,6,5,6};
    Solution solution;
    cout << solution.pivotIndex(test) << endl;
    return 0;
}
