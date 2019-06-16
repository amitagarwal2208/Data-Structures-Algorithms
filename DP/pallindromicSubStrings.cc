#include<iostream>
#include<string>
using namespace std ;

int GetLen(char* st){
	int len=0 ;
	while(st[len]!='\0'){
		++len ;
	}
	return len ;
}

int countPallindromicSubStrings(char* st){

	int len = GetLen(st) ;

	bool** dp = new bool*[len] ;
	for(int i=0 ; i<len ; ++i){
		dp[i] = new bool[len] ;
		dp[i][i] = true ;
	} 

	for(int i=0 ; i<len-1 ; ++i){
		//dp[i][i+1]?
		if(st[i]==st[i+1]){
			dp[i][i+1] = true ;
		} else {
			dp[i][i+1] = false ;
		}
	}
	int gap=2 ;

	for(int i=len-2 ; i>0 ; --i){
		for(int j=0 ; j<i ; ++j){
			if(st[j]==st[j+gap] && dp[j+1][j+gap-1]){
				dp[j][j+gap] = true ;
			} else {
				dp[j][j+gap] = false ;
			}
		}
		++gap ;
	}

	int ct = 0 ;

	for(int i=0 ; i<len ; ++i){
		for(int j=0 ; j<len ; ++j){
			if(j>=i && dp[i][j]){
				++ct ;
			}
		}
	}
	return ct ;

}


int main(){
	// string st ;
	// cin >> st ;
	// cout << st << endl ;

	char st[10000] ;
	cin >> st ; 

	int ans = countPallindromicSubStrings(st) ;
	cout << ans << endl ;
}