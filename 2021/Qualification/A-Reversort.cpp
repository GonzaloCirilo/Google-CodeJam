#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int ts;
    scanf("%d", &ts);
    for(int t = 0; t < ts; t++){
        printf("Case #%d: ", t + 1);
        int n; 
        scanf("%d", &n);
        vector<int> arr = vector<int>(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            int minValue = 99999, indx = 0;
            for(int j = i; j < arr.size(); j++){
                if(minValue > arr[j]){
                    minValue = arr[j];
                    indx = j;
                }
            }
            //printf("== %d %d\n", i, indx);
            reverse(arr.begin() + i, arr.begin() + indx + 1);
            ans += indx - i + 1;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}