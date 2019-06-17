

/*
6
12
0:start:0
1:start:2
1:end:5
2:start:6
2:end:9
3:start:10
4:start:14
5:start:16
5:end:18
4:end:20
3:end:23
0:end:30
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std ;

struct mypair{
    int pid ;
    int start ;
    int notMyTime ;
    mypair(int a , int b){
        pid = a ;
        start = b ;
        notMyTime = 0 ;
    }
};


int* getAloneFuncTime(int n , int l , vector<string> v){
    
    int* arr=  new int[n] ;
    stack<mypair> s ;
    
    for(int i=0 ; i<l ; ++i){
        string curlog = v[i] ;
        
        
        // Find process id
        int curpid = 0 ;
        int j=0 ;
        while(curlog[j]!=':'){
            curpid*=10 ;
            curpid+=(curlog[j]-'0') ;
            ++j ;
        }
        
        curlog = curlog.substr(j+1) ;
        bool start = false ;
        
        if(curlog[0]=='s'){
            start = true ;
            curlog = curlog.substr(6) ;
        }
        else if(curlog[0]=='e'){
            start = false ;
            curlog = curlog.substr(4) ;
        }
        
        // get timestamp
        int curTimeStamp = stoi(curlog) ;
        
        
        
        if(start){
            mypair p(curpid , curTimeStamp) ;
            s.push(p) ;
        } else {
            mypair curp = s.top() ;
            s.pop() ;
            
            int totSysTime = curTimeStamp - curp.start +1 ;
            int myAloneTime = totSysTime - curp.notMyTime ;
            arr[curpid] = myAloneTime ;
            
            if(s.empty()==false) s.top().notMyTime+=totSysTime ;
        }
    }
    
    
    
    return arr ;
}


int main(){
    
    int n ;
    cin >> n ;
    int l ;
    cin >> l ;
    vector<string> v ;
    for(int i=0 ; i<l ; ++i){
        string s ;
        cin >> s ;
        v.push_back(s) ;
    }
    int* arr = getAloneFuncTime(n, l, v) ;
    for(int i=0 ; i<n ; ++i){
        cout << arr[i] << " " ;
    }
    cout << endl ;
    
}
