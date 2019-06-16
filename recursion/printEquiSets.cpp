#include<iostream>
#include<vector>
#include<string>
using namespace std ;
int ct = 0 ;

void PrintEquiSubsets(int* arr , int n , string set1 , string set2 , int setsum1 , int setsum2,int sum){

	

	if(n==0){
		if(setsum1==setsum2) 
			cout << ++ct <<". " << set1 << "& " << set2 << endl ;
		return ;
	}

	//PrintEquiSubsets(arr+1,n-1,set1,set2,setsum1,setsum2,sum) ;

	string s=(to_string(arr[0]))+" " ;
	set1+=s ;
	int len = s.size() ;
	PrintEquiSubsets(arr+1,n-1,set1,set2,setsum1+arr[0],setsum2,sum) ;
	set1 = set1.substr(0,set1.size()-len) ;

	s=(to_string(arr[0]))+" " ;
	set2+=s ;
	len = s.size() ;
	PrintEquiSubsets(arr+1,n-1,set1,set2,setsum1,setsum2+arr[0],sum) ;
	set2 = set2.substr(0,set2.size()-len) ;
}




void PrintEquiSubsets(int* arr , int n , int sum){

	string set1 = "" , set2 = "" ;
	int setsum1 = 0 , setsum2 = 0 ;

	PrintEquiSubsets(arr,n,set1,set2,setsum1,setsum2,sum) ;

}



int main(){

	int n ;
	cin >> n ;
	int sum = 0 ;
	int* arr = new int[n] ;
	for(int i=0 ; i<n ; ++i){
		cin >> arr[i] ;
		sum+=arr[i] ;
	}
	


	PrintEquiSubsets(arr,n,sum) ;
}