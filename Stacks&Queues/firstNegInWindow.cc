#include <iostream>

using namespace std ;

void firstNegInWin(int* arr , int n , int k){
    
    int j = 0 ;
    for(int i=0 ; i<n-k+1 ; ++i){
        if(j<i){
            j=i ;
        }
        
        while(j!=n && arr[j]>=0){
            ++j ;
        }
        
        if(j<=i+k-1){
            cout << arr[j] << " " ;
        } else cout << 0 << " " ;
    }
    cout << endl ;
    
}

int main(){
    int n ;
    cin >> n ;
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    int k ;
    cin >> k ;
    firstNegInWin(arr, n, k) ;
}
