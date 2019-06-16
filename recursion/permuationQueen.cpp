#include<iostream>
#include<string>
#include <vector>
using namespace std ;

void PrintPermuations(vector<bool> board,int n , int tq , int queenpsf , string ansSoFar){

	if(queenpsf==tq){
		cout << ansSoFar << endl ;
		return ;
	}

	for(int i=0 ; i<n ; ++i){
		if(board[i]==false){
			board[i] = true ;
			string cur = "q"+to_string(queenpsf)+"b"+to_string(i)+" " ;
			ansSoFar+=cur ;
			PrintPermuations(board,n,tq,queenpsf+1,ansSoFar) ;
			board[i] = false ;
			int sz = ansSoFar.size() ;
			ansSoFar = ansSoFar.substr(0,sz-cur.size()) ;
		}
	}

}

void PrintPermuations(int n , int tq){

	int queenpsf = 0 ;
	string ansSoFar = "" ;
	vector<bool> board(n,false) ;
	PrintPermuations(board,n,tq,queenpsf,ansSoFar) ;

}


int main(){

	int n ;
	cin >> n ;

	int tq ;
	cin >> tq ;
	PrintPermuations(n,tq) ;

}