#include <bits/stdc++.h>

using namespace std;

#define ep_s 0.0001
#define total_steps 100

class Newton_Raphson {

public:

    double f(double x) { // original polynomial
        return (x*x*x + x*x - 1);
    }

    double df(double x) { // derivative function
        return (3*x*x + 2*x);
    }

    void solve() {
        
        srand(int(time(0)));

        double prev_root;

        while(true) {
            prev_root = -9 + rand()%10;
            if(df(prev_root) != 0) break;
        }
        double root;

        int step = 0;

        while(true) {

            double fx = f(prev_root);
            double dfx = df(prev_root);

            root = prev_root - (fx / dfx);  // finding the new root

            if(f(root) == 0.0) break;

            double ep_a = abs((root - prev_root)/root);  // finding the absolute relative apprx error

            if(ep_a < ep_s) {
                break;
            }

            cout << "Iteration-" << ++step << ":\t x = "<< setw(10) << root <<" and f(x) = " << setw(10) << f(root) << endl;

            prev_root = root;

            if(step > total_steps) {
                cout << "non convergent.." << endl;
                return;
            }
        }

        cout << "the value of the root is: " << root << endl;
    }
};



int main() {

    double x = -20.0;

    Newton_Raphson newton_raphson = Newton_Raphson();

    newton_raphson.solve();

    return 0;

}
