#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> list, vector<int> part1, vector<int> part2,int ini, int fin){
    int half = (ini+fin)/2;
    vector<int> part3 = {0,(fin-ini==1) ? 0 : half+1};

    for (int i = ini; i <= half; i++){
        if (list[i]<list[part3[0]]){
            part3[0]=i;
        }
    }

    for (int i = half; i < fin; i++){
        if(list[i]>list[part3[1]]){
            part3[1]=i;
        }
    }   

    if (list[part1[1]]-list[part1[0]]>=list[part3[1]]-list[part3[0]]){
        if (list[part1[1]]-list[part1[0]]>=list[part2[1]]-list[part2[0]]){
            return part1;
        }else{
            return part2;
        }
    }else{
        if (list[part3[1]]-list[part3[0]]>=list[part2[1]]-list[part2[0]]){
            return part3;
        }else{
            return part2;
        }
    }
}

//Dac that returns smaller pairs
vector<int> dac(vector<int> list, int ini, int fin){
    if (ini==fin){
        return {ini,fin};
    }
    int half = (ini+fin)/2;
    vector<int> part1 = dac(list, ini, half);
    vector<int> part2 = dac(list, half+1,fin);
    return merge(list,part1,part2,ini,fin);

}

int main(){
    int n, m,o;
    cin>>n;
    for (int i = 0; i < n; i++){
        vector<int> precios;
        cin>>m;
        for (int i = 0; i < m; i++){
            cin>>o;
            precios.push_back(o);
        }
        vector<int> result = dac(precios,0, precios.size());
        cout<<"Buy in "<<result[0]+1<<", sell in "<<result[1]+1<<endl;
    }
    return 0;
}