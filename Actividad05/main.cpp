#include <iostream>
#include <vector>

using namespace std;


vector<int> solve(vector<int> up, vector<int> down,vector<int> desired){
    for (int i = 0; i < up.size(); i++){
        cout<<up[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < down.size(); i++){
        cout<<down[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < desired.size(); i++)
    {
        cout<<desired[i]<<" ";
    }
    cout<<endl;

    
    return{0,0};
}

int main(){
    int n,m,tmp;
    cin>>n>>m;
    vector<int> up, down,desired;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        up.push_back(tmp);
    }
    for (int i = 0; i < m; i++){
        cin>>tmp;
        down.push_back(tmp);
    }

    for (int i = 0; i < n+m; i++){
        cin>>tmp;
        desired.push_back(tmp);
    }
    
    solve(up, down,desired);
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