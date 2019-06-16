#include <iostream>
#include<string>
using namespace std ;




void PrintPaths(int src , int dest , int* board , string ansSoFar){

	if(src>dest){
		return ;
	}

	if(src == dest){
		cout << ansSoFar << endl ;
		return ;
	}

	if(board[src] != 0){
		src = board[src] ;
	}


	for(int dice=1 ; dice<=6 ; ++dice){
		ansSoFar.append(to_string(dice)) ;
		PrintPaths(src+dice,dest,board,ansSoFar) ;
		ansSoFar.pop_back() ;
	}
}



void PrintPaths(int src , int dest , int* board){

	string ansSoFar = "" ;
	PrintPaths(src,dest,board,ansSoFar) ;

}



int main(){

	int* board = new int[16] ;
	for(int i=0 ; i<16 ; ++i){
		board[i] = 0 ;
	}

	board[2] = 13 ;
	board[3] = 11 ; 
	board[5] = 7 ;

	PrintPaths(0,15,board) ;

}