#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

    class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
            int answer = 0;
            vector<vector<int>> vertical;
            for (int j = 0; j < grid[0].size(); j++){
                vector<int> temp;
                for (int i = 0; i < grid.size(); i++){
                    temp.push_back(grid[i][j]);
                }
                vertical.push_back(temp);
                temp.clear();
            }
            set<vector<int>> verticalSet (vertical.begin(), vertical.end());
            for (vector<int> line : verticalSet){
                answer += count(grid.begin(), grid.end(), line) * count(vertical.begin(), vertical.end(), line);
            }
            return answer;
        }
    };

int main(){
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    Solution solution;
    cout << solution.equalPairs(grid) << endl;
    return 0;
}
