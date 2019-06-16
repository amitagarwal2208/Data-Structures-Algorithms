#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std ;

void RodCutting(int* arr,int n,vector<int> & maxCostdp , vector<string> & cuts){
    
    
    if(n<0){
        return ;
    }
    
    if(maxCostdp[n]!=-1){
        return ;
    }
    
    
    int max = arr[n] ;
    int start=1 , last=n-1 ;
    int cur ;
    string str = to_string(n) ;
    while(start<=last){
        
        RodCutting(arr, start, maxCostdp, cuts) ;
        RodCutting(arr, last, maxCostdp, cuts) ;
        cur = maxCostdp[start] + maxCostdp[last] ;
        
        if(cur > max){
            max = cur ;
            str = cuts[start]+cuts[last] ;
        }
        
        
        ++start ;
        --last ;
        
    }
    
    maxCostdp[n] = max ;
    cuts[n] = str ;
    
    
}


pair<int, string> RodCutting(int* arr , int n){
    
    vector<int> maxCostdp(n+1,-1) ;
    vector<string> cuts(n+1,"") ;
    maxCostdp[0] = 0 ;
    
    RodCutting(arr, n, maxCostdp, cuts) ;
    
    
    
    return make_pair(maxCostdp[n], cuts[n]) ;
    
}


int main(){
    
    int n ;
    cin >> n ;
    
    int* arr = new int[n+1] ;
    for(int i=0 ; i<n+1 ; ++i){
        cin >> arr[i] ;
    }
    
    pair<int,string> ans = RodCutting(arr,n) ;
    cout << ans.first << endl ;
    cout << ans.second << endl ;
    
}
