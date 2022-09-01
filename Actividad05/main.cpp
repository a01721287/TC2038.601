#include <iostream>
#include <vector>

using namespace std;

string resolver(int n1,int n2,vector<int> T1, vector<int> T2,vector<int> sal){
    bool solve[n1][n2];
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if (i==j==0||(i==n1&&j==n2)){
                continue;
            }
            *solve[i,j] = solve[i,j-1]&&T2[j]==sal[j];
        }
    }

    cout<<endl;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if (*solve[i,j]){
                cout<<"t"<<" ";
            }else{
                cout<<"f"<<" ";
            }
        }
        cout<<endl;
    }
    
    // *solve[n1,n2] = (sal[n1+n2]==T1[n1]&&T2[n1-1,n2])||(sal[n1+n2]==(T2[n2]&&*solve(n1,n2-1)));

/*     for (int i = 0; i < T1.size(); i++){
        cout<<T1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < T2.size(); i++){
        cout<<T2[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < sal.size(); i++)
    {
        cout<<sal[i]<<" ";
    }
    cout<<endl;

     */
    return "possible";
}

int main(){
    int n1,n2,tmp;
    while (true){
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
        
        resolver(n1,n2,T1, T2, sal);
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