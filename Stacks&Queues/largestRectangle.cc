#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
using namespace std ;

void get_nser(int* arr , int n , int* nser){
    
    stack<int> s ;
    nser[n-1] = n ;
    s.push(n-1) ;
    
    for(int i=n-2 ; i>=0 ; --i){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            s.pop() ;
        }
        
        if(s.empty()){
            nser[i] = n ;
            s.push(i) ;
        } else {
            nser[i] = s.top() ;
            s.push(i) ;
        }
    }
}
void get_nsel(int* arr , int n , int* nsel){
    
    stack<int> s ;
    nsel[0] = -1 ;
    s.push(0) ;
    for(int i=1 ; i<n ; ++i){
        while (s.empty()==false && arr[s.top()]>=arr[i]) {
            s.pop() ;
        }
        if(s.empty()){
            nsel[i] = -1 ;
            s.push(i) ;
        } else {
            nsel[i] = s.top() ;
            s.push(i) ;
        }
    }
    
}

int largestAreaHistogram(int* arr , int n){
    
    int* nsel = new int[n] ;
    int* nser = new int[n] ;
    
    get_nsel(arr,n,nsel) ;
    get_nser(arr,n,nser) ;
    
    int max = 0 ;
    for(int i=0 ; i<n ; ++i){
        int cur = 0 ;
        int r = nser[i] ;
        int l = nsel[i] ;
        cur = (r-l-1)*(arr[i]) ;
        if(cur>max) max = cur ;
    }
    return max ;
}





int maxRect(int** arr , int r , int c){
    
    int max = 0 ;
    int* hist = new int[c] ;
    for(int i=0 ; i<c ; ++i){
        hist[i] = 0 ;
    }
    for(int i=0 ; i<r ; ++i){
        
        // update histogram
        for(int j=0 ; j<c ; ++j){
            if(arr[i][j]==1){
                hist[j]+=1 ;
            } else if(arr[i][j]==0){
                hist[j] = 0 ;
            }
        }
        
        // find max rect area for this level
        int curmax = largestAreaHistogram(hist , c) ;
        if(curmax>max){
            max=curmax ;
        }
    }
    
    
    return max ;
    
}







int main(){
    
    int r,c ;
    cin >> r >> c ;
    int** arr = new int*[r] ;
    for(int i=0 ; i<r ; ++i){
        arr[i] = new int[c] ;
        for(int j=0 ; j<c ; ++j){
            cin >> arr[i][j] ;
        }
    }
    cout << maxRect(arr, r, c)<< endl ;
 }
