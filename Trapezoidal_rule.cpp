#include <bits/stdc++.h>

using namespace std;

class Trapezoidal {

    public:

    double function(double x) {
        return (1 / (1 + pow(x, 2)));
    }

    void solve() {

        double l, u, n, h;

        cout << "Enter lower limit: ";
        cin >> l;
        cout << "Enter upper limit: ";
        cin >> u;

        cout << "Enter sub-interval: ";
        cin >> n;

        // step size 
        h = (u-l) / n;

        // integration
        double i = function(l);  // integration -> i;

        for(int j = 1; j < n; j++) {
            double k = l + j*h;   // k = l + j*h; -> xi = a + i*del(x);
            i = i + 2 * function(k);
        }

        i = i + function(u);
        i = i * h/2;

        cout<< endl << "Required value of integration is: " << i;

    }
        
};

int main() {

    Trapezoidal trapezoidal;
    trapezoidal.solve();

    return 0;

}
