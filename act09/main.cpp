#include <iostream>
#include <queue> //priority list
#include <vector> 
#include <climits> //para intMAX 
#include <utility> //para pair

using namespace std;

#define INF INT_MAX
#define Edge pair <int,int> // a dónde llega y su costo
#define Graph vector<vector<Edge>> //Vector de pares
#define Vertex pair<int,int> //Distancia (costo), ID

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

int main(){
    vector<char> result;
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        int nodes, edges, source, u, v, w;
        char tmp1, tmp2;
        cin >> nodes >> edges;
        source = 1;

        Graph G(nodes);
        for (int i=0; i<edges; i++){
            cin >> tmp1 >> tmp2 >> w;
            u = tmp1-64;
            v = tmp2-64;
            // Arco de u->v con un costo w
            Edge edge1(v-1, w);
            G[u-1].push_back(edge1);
            // Arco de v->u con un costo w
            Edge edge2(u-1, w);
            G[v-1].push_back(edge2);
        }

        // print(G);
        vector<int> distances = dijkstra(G, source-1);
        
        // cout << "Distancias: " << endl;
        int highest=0;
        for (int i=0; i<nodes; i++){
            if (i != source-1){
                // cout << source << "-->" << (i+1) << " : ";
                if (distances[i] == INF){
                    // cout << "INF" << endl;
                    highest = i;
                }
                else if(distances[i]>highest){
                    highest = i+1;
                    // cout << distances[i] << endl;
                }else{
                    highest = 2
                }
            }
        }
        result.push_back(highest+64);
    }
    
    for (int i = 0; i < cases; i++){
        cout<<"Case "<< i+1<<": "<<result[i]<<endl;
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
C D 1


*/
