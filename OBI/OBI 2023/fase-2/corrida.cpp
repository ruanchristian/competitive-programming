#include <bits/stdc++.h>

using namespace std;

int N, minX = 0, maxX = 0, minY = 0, maxY = 0, x = 0, y = 0;

int main() {
    cin >> N;

    while (N--) {
        int C;
        char D;
        cin >> C >> D;

        if (D == 'N') {
            y += C;
            maxY = max(maxY, y);
        } else if (D == 'S') {
            y -= C;
            minY = min(minY, y);
        } else if (D == 'L') {
            x += C;
            maxX = max(maxX, x);
        } else {
            x -= C;
            minX = min(minX, x);
        }
    }

    int W = maxX-minX + 2;
    int H = maxY-minY + 2;
    
    cout << 2 * (W+H) << endl;

    return 0;
}