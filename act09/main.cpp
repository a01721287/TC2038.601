/* Rocky the beagle
Alejandro Hernandez A01721287 */
#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <climits>
#include <utility>

using namespace std;

#define INF INT_MAX
#define Edge pair<int, int> // A donde llego y su costo
#define Graph vector< vector<Edge> > // Grafo rep. en una lista de adjacencias
#define Vertex pair<int, int> // Distancia (Costo), ID

/* void print(Graph &G){
	for (int i=0; i<G.size(); i++){
		cout << (i+1) << " ==> ";
		for (int j=0; j<G[i].size(); j++){
			cout << "(" << (G[i][j].first+1) << "," 
				 << G[i][j].second << ") ";
		}
		cout << endl;
	}
} */
//Complejidad: O(n log n)
vector<int> dijkstra(Graph &G, int source){
	vector<int> dist(G.size(), INF);
	dist[source] = 0;
	priority_queue<Vertex, vector<Vertex>, greater<Vertex> > queue;
	Vertex vs(0, source);
	queue.push(vs);
	while (!queue.empty()){
		int u = queue.top().second;
		queue.pop();
		for (int i=0; i<G[u].size(); i++){
			Edge e = G[u][i];
			int v = e.first; // Hacia donde llego
			int w = e.second; // Con que costo llego
			if (dist[v] > dist[u]+w){
				dist[v] = dist[u]+w;
				Vertex vtx(dist[v], v);
				queue.push(vtx);
			}
		}
	}
	return dist;
}
//Complejidad: O(n^2)
int main(){
    vector<char> results;
    int cases;
    cin>>cases;
    for (int z = 0; z < cases; z++){
        int nodes, edges, source, u, v, w;
        char tmp1,tmp2;
        source = 1; //Todos salen de A
        cin >> nodes >> edges;
        Graph G(nodes);

        int check = false;
        for (int i=0; i<edges; i++){
            cin >> tmp1 >> tmp2 >> w;
            u = tmp1-64;
            v = tmp2-64;
            if (u == 1 || v ==1){
                check = true;
            }

            // Arco de u->v con un costo w
            Edge edge1(v-1, w);
            G[u-1].push_back(edge1);
            // Arco de v->u con un costo w
            Edge edge2(u-1, w);
            G[v-1].push_back(edge2);
        }
        if (!check){
            results.push_back('B');
            continue;
        }

        //print(G);
        vector<int> distances = dijkstra(G, source-1);
        /* for (int i = 0; i < distances.size(); i++){
            cout<<distances[i]<<", ";
        }
        cout<<endl; */
        int highest = 0;
        int highestCost= 0;
        for (int i = 0; i < distances.size(); i++){
            if (distances[i]>highestCost && distances[i]!=INF){
                highestCost = distances[i];
                highest = i;
            }else if(distances[i]==highestCost&&i<highest){
                highest = i;
            }
        }
        results.push_back(char(highest+65));
        /* 
        for (int i=0; i<nodes; i++){
            if (i != source-1){
                cout << source << "-->" << (i+1) << " : ";
                if (distances[i] == INF){
                    cout << "INF" << endl;
                }
                else{
                    cout << distances[i] << endl;
                }
            }
        } */
    }
    for (int i = 0; i < results.size(); i++){
        cout<<"Case "<< i+1 <<": "<<results[i]<<endl;
    }
    
}

// Cantidad de nodos, cantidad de arcos, nodo origen
// arcos punto origen punto destino y costo.
/*
2
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D  1
*/
