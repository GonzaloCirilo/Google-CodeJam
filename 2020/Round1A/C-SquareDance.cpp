#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
struct Node
{
    int skill, eliminated = 0, u = 0, d = 0, l = 0, r = 0;
};

int main(){
    int t;

    scanf("%d", &t);
    for (int ts = 1; ts <= t; ts++){
        int r, c, n;
        long long ans = 0, sum = 0;
        scanf("%d %d", &r, &c);
        vector<vector<Node>> df = vector<vector<Node>>(r, vector<Node>(c));
        queue<ii> q;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                scanf("%d", &n);
                sum += n;
                Node nn = Node{};
                nn.skill = n;
                nn.u = i - 1;
                nn.d = i + 1 == r ? -1 : i + 1;
                nn.l = j - 1;
                nn.r = j + 1 == c ? -1 : j + 1;
                df[i][j] = nn;
                q.push({i, j});
            }
        }
        ans += sum;
        int neli;
        while (true){
            neli = 0;
            vector<int> er = vector<int>(), ec = vector<int>();
            while (!q.empty()){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (!df[i][j].eliminated){
                    long long s = 0, nele = 0;
                    if (df[i][j].d != -1){
                        s += df[df[i][j].d][j].skill;
                        nele++;
                    }
                    if (df[i][j].u != -1){
                        s += df[df[i][j].u][j].skill;
                        nele++;
                    }
                    if (df[i][j].l != -1){
                        s += df[i][df[i][j].l].skill;
                        nele++;
                    }
                    if (df[i][j].r != -1){
                        s += df[i][df[i][j].r].skill;
                        nele++;
                    }

                    if (nele != 0 && df[i][j].skill < (double)s / nele){
                        neli++;
                        sum -= df[i][j].skill;
                        df[i][j].eliminated = 1;
                        er.push_back(i);
                        ec.push_back(j);
                    }
                }
            }

            for (int z = 0; z < er.size(); z++){
                int u = er[z], v = ec[z];
                if (df[u][v].l != -1){
                    df[u][df[u][v].l].r = df[u][v].r;
                    q.push({u, df[u][v].l});
                }
                if (df[u][v].r != -1){
                    df[u][df[u][v].r].l = df[u][v].l;
                    q.push({u, df[u][v].r});
                }
                if (df[u][v].d != -1){
                    df[df[u][v].d][v].u = df[u][v].u;
                    q.push({df[u][v].d, v});
                }
                if (df[u][v].u != -1){
                    df[df[u][v].u][v].d = df[u][v].d;
                    q.push({df[u][v].u, v});
                }
            }

            if (neli == 0)
                break;
            ans += sum;
        }

        printf("Case #%d: %lld\n", ts, ans);
    }

    return 0;
}