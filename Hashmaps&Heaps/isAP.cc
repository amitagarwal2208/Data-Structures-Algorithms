#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include<unordered_map>
 
 using namespace std;
 
 // ------------------------------------------------------
 bool checkAP(vector<int> &arr)
 {
     // write your code here
     unordered_map<int,int> m ;
     int n  = arr.size() ;
     int max = arr[0] , min=arr[0] ;
     for(int i=0 ; i<n ; ++i){
         if(m.count(arr[i]>0)){
             ++m[arr[i]] ;
         } else {
             m[arr[i]] = 1 ;
         }
         if(arr[i]>max) max = arr[i] ;
         if(arr[i]<min) min = arr[i] ;
     }
     
     
     double d = (max-min)/(double)(n-1) ;
     
     if(d==0 && m[max]>1){
         return true ;
     }
     
     for(int i=1 ; i<=n-2 ; ++i){
         if(m.count(min+i*d)>0 && m[min+i*d]==1){
             continue ;
         } else return false ;
     }
     
     return true ;
     
     
     
 }
 // ------------------------------------------------------
 
 // Do not change the main Method
 int main()
 {
     int n = 0;
     cin >> n;
     vector<int> num(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> num[i];
     }
     if (checkAP(num))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
 
     return 0;
 }