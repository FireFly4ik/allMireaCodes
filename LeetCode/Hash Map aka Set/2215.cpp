#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        vector<int> res1;
        set<int>n1(nums1.begin(), nums1.end());
        set<int>n2(nums2.begin(), nums2.end());
        for (int x : n1){
            if (n2.count(x)){
                n2.erase(x);
            } else {
                res1.push_back(x);
            }
        }
        answer.push_back(res1);
        vector<int>res2(n2.begin(), n2.end());
        answer.push_back(res2);
        return answer;
    }
};

int main(){
    vector<int> num11 = {1,2,3};
    vector<int> num12 = {2,4,6};
    Solution solution;
    solution.findDifference(num11, num12);
    return 0;
}
