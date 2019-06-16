#include<iostream>
#include<algorithm>
using namespace std ;


#define inf 1e5 ;

int minCostPath(int** arr , int xdest , int ydest , int xsrc , int ysrc , int** dp){


	if(xsrc>xdest || ysrc>ydest){
		return INT_MAX ;
	}

	if(xsrc==xdest && ysrc==ydest){
		return arr[xdest][ydest] ;
	}

	if(dp[xsrc][ysrc]!=-1){
		return dp[xsrc][ysrc] ;
	}


	int minCost_ir = minCostPath(arr,xdest,ydest, xsrc , ysrc+1 , dp) ;

	int minCost_id = minCostPath(arr,xdest,ydest, xsrc+1 , ysrc , dp) ;

	int curans = arr[xsrc][ysrc] + min(minCost_ir , minCost_id ) ;
	dp[xsrc][ysrc] = curans ;
	return curans ; 

}



int minCostPath(int** arr , int r , int c){

	int** dp = new int*[r] ;
	for(int i=0 ; i<r ; ++i){
		dp[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			dp[i][j] = -1 ;
		}
	}
	dp[r-1][c-1] = arr[r-1][c-1] ;

	return minCostPath(arr,r-1,c-1,0,0,dp) ;

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