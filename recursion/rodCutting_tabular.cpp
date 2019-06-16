#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std ;

void RodCutting(int* arr,int n,vector<int> & maxCostdp , vector<string> & cuts){
    
    int max , start , last , cur;
    string curstr = "" ;
    for(int i=1 ; i<n+1 ; ++i){
        max = arr[i] ;
        curstr = to_string(i) ;
        start = 1 ;
        last = i-1 ;
        
        while(last>0 && start<i && start<=last){
            cur = maxCostdp[start] + maxCostdp[last] ;
            if(cur>max){
                max = cur ;
                curstr = cuts[start] + cuts[last] ;
            }
            ++start ;
            --last ;
        }
        maxCostdp[i] = max ;
        cuts[i] = curstr ;
        
    }
    
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
