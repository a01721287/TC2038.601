//Algoritmo de branch & bound
//Requerimientos: Grafo completamente conectado de todos los nodos a todos
//Propósito: Partir de un nodo y recorrer todo el grafo sin regresarte o pasar por un camino previamente cruzado hasta llegar otra vez al nodo origen.

#include <iostream>
#include <climits>
#include <queue>

#define MAX 21

using namespace std;

struct Nodo{
    int niv; //nivel del nodo adentro del arbol de búsqueda soluciones
    int costoAcum;  //Costo acum hasta ese punto
    int costoPos; //
    int verticeAnterior;
    int verticeActual;
    bool visitados[MAX] = {false};
    bool operator<(const Nodo &otro) const{
        return costoPos >= otro.costoPos;
    }

};


void calculaCostoPosible(Nodo &nodoActual, int matAdy[MAX][MAX], int n){
    nodoActual.costoPos = nodoActual.costoAcum;
    int costoObtenido;
    for (int i = 1; i <= n; i++){
        costoObtenido = INT_MAX;
        //no he visitado al nodo i o es el último que visité
        if (!nodoActual.visitados[i]|| i == nodoActual.verticeActual){
            if (!nodoActual.visitados[i]){
                for (int j = 1; j <= n; j++){
                    if (i!=j&&(!nodoActual.visitados[i] || j==1)){
                        costoObtenido = min(costoObtenido, matAdy[i][j]);
                    }
                }
            }else{
                for (int j = 1; j <=n; j++){
                    costoObtenido = min(costoObtenido, matAdy[i][j]);
                }
                
            }
            
        }
        if (costoObtenido ==INT_MAX){
            nodoActual.costoPos = INT_MAX;
        }else{
            nodoActual.costoPos += costoObtenido;
        }
    }

}

void iniciaMat(int matAdy[MAX][MAX]){
    for (int i = 0; i < MAX; i++){
        matAdy[i][i] = 0;
        for (int j = 1; j < MAX; j++){
            matAdy[i][j] = matAdy[j][i] = INT_MAX;
        }
    }
}

void leeArcos(int matAdy[MAX][MAX], int m){
    char a,b;   //Nodos conectados
    int c;      //Costo de conexión
    
    for (int i = 0; i < m; i++){
        cin>>a>>b>>c;
        matAdy[a-'A'+1][b-'A'+1] = matAdy[b-'A'+1][a-'A'+1] = c;
    }
}

//Complejidad: O(2^n)
int tsp(int matAdy[MAX][MAX], int n){
    int costoOptimo = INT_MAX;
    Nodo raiz;
    raiz.niv = 0;
    raiz.costoAcum = 0;
    raiz.verticeActual = 1;
    raiz.verticeAnterior = 0;
    raiz.visitados[1] = true;
    calculaCostoPosible(raiz, matAdy, n);
    priority_queue<Nodo> pq;
    pq.push(raiz);
    /* while (!pq.empty()){
        // Sacar de pq;
        // Ver si el CostoPos < Costo Optimo
        // SI si, generar todos los posibles hijos de este nodo
        // Para cada hijo generar un nuevo nodo, actualizar los datos
        // y cuando el nivel == n-2 calcular el costo real, y si este
        // mejora el costo optimo ==> actualizarlo
        // Si el nivel < n-2 .... checar si el costo posible es mejor
        // que el costo optimo y lo metes a la pq.

        Nodo sacar = pq.top();
        if (sacar.costoPos < costoOptimo){
            cout<<"generar cada hijos de nodo "<< sacar.niv<<endl;
            
            
        }
        pq.pop();


        
    } */
    
    return 0;
}

int main(){
    int n, m, result; //n=cant nodos, m = cant arcos
    cin>>n,m;

    int matAdy[MAX][MAX];
    iniciaMat(matAdy);
    leeArcos(matAdy, m);
    result = tsp(matAdy, n);
    if (result == INT_MAX){
        cout<<"INF"<<endl;
    }else{
        cout<<result<<endl;
    }
    
    return 0;
}

/*
4 5 
A B 5 
A C 10 
A D 8 
B C 2 
C D 1


*/