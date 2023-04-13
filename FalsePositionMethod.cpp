#include <bits/stdc++.h>

using namespace std;

class Falsi {

    private:

    double ep_s = 0.0001;
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

        // root = a - (function(a) * (b - a)) / (function(b) - function(a));
        root = (b*function(a) - a*function(b)) / (function(a) - function(b));

        prev = root;

        int iteration = 1;

        while(true) {

            cout << "root at iteration " << iteration++ << " : " << root << endl; 

            double calc = function(root) * function(a);

            if(calc < 0.0) b = root;
            else if(calc > 0.0) a = root;
            else break;

            // root = a - (function(a) * (b - a)) / (function(b) - function(a));
            root = (b*function(a) - a*function(b)) / (function(a) - function(b));

            
            double ep_a = abs((prev - root) / root);

            if(ep_a < ep_s) break;

            prev = root;

        }

        cout << "The apprx. root is: " << root << endl;
    }
};

int main() {

    Falsi false_position = Falsi();

    false_position.solve();
    
    return 0;
}
