#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void show_vector(vector<int>a)
{
    while (a[0] == 0 and a.size() > 0) {
        a.erase(a.begin());
    }
    if (a.empty()){
        cout << "0" << endl;
        return;
    }
    for (vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it){
        if(it == a.begin() && *it == 0 && a.size() != 1){
            continue;
        }
        cout<<*it;
    }
    cout << endl;
}

vector<int> vuchitanie(vector<int> v1, vector<int> v2){
    vector<int> v3(v1.size());
    int minusRazr = v1.size() - v2.size();
    for (int i = v1.size() - 1; i != -1 ; i--){
        int minus;
        if (i >= minusRazr){
            minus = v1[i] - v2[i - minusRazr];
        } else {minus = v1[i];}
        v3[i] += minus;
        if (v3[i] < 0){
            v3[i] += 10;
            v3[i - 1] -= 1;
        }
    }
    return v3;
}

vector<int> slice(vector<int> &v, int nach, int kon){
    vector<int> slicedVector;
    for (int i = nach; i < kon; i++){
        slicedVector.push_back(v[i]);
    }
    return slicedVector;
}

bool check(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        if (v[i] != 0){
            return true;
        }
    }
    return false;
}

vector<int> sum(vector<int> v1, vector<int> v2){
    vector<int> nul {0};
    if (v1 == nul and v2 == nul){
        return nul;
    }
    if (v1.size() < v2.size()) {
        swap(v1, v2);
    }
    v1.emplace(v1.begin(), 0);
    int raznica = v1.size() - v2.size();
    while (check(v2) == true){
        for (int i = v1.size() - 1; i > -1; i--){
            if (i - raznica < 0){
                break;
            }
            if (v1[i] + v2[i - raznica] >= 10){
                v1[i - 1] += 1;
                v1[i] -= 10;
            }
            v1[i] = v1[i] + v2[i - raznica];
            v2[i - raznica] = 0;
        }
    }
    if (v1[0] == 0){
        v1.erase(v1.begin());
    }
    return v1;
}

void viravnivanie (vector<int> &num1, vector<int> &num2){
    if (num1.size() % 2 == 1) {
        num1.emplace(num1.begin(), 0);
    }
    if (num2.size() % 2 == 1) {
        num2.emplace(num2.begin(), 0);
    }
    while (num1.size() < num2.size()){
        num1.emplace(num1.begin(), 0);
    }
    while (num1.size() > num2.size()){
        num2.emplace(num2.begin(), 0);
    }
}

vector<int> umn(vector<int> v1, vector<int> v2){
    vector<int> itog (2);
    itog[1] = v1[0] * v2[0] % 10;
    itog[0] = v1[0] * v2[0] / 10;
    if (itog[0] == 0){
        itog.erase(itog.begin());
    }
    return itog;
}

vector<int> karacuba(vector<int> &num1, vector<int> &num2){
    if (num1.size() == 1 and num2.size() == 1){
        return umn(num1, num2);
    }
    viravnivanie(num1, num2);
    int polovina = num1.size() / 2;
    vector<int> a (polovina), b (polovina), c (polovina), d (polovina);
    a = slice(num1, 0, polovina);
    b = slice(num1, polovina, num1.size());
    c = slice(num2, 0, polovina);
    d = slice(num2, polovina, num2.size());
    vector<int> ac, bd, skobka, ab, cd;
    ac = karacuba(a, c);
    bd = karacuba(b, d);
    ab = sum(a, b);
    cd = sum(c,d);
    skobka = karacuba(ab, cd);
    skobka = vuchitanie(skobka, ac);
    skobka = vuchitanie(skobka, bd);
    for (int i = 0; i < polovina; i++){
        ac.push_back(0);
        ac.push_back(0);
        skobka.push_back(0);
    }
    vector<int> res = sum(ac, skobka);
    res = sum (res, bd);
    return res;
}

void sozdanieVectoraChisla(vector<int> &vec, string chislo){
    while (chislo.length() > 0){
        char q = chislo[0];
        string i = "";
        i = q;
        vec.emplace(vec.end(), stoi(i));
        chislo.erase(0, 1);
    }
}

int main(){
    clock_t start, end;
    string n1, n2;
    vector<int> num1, num2, kar;
    cin >> n1 >> n2;
    start = clock();
    sozdanieVectoraChisla(num1, n1);
    sozdanieVectoraChisla(num2, n2);
    viravnivanie(num1, num2);
    kar = karacuba(num1, num2);
    end = clock();
    cout << endl;
    show_vector(kar);
    cout << endl;
    cout << end - start << endl;
}