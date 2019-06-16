#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std ;


int coinChangePerm(int* denoms , int n , int amt , vector<int> & dp){
    
    if(amt<0){
        return 0 ;
    }
    
    if(dp[amt] != -1){
        return dp[amt] ;
    }
    
    int curans = 0 ;
    for(int i=0 ; i<n ; ++i){
        int curd = denoms[i] ;
        curans+=coinChangePerm(denoms, n, amt-curd, dp) ;
    }
    dp[amt] = curans ;
    return  curans ;
    
}


int coinChangePerm(int* denoms , int n , int amt){
    vector<int> dp(amt+1 , -1) ;
    dp[0] = 1 ;
    return coinChangePerm(denoms, n, amt , dp) ;
    
}



int main(){
    
    int n ;
    cin >> n ;
    
    int* denoms = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> denoms[i] ;
    }
    
    int amt ;
    cin >> amt ;
    
    int ans = coinChangePerm(denoms, n, amt) ;
    cout << ans << endl ;
    
    
}
