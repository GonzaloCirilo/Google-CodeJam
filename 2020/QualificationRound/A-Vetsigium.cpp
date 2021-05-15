#include <stdio.h>

int main(){
    int t, n, matrix[102][102];

    scanf("%d", &t);
    for(int ts = 1; ts <= t; ts++){
        printf("Case #%d: ", ts);
        scanf("%d", &n);
        int sum = 0;

        int repeatedCol = 0, repeatedRow = 0;

        for(int i = 0; i < n; i++){
            int visited [102] = {}; bool isRepeated = false;
            for(int j = 0; j < n; j++){
                scanf("%d", &matrix[i][j]);
                if(i == j)
                    sum += matrix[i][j];

                if(!visited[matrix[i][j]])
                    visited[matrix[i][j]] = 1;
                else{
                    isRepeated = true;
                }
            }
            if(isRepeated)
                repeatedRow++;
        }



        for(int i = 0; i < n; i++){
            int visited [102] = {}; bool isRepeated = false;
            for(int j = 0; j < n; j++){

                if(!visited[matrix[j][i]])
                    visited[matrix[j][i]] = 1;
                else{
                    isRepeated = true;
                }
            }
            if(isRepeated)
                repeatedCol++;
        }

        printf("%d %d %d\n", sum, repeatedRow, repeatedCol);
    }
    return 0;
}