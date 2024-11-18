#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 35;
int n, m;
string s[N];
int prefix[N][N];

int getSum(int x1, int y1, int x2, int y2) {
    return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i]; 
    }

    memset(prefix, 0, sizeof prefix);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (s[i][j] == '*' ? 1 : 0);
        }
    }

    int maxArea = 0;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    if (getSum(i, j, k, l) == 0) { 
                        int area = (k - i + 1) * (l - j + 1);
                        if (area > maxArea) {
                            maxArea = area;
                            x1 = i;
                            y1 = j;
                            x2 = k;
                            y2 = l;
                        }
                    }
                }
            }
        }
    }

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}
