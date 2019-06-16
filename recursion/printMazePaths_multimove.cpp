#include<iostream>
#include<string>
using namespace std ;



void PrintMazePaths(int curx , int cury , int n , string ansSoFar){


	if(curx>=n || cury>=n){
		return ;
	}

	if(curx==n-1 && cury==n-1){
		cout << ansSoFar << endl ;
		return ;
	}


	// Horizontal multimoves
	for(int i=1 ; i<=n-1-cury ; ++i){
		ansSoFar.push_back('H') ;
		ansSoFar.push_back('0'+i) ;
		PrintMazePaths(curx,cury+i,n,ansSoFar) ;
		ansSoFar.pop_back() ;
		ansSoFar.pop_back() ;
	}

	// Vertical multimoves
	for(int i=1 ; i<=n-1-curx ; ++i){
		ansSoFar.push_back('V') ;
		ansSoFar.push_back('0'+i) ;
		PrintMazePaths(curx+i,cury,n,ansSoFar) ;
		ansSoFar.pop_back() ;
		ansSoFar.pop_back() ;
	}


	// Diagonal multimoves

	for(int i=1 ; i<=min(n-1-curx,n-1-cury) ; ++i){
		ansSoFar.push_back('D') ;
		ansSoFar.push_back('0'+i) ;
		PrintMazePaths(curx+i,cury+i,n,ansSoFar) ;
		ansSoFar.pop_back() ;
		ansSoFar.pop_back() ;
	}

}





void PrintPaths_multimove(int n){

	string ansSoFar = "" ;
	PrintMazePaths(0,0,n,ansSoFar) ;

}



int main(){

	int n ;
	cin >> n ;

	PrintPaths_multimove(n) ;

}