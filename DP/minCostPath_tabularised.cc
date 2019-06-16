#include <iostream>
using namespace std ;


int minCostPath(int** arr , int r , int c){
	int** dp = new int*[r] ;
	for(int i=0 ; i<r ; ++i){
		dp[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			dp[i][j] = -1 ;
		}
	}
	dp[r-1][c-1] = arr[r-1][c-1] ;

	for(int i=c-2 ; i>=0 ; --i){
		dp[r-1][i] = arr[r-1][i] + dp[r-1][i+1] ;
	}
	for(int i=r-2 ; i>=0 ; --i){
		dp[i][c-1] = arr[i][c-1] + dp[i+1][c-1] ;
	}

	for(int currow = r-2 ; currow>=0 ; --currow){
		for(int curcol = c-2 ; curcol>=0 ; --curcol){
			dp[currow][curcol] = arr[currow][curcol] + min(dp[currow][curcol+1] , dp[currow+1][curcol] ) ;
		}
	}

	return dp[0][0] ;
}


int main(){
	int r,c ;
	cin >> r >> c ;

	int** arr = new int*[r] ;
	for(int i=0 ; i<r ; ++i){
		arr[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			cin >> arr[i][j] ;
		}
	}

	int ans = minCostPath(arr,r,c) ;
	cout << ans << endl ;
}