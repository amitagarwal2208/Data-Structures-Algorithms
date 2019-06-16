#include <iostream>
#include <vector>
using namespace std;


void Transpose(int n , vector<vector<int> >& mat){
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<n ; ++j){
            if(i!=j){
                int temp = mat[i][j] ;
                mat[i][j] = mat[j][i] ;
                mat[j][i] = temp ;
            }
        }
    }
}


void Reverse(int n , vector<vector<int> >& arr){
    
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<(n/2) ; ++j){
            int temp = arr[j][i] ;
            arr[j][i] = arr[n-1-j][i] ;
            arr[n-1-j][i] = temp ;
        }
    }
}

void rotateMatrix(int n, vector<vector<int> >& mat) 
    { 
        //you need to write this function only
    
        Transpose(n,mat) ;
        Reverse(n,mat) ;
        
    } 
  
    
    static void displayMatrix(int N, vector<vector<int> >& mat) 
    { 
        for (int i = 0; i < N; i++) 
        { 
            for (int j = 0; j < N; j++) 
                cout<<mat[i][j]<<" "; 
       
            cout<<endl; 
        } 
    cout<<endl;
    } 

int main(){
	    int r;
        cin>>r;
        int c = r;
        vector<vector<int> > arr(r,vector<int>(c,0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin>>arr[i][j];
            }

        }

        rotateMatrix(r,arr); 
       displayMatrix(r,arr); 
	return 0;
}