#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
using namespace std ;

string charToStr(char c){
    string s = "" ;
    s.push_back(c) ;
    return s ;
}

string canonicalPath(string s){
    
    string ans = "" ;
    stack<string> st ;
    int n = (int)s.size() ;
    
    for(int i=0 ; i<n ; ++i){
        char c = s[i] ;
        string curstr = charToStr(c) ;
        if(c=='/'){
            if(st.empty()) st.push(curstr) ;
            else {
                if(st.top().compare(curstr)!=0){
                    st.push(curstr);
                }
            }
        } else if(c=='.'){
            if(i<n-1 && s[i+1]=='.'){
                if(st.size()>1){
                    st.pop() ;
                    st.pop() ;
                }
                ++i ;
            }
        } else {
            // character
            if(st.empty()==false && st.top()=="/"){
                st.push(curstr) ;
            } else {
                st.top().append(curstr) ;
            }
        }
        
    }
    if(st.size()>1 && st.top()=="/")
    {
        st.pop() ;
    }
    while(st.empty()==false){
        string t = st.top() ;
        t.append(ans) ;
        ans = t ;
        st.pop() ;
    }
    
    
    
    return ans ;
    
}



int main(){
    string s ;
    cin >> s ;
    string ans = canonicalPath(s) ;
    cout << ans << endl ;
}






