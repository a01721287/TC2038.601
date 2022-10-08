// Solución al Problema de la Mochila

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define MAXOBJ 1000
#define MAXMOCH 1000

struct obj{
    int valor, peso;
    float valpeso; 
};

int bt_Helper(vector<obj> &datos, int i, int va, int pa, int vp, int N, int PESO, int &valOptimo){
    // if (i<N && pa<=PESO && vp>valOptimo){
        
    // }
    
}

int calculaVP (vector<obj> &datos, int i, int vpAux, int pesoAux, int N, int PESO){
    int k = i+1;
    while(k<N && pesoAux + datos[k].valor<=PESO){
        vpAux += datos[k].valor;
        pesoAux += datos[k].peso;
        k++;
    }
    if (k<N){
        vpAux += ((PESO -pesoAux)*datos[k].valpeso);
    }
    return vpAux;
}

//Complejidad: O(2^n) Back Tracking
int mochBT(vector<obj> &datos, int N, int PESO){
    int valOptimo = 0;
    int vpAux = calculaVP(datos, -1, 0, 0, N, PESO);
    bt_Helper(datos, -1, 0, 0, vpAux, N, PESO, valOptimo);
    return valOptimo;
}

//Complejidad O(np)
int mochDP(vector<obj> &datos, int n, int peso){
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


int main(){
    //N = cant de objetos
    //PESO = peso que soporta la mochila
    int v, p, n, peso;
    float vp;
    vector<obj> datos;

    cin>>n>>peso;
    for (int i = 0; i < n; i++){
        cin>>v>>p;
        vp = v*1.0/p;
        obj miDato;
        miDato.valor = v;
        miDato.peso = p;
        miDato.valpeso = vp;
        datos.push_back(miDato);
    }

    cout<<"La mochila con PD es: "<< mochDP(datos, n, peso)<<endl;
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
