#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> lettersInFirst (word1.begin(), word1.end());
        set<char> lettersInSecond (word2.begin(), word2.end());
        if (lettersInFirst != lettersInSecond){
            return false;
        }
        vector<int> quantityInFirst;
        vector<int> quantityInSecond;
        for (char x : lettersInFirst){
            int k = 0;
            for (int i = 0; i < word1.length(); i++){
                if (word1[i] == x){
                    k++;
                }
            }
            quantityInFirst.push_back(k);
        }
        for (char x : lettersInSecond){
            int k = 0;
            for (int i = 0; i < word2.length(); i++){
                if (word2[i] == x){
                    k++;
                }
            }
            quantityInSecond.push_back(k);
        }
        sort(quantityInFirst.begin(), quantityInFirst.end());
        sort(quantityInSecond.begin(), quantityInSecond.end());
        return quantityInFirst == quantityInSecond ? true : false;
    }
};

int main(){
    string word1 = "abc", word2 = "bca";
    Solution solution;
    cout << solution.closeStrings(word1, word2) << endl;
    return 0;
}
