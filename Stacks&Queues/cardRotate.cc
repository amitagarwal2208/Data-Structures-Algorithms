#include<iostream>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std ;

void cardRot(int n){
    
    unordered_map<int, int> m ;
    queue<int> q ;
    for(int i=1 ; i<=n ; ++i){
        q.push(i) ;
    }
    int k = 1 ;
    while(!q.empty()){
        
        int n = (int)q.size() ;
        int s = k%n ;
        while(s--){
            int tmp = q.front() ;
            q.pop() ;
            q.push(tmp) ;
        }
        
        int cur = q.front() ;
        q.pop() ;
        
        m[cur] = k ;
        
        ++k ;
    }
    for(int i=1 ; i<=n ; ++i){
        cout << m[i] << " " ;
    }
    cout << endl ;
    
}

int main(){
    
    int n ;
    cin >> n ;
    cardRot(n) ;
    
    
    
}




