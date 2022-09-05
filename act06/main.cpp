/*
    Alejandro Hernández A01721287
    Act06.cpp
    Sep 5, 2022
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Complejidad O(n^2):
int resolver(string s1, string s2){
    int n,m,max;
    n = s1.length();
    m = s2.length();
    max = 0;

    int mat[n][m]={};

    //Checar si las primeras letras coinciden
    if (s1[0]==s2[0]){
        mat[0][0]=1;
        max=1;
    }
    
    //La linea y columna 0:
    for (int i = 1; i < n; i++){
        if (s1[i] == s2[0]){
            mat[i][0]=1;
            max = 1;
        }
    }

    for (int i = 1; i < m; i++){
        if (s2[i]==s1[0]){
            mat[0][i]=1;
            max = 1;
        }
    }
    
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (s1[i]==s2[j]&&mat[i-1][j-1]!=0){
                mat[i][j]= mat[i-1][j-1]+1;
                if (mat[i][j]>max){
                    max = mat[i][j];
                }
            }else if(s1[i]==s2[j]){
                mat[i][j]++;
                if (mat[i][j]>max){
                    max = mat[i][j];
                }
                
            }
        }
    }

/*     for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Max:"<<max<<endl; */
    return max;
    
}

//Complejidad O(n):
int main(){
    int n;
    string s1,s2;
    vector<int> answ;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>s1>>s2;
        answ.push_back(resolver(s1,s2));
    }
    for (int i = 0; i < answ.size(); i++){
        cout<<"Case "<<i+1<<": "<<answ[i]<<endl;
    }
    
}

/* 
1
aaabbaab
abaabbab 

1
AAAAAAABBAAB
ABAABBAB
*/