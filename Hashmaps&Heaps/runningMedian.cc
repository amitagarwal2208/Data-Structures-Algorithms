#include <iostream>
#include<queue>
#include <iomanip>
using namespace std;



int main() {
    //code
    int n = 1  ;
    cin >> n ;
    
    priority_queue<double> maxpq ;
    priority_queue<double,vector<double>,greater<double> > minpq ;
    std::cout << setprecision(1) << fixed;
    double x ;
    cin >> x ;
    cout << (double)x << endl ;
    maxpq.push(x) ;
    
    if(n<2){
        return 0 ;
    }
    
    cin >> x ;
    if(x<=maxpq.top()){
        minpq.push(maxpq.top()) ;
        maxpq.pop() ;
        maxpq.push(x) ;
    } else {
        minpq.push(x) ;
    }
    cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
    
    for(int i=2 ; i<n ; ++i){
        
        cin >> x ;
        
        if(x<=maxpq.top()){
            if(maxpq.size()<=minpq.size()){
                maxpq.push(x) ;
                if(maxpq.size()==minpq.size()){
                    cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
                } else {
                    cout << (double)maxpq.top() << endl ;
                }
            } else {
                minpq.push(maxpq.top()) ;
                maxpq.pop() ;
                maxpq.push(x) ;
                cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
            }
        } else if(x>=minpq.top()){
            if(minpq.size()<=maxpq.size()){
                minpq.push(x) ;
                if(minpq.size()==maxpq.size()){
                    cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
                } else {
                    cout << (double)minpq.top() << endl ;
                }
            } else {
                maxpq.push(minpq.top()) ;
                minpq.pop() ;
                minpq.push(x) ;
                cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
            }
        } else {
            if(maxpq.size() == minpq.size()){
                maxpq.push(x) ;
                cout << (double)maxpq.top() << endl ; ;
            } else if(maxpq.size()>minpq.size()){
                minpq.push(x) ;
                cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
            } else {
                maxpq.push(x) ;
                cout << (double)(maxpq.top()+minpq.top())/2.0 << endl ;
            }
        }
        
        
        
        
    }
    
    
    return 0;
}


