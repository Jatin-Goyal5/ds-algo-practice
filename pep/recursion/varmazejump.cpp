#include<bits/stdc++.h>

using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    // write your code here
    if (sr > dr || sc > dc) {
        return;
    }
    if (sr == dr && sc == dc) {
        cout << psf << endl;
    }
   

    for (int i = 1; i <= dc-sc; i++) {
        string ans = "h" + to_string(i);
        printMazePaths(sr, sc + i, dr, dc, psf + ans);
    }
     for (int i = 1; i <= dr-sr; i++) {
        string ans = "v" + to_string(i);
        printMazePaths(sr + i, sc, dr, dc, psf + ans);
    }
    
    for (int i = 1; i <= dc-sc && i <= dr-sr; i++) {
        string ans = "d" + to_string(i);
        printMazePaths(sr+i, sc + i, dr, dc, psf + ans);
    }

}

int main() {
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}