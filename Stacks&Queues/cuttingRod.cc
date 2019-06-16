#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
#include<vector>


using namespace std ;



int main(){
    int n ;
    cin >> n ;
    priority_queue<int , vector<int> , greater<int> > pq ;
    for(int i=0 ; i<n ; ++i){
        int x ;
        cin >> x ;
        pq.push(x) ;
    }
    int cost = 0 ;
    while(pq.size()>1){
        int x = pq.top() ;
        pq.pop() ;
        int y = pq.top() ;
        pq.pop() ;
        cost+=x+y ;
        pq.push(x+y) ;
    }
    cout << cost << endl ;
    
}






