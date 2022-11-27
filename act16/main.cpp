//Act16 Alejandro Hernández A01721287

#include <iostream>
#include <vector>

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
        double m = (p2.y - p1.y)/(p2.x - p1.x);
        double b = p1.y - m*p1.x;

        if (m>0 && p.y > m*p.x + b){
            return true;
        }else if(m<0 && p.y < m*p.x + b){
            return true;
        }else{
            return false;
        }
    }
};

vector<int> checar(vector<Part> parts, vector<Point> toys){
/*     for (int i = 0; i < parts.size(); i++){
        cout<<"["<<parts[i].p1.x<<","<<parts[i].p1.y<<"]"<<" & "<<"["<<parts[i].p2.x<<","<<parts[i].p2.y<<"]"<<endl;
    }
    for (int i = 0; i < toys.size(); i++){
        cout<<"["<<toys[i].x<<","<<toys[i].y<<"]"<<endl;
    }
    cout<<endl<<endl;
 */
    vector<int> result(parts.size(),0);
    for (int i = 0; i < toys.size(); i++){
        Point point = toys[i];
        for (int j = 0; j < parts.size(); j++){
            Part part = parts[j];
            if (point.x < part.p1.x && point.x < part.p2.x && point.x){
                result[j]++;
                break;
            }else if(part.p1.x != part.p2.x && part.belongs(point)){
                result[j]++;
                break;
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
            vector<Part> parts;

            for (int i = 0; i < n; i++){
                int u,l;
                cin>>u>>l;
                Point p1temp, p2temp;
                p1temp.x = u;
                p1temp.y = y1;
                p2temp.x = l;
                p2temp.y = y2;
                Part partition;
                partition.p1 = p1temp;
                partition.p2 = p2temp;
                parts.push_back(partition);
            }
            Part fin;
            fin.p1.x = x2;
            fin.p1.y = y2;
            fin.p2.x = x2;
            fin.p2.y = y1;
            parts.push_back(fin);

            vector<Point> toys;
            for (int i = 0; i < m; i++){
                int x,y;
                cin>>x>>y;
                toys.push_back(Point(x,y));
            }
            vector<int> res;
            res = checar(parts, toys);
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