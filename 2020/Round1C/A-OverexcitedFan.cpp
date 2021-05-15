#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ts = 1; ts <= t; ts++){
        printf("Case #%d: ", ts);
        string s;
        int x, y;
        cin >> x >> y >> s;

        if(x== 0 && y == 0){
            printf("0\n");
        }

        bool found = false;

        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }
            int cost = manhattan(0,0, x, y);
            if(cost <= i + 1){
                printf("%d\n", i + 1);
                found = true;
                break;
            }
        }
        if(!found)
            printf("IMPOSSIBLE\n");
    }
    return 0;
}