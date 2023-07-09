#include <bits/stdc++.h>

using namespace std;

class Simpson {

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
            if(j%2 == 0) {
                i = i + 2 * function(k);
            } else {
                i = i + 4 * function(k);
            }
        }

        i = i + function(u);
        i = i * h/3;

        cout<< endl << "Required value of integration is: " << i << endl << endl;

    }
        
};

int main() {

    Simpson simpson;
    simpson.solve();

    return 0;

}
