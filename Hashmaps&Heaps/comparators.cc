#include <iostream>
#include<queue>

using namespace std ;
bool mycmp(int &a , int &b){
    return a>b ;
}

class mycmp2{
public:
    
    bool operator() (int a , int b){
        return a>b ;
    }
    
};


int main(){
    
    int arr[5] = {4,1,3,5,2} ;
    sort(arr,arr+5,mycmp) ;
    for(int i=0 ; i<5 ; ++i){
        cout << arr[i] << " " ;
    }
    cout << endl ;
    
    priority_queue<int , vector<int> , mycmp2> pq ;
    for(int i=1 ; i<=5 ; ++i){
        pq.push(i) ;
    }
    cout << pq.top() << endl ;
    
    
}
