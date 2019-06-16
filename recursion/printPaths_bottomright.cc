#include<iostream>
#include <vector>
#include<string>
using namespace std ;


int ct = 0 ; 

void PrintPaths(vector<vector<int> > maze,int curx ,int cury,int maxx , int maxy , string ansSoFar , vector<vector<bool> > visited){
	if(curx<0 || cury<0 || curx>maxx || cury>maxy){
		return ;
	}

	if(maze[curx][cury]==0){
		return ;
	}

	if(curx==maxx && cury==maxy){
		cout << ++ct << ". " << ansSoFar << endl ;
		return ;
	}

	if(visited[curx][cury]){
		return ;
	}
	visited[curx][cury] = true ;

	//right
	ansSoFar.push_back('R');
	PrintPaths(maze,curx,cury+1,maxx,maxy,ansSoFar,visited) ;
	ansSoFar.pop_back() ;
	ansSoFar.push_back('D');
	PrintPaths(maze,curx+1,cury,maxx,maxy,ansSoFar,visited) ;
	ansSoFar.pop_back() ;
	ansSoFar.push_back('L');
	PrintPaths(maze,curx,cury-1,maxx,maxy,ansSoFar,visited) ;
	ansSoFar.pop_back() ;
	ansSoFar.push_back('U');
	PrintPaths(maze,curx-1,cury,maxx,maxy,ansSoFar,visited) ;
	ansSoFar.pop_back() ;

}



void PrintPaths(vector<vector<int> > maze , int r , int c){

	string ansSoFar = "" ;

	vector<vector<bool> > visited(r,vector<bool>(c,false)) ;

	PrintPaths(maze,0,0,r-1,c-1,ansSoFar,visited) ;

}




int main(){
	int row, col;
    cin>>row;
    cin>>col;
    vector<vector<int> > matrix(row, vector<int>(col,0));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++){
            cin>>matrix[i][j];
        }

    PrintPaths(matrix , row , col) ;
}