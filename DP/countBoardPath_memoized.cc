#include <iostream>
using namespace std ;


int CountBoardPaths(int src , int dest , int* dp){

	if(src>dest){
		return 0 ;
	}

	else if(src==dest){
		return 1 ;
	}
	else if(dp[src]!=-1){
		// Already calculated.
		return dp[src] ;
	}


    int ct=0 ;

	for(int dice=1 ; dice<=6 ; ++dice){
		ct+=CountBoardPaths(src+dice , dest , dp) ;
	}

	dp[src] = ct ;
	return ct ;
}


int CountPaths(int n){
	int* dp = new int[n+1] ;
	
	for(int i=0 ; i<n+1 ; ++i){
		dp[i] = -1 ;
	}
	dp[n] = 1 ;
	return CountBoardPaths(0,n,dp) ;
}


int main(){
	int n ;
	cin >> n ;

	int ans = CountPaths(n) ;
	cout << ans << endl ;
}