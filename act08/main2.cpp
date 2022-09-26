//Algoritmo de Floyd-Warshall
//A01721287
#include <iostream>
#include <climits>
#include<algorithm>
using namespace std;
#define MAX 100

void leeArcos(int mat[MAX][MAX], int p[MAX][MAX], int m){
    int a, b, c; // de Nodo a<->b  con costo c;
    // Incializar Matrices
    for (int i=0; i<MAX; i++){
        mat[i][i] = 0;
        p[i][i] = -1; // -1 significa Conex Directa
        for (int j=i+1; j<MAX; j++){
            mat[i][j] = mat[j][i] = INT_MAX; // INT_MAX = inf
            p[i][j] = p[j][i] = -1;
        }
    }
    for (int i=0; i<m; i++){
        // Recordar que la base es 0 para los arreglos
        // base1 para la entrada del prog
        cin >> a >> b >> c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

// Complejidad: O(n^3)
void floyd(int mat[MAX][MAX], int p[MAX][MAX], int n){
for (int k=0; k<n; k++){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (mat[i][k] != INT_MAX && 
                mat[k][j] != INT_MAX &&
                max(mat[i][k], mat[k][j]) < mat[i][j]){
                    mat[i][j] = max(mat[i][k],mat[k][j]);
                    p[i][j] = k;
                }
            }
        }
    }
}

void checaTrayectoria(int p[MAX][MAX], int x, int y){
    if (p[x][y] != -1){
        checaTrayectoria(p, x, p[x][y]);
        cout << (p[x][y]+1) << "-"; // +1 porque es base1 el usuario
        checaTrayectoria(p, p[x][y], y);
    }
}

void consultas(int mat[MAX][MAX], int p[MAX][MAX], int q){
    int a, b; // De cual a cual quieres consultar
    for (int i=0; i<q; i++){
        cin >> a >> b;
        if (mat[a-1][b-1] == INT_MAX){
            cout << "no path" << endl;
        }
        else{
            cout << mat[a-1][b-1]<<endl;
            // << " Path: " << a << "-";
            // checaTrayectoria(p, a-1, b-1);
            // cout << b << endl;
        }
    }
}

void print(int mat[MAX][MAX], int p[MAX][MAX], int n){
cout << "La matriz de costos: " << endl;
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
if (mat[i][j] == INT_MAX){
cout << "INF\t";
}
else{
cout << mat[i][j] << "\t";
}
}
cout << endl;
}
cout << "La matriz de trayectorias: " << endl;
for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
cout << p[i][j] << "\t";
}
cout << endl;
}
}

int main(){
    // mat = Matriz de costos de del nodo i al nodo j
    // p = Matriz de Trayactoria, dice el nodo intermedio con 
    //     nombre mayor para ir de i a j
    int mat[MAX][MAX], p[MAX][MAX];
    int t, n, m, q;
    // t = Número de casos
    // n = Cantidad de Nodos
    // m = Cantidad de Arcos
    // q = Cantidad de Consultas
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> m >> q;
        cout<<"Case " <<i+1<<":"<<endl;
        leeArcos(mat, p, m);
        // print(mat, p, n);
        floyd(mat, p, n);
        // print(mat, p, n);
        consultas(mat, p, q);
    }
    return 0;
}
/*
2
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7 2
6 6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5 1
7 2 4
*/
/*
1
4 4 1
1 2 90
1 3 80
2 4 30
3 4 60
1 4
*/
