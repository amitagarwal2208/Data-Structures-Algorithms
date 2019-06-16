#include<iostream>
using namespace std ;

void lis(int* arr , int n , int** dp){


	for(int i=1 ; i<n ; ++i){
		for(int j=i-1 ; j>=0 ; --j){
			if(arr[i] > arr[j] && (1+dp[0][j])>=dp[0][i]){
				dp[0][i] = 1+dp[0][j] ;
				dp[1][i] = j ;
			}
		}
	}
}


int main(){
	int n ;
	cin >> n ;
	int* arr = new int[n] ;
	for(int i=0 ; i<n ; ++i){
		cin >> arr[i] ;
	}

	int** dp = new int*[2] ;
	for(int i=0 ; i<2 ; ++i){
		dp[i] = new int[n] ;
	}
	for(int i=0 ; i<n ; ++i){
		dp[0][i] = 1 ;
		dp[1][i] = -1 ;
	}

	lis(arr,n,dp) ;

	int max=0 , maxpos ;
	for(int i=0 ; i<n ; ++i){
		if(dp[0][i] > max){
			max = dp[0][i] ;
			maxpos = i ;
		}
	}

	cout << max << endl ;
	for(int i=0 ; i<max ; ++i){
		cout << arr[maxpos] << " " ;
		maxpos = dp[1][maxpos] ;
	}
	cout << endl ;

	for(int i=0 ; i<n ; ++i){
		cout << dp[0][i] << " " ;
	}
	cout << endl ;

}





