// Solución al Problema de SuperSale
//Alejandro Hernández A01721287

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define MAXOBJ 1001
#define MAXMOCH 1001

struct obj{
    int valor, peso;
    float valpeso; 
};

//Complejidad O(np)
int superSale(vector<obj> &datos, int n, int peso){
    int mat[MAXOBJ][MAXMOCH];
    //Inicializar colymna y renglón 0 con 0
    for (int i = 0; i <= n; i++){
        mat[i][0] = 0;
    }
    for (int j = 0; j <= peso; j++){
        mat[0][j] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= peso; j++){
            if(datos[i-1].peso>j){  //El objeto i-1 no cabe con una mochila de peso j
                mat[i][j] = mat[i-1][j];
            }else{                  //El objeto i-1 si cabe
                mat[i][j] = max(mat[i-1][j],    //Si este es mayor no se incluye a obj i-1
                            datos[i-1].valor + mat[i-1][j-datos[i-1].peso]); //Si no, si se incluye

            }
        }
    }
    return mat[n][peso];
}

//Complejidad: O(np)
int main(){
    int casos;
    vector<int> result;
    cin>>casos;
    for (int z = 0; z < casos; z++){
        //N = cant de objetos
        //PESO = peso que soporta la persona
        int n, peso, v, p, pers, total;
        float vp;
        vector<obj> datos;
        vector<int> family;

        cin>>n;
        for (int i = 0; i < n; i++){
            cin>>v>>p;
            vp = v*1.0/p;
            obj miDato;
            miDato.valor = v;
            miDato.peso = p;
            miDato.valpeso = vp;
            datos.push_back(miDato);
        }

        cin>>pers;
        for (int i = 0; i < pers; i++){
            cin>>peso;
            family.push_back(peso);
        }
        total = 0;

        for (int i = 0; i < family.size(); i++){
            total += superSale(datos, n, family[i]);
        }
        result.push_back(total);
    }
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<endl;
    }
    
    return 0;
}





/*
4 16
10 5
40 2
50 10
30 5

3 30
50 5
60 10
140 20

6 89
64 26
85 22
52 4
99 18
39 13
54 9

*/
