#include <iostream>
#include <string>
#include <stack>
#include<vector>
using namespace std ;

void GetInput(int* arr , int n){
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
}

int getStartingPoint(int* oilFilled , int* nextPPdist , int n){
    
    int start = 0 ;
    int end = 0 ;
    int sparePetrol = 0 ;
    int journey = 0 ;
    
    while(true){
        
        if(journey==n){
            if(sparePetrol>=0){
                return start ;
            } else {
                return -1 ;
            }
        }
        
        
        
        if(sparePetrol<0){
            // last journey did not happen
            
            if(end<start){
                return -1 ;
            }
            
            start = end ;
            sparePetrol = 0 ;
            journey = 0 ;
        }
        
        
        // Fill oil
        sparePetrol+=oilFilled[end] ;
        // do journey
        sparePetrol-=nextPPdist[end] ;
        ++end ;
        end = end%n ;
        ++journey ;
    }
    
    return -1 ;
    
    
}

int strToInt(string s){
    int num = 0 ;
    bool neg = false ;
    if(s[0]=='-'){
        neg = true ;
        s=s.substr(1) ;
    }
    while(!s.empty()){
        char c = s[0] ;
        s = s.substr(1);
        num=num*10 ;
        num+=(c-'0') ;
    }
    if(neg) num=(-1)*num ;
    return num ;
    
}


int getAns(vector<string> v , int n){
    
    stack<int> s ;
    int ans = 0 ;
   
    for(int i=0 ; i<n ; ++i){
        cout << ans << endl ;
        cout << v[i] << endl << endl ;
        if(v[i]=="C"){
            if(!s.empty()){
                int num = s.top();
                s.pop() ;
                ans-=num ;
            }
        } else if(v[i]=="D"){
            if(!s.empty()){
                int num = s.top() ;
                //s.pop() ;
                num=num*2 ;
                ans+=num ;
                s.push(num) ;
                
            }
        } else if (v[i]=="+"){
            if(s.size()>=2){
                cout << "hi" << endl ;
                int num1 = s.top() ;
                s.pop() ;
                int num2 = s.top() ;
                s.push(num1) ;
                int num = num1+num2 ;
                ans+=num ;
                s.push(num) ;
            }
        } else {
            int num = strToInt(v[i]) ;
            ans+=num ;
            s.push(num) ;
        }
    }
    
    return ans ;
    
}


int main(){
    int n ;
    cin >> n ;
    vector<string> v ;
    string s ;
    for(int i=0 ; i<n ; ++i){
        cin >> s ;
        v.push_back(s) ;
    }
    cout << getAns(v, n) << endl ;
    
}


