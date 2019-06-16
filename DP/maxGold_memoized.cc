#include<iostream>
using namespace std ;


int maxGold(int** arr , int xsrc , int ysrc , int r , int c , int** dp){

	if(xsrc<0 || xsrc>r-1){
		return 0 ;
	}

	if(dp[xsrc][ysrc] != -1){
		return dp[xsrc][ysrc] ;
	}

	int poss1 = maxGold(arr,xsrc-1,ysrc+1,r,c,dp) ;
	int poss2 = maxGold(arr,xsrc,ysrc+1,r,c,dp) ;
	int poss3 = maxGold(arr,xsrc+1,ysrc+1,r,c,dp) ;

	int curans = arr[xsrc][ysrc] + max(poss1,max(poss2,poss3)) ;
	dp[xsrc][ysrc] = curans ;
	return curans ;
}



int maxGold(int** arr , int r , int c){
	int** dp = new int*[r] ;
	for(int i=0 ; i<r ; ++i){
		dp[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			dp[i][j] = -1 ;
		}
	}
	for(int row=0 ;row<r;++row){
		dp[row][c-1] = arr[row][c-1] ;
	}

	for(int row=0 ; row<r ; ++row){
		int temp = maxGold(arr,row,0,r,c,dp) ;
	}

	int max=0 ;
	for(int row=0 ; row<r;++row){
		if(dp[row][0]>max){
			max = dp[row][0] ;
		}
	}
	return max ;
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

	int ans = maxGold(arr,r,c) ;
	cout << ans << endl ;
}