#include<iostream>
#include <string>
#include<vector>
using namespace std ;

vector<string> code = {
	"." ,
	"abc" ,
	"def" ,
	"ghi" ,
	"jkl" ,
	"mno" , 
	"pqrs",
	"tuv" ,
	"wx" ,
	"yz"
} ;



void PrintKeyPad(string s , string ansSoFar){

	if(s.size()==0){
		cout << ansSoFar << endl ;
		return ;
	}


	int num = s[0]-'0' ;
	string curcode = code[num] ;

	for(int i=0 ; i<curcode.size() ; ++i){

		ansSoFar.push_back(curcode[i]) ;
		PrintKeyPad(s.substr(1) , ansSoFar) ;
		ansSoFar.pop_back() ;

	} 

}

void PrintKeyPad(string s){
	string ansSoFar = "" ;
	PrintKeyPad(s,ansSoFar) ;
}


int main(){


	string s ;
	cin >> s ;

	PrintKeyPad(s) ;


}