#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
#include<vector>
using namespace std ;


int minTime(char* arr , int n , int k){
    priority_queue<int> pq ;
    unordered_map<char, int> m ;
    for(int i=0 ; i<n ; ++i){
        if(m.count(arr[i])>0){
            ++m[arr[i]] ;
        } else {
            m[arr[i]] = 1 ;
        }
    }
    
    unordered_map<char, int>::iterator it ;
    for(it=m.begin() ; it!=m.end() ; ++it){
        pq.push(it->second) ;
    }
    int ans = 0 ;
    queue<int> q ;
    //cout << pq.top() << endl ;
    while(true){
        //cout << pq.size() << endl ;
        if(pq.top()==1){
            break ;
        }
        
        for(int i=0 ; i<k+1 ; ++i){
            if(pq.empty()==false){
                q.push(pq.top()-1) ;
                pq.pop() ;
            }
            ++ans ;
            
        }
        
        while(q.empty()==false){
            if(q.front()!=0) pq.push(q.front()) ;
            q.pop() ;
        }
        
        
    }
    ans+=pq.size() ;
    return ans ;
}


int main(){
    
    int k , n ;
    cin >>k >>n ;
    char* task = new char[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> task[i] ;
    }
    
    cout << minTime(task, n, k) << endl ;
    
    
}






