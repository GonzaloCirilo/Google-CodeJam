#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int ts;
    cin >> ts;
    for(int t = 0; t < ts; t++){
        cout << "Case #" << t + 1 << ": ";
        int x, y; string s;
        cin >> x >> y >> s;

        vector<int> indexes;
        string aux;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '?'){
                aux.push_back(s[i]);
            }
        }
        int currentAns = 0;
        for(int i = 0; i < aux.size(); i++){
            switch(aux[i]){
                case 'C':
                    if(i + 1 < aux.size() && aux[i + 1] == 'J'){
                        currentAns += x;
                    }
                    break;
                case 'J':
                    if(i + 1 < aux.size() && aux[i + 1] == 'C'){
                        currentAns += y;
                    }
                    break;
            }
        }
        cout << currentAns << endl;
        
        
    }
    
    return 0;
}