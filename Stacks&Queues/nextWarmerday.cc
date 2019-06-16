#include<iostream>
#include <stack>

using namespace std ;
void printArr(int* arr , int n){
    for(int i=0 ; i<n ; ++i){
        cout << arr[i] << endl ;
    }
    
}


void nextWarmerDay(int* arr , int n){
    
    int* nger = new int[n] ;
    
    stack<int> s ;
    
    for(int i=n-1 ; i>=0 ; --i){
        while(!s.empty() && arr[s.top()]<=arr[i] ){
            s.pop() ;
        }
        
        if(s.empty()){
            nger[i] = -1 ;
            s.push(i) ;
        } else {
            nger[i] = s.top() ;
            s.push(i) ;
        }
    }
    int* nwd = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        if(nger[i]==-1){
            nwd[i] = 0 ;
        } else {
            nwd[i] = nger[i] - i ;
        }
    }
    printArr(nwd, n) ;
    
    
    
    
}

int main(){
    
    int n ;
    cin >> n  ;
    int * arr = new int[n] ;
    for(int i=0 ; i<n ;++i){
        cin >> arr[i] ;
    }
    
    nextWarmerDay(arr, n) ;
}
