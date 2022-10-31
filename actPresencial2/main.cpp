//
// Matricula:
// Nombre:
//


#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue> //priority list

#define INF INT_MAX
#define Edge pair <int,int> // a dónde llega y su costo
#define Graph vector<vector<Edge>> //Vector de pares
#define Vertex pair<int,int> //Distancia (costo), ID

#define MAX 10

using namespace std;

struct edge{
	int from, to, time;
	edge(int a, int b, int t){
		from = a;
		to = b;
		time = t;
	}
};

struct comm{
	char query;
	int from, to;
	comm(char q, int a, int b){
		query = q;
		from = a; 
		to = b;
	}
};

//Complejidad O(n log n)
vector<int> dijkstra(Graph &G, int src){
    vector<int> dist(G.size(), INF);
    dist[src] = 0;
    
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>>queue;
    Vertex vs(0,src);
    queue.push(vs);
    while(!queue.empty()){
        int u = queue.top().second;
        queue.pop();

        for (int i = 0; i < G[u].size(); i++){
            Edge e = G[u][i];
            int v = e.first;  //Hacia dónde  llego
            int w = e.second; //con qué costo llego
            if (dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                Vertex vtx(dist[v], v);
                queue.push(vtx);
            }
            
        }
        
    }
    
    return dist;
}

void print(Graph &G){
    for (int i = 0; i < G.size(); i++){
        cout<< i+1 <<"-->";
        for (int j = 0; j < G[i].size(); j++){
            cout<<"("<<G[i][j].first<<","<<G[i][j].second<<")";
        }
        cout<<endl;
    }
}

Graph acomodar(vector<edge> edges, int n){
	Graph G2(n);
    for (int i=0; i<edges.size(); i++){
			int u = edges[i].from;
			int v = edges[i].to;
			int w = edges[i].time;

            // Arco de u->v con un costo w
            Edge edge1(v-1, w);
            G2[u-1].push_back(edge1);
            // Arco de v->u con un costo w
            Edge edge2(u-1, w);
            G2[v-1].push_back(edge2);
    }
	cout<<"se agregó todo"<<endl;
	print(G2);
	return G2;
}

// Complejidad: 
void ejecuta_comandos(int n, vector<edge> &edges, vector<comm> &commands, vector<int> &salida){
	Graph G(n);
	vector<int> distances;
	for (int i = 0; i < commands.size(); i++){
		switch (commands[i].query){
		case 'c':
			G = acomodar(edges, n);
			distances = dijkstra(G, commands[i].from);

			for (int j=0; j<n; j++){
				if (j != commands[i].from-1){
					cout << commands[i].from << "-->" << (j+1) << " : ";
					if (distances[j] == INF){
						cout << "INF" << endl;
					}
					else{
						cout << distances[j] << endl;
					}
				}
    		}


			cout<<distances[commands[i].to]<<endl;
			// cout<<dijkstra()
		break;

		case 'a':
			cout<<"antialcohólica de "<< commands[i].from<<" a "<<commands[i].to<<endl;
		break;

		case 'l':
			cout<<"Liberó de "<< commands[i].from<<" a "<<commands[i].to<<endl;
		break;

		default:
			cout<<"otro caso"<<endl;
			break;
		}
	}
	
}

int main(){
	int n, m, k,a, b, t;
	char q;
	vector<edge> edges;
	vector<comm> commands;
	cin >> n >> m;
	for (int i=1; i<=m; i++){
		cin >> a >> b >> t;
		edge nuevo(a, b, t);
		edges.push_back(nuevo);
	}
	cin >> k;
	for (int i=1; i<=k; i++){
		cin >> q >> a >> b;
		comm nuevo(q, a, b);
		commands.push_back(nuevo);
	}
	vector<int> salida;
	ejecuta_comandos(n, edges, commands, salida);
	for (int i=0;i<salida.size(); i++){
		cout << salida[i]<< endl;
	}
}

/*

Ejemplo de Entrada:

5 8
1 2 4
1 3 2
1 4 4
2 3 1
2 5 3
3 4 7
3 5 1
4 5 4
7
c 1 5
c 4 2
a 3 5
c 5 3
c 3 5
l 5 3
c 5 3
 

Ejemplo de Salida:

3
6
4
4
1

*/
