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

int ctTripletTargetSum(int* arr , int n , int k){
    int ct=0 ;
    sort(arr,arr+n) ;
    for(int i=0 ; i<n ; ++i){
        int sum = k-arr[i] ;
        int end = n-1 ;
        int start = i ;
        incStart(arr,n,start) ;
        while(start<end){
            int cursum = arr[start]+arr[end] ;
            if(cursum==sum){
                ++ct ;
                incStart(arr,n,start) ;
                decEnd(arr,n,end) ;
            } else if(cursum<sum){
                incStart(arr,n,start) ;
            } else decEnd(arr,n,end) ;
        }
    }
    
    return ct ;
}


vector<vector<int>> printTripletTargetSum(int* arr , int n , int k){
    
    
    sort(arr,arr+n) ;
    
    vector<vector<int>> ans ;
    for(int i=0 ; i<n ; ++i){
        int sum = k-arr[i] ;
        int end = n-1 ;
        int start = i ;
        incStart(arr,n,start) ;
        while(start<end){
            int cursum = arr[start]+arr[end] ;
            if(cursum==sum){
                vector<int> v ;
                v.push_back(arr[i]) ;
                v.push_back(arr[start]) ;
                v.push_back(arr[end]) ;
                ans.push_back(v) ;
                incStart(arr,n,start) ;
                decEnd(arr,n,end) ;
            } else if(cursum<sum){
                incStart(arr,n,start) ;
            } else decEnd(arr,n,end) ;
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
    cout << ctTripletTargetSum(arr, n, k) << endl ;
    
    vector<vector<int>> ans = printTripletTargetSum(arr, n, k) ;
    for(int i=0 ; i<ans.size() ; ++i){
        for(int j=0 ; j<3 ; ++j){
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
    
    return 0;
}

//8 11
//2 3 4 5 6 7 8 9
//2
//2 3 6
//2 4 5





