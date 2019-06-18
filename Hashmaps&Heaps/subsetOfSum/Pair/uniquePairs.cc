#include <iostream>
#include<queue>
#include <iomanip>
#include <vector>
#include<algorithm>

using namespace std;

void incStart(int* arr , int n , int & start){
    
    while(start<n-1 && arr[start]==arr[start+1]){
        ++start ;
    }
    ++start ;
}

void decEnd(int* arr , int n , int & end){
    while(end>0 && arr[end]==arr[end-1]){
        --end ;
    }
    --end ;
}


int ctUniquePairTargetSum(int* arr , int n , int k){
    
    //Duplicacy not allowed
    sort(arr,arr+n) ;
    int start = 0 ;
    int end = n-1 ;
    int ct = 0 ;
    while(start < end){
        int cursum = arr[start] + arr[end] ;
        if(cursum==k){
            ++ct ;
            incStart(arr,n,start) ;
            decEnd(arr,n,end) ;
        } else if(cursum<k){
            incStart(arr,n,start) ;
        } else {
            decEnd(arr,n,end) ;
        }
        
        
        
    }
    return ct ;
    
}


vector<vector<int>> printUniquePairTargetSum(int* arr , int n , int k){
    
    
    sort(arr,arr+n) ;
    
    vector<vector<int>> ans ;
    int start = 0 ;
    int end = n-1 ;
    while(start<end){
        int cursum = arr[start]+arr[end] ;
        if(cursum==k){
            vector<int> v ;
            v.push_back(arr[start]) ;
            v.push_back(arr[end]) ;
            ans.push_back(v) ;
            
            incStart(arr,n,start) ;
            decEnd(arr,n,end) ;
        } else if(cursum<k){
            incStart(arr,n,start) ;
        } else {
            decEnd(arr,n,end) ;
        }
    }
    
    
    return ans ;
}




int main() {
    // Find pair - Duplicacy not allowed
    // Count and return only unique Pairs
    int n ,k;
    cin >> n >> k;
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    cout << ctUniquePairTargetSum(arr, n, k) << endl ;
    
    vector<vector<int>> ans = printUniquePairTargetSum(arr, n, k) ;
    for(int i=0 ; i<ans.size() ; ++i){
        for(int j=0 ; j<2 ; ++j){
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
    
    return 0;
}

//13 8
//2 2 3 4 4 5 5 5 6 6 7 7 7
//3
//2 6
//3 5
//4 4 





