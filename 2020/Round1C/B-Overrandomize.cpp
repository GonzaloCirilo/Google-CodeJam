#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    for(int ts = 1; ts <= t; ts++){
        printf("Case #%d: ", ts);
        long long u;
        scanf("%lld\n", &u);
        set<char> ww;
        
        vector<int> abc = vector<int>(27, -1);
        for(int i = 0; i < 10000; i++){
            //int qi;
            string qi, s;
            cin >> qi >> s;

            abc[s[0] - 'A']++;            

            for(int i = 0; i < s.size(); i++){
                ww.insert(s[i]);
            }
        }
        char ans[10] = {};
        for(int i = 1; i <= 9; i++){
            int maxe = *max_element(abc.begin(), abc.end());
            for(int j = 0; j < 27; j++){
                if(maxe == abc[j]){
                    abc[j] = -9999999;
                    ww.erase(j + 'A');
                    ans[i] = j + 'A';
                    break;
                }
            }
        }

        ans[0] = *(ww.begin());

        for(int i = 0; i < 10; i++){
            printf("%c", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}