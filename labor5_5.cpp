#include <iostream>
#include <cmath>
#define Pi 3.141592653589

using namespace std;


double f(double x) {
    return sin(x) - cos(x);
}


double findRoot(double a, double b, double eps, int& depth) {
    depth++;

    double m = (a + b) / 2.0;  

 
    if (fabs(b - a) < eps || fabs(f(m)) < eps) {
        return m;
    }

    if (f(a) * f(m) < 0) {
        return findRoot(a, m, eps, depth);  
    }
    else {
        return findRoot(m, b, eps, depth);  
    }
}

int main() {
    double a, b, eps;
       cout << "a = "; cin >> a;
       cout << "b = "; cin >> b; 
       cout << "eps = "; cin >> eps;     
    int depth = 0;               

    if (f(a) * f(b) >= 0) {
        return 0;
    }

    double root = findRoot(a, b, eps, depth);

    cout << "Root =  " << root << endl;
    cout << "Depth =  " << depth << endl;

    return 0;
}