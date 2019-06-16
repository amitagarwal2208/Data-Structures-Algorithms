#include <iostream>
#include<string>
#include<vector>
#include<map>
using namespace std ;


vector<vector<string> > findDuplicate(vector<string> paths){
    
    int n = (int)paths.size() ;
    map<string , vector<string> > m ;
    for(int i=0 ; i<n ; ++i){
        
        string s = paths[i] ;
        
        //find base path
        int curpos = 0 ;
        while(curpos<s.size() && s[curpos]!=' '){
            ++curpos ;
        }
        string basepath = s.substr(0,curpos) ;
        basepath.push_back('/') ;
        
        //update the string
        ++curpos ;
        s = s.substr(curpos) ;
        
        
        //find all files
        while(s.size()>0){
            curpos = 0 ;
            while(curpos<s.size() && s[curpos]!=' '){
                ++curpos ;
            }
            string curfile = s.substr(0,curpos) ;
            int idx = -1 ;
            for(int j=0 ; j<curfile.size() ; ++j){
                if(curfile[j]=='('){
                    idx = j ;
                    break ;
                }
            }
            
            string filename = curfile.substr(0,idx) ;
            string filecontent = curfile.substr(idx+1) ;
            filecontent.pop_back() ;
            
            if(m.count(filecontent)>0){
                m[filecontent].push_back(basepath+filename) ;
            } else {
                vector<string> v ;
                v.push_back(basepath+filename) ;
                m[filecontent] = v ;
            }
            
            
            //update string s
            if(curpos>=s.size()){
                s = "" ;
            } else {
                ++curpos ;
                s = s.substr(curpos) ;
            }
        }
        
        
    }
    
    vector<vector<string>> ans ;
    map<string , vector<string>>::iterator it ;
    for(it=m.begin() ; it!=m.end() ; ++it){
        vector<string> vs = it->second ;
        sort(vs.begin() , vs.end()) ;
        ans.push_back(vs) ;
    }
    
    return ans ;
}




int main(){
    string s ;
    int n ;
    cin >> n ;
    
    vector<string> paths ;
    getline(cin,s) ;
    for(int i=0 ; i<n ; ++i){
        getline(cin,s) ;
        paths.push_back(s) ;
    }
    
    //cout << paths[0] << endl ;
    vector<vector < string > > ans=findDuplicate(paths);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j!=ans[i].size()-1){
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }
}
    

