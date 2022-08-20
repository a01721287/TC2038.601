#include <iostream>
#include <vector>
#define MAX 50

using namespace std;

int main() {
    int n,m,tmp,mat[MAX][MAX];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>m;
        for (int j = 0; j < m; j++){
            cin>>tmp;
            mat[i][j]=(tmp);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m j++){
            cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
        }
        
    }
    

    return 0;
}