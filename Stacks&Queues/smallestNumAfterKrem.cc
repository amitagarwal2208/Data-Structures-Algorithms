#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
using namespace std ;

string smallestNum(string s , int k){
    
    stack<int> st ;
    int n = (int)s.size() ;
    
    for(int i=0 ; i<n ; ++i){
        int num = s[i]-'0' ;
        if(st.empty()){
            st.push(num) ;
        } else {
            while(st.empty()==false && st.top()>num && k>0){
                st.pop() ;
                --k ;
            }
            st.push(num) ;
        }
    }
    for(int i=0 ; i<k ; ++i){
        if(st.empty()==false) st.pop() ;
    }
    
    string ans = "" ;
    while(st.empty()==false){
        string digit = to_string(st.top()) ;
        digit.append(ans) ;
        ans = digit ;
        st.pop() ;
    }
    
    return ans ;
    
}




int main(){
    string s ;
    cin >> s ;
    int k ;
    cin >> k ;
    string ans = smallestNum(s, k) ;
    cout << ans << endl ;
    
}






