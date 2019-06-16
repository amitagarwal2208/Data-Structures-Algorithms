#include <iostream>
using namespace std ;


int Fibo(int n){
	int s0 = 0 ;
	int s1 = 1 ;

	for(int i=0 ; i<n ; ++i){
		int nf = s0+s1 ;
		s0 = s1 ;
		s1 = nf ;
	}
	return s0 ;
}


void PrintFiboN(int n){
	int ans = Fibo(n) ;
	cout << ans << endl ;
}

int main(){
	int n ;
	cin >> n ;
	PrintFiboN(n) ;
}