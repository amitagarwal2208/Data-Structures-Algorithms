#include<iostream>
using namespace std ;

struct mybox{
	int size ;
	int startrow ;
	int startcol ;
};


mybox maxSizeSubMatrix(int** arr , int r , int c){
	int** dp = new int*[r] ;
	for(int i=0 ; i <r ; ++i){
		dp[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			dp[i][j] = arr[i][j] ;
		}
	}

	int max = 0 , maxrow,maxcol;

	for(int currow=r-2 ; currow>=0 ; --currow){
		for(int curcol=c-2 ; curcol>=0 ; --curcol){
			if(dp[currow][curcol]!=0){
				dp[currow][curcol] = 1+min(dp[currow+1][curcol+1],min(dp[currow][curcol+1] , dp[currow+1][curcol])) ;
			}
			if(dp[currow][curcol] > max){
				max = dp[currow][curcol] ;
				maxrow = currow ;
				maxcol = curcol ;
			}

		}
	}


	mybox ans ;
	ans.size = max ;
	ans.startrow = maxrow ;
	ans.startcol = maxcol ;
	return ans ;


}


int main(){
	int r,c ;
	cin >> r >> c ;

	int** arr = new int*[r] ;
	for(int i=0 ; i <r ; ++i){
		arr[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			cin >> arr[i][j] ;
		}
	}

	mybox ans = maxSizeSubMatrix(arr,r,c) ;
	cout << ans.startrow << " " << ans.startcol << " " << ans.size << endl ;
}



