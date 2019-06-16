#include<iostream>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std ;

void firstNonRepChar(char* arr , int n){
    
    unordered_map<char, int> m ;
    queue<char> q ;
    
    for(int i=0 ; i<n ; ++i){
        char c = arr[i] ;
        if(m.count(c)>0){
            // already occured
            ++m[c] ;
            while(!q.empty() && m[q.front()]>1){
                q.pop() ;
            }
        } else {
            m[c] = 1 ;
            q.push(c) ;
        }
        
        if(q.empty()){
            cout << -1 << " " ;
        } else {
            cout << q.front() << " " ;
        }
    }
    
}

int main(){
    
    int n ;
    cin >> n ;
    char* arr = new char[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    
    firstNonRepChar(arr, n) ;
}




