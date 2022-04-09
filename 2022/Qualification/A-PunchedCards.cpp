#include <iostream>
#include <string>

using namespace std;

void printIntermidiate(int ind, int size) {
    string s;
    for(int i = 0; i < size * 2; i += 2) {
        if (ind == 0 && i == 0){
            s += "..";
        }else{
            s += "+-";
        }
    }
    s += "+";
    cout << s << endl;
}

void printContentLine(int ind, int size) {
    string s;
    for(int i = 0; i < size * 2; i += 2) {
        if (ind == 0 && i == 0){
            s += "..";
        }else{
            s += "|.";
        }
    }
    s += "|";
    cout << s << endl;
}

void solve(){
    int r, c; 
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        printIntermidiate(i, c);
        printContentLine(i, c);
    }
    printIntermidiate(r, c);
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ":" << endl;
        solve();
    }
    return 0;
}