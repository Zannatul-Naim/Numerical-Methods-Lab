#include <bits/stdc++.h>

using namespace std;

#define EP 0.001

class Solution {

    private:

    double low, up;

    double function(double x) {

        return x*x*x + x*x - 1;
    }

    public:


    void solve() {

        srand(int(time(0)));

        while(true) {

            low = -9 + rand()%10;
            up = rand()%10;

            if(function(low) * function(up) < 0.0) break;
        }

        if(low > up) swap(low, up);

        cout << "low: " << low << "   up: " << up << endl;

        double root;

        int iteration = 1;

        while((up - low) >= EP) {

            root = (low+up) / 2;
            if(function(root) == 0.0) break;
            else if(function(root) * function(low) <= 0.0) up = root;
            else low = root;

            cout << "root at iteration " << iteration++ << " : " << root << endl; 
        }


        cout << "the root is: " << root << endl;
    }
};

int main() {

    Solution sol = Solution();

    sol.solve();

    return 0;
}
