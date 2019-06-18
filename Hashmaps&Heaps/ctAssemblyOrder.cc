#include <iostream>
#include <unordered_map>
using namespace std ;

void printMovts(int* arr , int n){
    
    unordered_map<int, int> m ;
    for(int i=1 ; i<=n ; ++i){
        m[i] = 0 ;
    }
    int max = 0 ;
    int kid = -1 ;
    for(int i=0 ; i<n ; ++i){
        int cur = arr[i] ;
        if(m.count(cur-1)>0){
            m[cur] = m[cur-1] + 1 ;
        } else {
            m[cur] = 1 ;
        }
        if(max<m[cur]) {
            max = m[cur] ;
            kid = cur ;
        }
    }
    
    int alreadySorted = max ;
    int toBeSorted = n-max ;
    cout << toBeSorted << endl ;
    int maxkid = kid ;
    int minkid = maxkid - alreadySorted +1 ;
    for(int curkid = minkid-1 ; curkid>=1 ; --curkid){
        cout << "Send " << curkid << " to front" << endl ;
    }
    for(int curkid = maxkid+1 ; curkid<=n ; ++curkid){
        cout << "Send " << curkid << " to back" << endl ;
    }
    
    
}




int main(){
    int n ;
    cin >> n ;
    
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    
    printMovts(arr,n) ;
}
