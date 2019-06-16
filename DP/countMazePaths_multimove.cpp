#include <iostream>
using namespace std ;


int CountMazePaths_multimove(int curx , int cury , int n , int** dp){

	int maxx = n-1 ;
	int maxy = n-1 ;

	if(curx>maxx || cury>maxy){
		return 0 ;
	}

	if(curx==maxx && cury==maxy){
		return 1 ;
	}

	if(dp[curx][cury]!=-1){
		return dp[curx][cury] ;
	}

	int curans = 0 ;

	//Horizontal moves
	for(int step=1 ; step<=maxy-cury ; ++step){
		curans+=CountMazePaths_multimove(curx,cury+step,n,dp) ;
	}

	//Vertical moves
	for(int step=1 ; step<=maxx-curx ; ++step){
		curans+=CountMazePaths_multimove(curx+step,cury,n,dp) ;
	}

	//Diagonal moves
	for(int step=1 ; step<=min(maxx-curx,maxy-cury) ; ++step){
		curans+=CountMazePaths_multimove(curx+step,cury+step,n,dp) ;
	}

	dp[curx][cury] = curans ;
	return curans ;

}




void PrintDP(int** dp , int n){

	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			cout << dp[i][j] << " " ;
		}
		cout << endl ;
	}
}


int CountMazePaths_multimove(int n){


	int **dp = new int*[n];
	for(int i=0 ; i<n ; ++i){
		dp[i] = new int[n] ;
		for(int j=0 ; j<n ; ++j){
			dp[i][j] = -1 ;
		}
	}

	dp[n-1][n-1] = 1 ;

	int ans = CountMazePaths_multimove(0,0,n,dp) ;

	PrintDP(dp,n) ;
	return ans ;
}



int main(){

	int n ;
	cin >> n ; 
	int ans = CountMazePaths_multimove(n) ;
	cout << ans << endl ;

}