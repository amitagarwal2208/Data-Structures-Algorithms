#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std ;

struct mypair{
    int i1 ;
    int i2 ;
    int val ;
    mypair(int a , int b , int c){
        i1=a;
        i2=b;
        val=c ;
    }
};

bool mycmp(mypair a , mypair b){
    return a.val < b.val ;
}

int ctQuadTargetSum(int* arr , int n , int k){
    
    unordered_map<string, int> m ;
    vector<mypair> v ;
    for(int i=0 ; i<n ; ++i){
        for(int j=i+1 ; j<n ; ++j){
            mypair p(i,j,arr[i]+arr[j]) ;
            v.push_back(p) ;
        }
    }
    int ans = 0 ;
    
    sort(v.begin() , v.end() , mycmp) ;
    for(int i=0 ; i<v.size() ; ++i){
        cout << v[i].i1 << " " << v[i].i2 << " " << v[i].val << endl ;
    }
    int start = 0 ;
    int end = v.size()-1 ;
    while(start<end){
        int cursum = v[start].val + v[end].val ;
        if(v[start].i1!=v[end].i1
           &&
           v[start].i1!=v[end].i2
           &&
           v[start].i2!=v[end].i1
           &&
           v[start].i2!=v[end].i2
           
           ){
            if(cursum==k){
                //cout << "hi" << start << end << endl ;
                ++ans ;
                ++start ;
                //--end ;
            } else if(cursum<k){
                ++start ;
            } else {
                --end ;
            }
        } else {
            ++start ;
            --end ;
        }
    }
    return ans ;
}



int main(){
    
    int n ,k;
    cin >> n >> k;
    int* arr = new int[n] ;
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
    cout << ctQuadTargetSum(arr, n, k) << endl ;
}
