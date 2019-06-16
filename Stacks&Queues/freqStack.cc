#include<iostream>
#include<stack>
#include <unordered_map>
using namespace std ;


class freqStack{
    unordered_map<int, int> m1 ;
    unordered_map<int , stack<int> > m2 ;
    int mf=0 ;
    
public:
    
    void push(int x){
        if(m1.count(x)>0){
            ++m1[x] ;
        } else {
            m1[x]=1 ;
        }
        if(m1[x]>mf){
            mf=m1[x] ;
            stack<int> s ;
            s.push(x) ;
            m2[mf] = s ;
        } else {
            m2[m1[x]].push(x) ;
        }
        
    }
    
    int pop(){
        int t = m2[mf].top() ;
        --m1[t] ;
        if(m1[t]==0){
            m1.erase(t) ;
        }
        m2[mf].pop() ;
        if(m2[mf].empty()){
            m2.erase(mf) ;
            --mf ;
        }
        return t ;
    }
    
    
    
    
};

int main(){
    int n ;
    cin >> n ;
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    
    freqStack fs ;
    
    for(int i=0 ; i<n ; ++i){
        if(arr[i]==1){
            ++i ;
            fs.push(arr[i]) ;
        } else if(arr[i]==2){
            int t = fs.pop() ;
            cout << t << " " ;
        }
    }
    cout << endl ;
    
    
    
}
