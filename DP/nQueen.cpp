#include<iostream>
#include<string>
#include<vector>
using namespace std ;

void SetBoard(vector<vector<bool> > & arr){
	int n = arr.size();

	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			arr[i][j] = false ;
		}
	}
}

void AppendAns(string & ans , int currow ,int curcol){
	
	string a = to_string(currow) ;
	string b = to_string(curcol) ;

	string s = "[" ;
	s.append(a).append("-").append(b).append("]") ;
	ans.append(s) ;

}

bool canPlace(vector<vector<bool> >& arr , int r , int c , int n){
    
    int ans = true ;
    
    //check vertically
    for(int currow=0 ; currow<n ; ++currow){
        if(arr[currow][c]){
            ans = false ;
            return ans ;
        }
    }
    //cout << "v" << ans << endl ;
    
    //check horizontally
    for(int curcol=0 ; curcol<n ; ++curcol){
        if(arr[r][curcol]){
            ans = false ;
            return ans ;
        }
    }
    
    //cout << "h"<<ans << endl ;
    
    // check upper left diagonal
    int x=r , y=c ;
    --x ;
    --y ;
    while(x>=0 && y>=0){
        
        if(arr[x][y]){
            ans = false ;
            return ans ;
        }
        --x ;
        --y ;
    }
    
    //cout << "ul"<< ans << endl ;
    
    x=r ;
    y=c ;
    
    // check upper right diagonal
    --x ;
    ++y ;
    while(x>=0 && y<n){
        
        if(arr[x][y]){
            ans = false ;
            return ans ;
        }
        --x ;
        ++y ;
    }
    
   // cout << "ur"<<ans << endl ;
    
    x=r ;
    y=c ;
    
    // check lower left diagonal
    ++x ;
    --y ;
    while(x<n && y>=0){
        
        if(arr[x][y]){
            ans = false ;
            return ans ;
        }
        ++x ;
        --y ;
    }
    
  //  cout << "ll"<<ans << endl ;
    x=r ;
    y=c ;
    
    // check lower right diagonal
    ++x ;
    ++y ;
    while(x<n && y<n){
        
        if(arr[x][y]){
            ans = false ;
            return ans ;
        }
        ++x ;
        ++y ;
    }
    
    return ans ;
    
}

bool nQueen(vector<vector<bool> > & arr , int currow , string ans , int n){


	if(currow==n){
		return true ;
	}

	for(int curcol=0 ; curcol<n ; ++curcol){
		if(canPlace(arr,currow,curcol,n)){
			arr[currow][curcol] = true ;
			AppendAns(ans,currow,curcol) ;

			bool remBoard = nQueen(arr,currow+1,ans,n) ;
			if(remBoard){
				return true ; 
			}

			ans.pop_back() ;

		}
	}
	return false ;

}




void nQueen(vector<vector<bool> > & arr , int currow , string ans){


	int n = arr.size() ;
	SetBoard(arr) ;

	for(int curcol=0 ; curcol<n ; ++curcol){

		arr[currow][curcol] = true ;
		AppendAns(ans,currow,curcol) ;

		bool remBoard = nQueen(arr,currow+1,ans,n) ;
		if(remBoard){
			cout << ans << endl ;
		}

		ans.empty() ;
		SetBoard(arr) ;
	}



}





int main(int argc,char** argv) {
           int n;
           cin>>n;
        
        vector<vector<bool> > arr(n,vector<bool>(n,false));
        nQueen(arr, 0, "");
		return 0;
    }