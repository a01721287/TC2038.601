#include <iostream>
#include <vector>
#define DAYS 50
#define PRICE 1000

using namespace std;

/* //Calc Proto
void calc(int matrix[DAYS][PRICE], vector<int>caseLength){  
    for (int i = 0; i < caseLength.size(); i++){
        int lowpos =0;
        int highpos = 0;
        int highest = matrix[i][0];
        int lowest = matrix[i][0];
        cout<<"Case #"<<i<<": "<<endl;
        for (int j = 0; j < caseLength[i]; j++){
            cout<<"lowpos:"<<lowpos<<endl;
            cout<<"highpos:"<<highpos<<endl;
            cout<<"cycle #"<<j<<":"<<endl;
            if (matrix[i][j]>lowest){
                highest = matrix[i][j];
                highpos = j+1;
            }else if (matrix[i][j]<lowest){
                lowest = matrix[i][j];
                lowpos = j+1;
            }else{
                lowest = matrix[i][j];
                lowpos = j+1;
            }
            cout<<matrix[i][j]<<endl;
        }
            cout<<"Case "<<i<<" Highest: "<<highest<<" Lowest: "<<lowest<<endl;
            cout<<"Buy in "<<lowpos<<", sell in "<<highpos<<endl;
            cout<<endl<<endl;
    }
} */


void calc(int matrix[DAYS][PRICE], vector<int>caseLength){  
    for (int i = 0; i < caseLength.size(); i++){
        int lowpos =1;
        int highpos = 1;
        int highest = matrix[i][0];
        int lowest = matrix[i][0];
        for (int j = 1; j < caseLength[i]+1; j++){
            if (matrix[i][j-1]>lowest){
                highest = matrix[i][j-1];
                highpos = j;
            }else if(matrix[i][j-1]<lowest){
                lowest = matrix[i][j-1];
                lowpos = j;
                if (matrix[i][j]<matrix[i][j-1]){
                    highest = matrix[i][j-1];
                    highpos = j;
                }
                
            }else if(matrix[i][j-1]==highest){
                highpos =j;
            }
        }
            cout<<"Buy in "<<lowpos<<", sell in "<<highpos<<endl;
    }
}

int main(){
    vector<int> caseLength;
    int n,m,tmp,mat[DAYS][PRICE];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>m;
        caseLength.push_back(m);
        for (int j = 0; j < m; j++){
            cin>>tmp;
            mat[i][j]=(tmp);
        }
    }

    calc(mat,caseLength);

/*     cout<<endl<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < caseLength[i] ;j++){
            cout<<mat[i][j]<<endl;
        }
    }
     */

    return 0;
}