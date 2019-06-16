#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
using namespace std ;




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
