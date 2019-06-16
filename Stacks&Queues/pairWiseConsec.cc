#include <iostream>
#include <string>
#include <stack>
#include<vector>
#include <queue>
using namespace std ;

bool pairWiseConsec(stack<int> & s){
    bool ans = true ;
    int len = (int)s.size() ;
    stack<int> s2 ;
    if(len%2!=0){
        s2.push(s.top()) ;
        s.pop() ;
    }
    
    while(!s.empty()){
        int x = s.top() ;
        s.pop() ;
        s2.push(x) ;
        int y = s.top() ;
        s.pop() ;
        s2.push(y) ;
        
        int check = x-y ;
        if(check==-1 || check==1){
            continue ;
        } else {
            ans = false ;
        }
        
    }
    
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop() ;
    }
    
    
    return ans ;
}


int main(){
    
    stack<int> s ;
    int x ;
    int n ;
    cin >> n ;
    for(int i=0; i<n ; ++i){
        cin >> x ;
        s.push(x) ;
    }
    
    if(pairWiseConsec(s)){
        cout << "true" << endl ;
    } else cout << "false" << endl ;
}


