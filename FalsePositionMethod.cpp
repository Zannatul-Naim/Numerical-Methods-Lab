#include <bits/stdc++.h>

using namespace std;

class Falsi {

    private:

    double ep = 0.001;
    double a, b;
    
    double function(double x) {
        return (x*x*x + x*x - 1);
    }

    public:

    double root;

    void solve() {

        srand(int(time(0)));

        while(true) {

            a = -9 + rand()%10;
            b = rand()%10;

            if(function(a) * function(b) < 0.0) break;
        }

        if(a > b) swap(a, b);

        double prev;

        root = a - (function(a) * (b - a)) / (function(b) - function(a));
        prev = root;

        int iteration = 1;

        while((b-a) > ep) {

            cout << "root at iteration " << iteration++ << " : " << root << endl; 

            if(function(root)*function(a) < 0.0) b = root;
            else if(function(root) == 0.0) break;
            else a = root;
            root = a - (function(a) * (b - a)) / (function(b) - function(a));
            
            if(abs(prev - root) < 0.00001) break;

            prev = root;

        }

        cout << "The apprx. root is: " << root << endl;
    }
};

int main() {

    Falsi fpos = Falsi();

    fpos.solve();
    
    return 0;
}
