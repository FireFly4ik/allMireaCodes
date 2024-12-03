#include <iostream>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int latitude = 0, maximum = 0;
        for (int plus : gain){
            latitude += plus;
            maximum = max(maximum, latitude);
        }
        return maximum;
    }
};

int main(){
    vector<int> test = {-5,1,5,0,-7};
    Solution solution;
    solution.largestAltitude(test);
    return 0;
}