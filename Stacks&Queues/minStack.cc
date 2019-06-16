#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
using namespace std ;

class minStack{
    stack<int> s;
    int min = -1 ;
public:
    
    void push(int x){
        
        if(s.empty()){
            s.push(x) ;
            min = x ;
            return ;
        } else if(x>=min){
            s.push(x) ;
        } else if(x<min){
            s.push(2*x - min) ;
            min = x ;
        }
        
    }
    int top(){
        if(s.empty()) return -1 ;
        if(s.top()>=min) return s.top() ;
        else return min ;
    }
    
    int pop(){
        
        if(s.empty()) return -1 ;
        int ans = top() ;
        if(s.top()>=min){
            s.pop() ;
        } else {
            
            min = 2*min-s.top() ;
            s.pop() ;
        }
        
        return ans ;
    }
    int getMin(){ return min ;}
};





int main(){
    int n ;
    cin >> n ;
    int* a = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> a[i] ;
    }
    
    minStack ms ;
    
    for(int i=0 ; i<n ; ++i){
        if(a[i]==1){
            ms.push(a[i+1]) ;
            ++i ;
            continue ;
        } if(a[i]==2){
            cout << ms.pop() ;
        } if(a[i]==3){
            cout << ms.getMin() ;
        }
    }
    cout << endl ;
}




