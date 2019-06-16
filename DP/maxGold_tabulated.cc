#include <iostream>
using namespace std ;




int maxGold(int** arr , int r , int c){

	int** dp = new int*[r] ;
	for(int i=0 ; i<r ; ++i){
		dp[i] = new int[c] ;
	}

	for(int row=0 ; row<r ; ++row){
		dp[row][c-1] = arr[row][c-1] ;
	}
	for(int curcol=c-2 ; curcol>=0 ; --curcol){
		for(int currow=0 ; currow<r ; ++currow){
			int poss_ine=0 , poss_ie , poss_ise=0 ;
			poss_ie = dp[currow][curcol+1];
			if(currow!=0){
				poss_ine = dp[currow-1][curcol+1] ;
			}
			if(currow!=r-1){
				poss_ise = dp[currow+1][curcol+1] ;
			}

			dp[currow][curcol] = arr[currow][curcol] + max(poss_ie , max(poss_ine,poss_ise)) ;
		}
	}

	// return max from 1st coloumn
	int max=0 ;
	for(int currow=0 ; currow<r ; ++currow){
		if(dp[currow][0]>max){
			max = dp[currow][0] ;
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