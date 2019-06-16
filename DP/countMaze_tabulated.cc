#include<iostream>
using namespace std ;

void PrintDP(int** dp , int n){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			cout << dp[i][j] << " " ;
		}
		cout << endl ;
	}
}
int countMazePaths(int n){


	int** dp = new int*[n] ;
	for(int i=0 ; i<n ; ++i){
		dp[i] = new int[n] ;
	}


	dp[n-1][n-1] = 1 ;
	for(int i=0 ; i<n ; ++i){
		dp[n-1][i] = 1 ;
		dp[i][n-1] = 1 ;
	}

	for(int r=n-2 ; r>=0 ; --r){
		for(int c=n-2 ; c>=0 ; --c){
			dp[r][c] = dp[r][c+1] + dp[r+1][c] ;
		}
	}
	// cout << endl ;
	// PrintDP(dp,n) ;
	// cout << endl ;
	return dp[0][0] ;

}

int main(){

	int n ;
	cin >> n ;

	int ans = countMazePaths(n) ;
	cout << ans << endl ;

}








