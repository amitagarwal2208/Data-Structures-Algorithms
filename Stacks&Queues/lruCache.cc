#include<iostream>
#include<stack>
#include <unordered_map>
#include <string>
#include<queue>
#include<vector>


using namespace std ;

struct Node{
    int key ;
    int val ;
    Node* next ;
    Node* prev ;
    Node(int k , int v){
        key = k ;
        val = v ;
        next = NULL ;
        prev = NULL ;
    }
};


class lruCache{
    int cap ;
    int size ;
    Node *head , *tail ;
    unordered_map<int, Node*> m ;
    
    void removeLRU(){
        Node* cur = tail ;
        
        //cout << tail->key << " : " << tail->val << endl ;
        if(tail==head){
            m.erase(head->key) ;
            head = NULL ;
            tail = NULL ;
            return ;
        }
        tail->next->prev = NULL ;
        tail = tail->next ;
        cur->next = NULL ;
        int k = cur->key ;
        m.erase(k) ;
        
    }
    
    
    void addNewNode(Node* & cur){
        if(head==NULL){
            head = cur ;
            tail = cur ;
        } else {
            head->next = cur ;
            cur->prev = head ;
            head = cur ;
        }
    }
    
    
    void updateMRU(Node* & cur){
        if(head==NULL && tail==NULL){
            head=cur ;
            tail=cur ;
        }
        if(cur==head){
            return ;
        } else if(cur->prev == NULL){
            // cur is LRU
            //cout << "yo" << endl ;
            cur->next->prev = NULL ;
            tail = cur->next ;
            cur->next = NULL ;
            
            cur->prev = head ;
            head->next = cur ;
            head = cur ;
            
        } else {
            // cur is some middle node
            cur->prev->next = cur->next ;
            cur->next->prev = cur->prev ;
            cur->next = NULL ;
            cur->prev = NULL ;
            
            cur->prev = head ;
            head->next = cur ;
            head = cur ;
        }
        
    }
    
    
public:
    
    lruCache(int n){
        cap = n ;
        size = 0 ;
        head = NULL ;
        tail = NULL ;
        m.clear() ;
    }
    
    int get(int key){
        if(m.count(key)>0){
            //found
            
            // return val
            // make it MRU
            
            Node* cur = m[key] ;
            int ans = cur->val ;
            updateMRU(cur) ;
            
            return ans ;
            
        } else return -1 ;
    }
    
    void set(int k , int v){
        if(m.count(k)>0){
            // key is already present ==> Update value
            //cout << "hi" << endl ;
            Node* cur = m[k] ;
            cur->val = v ;
            updateMRU(cur) ;
        } else {
            // new node needs to be made
            if(size==cap){
                
                removeLRU() ;
                Node* cur = new Node(k,v) ;
                addNewNode(cur) ;
                m[k] = cur ;
                
            } else {
                
                Node* cur = new Node(k,v) ;
                ++size ;
                addNewNode(cur) ;
                m[k] = cur ;
            }
        }
    }
    
    void getLRU(){
        if(size==0){
            cout << -1 << endl ;
        } else {
            cout << tail->key << " : " << tail->val << endl ;
        }
    }
    void printLL(){
        Node* cur = head ;
        while(cur!=NULL){
            cout << cur->key << " : " << cur->val << " --> " ;
            cur=cur->prev ;
        }
        //cout << cur->key << " : " << cur->val << " --> " << endl ;
     }
    
    
};


int main(){
    int cap ;
    cin >> cap ;
    
    lruCache l(cap) ;
    int n ;
    cin >> n ;
    for(int i=0 ; i<n ; ++i){
//        l.printLL() ;
//        cout << endl ;
//        l.getLRU();
        string s ;
        cin >> s ;
        if(s.compare("SET")==0){
            int k,v ;
            cin >> k >> v ;
            l.set(k, v) ;
        } else if(s.compare("GET")==0){
            int k ;
            cin >> k ;
            cout << l.get(k) << " ";
        }
    }
}






