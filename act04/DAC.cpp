#include <iostream>
#include <vector>
#include<algorithm>
#include <iomanip>

using namespace std;

vector<int> solve(vector<int> n1,vector<int> n2, int ini, int fin){
    int half = (ini+fin)/2;

    vector<int> median;
    for (int i = ini; i <= half; i++){
        if (n1[i]>n1[i+1]&&n1[i]<n2[i]){
            median.push_back(n2[i]);
        }
    }
    for (int i = half; i < fin; i++){
        if (n2[i]>n2[i+1]&&n2[i]<n1[i]){
            median.push_back(n2[i]);
        }
    }
    
    return median;
}

vector<int> dac(vector<int> n1,vector<int> n2, int ini, int fin){
    if (ini==fin){  
        return {n1[ini],n2[ini]};  
    }else{
            int half = (ini+fin)/2;
            vector<int> header1;
            vector<int> header2;
            vector<int> header3;
            for (int i = 0; i < fin; i++){n1.push_back(n2[i]);
        }
        solve(n1,n2,ini,fin);
        sort(n1.begin(),n1.end());
        return {n1[(n1.size()-1)/2],n1[((n1.size()-1)/2)+1]};
    }
}

int main(){
    int c, m,o;
    cin>>c;
    for (int j = 0; j < c; j++){
        vector<int> n1;
        vector<int> n2;
        cin>>m;
        for (int i = 0; i < m; i++){
            cin>>o;
            n1.push_back(o);
        }
        for (int i = 0; i < m; i++){
            cin>>o;
            n2.push_back(o);
        }
        vector<int> result = dac(n1,n2,0,m-1);
        double answer= (result[0]*1.00  + result[1]*1.00)/2;
        cout<<setprecision(2)<<fixed;
        cout<<"Median case "<<j+1<<": "<<answer<<endl;
        
    }
    return 0;
}