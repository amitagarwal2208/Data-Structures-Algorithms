#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
#include<vector>
using namespace std ;

class Node{
public:
    int data ;
    Node* next ;
    Node* prev ;
    Node(int x){
        data = x ;
        next = NULL ;
        prev = NULL ;
    }
};


class circularDQ{
    
    int size ;
    int cap ;
    Node *fh , *ft ;
    

public:
    
    circularDQ(int k){
        cap = k ;
        size = 0 ;
        fh = new Node(0) ;
        ft = new Node(0) ;
        fh->next = ft ;
        ft->prev = fh ;
    }
    
    bool isEmpty(){
        return size==0 ;
    }
    bool isFull(){
        return size==cap ;
    }
    
    bool insertFront(int x){
        if(isFull()){
            return false ;
        }
        ++size ;
        Node* cur = new Node(x) ;
        cur->prev = fh ;
        cur->next = fh->next ;
        fh->next->prev = cur ;
        fh->next = cur ;
        
        return true ;
    }
    bool insertLast(int x){
        if(isFull()){
            return false ;
        }
        ++size ;
        Node* cur = new Node(x) ;
        cur->next = ft ;
        cur->prev = ft->prev ;
        ft->prev->next = cur ;
        ft->prev = cur ;
        
        return true ;
    }
    
    bool delFront(){
        if(isEmpty()) return false ;
        
        --size ;
        fh->next = fh->next->next ;
        fh->next->prev = fh ;
        
        return true ;
    }
    
    bool delLast(){
        if(isEmpty()) return false ;
        
        --size ;
        ft->prev = ft->prev->prev ;
        ft->prev->next = ft ;
        return true ;
    }
    
    int getFront(){
        if(isEmpty()){
            return -1 ;
        }
        
        return fh->next->data ;
    }
    int getLast(){
        if(isEmpty()){
            return -1 ;
        }
        return ft->prev->data ;
    }
    
    
    
};


void printBool(bool ans){
    if(ans){
        cout << "true" << " " ;
    } else cout << "false" << " " ;
}

int main(){
    
    int k,n ;
    cin >> k >> n ;
    
    circularDQ dq(k);
    int x ;
    
    
    for(int i=0 ; i<n ; ++i){
        //cout << i << endl ;
        cin >> x ;
        if(x==0){
            cin >> x ;
            bool ans = dq.insertLast(x) ;
            printBool(ans) ;
            continue ;
        } else if(x==1){
            cin >> x ;
            bool ans = dq.insertFront(x) ;
            printBool(ans) ;
            continue ;
        } else if(x==2){
            bool ans = dq.delFront() ;
            printBool(ans) ;
            continue ;
        } else if(x==-2){
            bool ans = dq.delLast();
            printBool(ans) ;
            continue ;
        } else if(x==3){
            int ans = dq.getFront() ;
            cout << ans << " " ;
            continue ;
        } else if(x==-3){
            int ans = dq.getLast() ;
            cout << ans << " " ;
            continue ;
        } else if(x==4){
            bool ans = dq.isEmpty() ;
            printBool(ans) ;
            continue ;
        } else if(x==5){
            bool ans = dq.isFull() ;
            printBool(ans) ;
            continue ;
        }
    }
}






