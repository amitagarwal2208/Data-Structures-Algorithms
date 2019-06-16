#include <iostream>
#include<stack>
#include<string>

using namespace std ;

bool isBal(string s){
    bool ans = true ;
    stack<char> st ;
    
    int n = (int)s.size() ;
    char c= '{' ;
    for(int i=0 ; i<n ; ++i){
        if(s[i]=='('||s[i]==c||s[i]=='['){
            st.push(s[i]) ;
        } else {
            if(s[i]==')'){
                if(st.empty()){
                    return false ;
                } else {
                    if(st.top()=='('){
                        st.pop() ;
                    } else {
                        return false ;
                    }
                }
            } else if(s[i]=='}'){
                if(st.empty()){
                    return false ;
                } else {
                    if(st.top()=='{'){
                        st.pop() ;
                    } else {
                        return false ;
                    }
                }
            } else if(s[i]==']'){
                if(st.empty()){
                    return false ;
                } else {
                    if(st.top()=='['){
                        st.pop() ;
                    } else {
                        return false ;
                    }
                }
            }
            
        }}
        if(st.empty()==false) return false ;
        return ans ;
        
}
int main() {
    //code
    int t ;
    cin >> t ;
    while(t--){
        
        string s ;
        cin >> s ;
        if(isBal(s)){
            cout << "balanced" << endl ;
        } else {
            cout << "not balanced" << endl ;
        }
    }
    return 0;
}
