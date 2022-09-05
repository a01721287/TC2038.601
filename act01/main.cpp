/*
    Actividad 01
    Alejandro Hernández Carrales A01721287
    Complejidad O(n)
*/

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

vector<char> prodName(vector<char> &name,char x, char y){
    for (int i = 0; i < name.size(); i++){
        if (name[i]==x){
            name[i]=y;
        }else if (name[i]==y){
            name[i]=x;
        }
    }
    return name;
}

int main(){
    int n;
    char x,y;
    string tempN, letters;
    vector <char> name;
    
    cin>>n;
    if (n<1 || n>200000){
        cout<<"number of designers is out of range"<<endl;
        exit(1);
    }
    
    cin>>tempN;

    for(int i = 0; i < tempN.length(); i++){
        name.push_back(tempN[i]);
    }

    x = letters[0];
    y = letters[2];

    for (int i = 0; i < n; i++){
        getline(cin >>ws, letters);
        x = letters[0];
        y = letters[2];
        name = prodName(name,x,y);
    }
    
    print(name);

    return 0;
}

