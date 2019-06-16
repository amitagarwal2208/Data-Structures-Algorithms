#include <iostream>
#include <string>
#include <stack>
#include<vector>
#include <queue>
using namespace std ;

void remAdjDup(string & s){
    stack<char> stk ;
    while(s.empty() == false){
        if(stk.empty()){
            stk.push(s[0]) ;
        } else {
            char c = stk.top() ;
            if(s[0] == c){
                stk.pop() ;
            } else {
                stk.push(s[0]) ;
            }
        }
        s = s.substr(1) ;
    }
    
    while(stk.empty()==false){
        s = stk.top() + s ;
        stk.pop() ;
    }
    
}


int main(){
    
    string s ;
    cin >> s ;
    remAdjDup(s) ;
    cout << s << endl ;
}


