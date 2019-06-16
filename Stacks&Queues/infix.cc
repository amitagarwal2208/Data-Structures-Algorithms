#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
using namespace std ;


class infix{
    string s ;
    stack<int> ns ;
    stack<char> os ;
    stack<string> ss ;
    unordered_map<char, int> p ;
    unordered_map<char, int> ip ;
    //char c = '+' ;
    
    void setMap1(){
        p['+'] = 1 ;
        p['-']=1 ;
        p['*']=2 ;
        p['/']=2 ;
        p['^']=3 ;
        p['(']=0 ;
    }
    void setMap2(){
        ip['+'] = 1 ;
        ip['-']=1 ;
        ip['*']=2 ;
        ip['/']=2 ;
        ip['^']=3 ;
        ip['(']=4 ;
    }
    void do_operation(char op){
        if(ns.size()<2){
            return ;
        }
        int x = ns.top() ;
        ns.pop() ;
        int y = ns.top() ;
        ns.pop() ;
        if(op=='+') ns.push(x+y) ;
        else if(op=='-') ns.push(y-x) ;
        else if(op=='*') ns.push(x*y) ;
        else if(op=='/') ns.push(y/x) ;
        else if(op=='^') ns.push(pow(y, x)) ;
    }
    
    
    void doPostFix(char op){
        if(ss.size()<2){
            return ;
        }
        string x = ss.top() ;
        ss.pop() ;
        string y = ss.top() ;
        ss.pop() ;
        x.push_back(op) ;
        y.append(x) ;
        
        
        ss.push(y) ;
    }
    
    
public:
    void input(string s1){
        s=s1 ;
    }
    int eval(){
        setMap1() ;
        setMap2() ;
        //int ans = 0 ;
        int n = (int)s.size() ;
        for(int i=0 ; i<n ; ++i){
            char c=s[i] ;
            //cout << c << " " ;
            if(c>='0' && c<='9'){
                int num = c-'0' ;
                ++i ;
                while(i<n && s[i]<='9' && s[i]>='0'){
                    num=num*10 ;
                    num+=(s[i]-'0') ;
                    ++i ;
                }
                --i ;
                ns.push(num) ;
            } else if(c==')'){
                while(!os.empty() && os.top()!='('){
                    char op = os.top() ;
                    do_operation(op) ;
                    os.pop() ;
                }
                if(os.empty()==false) os.pop() ;
            } else {
                while(!os.empty() && p[os.top()]>=ip[c]){
                    
                    char op = os.top() ;
                    do_operation(op) ;
                    os.pop() ;
                }
                os.push(c) ;
            }
            //cout << i << " : " << ns.size() << " " << os.size()<< endl ;
        }
        
        while(os.empty()==false){
            //cout << os.top() << endl ;
            do_operation(os.top()) ;
            os.pop() ;
        }
        //cout << ns.size() << endl;
        return ns.top() ;
    }
    
    
    void convToPostFix(){
        setMap1() ;
        setMap2() ;
        //int ans = 0 ;
        int n = (int)s.size() ;
        for(int i=0 ; i<n ; ++i){
            char c=s[i] ;
            cout << c << " " ;
            if(c>='0' && c<='9'){
                int num = c-'0' ;
                ++i ;
                while(i<n && s[i]<='9' && s[i]>='0'){
                    num=num*10 ;
                    num+=(s[i]-'0') ;
                    ++i ;
                }
                --i ;
                ss.push(to_string(num)) ;
            } else if(c==')'){
                while(!os.empty() && os.top()!='('){
                    char op = os.top() ;
                    doPostFix(op) ;
                    os.pop() ;
                }
                if(os.empty()==false) os.pop() ;
            } else {
                while(!os.empty() && p[os.top()]>=ip[c]){
                    
                    char op = os.top() ;
                    doPostFix(op) ;
                    os.pop() ;
                }
                os.push(c) ;
            }
            cout << i << " : " << ss.size() << " " << os.size()<<" "<< ss.top()<<endl ;
        }
        
        while(os.empty()==false){
            //cout << os.top() << endl ;
            doPostFix(os.top()) ;
            os.pop() ;
        }
        //cout << ns.size() << endl;
        cout << ss.top() << endl ;
    }
};

int main(){
    
    infix x ;
    string s ;
    cin >> s ;
    x.input(s) ;
   x.convToPostFix() ;
 
    
}
