#include<iostream>
#include<string>
#include<vector>
using namespace std ;

int ctprm(int* denoms , int n , int amt,vector<vector<int> > & dp,int cur){

	if(amt<0){
		return 0 ;
	}

	if(amt==0){
		return 1 ;
	}

	if(dp[cur][amt]!=-1){
		return dp[cur][amt] ;
	}


	int curans = 0 ;

	for(int i=0 ; i<n ; ++i){
		curans+=ctprm(denoms,n,amt-denoms[i],dp,i) ;
	}

	dp[cur][amt] = curans ;
	return curans ;

}


int ctprm(int* denoms , int n , int amt){

	vector<vector<int> > dp(n,vector<int>(amt+1,-1)) ;
	for(int i=0 ; i<n ; ++i){
		dp[i][0] = 0 ;
	}
	return ctprm(denoms,n,amt,dp,0) ;

}


int countPerm(int* denoms , int n , int amt){

	if(amt<0){
		return 0 ;
	}

	if(amt==0){
		return 1 ;
	}


	int curans = 0 ;

	for(int i=0 ; i<n ; ++i){
		curans+=countPerm(denoms,n,amt-denoms[i]) ;
	}

	return curans ;

}


void CoinChange_perm(int* denoms , int n , int amt , string ansSoFar){

	if(amt<0){
		return ;
	}

	if(amt==0){
		cout << ansSoFar << endl ;
		return ;
	}


	for(int i=0 ; i<n ; ++i){
		ansSoFar+=to_string(denoms[i]) ;
		CoinChange_perm(denoms,n,amt-denoms[i],ansSoFar);
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
	cout << countPerm(denoms,n,amt) << endl ;
	cout << ctprm(denoms,n,amt) << endl ;

	CoinChange_perm(denoms,n,amt,"");
}