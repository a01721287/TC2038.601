//Act16 Alejandro Hernández A01721287

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <climits>

#define MAX 5010

using namespace std;

struct Point{
    int x, y;
    Point(){
		x = y = 0;
	}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

struct Part{
    Point p1,p2;

    Part(){
		p1.x = p1.y = p2.x = p2.y = 0;
	}

	Part(Point p1, Point p2){
		this->p1 = p1;
		this->p2 = p2;
	}

    bool belongs(Point p){
        long double m = (p2.y - p1.y)/(p2.x - p1.x);
        long double b = p1.y - m*p1.x;

        if (m>0 && p.y > m*p.x + b){
            return true;
        }else if(m<0 && p.y < m*p.x + b){
            return true;
        }else{
            return false;
        }
    }
};

vector<int> checar(vector<Part> parts, vector<Point> toys, int n, int m){
/*     for (int i = 0; i < n; i++){
        cout<<"["<<parts[i].p1.x<<","<<parts[i].p1.y<<"]"<<" & "<<"["<<parts[i].p2.x<<","<<parts[i].p2.y<<"]"<<endl;
    }
    for (int i = 0; i < m; i++){
        cout<<"["<<toys[i].x<<","<<toys[i].y<<"]"<<endl;
    }
    cout<<endl<<endl; */

    vector<int> result(n,0);
    for (int i = 0; i < m; i++){
        Point point = toys[i];
        for (int j = 0; j < n; j++){
            Part part = parts[j];
            if (point.x < part.p1.x || point.x < part.p2.x){
                if (point.x < part.p1.x && point.x < part.p2.x){
                    result[j]++;
                    break;
                }else if(part.p1.x != part.p2.x && part.belongs(point)){
                    result[j]++;
                    break;
                }
            }
        }
    }
    return result;
}

int main(){
    vector<vector<int>> results;
    while (true){
        int n;
        cin>>n;
        if (n != 0){
            int m,x1,y1,x2,y2;
            cin>>m>>x1>>y1>>x2>>y2;
            vector<Part> parts(MAX);

            vector<pair<int,int>> temp; 
            for (int i = 0; i < n; i++){
                int u,l;
                cin>>u>>l;
                temp.push_back(make_pair(u,l));
            }
            sort(temp.begin(), temp.end());

            for (int i = 0; i < n; i++){
                Point p1temp, p2temp;
                p1temp.x = temp[i].first;
                p1temp.y = y1;
                p2temp.x = temp[i].second;
                p2temp.y = y2;
                Part partition;
                partition.p1 = p1temp;
                partition.p2 = p2temp;
                parts[i] = partition;
            }
            
            Part fin;
            fin.p1.x = x2;
            fin.p1.y = y2;
            fin.p2.x = x2;
            fin.p2.y = y1;
            parts[n] = fin;
            n = n+1;

            vector<Point> toys(MAX);
            for (int i = 0; i < m; i++){
                int x,y;
                cin>>x>>y;
                toys[i] = Point(x,y);
            }
            vector<int> res;
            res = checar(parts, toys, n, m);
            results.push_back(res);
            
        }else{
            break;
        }
    }
    
    for (int i = 0; i < results.size(); i++){
        for (int j = 0; j < results[i].size(); j++){
            cout<<j<<": "<<results[i][j]<<endl;
        }
        if (i != results.size()-1){
            cout<<endl;
        }
    }
    
    return 0;
}

/* 5 6 0 10 60 0
3 1
4 3
6 8
10 10
15 30
1 5
2 1
2 8
5 5
40 10
7 9
4 10 0 10 100 0
20 20
40 40
60 60
80 80
5 10
15 10
25 10
35 10
45 10
55 10
65 10
75 10
85 10
95 10
0  */