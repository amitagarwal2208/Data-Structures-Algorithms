#include <iostream>
#include <unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class Node {
public:
    int data;
    Node * next ;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Linkedlist {
public:
    Node * createlinkedlist(int numofnodes) {
        Node * head = NULL;
        Node * tail = NULL;
        int ctr = 0;
        while (ctr < numofnodes) {
            int d;
            cin >> d;
            Node * newnode = new Node(d);
            if (ctr == 0) {
                head = newnode;
                tail = newnode;
                ctr++;
            }
            else {
                tail -> next = newnode;
                tail = newnode;
                ctr++;
            }
        }
        return head;
    }
    void printlinkedlist(Node * head) {
        Node * curnode = head;
        while (curnode != NULL) {
            cout << curnode -> data << " ";
            curnode = curnode -> next;
        }
    }
    
    Node* arrangeVC(Node* head){
        Node* vh = NULL ;
        Node* vt = NULL ;
        Node* ch = NULL ;
        Node* ct = NULL ;
        
        Node * cur = head ;
        while(cur!=NULL){
            char c = cur->data ;
            Node * temp = new Node(c) ;
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                if(vh==NULL){
                    vh = temp ;
                    vt = temp ;
                    //vt->next = NULL ;
                } else {
                    vt->next = temp ;
                    vt = temp ;
                    //vt->next = NULL ;
                }
            } else {
                if(ch==NULL){
                    ch = temp ;
                    ct = temp ;
                    //ct->next = NULL ;
                } else {
                    ct->next = temp ;
                    ct = temp ;
                    //ct->next = NULL ;
                }
            }
            cur=cur->next ;
        }
        if(vh==NULL){
            return ch ;
        }
        vt->next = ch ;
        return vh ;
    }
    
    bool isCircular(Node* head){
        
        bool ans = false ;
        Node* slow = head;
        Node* fast = head ;
        while(fast->next && fast->next->next){
            slow = slow->next ;
            fast = fast->next->next ;
            if(fast==slow){
                ans = true ;
                break ;
            }
        }
        
        return ans ;
    }
    
    
    
    void SortAbsoluteLL(Node* & head){
        
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        Node* prev = head ;
        Node* cur = head->next ;
        
        while(cur!=NULL){
            
            if(cur->data > 0){
                cur = cur->next ;
                prev = prev->next ;
            } else {
                
                prev->next = cur->next ;
                
                //Most Negative--> throw it to head
                cur->next = head ;
                head = cur ;
                
                cur = prev->next ;
                
            }
            
        }
        
        
    }
    
    
    void zigZag(Node* & head){
        bool incFlag = false ;
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        Node* prev = head ;
        Node* cur = head->next ;
        
        
        while(cur!=NULL){
            incFlag = !incFlag ;
            if((incFlag && prev->data < cur->data) || (!incFlag && prev->data > cur->data)){
                prev = prev->next ;
                cur = cur->next ;
                continue ;
            }
            
            else {
                int temp = prev->data ;
                prev->data = cur->data ;
                cur->data = temp ;
                
                prev = prev->next ;
                cur = cur->next ;
                continue ;
            }
        }
    }
    
    int decimalEqui(Node* head){
        int ans = 0 ;
        
        while(head!=NULL){
            if(head->data == 0){
                ans = 2*ans ;
            } else if(head->data==1){
                ans = 2*ans + 1 ;
            }
            
            head = head->next ;
        }
        
        return ans ;
    }
    
    int ctPairsSumToX(Node* head1 ,Node* head2 ,int x){
        
        int ct = 0 ;
        
        unordered_map<int, int> map ;
        
        while(head1 != NULL){
            
            if(map.count(head1->data)>0){
                ++map[head1->data] ;
            } else {
                map[head1->data] = 1 ;
            }
            head1 = head1->next ;
        }
        
        while(head2!=NULL){
            
            int d = head2->data ;
            if(map.count(x-d)>0){
                ct+=map[x-d] ;
            }
            
            head2 = head2->next ;
        }
        
        
        return ct ;
        
    }
    
    void reverseLL_iter(Node* & head){
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        Node* prev = head ;
        Node* cur = head->next ;
        
        while(cur!=NULL){
            Node* ahead = cur->next ;
            cur->next = prev ;
            prev = cur ;
            cur = ahead ;
        }
        head->next = NULL ;
        head = prev ;
    }
    
    void reverseLL_MtoN(Node* & head , int m , int n){
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        Node* prev = head ;
        Node* cur = head->next ;
        
        Node* start=NULL ;
        Node* end = head ;
        
        int ct = 1 ;
        while(cur!=NULL){
            if(ct<m){
                if(ct==m-1){
                    //store prev and cur
                    start = prev ;
                    end = cur ;
                }
                prev = cur ;
                cur = cur->next ;
                ++ct ;
            } else {
                //break ;
                Node* ahead = cur->next ;
                cur->next = prev ;
                prev = cur ;
                cur = ahead ;
                ++ct ;
            }
            if(ct==n){
                break ;
            }
        }
        end->next = cur ;
        if(start!=NULL){
            start->next = prev ;
        } else {
            head = prev ;
        }
        
        
        
    }
    
    void addPoly(Node* head1 , int n1 , Node* head2 , int n2){
        
        Node* cur1 = head1 ;
        Node* cur2 = head2 ;
        Node* head3 = NULL ;
        Node* cur = NULL ;
        Node* coeff1 = head1 ;
        Node* pow1 = head1->next ;
        Node* coeff2 = head2 ;
        Node* pow2 = head2->next ;
        
        
        while(n1>0 && n2>0){
            Node* newCoeff = NULL ;
            Node* newPow = NULL ;
            if(pow1->data == pow2->data){
                
                newCoeff = new Node(coeff1->data + coeff2->data) ;
                
                newPow = new Node(pow2->data) ;
                
                
                
                n1-=2 ;
                n2-=2 ;
                
                if(n1>0) {
                    cur1 = cur1->next->next ;
                    coeff1=coeff1->next->next ;
                    pow1=pow1->next->next ;
                }
                if(n2>0) {cur2 = cur2->next->next ;
                    coeff2 = coeff2->next->next ;
                    pow2 = pow2->next->next ;
                }
            } else if (pow1->data > pow2->data){
                newCoeff = new Node(coeff1->data) ;
                newPow = new Node(pow1->data) ;
                cur1 = cur1->next ;
                n1-=2 ;
                if(n1>0) {
                    cur1 = cur1->next->next ;
                    coeff1=coeff1->next->next ;
                    pow1=pow1->next->next ;
                }
            } else {
                newCoeff = new Node(coeff2->data) ;
                newPow = new Node(pow2->data) ;
                cur2 = cur2->next ;
                n2-=2 ;
                if(n2>0) {cur2 = cur2->next->next ;
                    coeff2 = coeff2->next->next ;
                    pow2 = pow2->next->next ;
                }
            }
            
            if(head3==NULL){
                head3 = newCoeff ;
                head3->next = newPow ;
                cur = newPow ;
            } else {
                cur->next = newCoeff ;
                cur = cur->next ;
                cur->next = newPow ;
                cur=cur->next ;
            }
        }
        if(n1==0){
            cur->next = cur2 ;
        } else {
            cur->next = cur1 ;
        }
        
        printlinkedlist(head3) ;
    }
    
    
    void mergeLL(Node* head1 , int n1 , Node* head2 , int n2){
        
        Node* cur1 = head1 ;
        Node* cur2 = head2 ;
        
        while(cur1!=NULL && cur2!=NULL){
            Node* ahead1 = cur1->next ;
            Node* ahead2 = cur2->next ;
            
            if(ahead1) cur1->next = cur2 ;
            if(ahead2) cur2->next = ahead1 ;
            
            cur1 = ahead1 ;
            cur2 = ahead2 ;
        }
        
        printlinkedlist(head1) ;
        cout << endl ;
        //cout << "hi" << endl ;
        if(cur1==NULL && cur2==NULL){
            return ;
        }
        if(cur1==NULL){
            printlinkedlist(cur2) ;
        } else if (cur2==NULL){
            printlinkedlist(cur1) ;
        }
        
    }
    
    void remDup(Node* & head){
        unordered_set<int> s ;
        if(head==NULL || head->next==NULL){
            return ;
        }
        int ct = 2 ;
        Node* prev = head ;
        s.insert(prev->data) ;
        Node* cur = prev->next ;
        while(cur!=NULL){
            
            if(s.count(cur->data)>0){
                //remove
                prev->next = cur->next ;
                cur = prev->next ;
            } else {
                s.insert(cur->data) ;
                prev = cur ;
                cur = cur->next ;
            }
        }
        printlinkedlist(head) ;
    }
    
    void printV(vector<Node*> & v , int k){
        for(int i=0 ; i<k ; ++i){
            printlinkedlist(v[i]) ;
            cout << endl ;
        }
    }
    
    void splitIntoK(Node* & head ,int n ,int k){
        
        vector<Node*> v ;
        
        int baseSize = n/k ;
        int extraSize = n%k ;
        Node* cur = head ;
        for(int i=0 ; i<k ; ++i){
            v.push_back(cur) ;
            for(int j=0 ; j<baseSize-1 ; ++j){
                cur = cur->next ;
            }
            if(extraSize>0){
                cur = cur->next ;
                --extraSize ;
            }
            Node* ahead = NULL ;
            if(cur) ahead = cur->next ;
            if(cur) cur->next = NULL ;
            cur = ahead ;
        }
        //for(int i=0 ; i<k ; ++i) cout << v[i]->data << " " ;
        //cout << v.size() << endl ;
        //cout << endl ;
        printV(v,k) ;
    }
    
    int conComp(Node* head1 , Node* head2){
        unordered_set<int> s ;
        while(head2!=NULL){
            
            if(s.count(head2->data)==0){
                s.insert(head2->data) ;
            }
            head2 = head2->next ;
        }
//        unordered_set<int>::iterator it ;
//        for(it=s.begin() ; it!=s.end() ; ++it){
//            cout << *it << endl ;
//        }
//        cout << s.size() << endl ;
        
        int ans = 0 ;
        bool flag = false ;
        while(head1!=NULL){
            //cout << 1 << endl ;
            if(s.count(head1->data)>0){
                if(flag==false){
                    //cout << "hi" << endl ;
                    ++ans ;
                    flag = true ;
                }
            } else {
                if(flag == true){
                    flag = false ;
                }
            }
            head1 = head1->next ;
        }
        
        return ans ;
    }
    
};
int main() {
//    int numofnodes;
//    cin >> numofnodes;
//
//    Linkedlist L ;
//    Node* head1 = L.createlinkedlist(2*numofnodes) ;
//
//    int n ;
//    cin >> n ;
//    Node* head2 = L.createlinkedlist(2*n) ;
//
    
    
//    L.addPoly(head1, numofnodes, head2, n) ;
    int n ;
    cin >> n ;
    
    Linkedlist l ;
    Node* head1 = l.createlinkedlist(n) ;
    
    Node* tail = head1 ;
    while(tail->next){
        tail = tail->next ;
    }
    tail->next = head1 ;
    
    
    
    
}













