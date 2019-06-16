#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
#include<vector>
using namespace std ;

void generateSeq(string s){
    
    stack<int> st ;
    int cur = 1 ;
    st.push(cur) ;
    ++cur ;
    int n = (int)s.size() ;
    int i=0 ;
    while(i<n){
        
        while(i<n && s[i]!='i'){
            st.push(cur++) ;
            ++i ;
        }
        
        while(st.empty()==false) {
            cout << st.top() << " " ;
            st.pop() ;
         }
        st.push(cur++) ;
        ++i ;
        
    }
    
}

int main(){
    string s ;
    cin >> s ;
    generateSeq(s) ;
}






