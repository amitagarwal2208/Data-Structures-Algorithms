#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
using namespace std ;

void kRevQ(queue<int> & q , int n , int k){
    k = k%n ;
    stack<int> s ;
    for(int i=0 ; i<k ; ++i){
        if(q.empty()==false){
            s.push(q.front()) ;
            q.pop() ;
        }
    }
    while(!s.empty()){
        q.push(s.top()) ;
        s.pop() ;
    }
    
    for(int i=0 ; i<n-k ; ++i){
        q.push(q.front()) ;
        q.pop() ;
    }
}
void printQ(queue<int> q){
    while(q.empty()==false){
        cout << q.front() << " " ;
        q.pop() ;
    }
}

int main(){
    int n,k ;
    cin >> n >> k ;
    queue<int> q ;
    int x ;
    for(int i=0 ; i<n ; ++i){
        cin >> x;
        q.push(x) ;
    }
    kRevQ(q, n, k) ;
    printQ(q) ;
}






