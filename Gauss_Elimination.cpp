#include <bits/stdc++.h>

using namespace std;

class Gauss_Elimination {
    public:
    void solve() {
        cout.precision(4);
        int n;
        cout << "Enter number of equations : ";
        cin >> n;

        double a[n][n+1]; // augmented matrix

        cout << "Enter the augmented matrix: " << endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n+1; j++) {
                cin >> a[i][j];
            }
        }

        // pivotisation
        for(int i = 0; i < n; i++) {
            for(int k = i+1; k < n; k++) {
                if(fabs(a[i][i]) < fabs(a[k][i])) {
                    for(int j = 0; j < n; j++) {
                        swap(a[i][j], a[k][j]);
                    }
                }
            }
        }

        cout << "Matrix after pivotisation: " << endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n+1; j++) {
                cout << a[i][j] << " ";
            } cout << endl;
        }

        // loop to perform gauss elimination
        for(int i = 0; i < n-1; i++) {
            for(int k = i+1; k < n; k++) {
                double t = a[k][i] / a[i][i];
                for(int j = 0; j < n; j++) {
                    a[k][j] -= (a[i][j]*t);
                    // if(a[k][j] < 0.00001) a[k][j] = 0;
                }
            }
        }

        // matrix after gauss elimination

        cout << "Matrix after gauss elimination: " << endl;
 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n+1; j++) {
                cout << a[i][j] << " ";
            } cout << endl;
        }


        // back-substitution
        double ans[n];
        for(int i = n-1; i >= 0; i--) {
            ans[i] = a[i][n];

            for(int j = 0; j < n; j++) {
                if(j != i) {
                    ans[i] -= (a[i][j] * ans[j]);
                    ans[i] /= a[i][i];
                    // if(ans[i])
                }
            }
        }

        cout << "\nThe value of the variables are: " << endl;

        for(int i = 0; i < n; i++) {
            cout << ans[i] << endl;
        }

    }

};

int main() {

    Gauss_Elimination ge;
    ge.solve();

    return 0;
}
