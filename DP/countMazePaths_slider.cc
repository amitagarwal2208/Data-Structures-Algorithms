#include <iostream>
using namespace std ;




int countMazePaths(int n){

	int** dp = new int*[2] ;
	for(int i=0 ; i<2 ; ++i){
		dp[i] = new int[n] ;
	}

	for(int i=0 ; i<n ; ++i){
		dp[1][i] = 1 ;
	}
	dp[0][n-1] = 1 ;
	int cur = 0 ;

	for(int ct=0 ; ct<n-1 ; ++ct){
		for(int i=n-2 ; i>=0 ; --i){
			dp[cur][i] = dp[cur][i+1] + dp[1-cur][i] ;
		}
		cur = 1-cur ;
	}
	return dp[1-cur][0] ;
}



int main(){
	int n ;
	cin >> n ;

	int ans = countMazePaths(n) ;
	cout << ans << endl ;
}