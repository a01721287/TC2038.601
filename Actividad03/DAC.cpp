#include <iostream>
#include <vector>

using namespace std;

/* vector<int> merge(vector<int> list, vector<int> dac1, vector<int> dac2, int ini, int fin){
    int half = (ini+fin)/2;
    int lowest = list[ini];
    for (int i = ini; i <= half; i++){
        if (list[i]< lowest){
            lowest = list[i];
        }
    }
    cout<<"lowest: "<<lowest<<endl;
    int highest = list[half+1];
    for (int i = half+1; i <= fin; i++){
        if (list[i]> highest){
            highest = list[i];
        }
    }
    cout<<"highest: "<<highest<<endl;
    vector<int> buySell = {lowest, highest};
    int current = list[buySell[1]]-list[buySell[0]];
    int dac1buysell = list[dac1[1]]-list[dac1[0]];
    int dac2buysell = list[dac2[1]]-list[dac2[0]];

    if (dac1buysell > current){
        if (dac1buysell>dac2buysell){
            cout<<"returned dac1"<<endl;
            return dac1;
        }else{
            cout<<"returned dac2"<<endl;
            return dac2;
        }
    }else{
        if (current> dac2buysell)
        {
            cout<<"returned buySell"<<endl;
            return buySell;
        }else{
            cout<<"returned dac2"<<endl;
            return dac2;
        }
    }
} */

/* 
    //Este es el que medio-jalaba
    vector<int> merge(vector<int> list, vector<int> part1, vector<int> part2){
    int lowest,highest;
    if (part2.size()==1){
        if (list[part1[0]]<=list[part1[1]]){
            lowest = part1[0];
        }else{
            lowest = part1[1];
        }
        if (list[part2[0]]>=list[part1[1]]){
            highest = part2[0];
        }else{
            highest = part1[1];
        }
        // cout<<"RETURNED: "<<list[lowest]<<", "<<list[highest]<<endl;
        for (int i = 0; i < list.size(); i++){
            if (list[lowest]>list[i]&& i!= list.size()-1){
                lowest = i;
            }
        }
        // cout<<"LOWEST:" << lowest<<endl;
        if (list[lowest]>list[part2[0]]&& highest<=lowest){
            lowest = part2[0];
            highest = part2[0];
        }
        
        return {lowest,highest};
    }else{
        if (list[part1[0]]<=list[part1[1]]){
            lowest = part1[0];
        }else{
            lowest = part1[1];
        }
        if (list[part2[1]]>=list[part2[0]]){
            highest = part2[1];
        }else{
            highest = part2[0];
        }
        if (lowest>=list[part2[0]]){
            lowest = part2[0];
        }
        return {lowest,highest};
    }
} */

//Complejidad O(n)
vector<int> merge(vector<int> list, vector<int> part1, vector<int> part2){
    int lowest,highest;
    if (list[part1[0]]>list[part1[1]]){
        lowest = part1[1];
    }else{
        lowest = part1[0];
    }
    if (part2.size()==1)
    {
        highest = part2[0];

    }else{
        if (list[part2[0]]>list[part2[1]]){
            highest = part2[0];
        }else{
            highest = part2[1];
        }

    }
    vector<int> third = {lowest, highest};

    if (list[lowest] == list[highest]){
        return {lowest,highest};
    }
    

    int dac1buysell = list[part1[1]]-list[part1[0]];
    int dac2buysell;
    if (part2.size()!=1){
        dac2buysell = list[part2[1]]-list[part2[0]];
    }else{
        dac2buysell = 0-list[part2[0]];
    }
    
    int current = list[third[1]]-list[third[0]];

    if (dac1buysell > current){
        if (dac1buysell>dac2buysell){
            return part1;
        }else{
            return part2;
        }
    }else{
        if (current> dac2buysell)
        {
            return third;
        }else{
            return part2;
        }
    }
 
/*     if (part2.size()==1){
        if (list[part1[0]]<=list[part1[1]]){
            lowest = part1[0];
        }else{
            lowest = part1[1];
        }
        if (list[part2[0]]>=list[part1[1]]){
            highest = part2[0];
        }else{
            highest = part1[1];
        }
        // cout<<"RETURNED: "<<list[lowest]<<", "<<list[highest]<<endl;
        for (int i = 0; i < list.size(); i++){
            if (list[lowest]>list[i]&& i!= list.size()-1){
                lowest = i;
            }
        }
        // cout<<"LOWEST:" << lowest<<endl;
        if (list[lowest]>list[part2[0]]&& highest<=lowest){
            lowest = part2[0];
            highest = part2[0];
        }
        
        return {lowest,highest};
    }else{
        if (list[part1[0]]<=list[part1[1]]){
            lowest = part1[0];
        }else{
            lowest = part1[1];
        }
        if (list[part2[1]]>=list[part2[0]]){
            highest = part2[1];
        }else{
            highest = part2[0];
        }
        if (lowest>=list[part2[0]]){
            lowest = part2[0];
        }
        return {lowest,highest};
    } */
}

/* vector<int> merge(vector<int> list, vector<int> part1, vector<int> part2){
    int lowest,highest,a,b,c,d;
    a = list[part1[0]];
    b = list[part1[1]];
    c = list[part2[0]];
    if (part2.size()!=1){
        d = list[part2[1]];
    }else{
        d= 0;
    }
    
    if (b-a>d-c){
        if (a<=b){
            lowest = a;
        }else{
            lowest = b;
        }

    }
    return {lowest,highest};
} */

//Complejidad O(n^2)
vector<int> dac(vector<int> list, int ini, int fin){
    // cout<<"ini: "<<ini<<" fin: "<<fin<<endl;
    if (ini==(fin-1) || ini==fin){
        if (ini==fin){
            return{ini};
        }else{
            return {ini,fin};
        }
        // cout<<"returned "<<"{"<<ini<<","<<fin<<"}"<<endl;
    }else{
        int half = (ini+fin)/2;
        vector<int> part1,part2;
        part1 = (dac(list, ini, half));
        // cout<<endl;
        
        // cout<<endl;
        part2 = (dac(list, half+1,fin));
        // cout<<endl;
        // cout<<endl<<endl<<"==MERGE=="<<endl;
        
        return merge(list, part1,part2);
    }
}

//Complejidad O(n^2)
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
        if (precios.size()!=1){
            vector<int> result = dac(precios,0, m-1);
            cout<<"Buy in "<<result[0]+1<<", sell in "<<result[1]+1<<endl;
        }else{
            cout<<"Buy in "<<1<<", sell in "<<1<<endl;
        }
        
    }
    return 0;
}