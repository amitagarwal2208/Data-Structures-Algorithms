#include <iostream>
  #include <string>
  #include <vector>
  #include <unordered_set>
  #include <climits>
  
  using namespace std;
  
  //----------------------------------------
  bool isContiguous(vector<int> &arr)
  {
      // Write your code here
      
      int n = arr.size() ;
      unordered_set<int> s ;
      int max= arr[0] ;
      int min = arr[0];
      for(int i=0 ; i<n ; ++i){
          s.insert(arr[i]) ;
          if(max<arr[i]) max=arr[i] ;
          if(min>arr[i]) min=arr[i] ;
      }
      
      
      int size = max-min+1 ;
      int exist = s.size() ;
      
      return (size==exist) ;
      
      
      
      
  }
  //----------------------------------------
  
  int main()
  {
      int n = 0;
      cin >> n;
      vector<int> num(n, 0);
      for (int i = 0; i < n; i++)
      {
          cin >> num[i];
      }
  
      if (isContiguous(num))
      {
          cout << "true" << endl;
      }
      else
      {
          cout << "false" << endl;
      }
  
      return 0;
  }