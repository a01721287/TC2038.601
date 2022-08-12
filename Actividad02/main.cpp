#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>

using namespace std;

void print(vector<char> name){
    for(int i = 0; i < name.size(); i++){
        cout<<name[i];
    }
    cout<<endl;
}

void decypher(vector<char> map, string operation){
    string solution;
    for (int j = 0; j < map.size(); j++){
        for (int i = 0; i < operation.length(); i++){
            if (operation[i]==map[j]){
                operation[i]=j+1;
            }
        }
    }
}

int main(){
    int n;
    string tmp;
    vector<char> map;

    cin>>n;
    getline(cin >>ws, tmp);

    for (int i = 0; i < tmp.length(); i=i+2){
        map.push_back(tmp[i]);
    }

    for (int i = 0; i < n; i++){
        getline(cin >>ws, tmp);
        decypher(map,tmp);
    }
    
    return 0;
}