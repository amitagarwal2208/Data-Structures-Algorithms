#include <iostream>
#include <string>
#include <stack>
#include<vector>
#include <queue>
using namespace std ;



int main(){
    int n ;
    cin >> n ;
    int x ;
    queue<int> q ;
    for(int i=0 ; i<n ; ++i){
        cin >> x ;
        if(!q.empty()){
            q.push(x) ;
            while(q.front()<(x-3000)){
                q.pop() ;
            }
            cout << q.size() << " " ;
        } else {
            q.push(x) ;
            cout << 1 << " " ;
        }
    }
    
    
    
}

//6
//15
//61
//34
//24
//79
//57
//60
//20
//10
//73
//61
//68

