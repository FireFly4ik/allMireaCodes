#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> kolvo;
        set<int> chisla;
        for (int i = 0; i < arr.size(); i++){
            if (!chisla.count(arr[i])){
                int kolichestvo = 1;
                for (int j = i + 1; j < arr.size(); j++){
                    if (arr[j] == arr[i]){
                        kolichestvo++;
                    }
                }
                if (kolvo.count(kolichestvo)){
                    return false;
                } else {
                    kolvo.emplace(kolichestvo);
                }
                chisla.emplace(arr[i]);
            }
        }
        return true;
    }
};

int main(){
    vector<int> num = {1,2,2,1,1,3};
    Solution solution;
    cout << solution.uniqueOccurrences(num) << endl;
    return 0;
}
