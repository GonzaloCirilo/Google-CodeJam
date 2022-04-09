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
    int n, di; vector<int> arr;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> di;
        arr.push_back(di);
    }
    sort(arr.begin(), arr.end());
    int s = 1, ans = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] >= s) {
            s++; ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ": ";
        solve();
    }
    return 0;
}