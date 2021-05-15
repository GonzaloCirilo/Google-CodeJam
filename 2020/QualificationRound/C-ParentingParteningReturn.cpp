#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main(){
    int t, n, s, e;
    scanf("%d", &t);
    char ans[100] = {}, partners[2] = {'C', 'J'};
    for(int ts = 1; ts <= t; ts++){
        printf("Case #%d: ", ts);
        int timeline[1445] = {}, open[1000] = {}, closes[1000] = {};
        scanf("%d", &n);
        vector<iii> tasks;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &s, &e);
            ii aux = {s, e};
            tasks.push_back({aux, i});
        }
        sort(tasks.begin(), tasks.end());
        int c = 0, j = 0; bool invalid = false; int  k = 0, cont = 0;
        char ans[1001] = {};
        for(int i = 0; i <= 1440; i++){
            if(c==i)
                c = 0;
            if(j==i)
                j = 0;

            if(k < tasks.size() && tasks[k].first.first == i){
                if(!c){
                    c = tasks[k].first.second;
                    ans[tasks[k].second] = 'C';
                }else if(!j){
                    j = tasks[k].first.second;
                    ans[tasks[k].second] = 'J';
                }
                else{
                    invalid = true;
                }
                i--;
                k++;
            }
        }

        if(invalid){
            printf("IMPOSSIBLE\n");
        }else{
            for(int i = 0; i < n; i++)
                putchar(ans[i]);
            putchar('\n');
        }




    }
    return 0;
}