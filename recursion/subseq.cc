#include<iostream>
#include<string>
#include<vector>

using namespace std ;

void subseq_ascii(string s , vector<string>& v){

	if(s.size()==0){
		v.push_back("") ;
		return ;
	}


	subseq_ascii(s.substr(1) , v) ;

	int n = v.size() ;
	for(int i=0 ; i<n ; ++i){
		string cur = "" ;
		cur.push_back(s[0]) ;
		v.push_back(cur.append(v[i])) ;
	}

	for(int i=0 ; i<n ; ++i){
		string cur = "" ;
		int ascii = s[0] ;
		cur.append(to_string(ascii)) ;
		v.push_back(cur.append(v[i])) ;
	}


}


vector<string> subseq_ascii(string s){

	vector<string> v ;
	subseq_ascii(s,v) ;
	return v ;

}



void getSubSeq(string s , vector<string> & v){
    
    if(s.size()==0){
        string str = "" ;
        v.push_back(str) ;
        return ;
    }
    
    getSubSeq(s.substr(1) , v) ;
    
    
    //int endpos = (int)v.size() ;
    int n = v.size() ;
    for(int curpos=0 ; curpos<n ; ++curpos){
        string cur = "" ;
        cur.push_back(s[0]) ;
        //cout << cur << endl;
        v.push_back(cur.append(v[curpos])) ;
    }
    
}


vector<string> getSubSeq(string s){
    
    //int n = s.size() ;
    vector<string> v ;
    
    getSubSeq(s,v) ;
    return v ;
}



int main(){
    
    string s ;
    cin >> s ;
    //cout << s.size() << endl ;
    //cout << s.substr(1) << endl ;
   // cout << "hi" << endl ;
    vector<string> ans = getSubSeq(s) ;
    for(int i=0 ; i<ans.size() ; ++i){
        cout << ans[i] << endl ;
    }
    cout << endl << endl ;
    vector<string> ans2 = subseq_ascii(s) ;
    for(int i=0 ; i<ans2.size() ; ++i){
        cout << ans2[i] << endl ;
    }
    cout << endl ;
    
}
