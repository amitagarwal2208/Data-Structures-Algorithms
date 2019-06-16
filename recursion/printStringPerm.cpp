#include <iostream>
#include <string>
using namespace std;

void printPerm(string s , string ansSoFar){
  
  if(s.size()==0){
  	cout << ansSoFar << endl ;
  	return ;
  }
  
  for(int i=0 ; i<s.size() ; ++i){
	  
	  ansSoFar.push_back(s[i]) ;
	  printPerm(s.substr(0,i)+s.substr(i+1,s.size()-1-i) , ansSoFar) ;
	  ansSoFar.pop_back() ;
  }
  
}


void printPermutations(string s){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  
  string ansSoFar = "" ;
  	printPerm(s,ansSoFar) ;
}