#include <iostream>
using namespace std ;

void PrintDP(int** dp , int n){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			cout << dp[i][j] << " " ;
		}
		cout << endl ;
	}
}

int CountPaths(int xsrc , int ysrc , int xdest , int ydest , int** dp){

	if(xsrc>xdest || ysrc>ydest){
		return 0 ;
	}
	

	if(xsrc==xdest && ysrc==ydest){
		return 1 ;
	}

	if(dp[xsrc][ysrc] != -1){
		return dp[xsrc][ysrc] ;
	}

	// left movt.
	int poss1 = CountPaths(xsrc , ysrc+1 , xdest , ydest,dp) ;

	// down movt.
	int poss2 = CountPaths(xsrc+1 , ysrc , xdest , ydest,dp) ;


	int curans = poss1 + poss2 ;
	dp[xsrc][ysrc] = curans ;
	return curans ;

}



int CountMazePaths(int n){

	int** dp = new int*[n] ;
	for(int i=0 ; i<n ; ++i){
		dp[i] = new int[n] ;
		for(int j=0 ; j<n ; ++j){
			dp[i][j] = -1 ;
		}
	}
	dp[n-1][n-1] = 1 ;

	int ans = CountPaths(0,0,n-1,n-1 , dp) ;

//PrintDP(dp,n) ;

	return ans ;
}



int main(){
	int n ;
	cin >> n ;

	// n X n matrix
	// Only right and down movements allowed

	// Calculate paths from (0,0) to (n-1,n-1)

	int ans = CountMazePaths(n) ;
	cout << ans << endl ;

}