/*
    Actividad 01
    Alejandro Hernández Carrales A01721287
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <array>

using namespace std;

//Complejidad: O(n^2)
vector<char> decypher(vector<char> dic, string oper){
    vector<char> decoded;
    
    for (int i = 0; i < oper.length(); i++){
        for (int j = 0; j < dic.size(); j++){
            if (oper[i]==dic[j]){
                switch (j){
                    case 10:
                        decoded.push_back('+');
                        break;
                    case 11:
                        decoded.push_back('-');
                        break;
                    case 12:
                        decoded.push_back('*');
                        break;
                    case 13:
                        decoded.push_back('/');
                        break;
                    default:
                        decoded.push_back((char)(j+48));
                        break;
                }
            }
            
        }   
    }  
    return decoded;
}

//Complejidad: O(n)
string solve(vector<char> op){
    string tmp;
    char action;
    vector<int> terms;
    int answ;

    for (int i = 0; i < op.size(); i++){
        if(isdigit(op[i])){
            tmp = tmp + op[i];
        }else if(op[i]=='-'){
            if(i==0){
                tmp = tmp + op[i];
            }else if(isdigit(op[i-1])){
                terms.push_back(stoi(tmp));
                tmp=op[i];
            }else{
                tmp = tmp + op[i];
            }
        }else{
            action = op[i];
            terms.push_back(stoi(tmp));
            tmp="";
        }
    }
    terms.push_back(stoi(tmp));

    switch (action){
        case '+':
            answ = terms[0] + terms[1];
            break;
        case '*':
            answ = terms[0] * terms[1];
            break;
        case '/':
            answ = terms[0] / terms[1];
            break;
        default:
            answ = terms[0] + terms[1];
            break;
    }

    string tmp2(op.begin(),op.end());
    string result = tmp2 +"="+ to_string(answ);
    return result;
};

//Complejidad: O(n)
int main(){
    int n;
    string input;
    vector<char> dic;
    vector<string> answers;
    
    cin>>n;
    getline(cin >>ws, input);
    for (int i = 0; i < input.length(); i+=2){
        dic.push_back(input[i]);
    }

    for (int i = 0; i < n; i++){
        getline(cin >>ws, input); 
        answers.push_back(solve(decypher(dic,input)));
    }

    for (int i = 0; i < n; i++){
        cout<<answers[i]<<endl;
    }
        
    return 0;
}