#include <iostream>
#include <vector>
#include <algorithm>

//De una lista, encontrar qué combinacion de números al ser sumados da un valor específico

using namespace std;
//n es a cantidad de la lista de números
//valor es el valor que se busca encontrar en la suma de diferentes objetos
int n, valor;
//El orden de cuáles objetos se incluyen
vector<bool> include;
//los valores de los objetos
vector<int> obj;

//Complejidad: O(2^n)
void sum_of_subset(int i, int acum, int total){
    if (acum+total >= valor && 
        (acum==valor||acum+obj[i+1]<= valor)){
        if (acum==valor){
            for (int j = 0; j < n; j++){
                if (include[j]){
                    cout<<obj[j]<<" ";
                }
            }
            cout<<endl;
            
        }else{
            //Si incluir al sig obj
            include[i+1]=true;
            sum_of_subset(i+1,acum+obj[i+1],total-obj[i+1]);
            //NO incluir al sig obj
            include[i+1]=false;
            sum_of_subset(i+1,acum,total-obj[i+1]);
        }
        
    }
    
}

int main(){
    cin>>n>>valor;
    int dato, total = 0;
    for (int i = 0; i < n; i++){
        cin>>dato;
        obj.push_back(dato);
        total += dato;
        include.push_back(false);
    }
    sort(obj.begin(),obj.end());
    sum_of_subset(-1,0,total);
}

/* 
INPUT:
5 21
10
6
5
16
11 
*/