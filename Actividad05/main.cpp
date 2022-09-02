#include <iostream>
#include <vector>

using namespace std;

string resolver(int n1,int n2,vector<int> T1, vector<int> T2,vector<int> sal){
/*     cout<<endl<<"-----------------------"<<endl;

    cout<<"T1:"<<endl;
    for (int i = 0; i < T1.size(); i++)
    {
        cout<<T1[i]<<" ";
    }
    cout<<endl;

    cout<<"T2:"<<endl;
    for (int i = 0; i < T2.size(); i++)
    {
        cout<<T2[i]<<" ";
    }
    cout<<endl;

    cout<<"Sal:"<<endl;
    for (int i = 0; i < sal.size(); i++)
    {
        cout<<sal[i]<<" ";
    }
    cout<<endl<<endl; */
    
    bool solve[n1+1][n2+1]={false};
    
    //Primero los 0 de renglon y columna
    solve[0][0] = {true};
    for (int i = 0; i < n1+1; i++){
        solve[0][i+1] = solve[0][i]&&(T2[i]==sal[i]);
    }
    for (int i = 0; i < n2+1; i++){
        solve[i+1][0] = solve[i][0]&&(T1[i]==sal[i]);
    }

    //ahora el relleno
    for (int i = 1; i < n1+1; i++){
        for (int j = 1; j < n2+1; j++){
            solve[i][j] = (sal[(i+j)-1]==T1[i-1])&&solve[i-1][j] || (sal[(i+j)-1]==T2[j-1])&&solve[i][j-1];
        }
    }

/*     cout<<endl;
    for (int i = 0; i < n1+1; i++){
        for (int j = 0; j < n2+1; j++){
            if (solve[i][j]){
                cout<<"T"<<" ";
            }else{
                cout<<"F"<<" ";
            }
        }
        cout<<endl;
    } */

    // cout<<"solve["<<n1<<"]["<<n2<<"]"<<endl;
    if (solve[n1][n2]){
        return "possible";
    }
    return "not possible";
}

int main(){
    while (true){
        int n1,n2,tmp;
        cin>>n1>>n2;
        if (n1==0&&n2==0){
            exit(1);
        }
        vector<int> T1, T2,sal;
        for (int i = 0; i < n1; i++){
            cin>>tmp;
            T1.push_back(tmp);
        }
        for (int i = 0; i < n2; i++){
            cin>>tmp;
            T2.push_back(tmp);
        }
        for (int i = 0; i < n1+n2; i++){
            cin>>tmp;
            sal.push_back(tmp);
        }
        cout<<resolver(n1,n2,T1, T2, sal)<<endl;
    }
}

/*
3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0



*/