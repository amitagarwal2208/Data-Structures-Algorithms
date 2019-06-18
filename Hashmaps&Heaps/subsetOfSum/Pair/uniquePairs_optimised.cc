#include <iostream>
#include<queue>
#include <iomanip>
#include <vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


int ctUniquePairTargetSum(int* arr , int n , int k){
    
    //Duplicacy not allowed
    
    unordered_map<int , int> m ;
    for(int i=0 ; i<n ; ++i){
        if(m.count(arr[i])>0){
            ++m[arr[i]] ;
        } else {
            m[arr[i]]=1 ;
        }
    }
    
    int ct=0 ;
    for(int i=0 ; i<=(k/2) ; ++i){
        if(k%2==0 && i==(k/2)){
            if(m[i]>=2){
                ++ct ;
            }
        }
        else if(m.count(i)>0 && m.count(k-i)>0){
            ++ct ;
        }
    }
    return ct ;
}

vector<vector<int>> printUniquePairTargetSum(int* arr , int n , int k){
    
    vector<vector<int>> ans ;
    
    unordered_map<int, int> m ;
    for(int i=0 ; i<n ; ++i){
        if(m.count(arr[i])>0){
            ++m[arr[i]] ;
        } else {
            m[arr[i]]=1 ;
        }
    }
    
    for(int i=0 ; i<=(k/2) ; ++i){
        if(k%2==0 && i==(k/2) && m.count(i)>=2){
            vector<int> v ;
            v.push_back(i) ;
            v.push_back(k-i) ;
            ans.push_back(v) ;
        }
        
        if(m.count(i)>0 && m.count(k-i)>0){
            vector<int> v ;
            v.push_back(i) ;
            v.push_back(k-i) ;
            ans.push_back(v) ;
        }
    }
    
    
    return ans ;
    
}




int main() {
    // Find pair - Duplicacy not allowed
    // Count and return only unique Pairs
    // O(N) solution using hashmap
    int n ,k;
    cin >> n >> k;
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    cout << ctUniquePairTargetSum(arr, n, k) << endl ;
    
    vector<vector<int>> ans = printUniquePairTargetSum(arr, n, k) ;
    for(int i=0 ; i<ans.size() ; ++i){
        for(int j=0 ; j<2 ; ++j){
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
    
    return 0;
}



//13 8
//2 2 3 4 4 5 5 5 6 6 7 7 7
//3
//2 6
//3 5
//4 4





