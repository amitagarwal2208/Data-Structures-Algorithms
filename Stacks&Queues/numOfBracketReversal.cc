#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
using namespace std ;



int numOfRev(string s){
    
    stack<char> st ;
    int n = s.size();
    for(int i=0 ; i<n ; ++i){
        if(s[i]=='{'){
            st.push(s[i]) ;
        } else if(s[i]=='}'){
            if(st.empty()){
                st.push(s[i]) ;
            } else if(st.empty()==false && st.top()=='}'){
                st.push(s[i]) ;
            } else if(st.empty()==false && st.top()=='{'){
                st.pop() ;
            }
        }
    }
    int ans = 0;
    int o=0 , c=0 ;
    if(st.empty()==false){
        
        
        while(!st.empty() && st.top()=='{'){
            ++o ;
            st.pop() ;
        }
        while(!st.empty() && st.top()=='}'){
            ++c ;
            st.pop() ;
        }
        
        
    }
    
    if((o%2==0 && c%2!=0) || (o%2!=0 && c%2==0)){
        return -1 ;
    } else {
        if(o%2==0){
            ans+=(o/2) ;
        } else {
            ans+=(o/2) ;
            ++ans ;
        }
        if(c%2==0){
            ans+=(c/2) ;
        } else{
            ans+=(c/2) ;
            ++ans;
        }
    }
    
    return ans ;
    
}

char decodeAtIndex(string s , int k){

    // calculate size
    int n = 0 ;
    int len = (int)s.size() ;
    
    for(int i=0 ; i<len ; ++i){
        if(s[i]>='0' && s[i]<='9'){
            int num = s[i]-'0' ;
            ++i ;
            while(i<len && s[i]>='0' && s[i]<='9'){
                num=num*10 ;
                num+=(s[i]-'0') ;
                ++i ;
            }
            --i ;
            
            n=n*num ;
        } else {
            ++n ;
        }
    }
    //cout << n << endl ;
    for(int i=len-1 ; i>=0 ; --i){
        cout << n << " " << k << " " << s[i] << endl ;
        
        
        if(s[i]>='0' && s[i]<='9'){
            int num = s[i] - '0' ;
            n = n/num ;
            k=k%n ;
            continue ;
        }
        if(k==n-1){
            return s[i] ;
        } else {
            --n ;
            k=k%n ;
        }
        
    }

    return '0' ;
}


int main(){
    
    string s ;
    cin >> s ;
    int k ;
    cin >> k ;
    cout << decodeAtIndex(s, k) << endl ;
}
