#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input an array A and a sum S.
// You have to return the number of subarrays with sum S.

int numSubarraysWithSum(vector<int> v, int sum) {
    // write your code here.
    int ct = 0 ;
    unordered_map<int, int> m ;
    int cursum = 0 ;
    m[0] = 1 ;
    int n = (int)v.size() ;
    
    if(sum==0){
        int i=0 , j=0 ;
        while(i<n && j<n){
            while(j<n && v[j]==0){
                ++j ;
            }
            if(j==i){
                ++j ;
                ++i ;
                continue ;
            }
            int cur = j-i ;
            ct+=(cur*(cur+1)/2) ;
            i=j ;
        }
        return ct ;
    }
    
    
    
    for(int i=0 ; i<n ; ++i){
        cursum+=v[i] ;
        
        //update map
        if(m.count(cursum)>0){
            ++m[cursum] ;
        } else {
            m[cursum] = 1 ;
        }
        
        //check for subarray with sum
        if(m.count(cursum-sum)>0){
            ct+=m[cursum-sum] ;
        }
        
    }
    
    return ct ;
}

int main(int args,char** argv) {
    // Taking input for the array.
    int N; cin>>N;
    vector<int> array(N,0);
    
    for (int i = 0; i < N; i++) {
        cin>>array[i];
    }
    
    // Taking input for sum.
    int sum;cin>>sum;
    
    cout<<(numSubarraysWithSum(array, sum));
    
}
