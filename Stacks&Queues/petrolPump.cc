#include <iostream>
using namespace std ;

void GetInput(int* arr , int n){
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
}

int getStartingPoint(int* oilFilled , int* nextPPdist , int n){
    
    int start = 0 ;
    int end = 0 ;
    int sparePetrol = 0 ;
    int journey = 0 ;
    
    while(true){
        
        if(journey==n){
            if(sparePetrol>=0){
                return start ;
            } else {
                return -1 ;
            }
        }
        
        
        
        if(sparePetrol<0){
            // last journey did not happen
            
            if(end<start){
                return -1 ;
            }
            
            start = end ;
            sparePetrol = 0 ;
            journey = 0 ;
        }
        
        
        // Fill oil
        sparePetrol+=oilFilled[end] ;
        // do journey
        sparePetrol-=nextPPdist[end] ;
        ++end ;
        end = end%n ;
        ++journey ;
    }
    
    return -1 ;
    
    
}


int main(){
    int n ;
    cin >> n ;
    int* oilFilled = new int[n] ;
    int* nextPPdist = new int[n] ;
    
    GetInput(oilFilled, n) ;
    GetInput(nextPPdist, n);
    int ans = getStartingPoint(oilFilled,nextPPdist,n) ;
    cout << ans << endl ;
}

//6
//15
//61
//34
//24
//79
//57
//60
//20
//10
//73
//61
//68

