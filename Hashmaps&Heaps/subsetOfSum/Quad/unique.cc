#include <iostream>
#include<queue>
#include <iomanip>
#include <vector>
#include<algorithm>

using namespace std;

void incStart(long long int* arr , int n , int & start){
    
    while(start<n-1 && arr[start]==arr[start+1]){
        ++start ;
    }
    ++start ;
}

void decEnd(long long int* arr , int n , int & end){
    while(end>0 && arr[end]==arr[end-1]){
        --end ;
    }
    --end ;
}
int ctQuadTargetSum(long long int* arr , int n , long long int k){
    int ct = 0 ;
    sort(arr,arr+n) ;
    for(int i=0 ; i<n ; ++i){
        long long int sum1 = k-arr[i] ;
        for(int j=i+1 ; j<n ; ++j){
            long long int sum = sum1 - arr[j] ;
            int start = j+1 ;
            int end = n-1 ;
            while(start<end){
                long long int cursum = arr[start]+arr[end] ;
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





vector<vector<long long int>> printQuadTargetSum(long long int* arr , int n , long long int k){
    
    
    sort(arr,arr+n) ;
    
    vector<vector<long long int>> ans ;
    
    int i=0 ;
    while(i<n){
        long long int sum1 = k - arr[i] ;
        int j=i+1 ;
        //incStart(arr,n,j) ;
        while(j<n){
            long long int sum = sum1 - arr[j] ;
            int start = j;
            int end = n-1 ;
            //incStart(arr,n,start) ;
            ++start ;
            while(start<end){
                
                
                long long int cursum = arr[start] + arr[end] ;
                
                
                if(cursum==sum){
                    //cout << sum1 << endl ;
                    vector<long long int> v ;
                    v.push_back(arr[i]) ;
                    v.push_back(arr[j]) ;
                    v.push_back(arr[start]) ;
                    v.push_back(arr[end]) ;
                    ans.push_back(v) ;
                    incStart(arr,n,start) ;
                    decEnd(arr,n,end) ;
                } else if(cursum<sum){
                    incStart(arr,n,start) ;
                } else {
                    decEnd(arr,n,end) ;
                }
            }
            incStart(arr, n, j) ;
        }
        incStart(arr, n, i) ;
    }
    
    return ans ;
}




int main() {
    // Find pair - Duplicacy not allowed
    // Count and return only unique Pairs
    int t ;
    cin >> t ;
    while(t--){
        long long int n ,k;
        cin >> n >> k;
        long long int* arr = new long long int[n] ;
        for(int i=0 ; i<n ; ++i){
            cin >> arr[i] ;
        }
        //cout << ctQuadTargetSum(arr, n, k) << endl ;
        vector<vector<long long int>> ans = printQuadTargetSum(arr, n, k) ;
        if(ans.size()==0){
            cout << -1 << endl ;
            //continue ;
        } else {
            for(long long int i=0 ; i<ans.size() ; ++i){
                for(int j=0 ; j<4 ; ++j){
                    cout << ans[i][j] << " " ;
                }
                cout << "$" ;
            }}
    }
    return 0;
}







