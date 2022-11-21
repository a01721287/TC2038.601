// Protecting BeagleTown act15.cpp
// Alejandro Hernández Carrales A01721287

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <iomanip>

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

// Punto pivote
Point p0;

//Distancia al cuadrado
int distSq(Point &p1, Point &p2){
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

// 0 ==> p0, p1 y p2 son colineales
// 1 ==> A favor de la manecillas del Reloj. Clockwise
// 2 ==> En contra de las manecillas de Reloj. Counter Clockwise
int orientation(Point &p0, Point &p1, Point &p2){
	int v = (p1.y - p0.y) * (p2.x - p1.x) -
			(p1.x - p0.x) * (p2.y - p1.y);
	if (v == 0){
		return 0;
	}
	return (v > 0) ? 1 : 2;
}

// Comparar 2 puntos con el punto pivote
bool compare(Point &p1, Point &p2){
	int orien = orientation(p0, p1, p2);
	if (orien == 0){
		return distSq(p0,p2) >= distSq(p0,p1);
	}
	return (orien == 2);
}

// Saber quien es el siguiente del tope de la pila
Point nextToTop(stack<Point> &s){
	Point p = s.top();
	s.pop();
	Point ans = s.top();
	s.push(p);
	return ans;
}

//Sacar el perímetro del polígono dado un arreglo de sus puntos
//Complejidad O(n)
double perimeter(vector<Point> p){ 
    double res = 0;
    for (int i = 0; i < p.size()-1; i++){
        res = res + sqrt(distSq(p[i], p[i+1]));
    }
    res = res + sqrt(distSq(p[p.size()-1], p[0]));
    return res;
}


//Complejidad: O(n logn)
void convexHull(vector<Point> &points){
	int n = points.size();
	// localizar al pivote, es el punto más bajo y más a la izquierda.
	int yMin = points[0].y, minIdx = 0;
	for (int i=1; i<n; i++){
		int x = points[i].x;
		int y = points[i].y;
		if (y < yMin || y == yMin && x < points[minIdx].x){
			yMin = y;
			minIdx = i;
		}
	}
	// Encontramos al pivote (minIdx) y lo intercambiamos con la pos 0
	Point temp = points[0];
	points[0] = points[minIdx];
	points[minIdx] = temp;
	p0 = points[0];
	// Ordenar los n-1 puntos restantes (sin incluir el 0
	// con respecto al punto 0.
	// Un punto p1 si esta antes del punto p2, tiene un angulo mayor
	// (en contra de las manecillas del reloj) con respecto a p0
	sort(points.begin()+1,points.end(), compare);
	int m = 1;
	for (int i=1; i<n; i++){
		while (i < n-1 && orientation(p0, points[i], points[i+1])== 0){
			i++;
		}
		points[m++] = points[i];
	}
	if (m < 3){ // No se puede formar un poligono con 2 puntos
		return;
	}
	stack<Point> s;
	s.push(points[0]);
	s.push(points[1]);
	s.push(points[2]);
	for (int i=3; i<m; i++){
		Point nTT = nextToTop(s);
		while (s.size() > 1 && orientation(nTT, s.top(),points[i]) != 2){
			s.pop();
			nTT = nextToTop(s);
		}
		s.push(points[i]);
	}
    vector<Point> p2;
	// Vaciar el stack, porque esa es la solución
	while (!s.empty()){
		Point p = s.top();
        p2.push_back(p);
		s.pop();
	}
    //imprimir perímetro
    cout.precision(2);
    cout<<"The perimeter of the wall is: "<<fixed<< perimeter(p2) <<endl;
}

int main(){
	vector<Point> points;
	// n = cantidad de puntos
	int n, x, y;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> x >> y;
		points.push_back(Point(x,y));
	}
	convexHull(points);
}

/*
5
2 10
12 10
12 30
2 30
7 20  
*/