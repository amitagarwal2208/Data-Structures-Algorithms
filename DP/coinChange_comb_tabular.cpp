#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std ;



int coinChangeComb(int* denoms , int n,int amt){
    
    vector<int> dp(amt+1 , 0) ;
    dp[0] = 1 ;
    vector<vector<string> > v(amt+1) ;
    v[0].push_back("") ;
    
    for(int i=0 ; i<n ; ++i){
        int curd = denoms[i] ;
        for(int curamt=1 ; curamt<=amt ; ++curamt){
            if(curamt-curd>=0){
                dp[curamt]+=dp[curamt-curd] ;
                for(int j=0 ; j<dp[curamt-curd];++j){
                    v[curamt].push_back(v[curamt-curd][j]+to_string(curd));
                }
            }
        }
    }
    
    for(int i=0 ; i<=amt ; ++i){
        cout << i << " : " ;
        for(int j=0 ; j<dp[i] ; ++j){
            cout << v[i][j] << " , " ;
        }
        cout << endl ;
    }
    return dp[amt];
    
}



int main(){
    
    int n ;
    cin >> n ;
    
    int* denoms = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> denoms[i] ;
    }
    
    int amt ;
    cin >> amt ;
    
    int ans = coinChangeComb(denoms, n, amt) ;
    cout << ans << endl ;
    
    
}
