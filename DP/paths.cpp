#include <iostream>
#include <vector>

using namespace std;

void PrintDP(int** dp , int r , int c){

    cout << endl ;

    for(int i=0 ; i<r ; ++i){
        for(int j=0 ; j<c ; ++j){
            cout << dp[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;
}



int countWays(vector<vector<int> >& arr , int curx , int cury , int maxx , int maxy , int** dp , int prev,int movt[4][2]){
    

    if(curx==maxx && cury==maxy){
        return 1 ;
    }
    
    if(curx<0 || cury<0 || curx>maxx || cury>maxy){
        return 0 ;
    }
    
    
    if(dp[curx][cury]!=-1){
        return dp[curx][cury] ;
    }
    
    
    int dontgo = prev+2 ;
    dontgo = dontgo%4 ;
    
    int curans = 0 ;
    for(int cur=0 ; cur<4 ; ++cur){
        if(cur!=dontgo){
            curans+=countWays(arr,curx+movt[cur][0],cury+movt[cur][1],maxx,maxy,dp,cur,movt) ;
        }
    }
    
    dp[curx][cury] = curans ;
    return curans ;
    
}




int countWays(vector<vector<int> > arr)
{
    //WRITE YOUR CODE HERE ONLY
    int r = arr.size() ;
    int c = arr[0].size() ;
    
    int** dp = new int*[r] ;
    for(int i=0 ; i<r ; ++i){
        dp[i] = new int[c] ;
        for(int j=0 ; j<c ; ++j){
            if(arr[i][j]==0){
                dp[i][j]=0 ;
            } else {
                dp[i][j]=-1 ;
            }
        }
    }
    dp[r-1][c-1] = 1 ;
    
    // 0 : east
    // 1 : south
    // 2 : west
    // 3 : north
    
    int movt[4][2] = {
        {0,1} ,
        {1,0} ,
        {0,-1} ,
        {-1,0}
    } ;
    

    int ans = countWays(arr,0,0,r-1,c-1,dp,0,movt) ;
    //PrintDP(dp,r,c) ;
    return ans ;
    
    
}
int main(int argc, char** argv)
{
    int row, col;
    cin>>row;
    cin>>col;
    vector<vector<int> > matrix(row, vector<int>(col,0));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++){
            cin>>matrix[i][j];
        }
        cout<<countWays(matrix);    
            
}