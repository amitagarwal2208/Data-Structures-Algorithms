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
int ctQuadTargetSum(int* arr , int n , int k){
    int ct = 0 ;
    sort(arr,arr+n) ;
    for(int i=0 ; i<n ; ++i){
        int sum1 = k-arr[i] ;
        for(int j=i+1 ; j<n ; ++j){
            int sum = sum1 - arr[j] ;
            int start = j+1 ;
            int end = n-1 ;
            while(start<end){
                int cursum = arr[start]+arr[end] ;
                if(cursum==sum){
                    ++ct ;
                    ++start ;
                    --end ;
                } else if(cursum<sum){
                    ++start ;
                } else --end ;
            }
        }
    }
    return ct ;
}





vector<vector<int>> printQuadTargetSum(int* arr , int n , int k){
    
    
    sort(arr,arr+n) ;
    
    vector<vector<int>> ans ;
    
    
    for(int i=0 ; i<n ; ++i){
        int sum1 = k-arr[i] ;
        for(int j=i+1 ; j<n ; ++j){
            int sum = sum1 - arr[j] ;
            int start = j+1 ;
            int end = n-1 ;
            while(start<end){
                int cursum = arr[start] + arr[end] ;
                if(cursum==sum){
                    vector<int> v ;
                    v.push_back(arr[i]) ;
                    v.push_back(arr[j]) ;
                    v.push_back(arr[start]) ;
                    v.push_back(arr[end]) ;
                    ans.push_back(v) ;
                    ++start ;
                    --end ;
                } else if(cursum<sum){
                    ++start ;
                } else {
                    --end ;
                }
            }
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
    cout << ctQuadTargetSum(arr, n, k) << endl ;
    
    vector<vector<int>> ans = printQuadTargetSum(arr, n, k) ;
    for(int i=0 ; i<ans.size() ; ++i){
        for(int j=0 ; j<4 ; ++j){
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
    
    return 0;
}






