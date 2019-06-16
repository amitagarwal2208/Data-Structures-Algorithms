#include<iostream>
#include <stack>
#include <string>

using namespace std ;
void printArr(int* arr , int n){
    for(int i=0 ; i<n ; ++i){
        cout << arr[i] << endl ;
    }
    
}


void fillStack(string a , stack<char> & s1){
    for(int i=0 ; i<a.size() ; ++i){
        if(a[i] == '#'){
            if(!s1.empty()){
                s1.pop() ;
            }
        } else {
            s1.push(a[i]) ;
        }
    }
}


bool cmpStks(stack<char> & s1 , stack<char> & s2){
    if(s1.size()==s2.size()){
        while(!s1.empty()){
            
            if(s1.top() != s2.top()){
                return false ;
            }
            
            
            s1.pop() ;
            s2.pop() ;
        }
        return true ;
    } else return false ;
}

bool cmpStrDel(string a , string b){
    bool ans = true ;
    
    stack<char> s1,s2 ;
    
    
    fillStack(a, s1) ;
    fillStack(b, s2) ;
    
    ans = cmpStks(s1 , s2) ;
    
    return ans ;
}

int main(){
    
    string a,b ;
    cin >> a >> b ;
    if(cmpStrDel(a, b)) cout << "true" << endl ;
    else cout << "false" << endl;
}
