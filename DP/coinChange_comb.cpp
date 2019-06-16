#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std ;

int coinChangeComb(int* denoms , int n,int amt , vector<vector<int> > & dp , int start){
    
    
    if(start>=n){
        return 0 ;
    }
    
    if(amt<0){
        return 0 ;
    }
    
    if(amt==0){
        return 1 ;
    }
    
    if(dp[start][amt] != -1){
        return dp[start][amt] ;
    }
    
    int curans = 0 ;
    for(int i=start ; i<n ; ++i){
        curans+=coinChangeComb(denoms, n, amt-denoms[i], dp, i) ;
    }
    
    dp[start][amt] = curans ;
    return curans ;
    
}

int coinChangeComb(int* denoms , int n,int amt){
    
    vector<vector<int> > dp(n,vector<int>(amt+1 , -1)) ;
    
    return coinChangeComb(denoms, n, amt, dp,0) ;
    
    
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
    
    int ans = coinChangeComb(denoms, n, amt) ;
    cout << ans << endl ;
    
    
}
