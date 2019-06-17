#include <iostream>
#include <unordered_map>

using namespace std ;

bool k_anagram(string s1 , string s2 , int k){
    if(s1.size()!=s2.size()){
        return false ;
    }
    unordered_map<char, int> m ;
    int n = (int)s1.size() ;
    for(int i=0 ; i<n ; ++i){
        char c = s1[i] ;
        if(m.count(c)>0){
            ++m[c] ;
        } else {
            m[c] = 1 ;
        }
    }
    
    for(int i=0 ; i<n ; ++i){
        char c = s2[i] ;
        if(m.count(c)>0){
            --m[c] ;
        } else {
            m[c] = -1 ;
        }
    }
    
    int pos = 0 ;
    unordered_map<char, int>::iterator it ;
    for(it=m.begin() ; it!=m.end() ; ++it){
        if(it->second>0){
            pos+=it->second ;
        }
    }
    return (pos<=k) ;
    
}

int main(){
    
    // k-Anagram
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    int k ;
    cin >> k ;
    if(k_anagram(s1,s2,k)){
        cout << "True" << endl ;
    } else cout << "False" << endl ;
    
}
