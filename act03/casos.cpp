#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

int main(){
    srand (time(NULL));
    
    for (int j = 0; j < 10; j++)
    {
        int n = rand()%7+1;    
        vector<int> cases;
        for (int i = 0; i < n; i++){
            cases.push_back(rand()%10+1);
        }

        cout<<cases.size()<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<cases[i]<<endl;
        }
    }
    return 0;
}