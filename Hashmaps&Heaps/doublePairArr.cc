#include<iostream>

#include<map>
using namespace std;
bool canReorder(int arr[], int n) {
    
    map<int , int> m ;
    
    //freq map
    for(int i=0 ; i<n ; ++i){
        if(m.count(arr[i])>0){
            ++m[arr[i]] ;
        } else {
            m[arr[i]] = 1 ;
        }
    }
    
    map<int,int>::iterator it ;
    
    
    
    
    
    
    int ct = 0 ;
    
    for(it=m.begin() ; it!=m.end() ; ++it){
        int cur = it->first ;
        if(m[cur]==0){
            continue ;
        }
        
        
        if(cur==0){
            if(m[0]<2){
                return false ;
            } else {
                m[0]-=2 ;
                if(m[0]==0){
                    ++ct ;
                }
            }
        } else if(cur<0){
            
            // find for half
            if(cur%2!=0){
                // half wont exist
                return false ;
            }
            
            int h = cur/2 ;
            
            if(m.count(h)==0){
                return false ;
            } else {
                if(m[h] < m[cur]){
                    return false ;
                } else if(m[h]==m[cur]){
                    m[h] = 0 ;
                    m[cur] = 0 ;
                    ct+=2 ;
                } else if(m[h]>m[cur]){
                    m[h]-=m[cur] ;
                    m[cur] = 0 ;
                    ++ct ;
                }
            }
            
        } else if(cur>0){
            
            // find for double
            int d = cur*2 ;
            
            if(m.count(d)==0){
                return false ;
            } else {
                if(m[d] < m[cur]){
                    return false ;
                } else if(m[d]==m[cur]){
                    m[d] = m[cur] = 0 ;
                    ct+=2 ;
                } else if(m[d] > m[cur]){
                    m[d]-=m[cur] ;
                    m[cur] = 0 ;
                    ct++ ;
                }
            }
            
        }
        
        
        
        
    }
    return true ;
}

int main(int argc, char** argv) {
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    if(canReorder(a, size) == 0){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }
}
