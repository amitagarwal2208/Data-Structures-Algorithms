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

class kStack{
    
    int *data , *next , *tos ;
    int free ;
    
public:
    
    kStack(int n , int k){
        data = new int[n] ;
        next = new int[n] ;
        tos = new int[k] ;
        
        // initialize
        free = 0 ;
        for(int i=0 ; i<n ; ++i){
            data[i] = 0 ;
            next[i] = i+1 ;
        }
        next[n-1] = -1 ;
        for(int i=0 ; i<k ; ++i){
            tos[i] = -1 ;
        }
    }
    
    void push(int curstk , int val){
        
        if(isFull()) return ;
        
        int idx = free ;
        free = next[free] ;
        
        next[idx] = tos[curstk] ;
        tos[curstk] = idx ;
        
        data[idx] = val ;
        
    }
    
    void pop(int curstk){
        if(isEmpty(curstk)) return ;
        
        int idx = tos[curstk] ;
        tos[curstk] = next[idx] ;
        
        next[free] = idx ;
        free = idx ;
    }
    
    int top(int curstk){
        if(isEmpty(curstk)) return -1 ;
        
        int idx = tos[curstk] ;
        return data[idx] ;
    }
    
    bool isEmpty(int curstk){
        return (tos[curstk]==-1) ;
    }
    bool isFull(){
        return (free==-1) ;
    }
    
    
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






