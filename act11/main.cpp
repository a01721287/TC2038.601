// Sparko Birthday II & TSP con Branch & Bound
//Alejandro Hernández Carrales A01721287


#include <iostream>
#include <climits>
#include <queue>

#define MAX 21

using namespace std;

struct Nodo{
	int niv; 			// Nivel del Nodo
	int costoAcum;		// Costo Real Acumulado hasta ese nodo
	int costoPos;		// Costo Posible por esa trayectoria
	int verticeAnterior;
	int verticeActual;
	bool visitados[MAX] = {false};
	bool operator<(const Nodo &otro) const{	// Para que la fila priorizada tenga priodad
		return costoPos > otro.costoPos;	// Costo Posible menor.
	}
};

//Complejidad: O(n^2)
void calculaCostoPosible(Nodo &nodoActual, int matAdj[MAX][MAX], int n){
	nodoActual.costoPos = nodoActual.costoAcum;
	int costoObtenido;
	for (int i=1; i<=n; i++){
		costoObtenido = INT_MAX;
		// No he visitado al nodo i o es el Ãºltimo que visite,
		if (!nodoActual.visitados[i] || i == nodoActual.verticeActual){
			if (!nodoActual.visitados[i]){ // Al nodo i no lo he visitado
				for (int j=1; j<=n; j++){
					if (i!=j && (!nodoActual.visitados[j] || j == 1)){
						costoObtenido = min(costoObtenido, matAdj[i][j]); 
					}
				}
			}
			else{	// El nodo i es el Ãºltimo visitado
				for (int j=1; j<=n; j++){
					if (!nodoActual.visitados[j]){
						costoObtenido = min(costoObtenido, matAdj[i][j]);
					}
				}
			}
			if (costoObtenido != INT_MAX){
				nodoActual.costoPos += costoObtenido;
			}
			else{
				nodoActual.costoPos = INT_MAX;
			}
		}
	}
}


/* void printMat(int matAdj[MAX][MAX], int n){
	cout<<endl<<endl;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cout<<matAdj[i][j]<<" ";
        }
        cout<<endl;
    }
	cout<<endl<<endl;
} */

/* void prpq(priority_queue<Nodo> pq){
	cout<<endl;
	priority_queue<Nodo> e = pq;
	cout<<"queue: ";
	while (!e.empty()){
		cout<<e.top().costoPos<<", ";
		e.pop();
	}
	cout<<endl<<endl;
} */

//Complejidad: O(2^n)
int tsp(int matAdj[MAX][MAX], int n){
	int costoOptimo = INT_MAX;
	Nodo raiz;
	raiz.niv = 0;
	raiz.costoAcum = 0;
	raiz.verticeActual = 1;
	raiz.verticeAnterior = 0;
	raiz.visitados[1] = true;
	calculaCostoPosible(raiz, matAdj, n);
	priority_queue<Nodo> pq;
	pq.push(raiz);
    while (!pq.empty()){
    	// printMat(matAdj, n);
		// Sacar de pq;
		// Ver si el CostoPos < Costo Optimo
		// SI si, generar todos los posibles hijos de este nodo
		// Para cada hijo generar un nuevo nodo, actualizar los datos
		// y cuando el nivel == n-2 calcular el costo real, y si este
		// mejora el costo optimo ==> actualizarlo
		// Si el nivel < n-2 .... checar si el costo posible es mejor
		// que el costo optimo y lo metes a la pq.

		Nodo parent = pq.top();
		if (parent.costoPos < costoOptimo){
			for (int i = 1; i <= n; i++){
				if (!parent.visitados[i]){
					Nodo child;
					child.niv = parent.niv + 1;
					child.costoAcum = parent.costoAcum + matAdj[parent.verticeActual][i];
					child.verticeActual = i;
					child.verticeAnterior = parent.verticeActual;
					copy(begin(parent.visitados), end(parent.visitados), begin(child.visitados));
					child.visitados[i] = true;

					if (child.costoAcum<0){
						child.costoAcum = INT_MAX;
					}

					calculaCostoPosible(child, matAdj, n);

					if (child.costoPos<0){
						child.costoPos = INT_MAX;
					}

					if (child.niv == n-2 && child.costoPos<costoOptimo){
						costoOptimo = child.costoPos;
					}else if(child.niv < n-2 && child.costoPos<costoOptimo){
						pq.push(child);
					}
				}
			}
			pq.pop();
		}else{
			pq.pop();
		}
    }
	return costoOptimo;
}

//Complejidad: O(n^2)
void iniciaMat(int matAdj[MAX][MAX]){
	for (int i=0; i<MAX; i++){
		matAdj[i][i] = 0;
		for (int j=i+1; j<MAX; j++){
			matAdj[i][j] = matAdj[j][i] = INT_MAX;
		}
	}
}

//Complejidad: O(n)
void leeArcos(int matAdj[MAX][MAX], int m){
	char a, b; 	// De dÃ³nde a dÃ³nde en la trayectoria
	int c; 		// Costo de la trayectoria
	for (int i=0; i<m; i++){
		cin >> a >> b >> c;
		matAdj[a-'A'+1][b-'A'+1] = matAdj[b-'A'+1][a-'A'+1] = c;
	}
}

int main(){
	// n = Cantidad de nodos
	// m = Cantidad de arcos
	int n, m, result;
	cin >> n >> m;
	int matAdj[MAX][MAX];
	iniciaMat(matAdj);
	leeArcos(matAdj, m);
	result = tsp(matAdj, n);
	if (result == INT_MAX){
		cout<<"INF"<<endl;
	}else{
		cout<<result<<endl;
	}
	
}

/*
4 6
A B 2
A C 3
A D 5
B C 4
C D 1
B D 6

4 5
A B 2
A C 3
A D 5
B C 4
C D 1

4 5
A B 5
A C 10
A D 8
B C 2
C D 1
*/