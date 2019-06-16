#include <iostream>
#include <vector>

using namespace std;


int countPaths(vector<vector<int> > maze , int curx , int cury , int maxx , int maxy , vector<vector<bool> > visited){

    if(curx<0 || cury <0 || curx>maxx || cury>maxy){
        return 0 ;
    }

    if(maze[curx][cury]==0){
        return 0 ;
    }

    if(curx==maxx && cury==maxy){
        return 1 ;
    }

    if(visited[curx][cury]){
        return 0 ;
    }



    visited[curx][cury] = true ;

    int curans = 0 ;

    //right
    curans+=countPaths(maze,curx,cury+1,maxx,maxy,visited) ;
    //down
    curans+=countPaths(maze,curx+1,cury,maxx,maxy,visited) ;
    //left
    curans+=countPaths(maze,curx,cury-1,maxx,maxy,visited) ;
    //up
    curans+=countPaths(maze,curx-1,cury,maxx,maxy,visited) ;

    return curans ;


}


int countWays(vector<vector<int> > maze){
    
    int r = maze.size() ;
    int c = maze[0].size() ;
    
    vector<vector<bool> > visited(r, vector<bool>(c,false));
    //cout << "hi" << endl ;
    return countPaths(maze,0,0,r-1,c-1,visited) ;
    
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
        //cout << "hi" << endl ;
        cout<<countWays(matrix);    
            
}