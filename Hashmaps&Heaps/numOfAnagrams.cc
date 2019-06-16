#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> findAnagrams(string& s,string& p){
    //write your code here
    
    
    unordered_map<char,int> m1 , m2 ;
    
    
    // fill up m2 completely
    
    int n2 = (int)p.size() ;
    int n1 = (int)s.size() ;
    for(int i=0 ; i<n2 ; ++i){
        
        char c = p[i] ;
        if(m2.count(c)>0){
            ++m2[c] ;
        } else {
            m2[c] = 1 ;
            m1[c] = 0 ;
        }
        
    }
    
    
    // fill up m1 from 0 to n2-1
    // maintain matchcount
    int matchct = 0 ;
    for(int i=0 ; i<n2 ; ++i){
        char c = s[i] ;
        if(m1.count(c)>0){
            
            if(m2.count(c)>0 && m1[c] < m2[c]){
                ++matchct ;
            }
            ++m1[c] ;
            
        } else {
            if(m2.count(c)>0){
                ++matchct ;
            }
            m1[c] = 1 ;
        }
    }
    vector<int> v ;
    
    int start = 0 , end=n2-1 ;
    int ans = 0 ;
    while(end<n1){
        
        //check if anagram
        
        if(matchct==n2){
            //anagram yes
            v.push_back(start) ;
            ++ans ;
        }
        
        //update subarray
        
        //remove start and increment
        char c = s[start] ;
        if(m2.count(c)>0){
            // kya remove hone se farak pada?
            if(m1[c]<=m2[c]){
                //kaam ka banda tha
                --matchct ;
            }
        }
        --m1[c] ;
        ++start ;
        
        
        
        
        
        //increment end and add
        ++end ;
        if(end>=n1) break ;
        c = s[end] ;
        if(m2.count(c)>0){
            if(m1[c]<m2[c]){
                ++matchct ;
            }
        }
        if(m1.count(c)>0){
            ++m1[c] ;
        } else {
            m1[c] = 1 ;
        }
        
    }
    //cout << ans << endl ;
    return v ;
    
}

int main(int argc,char** argv){
    string s;
    string p;
    getline(cin,s);
    getline(cin,p);
    vector<int> v;
    v=findAnagrams(s,p);
    //cout << v.size() << endl ;
    cout<<"[";
    int i=0;
    for(i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    
}
