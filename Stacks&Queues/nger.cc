#include<iostream>
#include <stack>

using namespace std ;
void printArr(int* arr , int n){
    for(int i=0 ; i<n ; ++i){
        cout << arr[i] << endl ;
    }
}




void get_nser(int* arr , int n , int* nser){
    
    stack<int> s ;
    for(int i=n-1 ; i>=0 ; --i){
        while(s.empty() && arr[i] < s.top()){
            s.pop() ;
        }
        if(s.empty()){
            s.push(arr[n-1]) ;
            nser[i] = -1 ;
        } else {
            nser[i] = s.top() ;
            s.push(arr[n-1]) ;
        }
    }
    
}
void get_nger(int* arr , int n , int* nger){
    
    stack<int> s ;
    for(int i=n-1 ; i>=0 ; --i){
        
        while(!s.empty() && arr[i] > s.top()){
            s.pop() ;
        }
        if(s.empty()){
            nger[i] = -1 ;
            s.push(arr[i]) ;
        } else {
            nger[i] = s.top() ;
            s.push(arr[i]) ;
        }
    }
    
    
    
}


int main(){
    
    int n ;
    cin >> n  ;
    int * arr = new int[n] ;
    for(int i=0 ; i<n ;++i){
        cin >> arr[i] ;
    }
    int* nger = new int[n] ;
    get_nger(arr, n, nger) ;
    printArr(nger, n) ;
}
