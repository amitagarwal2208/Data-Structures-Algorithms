#include<iostream>
#include<vector>
using namespace std;

    
    
    

    void exitPoint(vector<vector<int> >& arr) {
        // Write your code only here.
        
        int curx = 0 ;
        int cury = 0 ;
        
        int r = arr.size() ;
        int c = arr[0].size() ;
        
        int move[4][2] = {
            {0,1} ,
            {1,0} ,
            {0,-1} ,
            {-1,0} 
        } ;
        
        int cur = 0 ;
        
        while(curx!=r && cury!=c && curx>=0 && cury>=0){
            if(arr[curx][cury]==0){
                curx+=move[cur][0] ;
                cury+=move[cur][1] ;
            } else {
                ++cur ;
                cur = cur%4 ;
                curx+=move[cur][0] ;
                cury+=move[cur][1] ;
            }
        }
        
        if(curx==r){
            --curx ;
        } else if(cury==c){
            --cury ;
        } else if(curx<0){
            ++curx ;
        } else if(cury<0){
            ++cury ;
        }
        
        cout << curx<<", "<<cury<<endl ;
        
    }



    // This is a functional problem. 
    // Input is managed for you.
    // Don't change main, write your code in the function below

    int main() {
        int r;
        cin>>r;
        int c;
        cin >> c;
        vector<vector<int> > arr(r,vector<int>(r,0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin>>arr[i][j];
            }

        }
        exitPoint(arr);
    }