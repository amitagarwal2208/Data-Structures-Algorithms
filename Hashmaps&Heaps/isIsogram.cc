#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 // --------------------------------------
 bool isIsogram(string &data)
 {
     // write your code here
     unordered_set<char> s;
     int n = data.size() ;
     for(int i=0 ; i<n ; ++i){
         char c = data[i] ;
         if(s.count(c)>0){
             return false ;
         } else s.insert(c) ;
     }
     return true ;
 }
 // --------------------------------------
 
 int main()
 {
     string s;
     cin >> s;
 
     if (isIsogram(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }