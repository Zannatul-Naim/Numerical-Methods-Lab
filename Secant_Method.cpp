#include <bits/stdc++.h>

using namespace std;

#define ep_s 0.0001
#define N 100

class Secant {

public:
    double f(double x) { // original polynomial
        return (x*x*x + x*x - 1);
    }

    void solve() {

        double prev_prev_root, prev_root, root;

        srand(int(time(0)));

        /*
            generating two different random variables
        */

        prev_prev_root = rand() % 10;

        while(true) {
            prev_root = rand()%10;
            if(prev_root != prev_prev_root) break;
        }

        cout << prev_prev_root << " " << prev_root << endl;

        int step = 0;

        while(true) {

            root = prev_root - ((f(prev_root)*(prev_root - prev_prev_root)) / (f(prev_root) - f(prev_prev_root)));  // calculating new root

        
            double ep_a = abs((root - prev_root) / root);  // finding the absolute relative apprx. error

            if(ep_s > ep_a) break; 

            cout << "Iteration-" << ++step << ":\t x = "<< setw(10) << root <<" and f(x) = " << setw(10) << f(root) << endl;

            if(step > N) {
                cout << "non convergent.." << endl;
                return;
            }

            prev_prev_root = prev_root;
            prev_root = root;
        }

        cout << "the root is: " << root << endl;
        cout << "Total number of iterations : " << step << endl;
    }
};

int main() {

    Secant secant = Secant();

    secant.solve();

    return 0;

}
