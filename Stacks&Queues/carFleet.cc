#include<iostream>
#include <stack>
#include <math.h>
using namespace std ;


int carFleet(int target , int* pos , int* speed , int n){
    
    int ans = 1 ;
    double cft = (target-pos[n-1])/speed[n-1] ;
    
    for(int curCar = n-2 ; curCar>=0 ; --curCar){
        double cct = (target-pos[curCar])/speed[curCar] ;
        if(cct>=cft){
            // part of the current fleet
            continue ;
        } else {
            // make a new fleet
            ++ans ;
        }
    }
    
    
    
    return ans ;
}


void GetInput(int* arr , int n){
    
    for(int i=0 ; i<n ; ++i){
        cin >> arr[i] ;
    }
}

int main(){
    int target ;
    cin >> target ;
    int n ;
    cin >> n ;
    int* pos=new int[n];
    int* speed=new int[n];
    GetInput(pos, n) ; GetInput(speed, n) ;
    cout << carFleet(target, pos, speed, n) << endl ;
}




