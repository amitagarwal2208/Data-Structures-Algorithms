#include <isotream>
using namespace std ;

struct mypair{
	int startrow ;
	int startcol ;
	int size ;
};


void FillDP(int** arr , int currow , int curcol , int endrow , int endcol , mypair & finalans , int** dp){


	if(dp[currow][curcol] == 0){
		
	}

	//right poss
	mypair poss_ih = FillDP(arr,currow,curcol+1,endrow,endcol) ;
	mypair poss_id = FillDP(arr,currow+1,curcol+1,endrow,endcol) ;
	mypair poss_iv = FillDP(arr,currow+1,curcol,endrow,endcol) ;


	mypair curans ;
	curans.startrow = currow ;
	curans.startcol = curcol ;

	curans.size = 1+min(poss_iv.size,min(poss_id.size,poss_ih.size)) ;

	if(curans.size>finalans.size){
		finalans = curans ;
	}
}


mypair maxSizeSubMatrix(int** arr , int r , int c){

	int** dp = new int*[r] ;
	for(int i=0 ; i <r ; ++i){
		dp[i] = new int[c] ;
		for(int j=0 ; j<c ; ++j){
			dp[i][j] = arr[i][j] ;
		}
	}
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


	mypair ans = maxSizeSubMatrix(arr,r,c) ;
	cout << ans.startrow << " " << ans.startcol << " " << ans.size << endl ;

}