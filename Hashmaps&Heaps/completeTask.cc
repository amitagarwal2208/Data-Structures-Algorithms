#include <iostream>
 #include <vector>
 #include <unordered_set>
 
 using namespace std;
 
 // -------------------------------------------------------
 void completeTask(int n, int m, vector<int> &comp)
 {
     // Write Your Code here;
     //vector<int> v1,v2 ;
     unordered_set<int> s ;
     for(int i=0 ; i<m ; ++i){
         s.insert(comp[i]) ;
     }
     bool flag = true ;
     for(int i=1 ; i<=n ; ++i){
         
         if(s.count(i)>0){
             //completed
             continue ;
         } else {
             if(flag){
                 s.insert(i);
                 cout << i << " " ;
                 flag = false ;
             } else {
                 flag = true ;
             }
         }
     }
     cout << endl ;
     for(int i=1 ; i<=n ; ++i){
         if(s.count(i)==0){
             cout << i << " " ;
         }
     }
     cout << endl ;
     
 }
 // -------------------------------------------------------
 
 int main(int argc, char *argv[])
 {
     int n = 0, m = 0;
     cin >> n >> m;
     vector<int> num(m);
     for (int i = 0; i < m; i++)
     {
         cin >> num[i];
     }
     completeTask(n, m, num);
     return 0;
 }