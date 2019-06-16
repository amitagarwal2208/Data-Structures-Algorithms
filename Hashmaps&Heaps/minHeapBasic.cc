#include <iostream>
#include<string>
#include<vector>
#include<map>
using namespace std ;

class minHeap{
    
    vector<int> v ;
    int size ;
    
    int parent(int i){
        return i/2 ;
    }
    
    int leftChild(int i){
        return 2*i ;
    }
    
    int rightChild(int i){
        return 2*i + 1 ;
    }
    
    
    void heapify(int i){
        
        int minpos = i ;
        if(leftChild(i)<=size && v[leftChild(i)]<v[minpos]){
            minpos = leftChild(i) ;
        }
        
        if(rightChild(i)<=size && v[rightChild(i)]<v[minpos]){
            minpos = rightChild(i) ;
        }
        
        if(minpos!=i){
            swap(v[i],v[minpos]) ;
            heapify(minpos) ;
        }
        
    }
    
    
    
    
public:
    
    minHeap(){
        v.push_back(-1) ;
        size = 0 ;
    }
    
    void push(int x){
        v.push_back(x) ;
        ++size ;
        
        int curpos = (int)v.size() - 1 ;
        
        while(curpos>1 && v[parent(curpos)]>v[curpos]){
            swap(v[curpos], v[parent(curpos)]) ;
            curpos = parent(curpos) ;
        }
    }
    
    void print(){
        for(int i = 1; i <= size; ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
    int top(){
        if(!isEmpty()){
            return v[1] ;
        } else return -1 ;
    }
    
    bool isEmpty(){
        return size==0 ;
    }
    
    void pop(){
        
        swap(v[1] , v[v.size()-1]) ;
        v.pop_back() ;
        
        --size ;
        heapify(1) ;
        
    }
    
    
};




int main(){
    minHeap H;
    H.push(2);
    H.print();
    H.push(30);
    H.print();
    H.push(32);
    H.print();
    H.push(-1);
    H.print();
    
     cout << H.top(); H.pop();
     cout << H.top(); H.pop();
     cout << H.top(); H.pop();
     cout << H.top(); H.pop();
}
    

