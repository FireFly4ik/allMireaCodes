#include <iostream> 
#include <vector>
using namespace std;

void show_vector(vector<int>&a)
{
    for (vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    vector<int> massiv;
    int x, k;
    while (x != -1){
        cout << "Введите положительный инт для вноса в массив или -1 для начала сортировки" << endl;
        cin >> x;
        if (x == -1){
            break;
        }
        massiv.push_back(x);
    }
    while (true){
        if (k == massiv.size() - 1){
            break;
        }
        k = 0;
        for (int i = 0; i < massiv.size() - 1; i++){
            if (massiv[i] > massiv[i + 1]){
                swap(massiv[i], massiv[i + 1]);
            } else {
                k++;
            }
        }
    } 
    show_vector(massiv);
    return 0;
}