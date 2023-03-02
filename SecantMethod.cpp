#include <bits/stdc++.h>
using namespace std;

#define tolerance 0.001

class Solution {
    private:
    double f(double x) {

        return pow(x, 4) + pow(x, 3) + pow(x, 2) + x -1;
    }

    double secantFunction(double a, double b) {

        return ((b * f(a) - a * f(b)) / (f(a) - f(b)));
    }

    public:
        double a, b;
    void solve() {
        srand(int(time(0)));

        while(true) {
        a = -9 + rand() % 10;
        b = rand() % 10;

        if (f(a) * f(b) < 0.0)
            break;
        }

        int k = 1;
        double root = secantFunction(a, b);

        while(true) {
        cout << "a = " << setprecision(4) << a << " b = " << setprecision(4) << b << "  iteration " << k++ << setprecision(4) << " root = " << root << endl;
        if (f(root) == 0.0)
            break;
        if (abs(root - secantFunction(root, a)) < tolerance)
            break;

        b = a;
        a = root;
        root = secantFunction(a, b);
        }

        root = secantFunction(a, b);

        cout << "final root is: " << root << endl;
    }
};

int main() {

    Solution secant;
    secant.solve();

    return 0;
}