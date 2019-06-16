#include <iostream>
using namespace std ;





int CountPaths(int n){
	int* dp = new int[n+6] ;
	dp[n] = 1 ;
	for(int i=n+1 ; i<n+6 ; ++i){
		dp[i] = 0 ;
	}
	
	for(int curpos=n-1 ; curpos>=0 ; --curpos){
		for(int scanpos=curpos+1 ; scanpos<=curpos+6 ; ++scanpos){
			dp[curpos]+=dp[scanpos] ;
		}
	}






	return dp[0] ;
}



int main(){

	int n ;
	cin >> n ;

	int ans = CountPaths(n) ;
	cout << ans << endl ; 

}