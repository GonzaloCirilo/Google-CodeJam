#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <numeric>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    // C, M, Y, K
    int printer[3][4] = {}, ans[4] = {(int)1e7, (int)1e7, (int)1e7, (int)1e7};
    for(int i = 0; i < 3; i++) {
        cin >> printer[i][0] >> printer[i][1] >> printer[i][2] >> printer[i][3];
    }
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            ans[j] = min(ans[j], printer[i][j]);
        }
    }

    for(int i = 0; i < 4; i++) {
        sum += ans[i];
    }
    if(sum >= 1e6){
        int dif = sum - 1e6;
        for(int i = 0; i < 4; i++) {
            int aux = ans[i] - dif;
            if (aux < 0) {
                aux = 0;
                dif -= ans[i];
            } else {
                dif = 0;
            }

            cout << " " << aux;
        }
    }else {
        cout << " IMPOSSIBLE";
    }
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ":";
        solve();
    }
    return 0;
}