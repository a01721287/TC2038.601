//Freckles A01721287 Alejandro Hernández

// Minumum Spanning Tree (Kruskal)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
#include <math.h>

using namespace std;

typedef pair<double,double> iPair;

struct Graph {
	// V = Cantidad de nodos (Vertex)
	// E = Cantidaf de arcos (Edges)
	int V, E;
    double costMSTKruskal;
	vector<pair<double, pair<int,int>>> edges; 	// Utilizar en Krukal
	vector<pair<int,int>> selectedEdgesK;		// Los arcos sel Kruskal
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		costMSTKruskal = 0;
	}
	// u = salida del arco
	// v = llegada del arco
	// w = costo del arco
	void addEdge(int u, int v, double w){
		edges.push_back({w, {u, v}}); //First = costo, second conexión
	}

	void load();
	void print();
	void kruskalMST();
	void printEdgesK();
};

// Disjont Sets (Union-Find)
struct DisjointSets{
	int *parent, *rnk;
	int n;
	DisjointSets(int n){
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];
		for (int i=0; i<=n; i++){
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	// Para encontrar el parent de 'u'
	int find(int u){
		if (u != parent[u]){
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}

	// Union por rank
	void merge(int x, int y){
		x = find(x);
		y = find(y);
		if (rnk[x] > rnk[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if (rnk[x] == rnk[y]){
			rnk[y]++;
		}
	}
};

//Complejidad: O(1)
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1), 2.0) + pow((y2-y1), 2.0));
}

//Complejidad: O(n^2)
void Graph::load(){
    double x,y;
    vector<pair<double,double>> coord;
    for (int i = 0; i < V; i++){
        cin>>x>>y;
        coord.push_back(make_pair(x,y));
    }

    for (int i=0; i<V; i++){
        for (int j = i+1; j < V; j++){
            addEdge(i, j, distance(coord[i].first,coord[i].second,coord[j].first,coord[j].second));
            addEdge(j, i, distance(coord[i].first,coord[i].second,coord[j].first,coord[j].second));
        }
    }
}

// Complejidad: P(E logE)
void Graph::kruskalMST(){
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	costMSTKruskal = 0;
	for (auto it:edges){
		int p1 = ds.find(it.second.first);
		int p2 = ds.find(it.second.second);

		if (p1 != p2){
			costMSTKruskal += it.first;
			selectedEdgesK.push_back({it.second.first,it.second.second});
			ds.merge(it.second.first,it.second.second);
		}
	}
}

void Graph::printEdgesK(){
	cout << "Selected Edges Kruskal: ";
	for (auto it:selectedEdgesK){
		cout << "(" << it.first << "," << it.second << ") ";
	}
	cout << endl;
}

int main(){ 
	int V, E;
	cin >> V;
    E = V*(V-1)/2;
	Graph g(V, E);
	g.load();
	g.kruskalMST();

    printf("%.2f", g.costMSTKruskal);
    cout<<endl;
	return 0;
}

/*
Unidrected Graph
3
1.0 1.0
2.0 2.0
2.0 4.0
*/