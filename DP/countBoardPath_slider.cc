#include<iostream>
using namespace std ;


int countBoardPaths(int n){
	int* sliderdp = new int[7] ;
	for(int i=1 ; i<=6 ; ++i){
		sliderdp[i] = 0 ;
	}
	sliderdp[1] = 1 ;

	for(int curpos=n-1 ; curpos>=0 ; --curpos){
		
		sliderdp[0] = 0 ;
		for(int i=1 ; i<=6 ; ++i){
			sliderdp[0]+=sliderdp[i] ;
		}

		// Shift elements.
		for(int i=6 ; i>=1 ; --i){
			sliderdp[i] = sliderdp[i-1] ;
		}

	}
	return sliderdp[1] ;
}


int main(){
	int n ;
	cin >> n ;

	int ans = countBoardPaths(n) ;
	cout << ans << endl ;
}