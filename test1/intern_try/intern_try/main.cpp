#include <iostream>
#include<queue>
using namespace std;

int main() {
    //code
    int n ;
    cin >> n ;
    
    priority_queue<int> maxpq ;
    priority_queue<int,vector<int>,greater<int> > minpq ;
    
    int x ;
    for(int i=0 ; i<n ; ++i){
        cin >> x ;
        //cout << "x : "<<x << " " ;
        if(maxpq.empty() && minpq.empty()){
            minpq.push(x) ;
            cout << x << endl ;
        } else {
            
            if(!maxpq.empty() && x<=maxpq.top()){
                if(maxpq.size() <=minpq.size()){
                    // can push to maxpq
                    maxpq.push(x) ;
                    if(maxpq.size()==minpq.size()){
                        cout << (maxpq.top() + minpq.top())/2 << endl ;
                    } else if(maxpq.size() == minpq.size()+1){
                        cout << maxpq.top() << endl ;
                    }
                } else {
                    // cannot push to maxpq
                    minpq.push(maxpq.top()) ;
                    maxpq.pop() ;
                    maxpq.push(x) ;
                    cout << (maxpq.top() + minpq.top())/2 << endl ;
                }
                
                
            } else if(!minpq.empty() && x>=minpq.top()){
                if(minpq.size()<=maxpq.size()){
                    // can push to minpq
                    minpq.push(x) ;
                    if(maxpq.size()==minpq.size()){
                        cout << (maxpq.top() + minpq.top())/2 ;
                    } else if(maxpq.size()+1 == minpq.size()){
                        cout << minpq.top() << endl ;
                    }
                } else {
                    //cannot push to minpq
                    maxpq.push(minpq.top()) ;
                    minpq.pop() ;
                    minpq.push(x) ;
                    cout << (maxpq.top() + minpq.top())/2 << endl ;
                }
            } else {
                if(minpq.size()==maxpq.size()){
                    minpq.push(x) ;
                    cout << x << endl ;
                } else if(minpq.size()>maxpq.size()){
                    maxpq.push(minpq.top()) ;
                    minpq.pop() ;
                    minpq.push(x) ;
                    cout << (maxpq.top() + minpq.top())/2 << endl ;
                } else {
                    minpq.push(maxpq.top()) ;
                    maxpq.pop() ;
                    maxpq.push(x) ;
                    cout << (maxpq.top() + minpq.top())/2 << endl ;
                }
            }
            
        }
        
    }
    
    
    return 0;
}
