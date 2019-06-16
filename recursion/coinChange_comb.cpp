#include<iostream>
#include<vector>
#include<string>
using namespace std ;

int ctcmb(int* denoms , int n,int amt , int cur , vector<vector<int> > & dp){

	if(amt<0){
		return 0;
	}

	if(amt==0){
		return 1 ;
	}

	if(dp[cur][amt]!=-1){
		return dp[cur][amt] ;
	}

	int curans = 0 ;
	for(int i=cur ; i<n ; ++i){
		curans+=ctcmb(denoms,n,amt-denoms[i],i,dp) ;
	}
	dp[cur][amt] = curans ;
	return curans ;

}

int ctcmb(int* denoms , int n,int amt , int cur){

	vector<vector<int> > dp(n,vector<int>(amt+1,-1)) ;
	for(int i=0 ; i<n ; ++i){
		dp[i][0] = 0 ;
	}
	int ans = ctcmb(denoms,n,amt,cur,dp) ;

	cout << endl ;
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<=amt ; ++j){
			cout << dp[i][j] << " " ;
		}
		cout << endl ;
	}

	return ans ;
}



int countComb(int* denoms , int n,int amt , int cur){

	if(amt<0){
		return 0;
	}

	if(amt==0){
		return 1 ;
	}

	int curans = 0 ;
	for(int i=cur ; i<n ; ++i){
		curans+=countComb(denoms,n,amt-denoms[i],i) ;
	}

	return curans ;

}





void PrintCoinChangeCombinations(int* denoms , int n , int amt , int cur , string ansSoFar){


	if(amt<0){
		return ;
	}

	if(amt==0){
		cout << ansSoFar << endl;
		return ;
	}



	for(int i=cur ; i<n ; ++i){
		ansSoFar+=to_string(denoms[i]) ;
		PrintCoinChangeCombinations(denoms,n,amt-denoms[i],i,ansSoFar) ;
		ansSoFar.pop_back() ;
	}

}


int main(){

	int n ; 
	cin >> n ;
	int* denoms = new int[n] ;
	for(int i=0 ; i<n ; ++i){
		cin >> denoms[i] ;
	}
	int amt ;
	cin >> amt ;

	int ans = countComb(denoms,n,amt,0) ;
	cout << ans << endl ;
	cout << ctcmb(denoms,n,amt,0) << endl;

	PrintCoinChangeCombinations(denoms,n,amt,0,"") ;


}