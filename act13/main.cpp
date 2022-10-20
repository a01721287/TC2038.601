//Cutting Sticks
// Alejandro Hernández A01721287

#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

void  inicMat(int D[MAX][MAX], int P[MAX][MAX], int d[MAX]){
	for (int i=0; i<MAX; i++){
        d[i] = 0;
		for (int j=0; j<MAX; j++){
			D[i][j] = P[i][j] = 0;
		}
	}
}

void lee(int d[MAX], int &n, int l){
	cin >> n;
    d[0] = 0;
    d[n+1] = l;
	for (int i=1; i<=n; i++){
		cin >> d[i];
	}  
}

/* void despM(int D[MAX][MAX], int P[MAX][MAX], int n){
	cout << "Matriz D " << endl;
	for (int i=1; i<=n+1; i++){
		for (int j=1; j<=n+1; j++){
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
	cout << "Matriz P"<< endl;
	for (int i=1; i<=n+1; i++){
		for (int j=1; j<=n+1; j++){
			cout << P[i][j] << "\t";
		}
		cout << endl;
	}
}
 */
//Complejidad: O(n^3)
void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n){
	for (int i=1; i<=n+1; i++){
		D[i][i] = P[i][i] = 0;
	}

	for (int diag=1; diag<n+1; diag++){
		for (int i=1; i<=n-diag+1; i++){
			int j = i+diag;
			int min = INT_MAX;
			int mink;
			for (int k=i; k<j; k++){
				int multesc = D[i][k]+D[k+1][j]+d[j]-d[i-1];
				if (multesc < min){
					min = multesc;
					mink = k;
				}
			}
			D[i][j] = min;
			P[i][j] = mink;
            // despM(D,P,n);
		}
	}
}

/* void recorre(int P[MAX][MAX], int ini, int fin){
	if (P[ini][fin] != 0){
		cout << "(";
		recorre(P, ini, P[ini][fin]);
		cout << ")x(";
		recorre(P, P[ini][fin]+1, fin);
		cout << ")";	
	}
	else{
		char ch = 'A'+ini-1;
		cout << ch;
	}
} */

/* void despliega(int P[MAX][MAX], int n){
	recorre(P, 1, n);
	cout << endl;
} */

int main(){
	int d[MAX]; // Las dimenciones de las matrices
	// D guarda las múltipicaciones minimas escalares desde la matriz i hasta la matriz j
	// P guarda la k que minimiza las MEM Mi...Mj
	int D[MAX][MAX], P[MAX][MAX];
	int n;
    int l = 1;
    while (true){
        cin>>l;
        if (l==0){
            break;
        }
        inicMat(D,P,d);	// Incicializa Matrices y dimensiones
        lee(d,n, l);		// Lee los datos de dimen y la n
        calcula(D, P, d, n);
        cout << "The minimum cutting is " << D[1][n+1]<<"."<< endl;
        //despliega(P, n);
    }
}

/*
100
3
25 50 75
10
4
4 5 7 8
0
*/