#include<iostream>
 #include<vector>
 #include<queue>
 #include<stack>
 #include<algorithm>
 #include<bits/stdc++.h>
 using namespace std;
 
 //#typedef p pair<int,int> ; 
 
 
 class comp{
public:
    bool operator() (const pair<int,int>& p1 , const pair<int,int>& p2){
        return p2.first < p1.first ;
    }
     
 };
 
 
 //you can use a comparator if you want
 //write code here
 int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
     
     int n = profit.size() ;
     
     
     priority_queue<pair<int,int> ,vector<pair<int,int>> , comp > minpq ; 
     for(int i=0 ; i<n ; ++i){
         minpq.push(make_pair(capital[i] , profit[i])) ;
     }
     
     priority_queue<int> pq ;
     for(int i=0 ; i<k ; ++i){
         while(minpq.empty()==false && minpq.top().first<=w){
             pair<int,int> cur = minpq.top() ;
             pq.push(cur.second) ;
             
             minpq.pop() ;
         }
         
         if(pq.empty()){
             break ;
         }
         
         int prof = pq.top() ;
         pq.pop() ;
         w+=prof ;
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