#include<iostream>
 #include<vector>
 #include<queue>
 #include<algorithm>
 #include<bits/stdc++.h>
 using namespace std;
 
 //you can use a comparator if you want
 //write code here
 
 
 struct mypair{
     int cost ;
     int prof ;
     mypair(){
         cost=0 ; 
         prof = 0 ;
     }
     mypair(int x , int y){
         cost = x ;
         prof = y ;
     }
 };
 
 bool comp(mypair a , mypair b){
     return a.cost < b.cost ;
 }
 
 int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
     int n = profit.size() ;
     mypair* v = new mypair[n];
     for(int i=0 ;  i<n ; ++i){
         mypair p(capital[i] , profit[i]) ;
         v[i] = p ;
     }
     
     sort(v,v+n,comp) ;
     stack<mypair> s ;
     for(int i=n-1 ; i>=0 ; --i){
         s.push(v[i]) ;
     }
     
     int ans = 0 ;
     
     priority_queue<int> pq ;
     
     for(int i=0 ; i<k ; ++i){
         //prepare pq
         while(s.empty()==false && s.top().cost<=w){
             pq.push(s.top().prof) ;
             s.pop() ;
         }
         
         //extract
         if(pq.empty()){
             break ;
         }
         int curp = pq.top() ;
         pq.pop() ;
         w+=curp ;
         
     }
     return w ;
 }
 
 int main(int argc, char** argv){
     int k, w;
     cin>>k>>w;
 
     int n;
     cin>>n;
     vector<int> profits;
     vector<int> capital;
 
     for (int i = 0; i < n; i++) {
         int a;
         cin>>a;
         profits.push_back(a);
     }
 
     for (int i = 0; i < n; i++) {
         int a;
         cin>>a;
         capital.push_back(a);
     }
 
     cout<<findMaximizedCapital(k, w, profits, capital);
 }