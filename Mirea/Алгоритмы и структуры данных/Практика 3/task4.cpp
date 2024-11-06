#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

int minusa = 0;

void show_vector(vector<int>&a)
{
    if (minusa % 2){
        cout << "-";
    }
    for (vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it){
        cout<<*it;
    }
    cout << endl;
    cout << endl;
}

void sozdanie(string chislo, vector<int> &v){
    while (chislo.length() > 0){
        char bukvaChar = chislo[0];
        string bukvaString = "";
        bukvaString = bukvaChar;
        v.push_back(stoi(bukvaString));
        chislo.erase(0,1);
    }
}

bool check(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        if (v[i] != 0){
            return true;
        }
    }
    return false;
}

void sum(vector<int> &v1, vector<int> &v2){
    while (check(v2) == true){
        for (int i = v1.size() - 1; i > -1; i--){
            if (v2[i] >= 10){
                v2[i - 1] += 1;
                v2[i] -= 10;
            }
            if (0 < v2[i] && v2[i] < 10){
                if (v1[i] + v2[i] >= 10){
                    v2[i - 1] += 1;
                    v1[i] -= 10;
                }
                v1[i] = v1[i] + v2[i];
                v2[i] = 0;
            }
        }
    }
}

void umn(vector<int> &v, int chislo, vector<int> &itog){
    itog.insert(itog.begin(), v.size() + 1, 0);
    for (int i = v.size() - 1; i > -1; i--){
        int plus = v[i] * chislo;
        itog[i + 1] += plus;
        if (itog[i + 1] >= 10){
            itog[i] += itog[i + 1] / 10;
            itog[i + 1] %= 10;
        }
    }
    if (itog[0] == 0){
        itog.erase(itog.begin());
    }
}

int main(){
    string num1, num2;
    cin >> num1 >> num2;
    clock_t start,end;
    start = clock();
    if (num1[0] == '-'){
        minusa += 1;
        num1.erase(0, 1);
    }
    if (num2[0] == '-'){
        minusa += 1;
        num2.erase(0, 1);
    }
    vector<int> n1;
    vector<int> n2;
    sozdanie(num1, n1);
    sozdanie(num2, n2);
    vector<vector<int>> stolbik(n2.size());
    int razr = 0;
    for (int i = n2.size() - 1; i > -1; i--){
        umn(n1, n2[i], stolbik[stolbik.size() - i - 1]);
        stolbik[stolbik.size() - i - 1].insert(stolbik[stolbik.size() - i - 1].begin(), n1.size() + n2.size() - razr - stolbik[stolbik.size() - i - 1].size(), 0);
        stolbik[stolbik.size() - i - 1].insert(stolbik[stolbik.size() - i - 1].end(), razr, 0);
        razr++;
    }
    cout << endl;
    for (int i = 0; i < stolbik.size(); i++){
        show_vector(stolbik[i]);
    }
    for (int i = 0; i < stolbik.size() - 1; i++){
        sum(stolbik[i + 1], stolbik[i]);
    }
    cout << endl;
    if (stolbik[stolbik.size() - 1][0] == 0){
        stolbik[stolbik.size() - 1].erase(stolbik[stolbik.size() - 1].begin());
    }
    end = clock();
    show_vector(stolbik[stolbik.size() - 1]);
    cout << endl;
    cout << end - start << endl;
    return 0;
}