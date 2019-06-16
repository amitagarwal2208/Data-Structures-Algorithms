#include<iostream>
#include<string>
using namespace std ;


void PrintPaths16(int src , int dest , string ansSoFar){

	if(src>dest){
		return ;
	}

	if(src == dest){
		cout << ansSoFar << endl ;
		return ;
	}

	for(int dice=1 ; dice<=6 ; ++dice){
		ansSoFar.append(to_string(dice)) ;
		PrintPaths16(src+dice , dest , ansSoFar) ;
		ansSoFar.pop_back() ;
	}

}



void PrintPaths16(int src , int dest){

	string ansSoFar = "" ;


	ansSoFar.append(to_string(1)) ;
	PrintPaths16(src,dest,ansSoFar) ;
	ansSoFar.pop_back(); 
	ansSoFar.append(to_string(6)) ;
	PrintPaths16(src,dest,ansSoFar) ;
	ansSoFar.pop_back() ;

}






int ct = 0 ;
void PrintPaths(int src , int dest , string ansSoFar){


	if(src > dest){
		return ;
	}

	if(src==dest){
		cout << ansSoFar << endl ;
		++ct ;
		return ;
	}


	for(int dice=1 ; dice<=6 ; ++dice){
		ansSoFar.append(to_string(dice)) ;
		//ansSoFar.append("->") ;	
		PrintPaths(src+dice , dest , ansSoFar) ;
		ansSoFar.pop_back() ;
	}

}


void PrintPaths(int src , int dest){

	string ansSoFar = "" ;
	PrintPaths(src,dest,ansSoFar) ;

}


int main(){

	int n ;
	cin >> n ;

	PrintPaths(0,n) ;
	cout << endl << ct << endl ;

	PrintPaths16(0,n) ;


}