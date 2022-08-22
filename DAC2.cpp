//Patricio Santos Garza A01197723
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Complejidad de funcion: O👎
vector<int> compare(vector<int> prices, vector<int> first, vector<int> second, int a, int b){
    
    //Se comparan los profits del first, second, y del mixto, es decir, el numero mas
    //pequeño del first y el mas grande del second. Se regresa el del mayor profit.
    int m = (a+b)/2;
    vector<int> mix = {0, (b-a == 1) ? 0 : m+1};

    for (int i = a; i <= m; i++){ //O👎
        if (prices[i] < prices[mix[0]]){
            mix[0] = i;
        }
    }

    for (int i = m; i < b; i++){ //O👎
        if (prices[i] > prices[mix[1]]){
            mix[1] = i;
        }
    }

    if (prices[first[1]] - prices[first[0]] >= prices[mix[1]] - prices[mix[0]]){
        if (prices[first[1]] - prices[first[0]] >= prices[second[1]] - prices[second[0]]){
            return first;
        } else {
            return second;
        }
    } else {
        if (prices[mix[1]] - prices[mix[0]] >= prices[second[1]] - prices[second[0]]){
            return mix;
        } else {
            return second;
        }
    }
}

vector<int> searchPrices(vector<int> prices, int a, int b){ //O(logn)
    //Si el sub-arreglo mide 1, cregresar su indice con su profit siendo 0
    if (a >= b){
        vector<int> out = {a,b};
        return out;
    }

    //Si el sub-arreglo no es 0, partir a la mitad
    int m = (a+b)/2;

    vector<int> first = searchPrices(prices, a, m); //O(logn)
    vector<int> second = searchPrices(prices, m+1, b); //O(logn)

    //Comparar los profits del primer sub-arreglo y segundo sub-arreglo y el mixto
    //Regresar combinacion de dias con el mejor profit
    return compare(prices, first, second, a, b); //O👎
}

string invest(){
    int d;
    cin >> d;
    vector<int> prices(d);

    //Recibir los dias
    for (int i = 0; i < d; i++){ //O👎
        cin >> prices[i];
    }

    //Conseguir los dias de comprar y vender
    vector<int> out = searchPrices(prices, 0, prices.size());
    
    //Regresar string
    return "Buy in " + to_string(out[0]+1) + ", sell in " + to_string(out[1]+1) + "\n";
}

int main() {
    int n;
    string ans = "";
    cin >> n;
	
	for (int i = 0; i < n; i++){
        ans += invest();
    }
    
	cout << ans;

    return 0;
}