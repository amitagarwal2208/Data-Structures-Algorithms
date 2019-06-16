#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
using namespace std ;

int celeb(int** arr , int n){
    
    stack<int> s ;
    for(int i=0 ; i<n ; ++i){
        s.push(i) ;
    }
    
    while(s.empty()==false && s.size()>=2){
        int x = s.top() ;
        s.pop() ;
        int y = s.top() ;
        s.pop() ;
        
        if(arr[x][y]){
            // x knows y
            // x cannot be a celeb
            // y can be a celeb
            
            s.push(y) ;
        } else {
            // x does not know y
            // y cannot be a celeb
            // x can be
            s.push(x) ;
        }
    }
    int poss = -1 ;
    if(s.empty()){
        return -1 ;
    } else if(s.size()==1) {
        poss = s.top() ;
        for(int i=0 ; i<n ; ++i){
            if(i==poss){
                continue ;
            }
            if(arr[i][poss]==0 || arr[poss][i]==1){
                return -1 ;
            }
        }
    }
    return poss ;
}

int main(){
    int n ;
    cin >> n ;
    int** arr = new int*[n] ;
    for(int i=0 ; i<n ; ++i){
        arr[i] = new int[n] ;
        for(int j=0 ; j<n ; ++j){
            cin >> arr[i][j] ;
        }
    }
    cout << celeb(arr, n) << endl ;
}






