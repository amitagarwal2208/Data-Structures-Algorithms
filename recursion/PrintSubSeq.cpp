#include <iostream>
#include <string>

using namespace std ;

void PrintSubSeq(string s , string ansSoFar){

	if(s.size()==0){
		cout << ansSoFar << endl ;
		return ;
	}

	PrintSubSeq(s.substr(1) , ansSoFar) ;

	ansSoFar.push_back(s[0]) ;

	PrintSubSeq(s.substr(1) , ansSoFar) ;

}




void PrintSubSeq(string s){

	string ansSoFar = "" ;
	PrintSubSeq(s,ansSoFar) ;
}





int main(){

	string s ;
	cin >> s ;

	PrintSubSeq(s) ;

}