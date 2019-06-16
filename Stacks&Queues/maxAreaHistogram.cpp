#include<iostream>
#include <stack>

using namespace std ;
void printArr(int* arr , int n){
    for(int i=0 ; i<n ; ++i){
        cout << arr[i] << endl ;
    }
    
}

void get_nsel(int* arr , int n , int* nsel){
    
    stack<int> s ;
    for(int i=0 ; i<n ; ++i){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop() ;
        }
        if(s.empty()){
            nsel[i] = -1 ;
        } else {
            nsel[i] = s.top() ;
        }
        
        s.push(i) ;
    }
    
}


void get_nser(int* arr , int n , int *nser){
    
    stack<int> s ;
    for(int i=n-1 ; i>=0 ; --i){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop() ;
        }
        if(s.empty()){
            nser[i] = n ;
        } else {
            nser[i] = s.top() ;
        }
        
        s.push(i) ;
    }
    
}



int maxArea(int* arr , int n){
    int max = 0 ;
    int* nser = new int[n] ;
    int* nsel = new int[n] ;
    
    get_nser(arr, n, nser) ;
    get_nsel(arr, n , nsel) ;
    
    for(int i=0 ; i<n ; ++i){
        int cur = arr[i]*(nser[i]-nsel[i]-1) ;
        if(cur>max){
            max = cur ;
        }
    }
    
    return max ;
}
int main(){
    
    int n ;
    cin >> n  ;
    int * arr = new int[n] ;
    for(int i=0 ; i<n ;++i){
        cin >> arr[i] ;
    }
    int ans = maxArea(arr, n) ;
    cout << ans << endl ;
   
}
