#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
#include<vector>


using namespace std ;


struct mypair{
    int x ;
    int y ;
    int time ;
    mypair(int a , int b , int c){
        x=a ;
        y=b ;
        time = c ;
    }
};





int minTime(int arr[8][7]){
    bool** visited = new bool*[8] ;
    for(int i=0 ; i<8 ; ++i){
        visited[i] = new bool[7] ;
        for(int j=0 ; j<7 ; ++j){
            visited[i][j] = false ;
        }
    }
    
    queue<mypair> q ;
    
    for(int i=0 ; i<8 ; ++i){
        for(int j=0 ; j<7 ; ++j){
            if(arr[i][j]==2){
                mypair p(i,j,0) ;
                q.push(p) ;
            }
        }
    }
    int max = 0 ;
    while(q.empty()==false){
        
        //get
        mypair cur = q.front() ;
        
        //remove
        q.pop() ;
        
        //mark
        visited[cur.x][cur.y] = true ;
        
        //work
        
        
        //add
        int r,c ;
        
        // add top
        r = cur.x-1 ;
        c = cur.y ;
        if(r>=0 && arr[r][c]==1 && visited[r][c]==false){
            mypair p(r,c,cur.time+1) ;
            max = cur.time+1 ;
            q.push(p) ;
        }
        
        // add right
        r = cur.x ;
        c = cur.y+1 ;
        if(c<7 && arr[r][c]==1 && visited[r][c]==false){
            mypair p(r,c,cur.time+1) ;
            max = cur.time+1 ;
            q.push(p) ;
        }
        
        // add bottom
        r = cur.x+1 ;
        c = cur.y ;
        if(r<8 && arr[r][c]==1 && visited[r][c]==false){
            mypair p(r,c,cur.time+1) ;
            max = cur.time+1 ;
            q.push(p) ;
        }
        
        // add left
        r = cur.x ;
        c = cur.y-1 ;
        if(c>=0 && arr[r][c]==1 && visited[r][c]==false){
            mypair p(r,c,cur.time+1) ;
            max = cur.time+1 ;
            q.push(p) ;
        }
        
    }
    
    
    //int ans = 0 ;
    for(int i=0 ; i<8 ; ++i){
        for(int j=0 ; j<7 ; ++j){
            if(arr[i][j]==1 && visited[i][j]==false){
                return -1 ;
            }
        }
    }
    return max ;
    
}


int main(){
    int arr[8][7]={
        {0,1,0,0,0,1,0},
        {1,1,1,0,0,1,1},
        {0,2,0,0,0,1,0},
        {0,0,0,1,1,1,0},
        {0,1,0,2,1,0,0},
        {2,1,0,0,1,1,0},
        {0,1,1,0,0,0,0},
        {0,0,0,1,1,1,0}
    };
    
    // 0 : empty
    // 1 : fresh
    // 2 : rotten
    cout << minTime(arr) << endl ;
}






