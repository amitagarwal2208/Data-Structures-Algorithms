#include<iostream>
 #include<bits/stdc++.h> 
 using namespace std; 
   
 // Method to count number of substring which 
 // has equal 0, 1 and 2 
 //write your code here
 
 
 int fact(int n){
     
     if(n==0 || n==1){
         return 1 ;
     }
     int ans = 1 ;
     for(int i=n ; i>=1 ; --i){
         ans=ans*i ;
     }
     return ans ;
     
 }
 
 
 
 int nC2(int n){
     
     return fact(n)/(2*fact(n-2)) ;
     
 }
 
 
 int getSubstringWithEqual012(string arr) 
 { 
     
     int ct0=0 , ct1=0 , ct2=0 ;
     int n = (int)arr.size() ;
     
     unordered_map<string , int> m ;
     m["00"] = 1 ;
     for(int i=0 ; i<n ; ++i){
         if(arr[i]=='0'){
             ++ct0 ;
         } else if(arr[i]=='1'){
             ++ct1 ;
         } else if(arr[i]=='2'){
             ++ct2 ;
         }
         string curstr = "" ;
         
         int d1 = ct1 - ct0 ;
         int d2 = ct2 - ct1 ;
         
         curstr.append(to_string(d1)) ;
         curstr.append(to_string(d2)) ;
         //cout << curstr << " " ;
         if(m.count(curstr)>0){
             ++m[curstr] ;
         } else {
             m[curstr] = 1 ;
         }
         
     }
     int ans = 0 ;
     unordered_map<string,int>::iterator it ;
     for(it=m.begin() ; it!=m.end() ; ++it){
         int ct = it->second ;
         if(ct<2){
             continue ;
         } else {
             ans+=(nC2(ct)) ;
         }
         
         
     }
     return ans ;
     
 } 
   
 int main(int argc, char** argv) 
 { 
     string str;
     cin>>str; 
     cout << getSubstringWithEqual012(str) << endl; 
     return 0; 
 }