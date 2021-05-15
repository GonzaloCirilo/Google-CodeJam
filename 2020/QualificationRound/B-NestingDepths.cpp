#include <stdio.h>

int main(){
    int t, d;
    scanf("%d\n", &t);
    for(int ts = 1; ts <= t; ts++){
        printf("Case #%d: ", ts);
        char c = ' '; int open = 0;
        while(true){
            c = getchar();
            if(c == '\n'|| c == EOF){
                for(int i = 0; i < open; i++){
                    putchar(')');
                }
                break;
            }
            int aux = c - '0';
            if(aux > open){
                for(int i = 0; i < aux - open; i++){
                    putchar('(');
                }
                open = aux;

            }
            if(aux < open){
                for(int i = 0; i < open - aux; i++){
                    putchar(')');
                }
                open = aux;
            }
            putchar(c);
        }
        putchar('\n');
    }
    return 0;
}