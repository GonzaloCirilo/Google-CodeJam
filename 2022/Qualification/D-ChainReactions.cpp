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

vector<vi> g;
vi fun;
pair<ll, ll> rec(int ind) {
    if(g[ind].size() == 0) {
        return {fun[ind], 0};
    }
    long long f = fun[ind];
    vector<pair<long long,long long>> ss;
    for(int i = 0; i < g[ind].size(); i++) {
        auto a = rec(g[ind][i]);
        ss.push_back(a);
    }
    sort(ss.begin(), ss.end());
    long long x = fun[ind], sum = 0;
    for(int i = 0; i < ss.size(); i++) {
        if(i == 0) {
            x = max(x,ss[i].first);
            sum += ss[i].second;
        } else {
            sum += ss[i].second + ss[i].first;
        }
    }
    //cout << x << " " << sum << endl;
    return {x,sum};
}

void solve(){
    long long n, fi, pi;
    cin >> n;
    vi s;
    fun = vi();
    g = vector<vi>(n);
    for(int i = 0; i < n; i++) {
        cin >> fi;
        fun.push_back(fi);
    }

    for(int i = 0; i < n; i++) {
        cin >> pi;
        if(pi == 0) {
            s.push_back(i);
        }else{
            g[pi-1].push_back(i);
        }
    }
    long long ans = 0;
    for(int i = 0; i < s.size(); i++) {
        auto [x, sum] = rec(s[i]);
        ans += sum + x;
    }
    cout << ans << endl;
}

int main(){
    long long t;
    cin >> t;
    for(long long ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ": ";
        solve();
    }
    return 0;
}