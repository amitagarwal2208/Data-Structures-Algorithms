#include<iostream>
using namespace std ;


void PrintPaths(int xsrc , int ysrc,int xdest , int ydest , string ansSoFar){

	if(xsrc>xdest || ysrc>ydest){
		return ;
	}

	if(xsrc==xdest && ysrc==ydest){
		cout << ansSoFar << endl ;
		return ;
	}


	ansSoFar.push_back('H') ;
	PrintPaths(xsrc,ysrc+1,xdest,ydest,ansSoFar) ;
	ansSoFar.pop_back() ;
	ansSoFar.push_back('D') ;
	PrintPaths(xsrc+1,ysrc+1,xdest,ydest,ansSoFar) ;
	ansSoFar.pop_back() ;
	ansSoFar.push_back('V') ;
	PrintPaths(xsrc+1,ysrc,xdest,ydest,ansSoFar) ;
	//ansSoFar.pop_back() ;

}



void PrintPaths(int n){

	string ansSoFar = "" ;
	PrintPaths(0,0,n-1,n-1,ansSoFar);

}


int main(){

	int n ;
	cin >> n ;

	PrintPaths(n) ;

}