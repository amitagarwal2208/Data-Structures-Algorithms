#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
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





int keyPad(string str , vector<string> & v){


	if(str.size()==0){
		return 0 ;
	}

	if(str.size() == 1){

		int num = str[0]-'0' ;
		string curcode = code[num] ;
		for(int i=0; i<curcode.size() ; ++i){
			string temp = "" ;
			temp.push_back(curcode[i]) ;
			v.push_back(temp) ;
		}

		return curcode.size() ;
	}



	int smallans = keyPad(str.substr(0,str.size()-1) , v) ;

	int curnum = str[str.size()-1] - '0' ;
	string curcode = code[curnum] ;

	int n = curcode.size() ;
	int ans = n*smallans ;


	for(int i=0 ; i<n-1 ; ++i){
		for(int j=0 ; j<smallans ; ++j){
			v.push_back(v[j]) ;
		}
	}

	int cur = 0 ;
	for(int i=0 ; i<n ; ++i){
		char ch = curcode[i] ;
		string tmp = "" ;
		tmp.push_back(ch) ;
		for(int j=0 ; j<smallans ; ++j){
			
			v[cur].append(tmp) ;
			++cur ;
		}
	}


	return ans ;



	

}


void Print(vector<string> & v){
	for(int i=0 ; i<v.size() ; ++i){
		cout << v[i] << endl ;
	}
}
int keyPad(string str, string ans){

	vector<string> v ;
	int ans = (int)keyPad(str , v) ;
	Print(v) ;
	return ans ;
}



//Driver program
int main(int argc, char** argv){
        string s;
        cin >> s;

        int ans = keyPad(s, "");
  cout << ans << endl;   
}











