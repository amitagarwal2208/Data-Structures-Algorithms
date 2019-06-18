#include <iostream>
#include<queue>
#include <iomanip>
#include <vector>
#include<algorithm>

using namespace std;


int ctPairTargetSum(int* arr , int n , int k){
    
    //Duplicacy allowed
    sort(arr,arr+n) ;
    int start = 0 ;
    int end = n-1 ;
    int ct = 0 ;
    while(start < end){
        if(arr[start]+arr[end]==k){
            ++ct ;
            ++start ;
            --end ;
        } else if(arr[start]+arr[end]<k){
            ++start ;
        } else {
            --end ;
        }
    }
    return ct ;
    
}


vector<vector<int>> printPairTargetSum(int* arr , int n , int k){
    
    
    sort(arr,arr+n) ;
    
    vector<vector<int>> ans ;
    int start = 0 ;
    int end = n-1 ;
    while(start<end){
        if(arr[start]+arr[end]==k){
            vector<int> v ;
            v.push_back(arr[start]) ;
            v.push_back(arr[end]) ;
            ans.push_back(v) ;
            ++start ;
            --end ;
        }
        else if(arr[start]+arr[end]<k){
            ++start ;
        } else {
            --end ;
        }
    }
    
    
    return ans ;
}




int main() {
    // Find pair - Duplicacy allowed
    int n ,k;
    cin >> n >> k;
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    cout << ctPairTargetSum(arr, n, k) << endl ;
    
    vector<vector<int>> ans = printPairTargetSum(arr, n, k) ;
    for(int i=0 ; i<ans.size() ; ++i){
        for(int j=0 ; j<2 ; ++j){
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
    
    return 0;
}

//Input
//7 11
//2 9 3 5 6 11 4
//
//
//Output
//2
//2 9
//5 6





