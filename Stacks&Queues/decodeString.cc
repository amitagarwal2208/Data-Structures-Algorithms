#include<iostream>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std ;

void printI(stack<int> s){
    while (!s.empty()) {
        cout << s.top() << " " ;
        s.pop() ;
    } cout << endl ;
    
}

void printS(stack<string> s){
    while (!s.empty()) {
        cout << s.top() << " " ;
        s.pop() ;
    } //cout << endl ;
    
}
string decode1(string s){
    
    stack<int> ns ;
    stack<string> ss ;
    ss.push("") ;
    int n = (int)s.size() ;
    for(int i=0 ; i<n ; ++i){
        
        if(s[i]>='0' && s[i]<='9'){
            // number
            ns.push(s[i]-'0') ;
        } else if(s[i]=='['){
            // opening bracket
            ss.push("") ;
            
        } else if(s[i]==']'){
            // closing bracket
            if(!ns.empty() && !ss.empty()){
                int num = ns.top() ;
                ns.pop() ;
                string st = ss.top();
                ss.pop() ;
                string s1 = st ;
                for(int i=0 ; i<num-1 ; ++i){
                    st.append(s1) ;
                }
                ss.top().append(st) ;
            }
        
        } else {
            // character
            ss.top().push_back(s[i]) ;
        }
        
        
    }
    return ss.top() ;
    
}
string decode2(string s){
    
    
    
    stack<int> ns ;
    stack<string> ss ;
    ss.push("") ;
    int n = (int)s.size() ;
    for(int i=0 ; i<n ; ++i){
       // cout << s[i] << endl ;
        if(s[i]>='0' && s[i]<='9'){
            // number
            //ns.push(s[i]-'0') ;
            
            
            int num = s[i]-'0' ;
           // cout << num << endl ;
            string s1 = ss.top() ;
            for(int i=0 ; i<num-1 ; ++i){
                ss.top().append(s1) ;
            }
        } else {
            // character
            ss.top().push_back(s[i]) ;
        }
        
        
    }
    return ss.top() ;
    
}

string decode3(string s){
    stack<string> ss ;
    int n = (int)s.size() ;
    
    for(int i=n-1 ; i>=0 ; --i){
        //cout << s[i] << endl ;
        if(s[i]==']'){
            // closing bracket
            string tmp = "" ;
            tmp.push_back(s[i]) ;
            ss.push(tmp) ;
            //continue ;
        } else if(s[i]=='['){
            // opening bracket
            string ansSoFar = "" ;
            string t = ss.top() ;
            //cout << (t.compare("]")==0) << endl ;
            while(t.compare("]")!=0){
                ansSoFar.append(ss.top()) ;
                //cout <<"hi"<<endl ;
                ss.pop() ;
                t=ss.top() ;
            }
            //cout << ansSoFar << endl ;
            ss.pop() ;
            ss.push(ansSoFar) ;
            //continue ;
        } else if(s[i]>='0' && s[i]<='9'){
            int num = s[i]-'0' ;
            string s2 = ss.top() ;
            ss.pop() ;
            string s1 = s2 ;
            for(int i=0 ; i<num-1 ; ++i){
                s2.append(s1) ;
            }
            ss.push(s2) ;
            //continue ;
        } else {
            if(ss.top().compare("]")==0){
                string tmp = "" ;
                tmp.push_back(s[i]) ;
                ss.push(tmp) ;
            } else {
            string s1 = ss.top() ;
            ss.pop() ;
            s1 = s[i] + s1 ;
            ss.push(s1) ;
                
            }
        }
//        cout << i << " : " ;
//        printS(ss) ;
//        cout << endl << endl;
    }
    string ans = "" ;
    while(!ss.empty()){
        //cout << ss.top() << endl ;
        ans.append(ss.top()) ;
        
        ss.pop() ;
    }
    return ans ;
}


int main(){
    
    string s ;
    cin >> s ;
    
    string d = decode3(s) ;
    cout << d << endl ;
    
    
    
}




