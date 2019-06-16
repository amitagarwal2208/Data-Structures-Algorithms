#include<iostream>
using namespace std ;

struct Node{
    int data ;
    Node* next ;
    Node(int x){
        data = x ;
        next = NULL ;
    }
};

class linkedList{
    
public:
    
    Node* createLL(int n){
        Node* head = NULL ;
        Node* tail = NULL ;
        int d ;
        if(n>0){
            cin >> d ;
            Node* tmp = new Node(d) ;
            head = tmp ;
            tail = tmp ;
        }
        for(int i=1 ; i<n ; ++i){
            cin >> d ;
            Node* tmp = new Node(d) ;
            tail->next = tmp ;
            tail = tail->next ;
        }
        return head ;
        
    }
    
    void printLL(Node* head){
        while(head!=NULL){
            cout << head->data << " " ;
            head = head->next ;
        }
        cout << endl ;
    }
    
    
    Node* remFirst(Node* & head){
        Node* first = head ;
        head = head->next ;
        first->next = NULL ;
        return first ;
    }
    
    
    
    void OddEven(Node* & head){
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return ;
        }
        Node *oh = NULL , *ot=NULL , *eh=NULL , *et=NULL ;
        bool flag = true ;
        
        while(head!=NULL){
            Node* cur = remFirst(head) ;
            if(flag){
                // Add in odd list
                if(oh==NULL){
                    oh = cur ;
                    ot = cur ;
                } else {
                    ot->next = cur ;
                    ot = cur ;
                }
            } else {
                // Add in even list
                if(eh==NULL){
                    eh = cur ;
                    et = cur ;
                } else {
                    et->next = cur ;
                    et = cur ;
                }
            }
            flag = !flag ;
        }
        
        head = oh ;
        ot->next = eh ;
    }
    
    int occOf(Node* head , int k){
        int ans = 0 ;
        while(head!=NULL){
            if(head->data == k){
                ++ans ;
            }
            
            head = head->next ;
        }
        return  ans ;
    }
    void printPoly(Node* head){
        while(head!=NULL){
            cout << head->data << "x^" << head->next->data ;
            head = head->next->next ;
            if(head!=NULL){
                cout << " + " ;
            }
        }
    }
    
    Node* addPoly(Node* head1 , Node* head2){
        
        Node* cur1 = head1 ;
        Node* cur2 = head2 ;
        Node* head = NULL ;
        Node* cur = NULL ;
        while(cur1!=NULL && cur2!=NULL){
            
            int coeff1 = cur1->data ;
            int pow1 = cur1->next->data ;
            int coeff2 = cur2->data ;
            int pow2 = cur2->next->data ;
            
            Node* coeffNode = NULL ;
            Node* powNode = NULL ;
            
            if(pow1==pow2){
                //cout << 1 << endl ;
                coeffNode = new Node(coeff1+coeff2) ;
                powNode = new Node(pow1) ;
                coeffNode->next = powNode ;
                
                cur1 = cur1->next->next ;
                cur2 = cur2->next->next ;
                
            } else if(pow1>pow2){
                //cout << 2 << endl ;
                coeffNode = new Node(coeff1) ;
                powNode = new Node(pow1) ;
                coeffNode->next = powNode ;
                cur1 = cur1->next->next ;
                
            } else {
                //cout << 3 << endl ;
                coeffNode = new Node(coeff2) ;
                powNode = new Node(pow2) ;
                coeffNode->next = powNode ;
                cur2 = cur2->next->next ;
            }
            
            
            if(head==NULL){
                head = coeffNode ;
                cur = powNode ;
            } else {
                cur->next = coeffNode ;
                cur = powNode ;
            }
            
            
            
        }
        
        if(cur1==NULL){
            cur->next = cur2 ;
        } else if(cur2==NULL){
            cur->next = cur1 ;
        }
        
        
        return head ;
        
        
    }
    
    Node* revLL_rec(Node* head){
        if(head==NULL || head->next == NULL){
            return head ;
        }
        
        Node* newHead = revLL_rec(head->next) ;
        head->next->next = head ;
        head ->next = NULL ;
        
        return newHead ;
    }
    
    Node* revLL_iter(Node* head){
        
        if(head==NULL || head->next == NULL){
            return head ;
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
        return prev ;
    }
    
    Node* remHead(Node* & head){
        if(head==NULL){
            return head ;
        }
        
        Node* first = head ;
        head = head->next ;
        first->next = NULL ;
        return first ;
    }
    
    void altMergeLL(Node* head1 , Node* head2){
        bool flag = true ;
        
        Node* head = NULL , *tail = NULL ;
        
        while(head1!=NULL && head2!=NULL){
            Node* h1 = remHead(head1) ;
            Node* h2 = remHead(head2) ;
            h1->next = h2 ;
            if(head==NULL){
                head = h1 ;
                tail = h2 ;
            } else {
                tail->next = h1 ;
                tail = h2 ;
            }
        }
        printLL(head) ;
        if(head1==NULL){
            printLL(head2) ;
        } else if(head2==NULL){
            printLL(head1) ;
        }
    }
    
    void insertSortedCyclic(Node* & head , int k){
        Node* tmp = new Node(k) ;
        if(head==NULL){
            head = tmp ;
            head->next = head ;
            
        }
        
        if(head->next==NULL){
            
            if(k>head->data){
                head->next = tmp ;
                tmp->next = head ;
            } else {
                head->next = tmp ;
                tmp->next = head ;
                head = tmp ;
            }
        }
        
        Node* prev = head ;
        Node* cur = head->next ;
        
        while(cur!=head){
            if(k>prev->data && k<cur->data){
                //Node* tmp = new Node(k) ;
                prev->next = tmp ;
                tmp->next = cur ;
                return ;
            }
            
            prev = cur ;
            cur = cur->next ;
        }
        
        if(k<head->data){
            prev->next = tmp ;
            tmp->next = head ;
            head = tmp ;
        } else if(k > prev->data){
            prev->next = tmp ;
            tmp->next = head ;
        }
    }
    
    Node* mergeSorted(Node* head1 , Node* head2)
    {
        Node* head = NULL , *tail=NULL;
        if(head1==NULL){
            return head2 ;
        }
        if(head2==NULL){
            return head1 ;
        }
        
        //ListNode *cur1=head1 , cur2=head2 ;
        
        while(head1!=NULL && head2!=NULL){
            
            Node* cur = NULL ;
            if(head1->data < head2->data){
                //cur = remFirst(head1) ;
                cur = head1 ;
                head1 = head1->next ;
                cur->next = NULL ;
                
            } else {
                cur = head2 ;
                head2 = head2->next ;
                cur->next = NULL ;
            }
            
            if(head==NULL){
                head = cur ;
                tail = cur ;
            } else {
                tail->next = cur ;
                tail = cur ;
            }
            
        }
        
        
        return head ;
        
    }
    
    int getLen(Node * head){
        int len=0 ;
        while(head!=NULL){
            head=head->next ;
            ++len ;
        }
        return len ;
    }
    //struct node* rev(struct node* & head , int k)
    Node *reverse (Node *head, int k)
    {
        // Complete this method
        Node *newHead = NULL , *tail=NULL ;
        int n = getLen(head) ;
        //if(n%k!=0) return head ;
        int x = (n/k) ;
        if(n%k!=0) ++x ;
        
        Node *prev = head ;
        Node *cur = head->next ;
        for(int i=0 ; i<(x) ; ++i){
            //cout << endl ;
            for(int j=0 ; (j<k-1) && cur!=NULL ; ++j){
                //cout << prev->data <<" " << cur->data <<endl ;
                Node *ahead = cur->next ;
                cur->next = prev ;
                prev = cur ;
                cur = ahead ;
            }
            head->next = NULL ;
            
            
            if(newHead==NULL){
                newHead = prev ;
                tail = head ;
            } else {
                tail->next = prev ;
                tail = head ;
            }
            
            
            head= cur ;
            prev = head ;
            if(head) cur = head->next ;
        }
        
        
        return newHead ;
        
    }
    
    Node* reverseLL(Node* head){
        
        if(head==NULL || head->next==NULL){
            return head ;
        }
        struct Node* prev = head ;
        struct Node* cur = head->next ;
        
        while(cur!=NULL){
            Node* ahead = cur->next ;
            cur->next = prev ;
            prev = cur ;
            cur = ahead ;
        }
        head->next = NULL ;
        return prev ;
        
    }
    
    int len(Node* head){
        int len=0 ;
        while(head!=NULL){
            //cout << "#"<< endl ;
            head=head->next ;
            ++len ;
        }
        return len ;
    }
    
    //    Node* remHead(Node* & head){
    //        if(head==NULL) return head ;
    //        Node* first = head ;
    //        head = head->next ;
    //        first->next = NULL ;
    //        return first ;
    //    }
    
    
    void reorderList(Node* & head)
    {
        // Your code here
        int n = len(head) ;
        Node* cur = head ;
        Node* rhead = reverseLL(cur) ;
        
        //cout << "n : "<<n << endl << endl ;
        Node* nhead=NULL , *tail=NULL ;
        
        for(int i=0 ; i<(n/2) ; ++i){
            cout << i << endl ;
            Node* f1 = remHead(head) ;
            Node* f2 = remHead(rhead) ;
            //cout << f1->data << " "<< f2->data << endl ;
            f1->next = f2 ;
            if(nhead==NULL){
                nhead = f1 ;
                tail = f2 ;
            } else {
                tail->next = f1 ;
                tail = f2 ;
            }
        }
        
        if(n%2!=0){
            tail->next = head ;
            tail = head ;
            tail->next = 0 ;
        }
        head = nhead ;
    }
    
    
    void revLL(Node* & head){
        
        if(head==NULL || head->next==NULL){
            return ;
        }
        
        Node* prev = head ;
        Node* cur=head->next ;
        
        while(cur!=NULL){
            Node* ahead = cur->next ;
            cur->next = prev;
            prev = cur ;
            cur = ahead ;
        }
        head->next = NULL ;
        head = prev ;
        
    }
    
    
    
    
    
    Node* add2Num(Node* head1 , Node* head2){
        //revLL(head1) ;
        //revLL(head2) ;
        
        int carry = 0 ;
        Node* tail1 = head1 , *tail2 = head2 ;
        Node* head = NULL , *tail=NULL ;
        while(tail1!=NULL && tail2!=NULL){
            
            
            int cursum = tail2->data + tail1->data + carry ;
            carry = cursum/10 ;
            int curdigit = cursum%10 ;
            
            Node* cur = new Node(curdigit) ;
            if(head==NULL){
                head = cur ;
                tail = cur ;
            } else {
                tail->next = cur ;
                tail = cur ;
                
            }
            
            tail1=tail1->next ;
            tail2=tail2->next ;
            
        }
        
        if(tail1==NULL && tail2==NULL){
            if(carry==1){
                tail->next = new Node(1) ;
            }
        }
        
        if(tail1!=NULL && tail2==NULL){
            while(tail1!=NULL){
                int d = tail1->data+carry ;
                if(d>=10){
                    carry = 1 ;
                    d = d%10 ;
                } else {
                    carry = 0 ;
                }
                Node* tmp = new Node(d) ;
                
                tail->next = tmp ;
                tail = tmp ;
                tail1=tail1->next ;
            }
            if(carry==1){
                tail->next = new Node(1) ;
            }
        }
        
        
        if(tail2!=NULL && tail1==NULL){
            while(tail2!=NULL){
                int d = tail2->data+carry ;
                if(d>=10){
                    carry = 1 ;
                    d = d%10 ;
                } else {
                    carry = 0 ;
                }
                Node* tmp = new Node(d) ;
                
                tail->next = tmp ;
                tail = tmp ;
                tail2=tail2->next ;
            }
            if(carry==1){
                tail->next = new Node(1) ;
            }
        }
        
        //revLL(head1) ;
        //revLL(head2);
        
        return head ;
    }
    
    
    
    
    
    
    Node* mul2LL(Node* head1 , Node* head2){
        
        revLL(head1) ;
        revLL(head2) ;
        Node *tail1 = head1 , *tail2 = head2 ;
        
        Node* head = NULL , *tail = NULL ;
        
        int zeros = 0 ;
        
        while(tail1!=NULL){
            
            Node *curh = NULL , *curt = NULL ;
            for(int i=0 ; i<zeros ; ++i){
                Node* tmp = new Node(0) ;
                if(curh==NULL){
                    curh = tmp ;
                    curt = tmp ;
                } else {
                    curt->next = tmp ;
                    curt = tmp ;
                }
            }
            
            int carry = 0 ;
            
            while(tail2!=NULL){
                
                int num = tail1->data * tail2->data ;
                num+=carry ;
                
                int digit = num%10 ;
                carry = num/10 ;
                
                Node* tmp = new Node(digit) ;
                if(curh==NULL){
                    curh=tmp ;
                    curt = tmp ;
                } else {
                    curt->next = tmp ;
                    curt=tmp ;
                }
                
                tail2=tail2->next ;
            }
            
            if(carry>0){
                Node* tmp = new Node(carry) ;
                curt->next = tmp ;
                curt = tmp ;
            }
            
            if(head==NULL){
                head = curh ;
                //tail = curt ;
            } else {
                head = add2Num(head, curh) ;
            }
            
            
            
            tail2 = head2 ;
            ++zeros ;
            tail1=tail1->next ;
        }
        
        
        revLL(head1) ;
        revLL(head2) ;
        revLL(head) ;
        
        return head ;
    }
    
    bool isPallindrome(Node* head){
        
        if(head==NULL || head->next==NULL){
            return true ;
        }
        bool ans = true ;
        Node *slow = head , *fast = head ;
        
        
        while(fast->next && fast->next->next){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        
        Node* head1 = slow->next ;
        slow->next = NULL ;
        
        
        revLL(head1) ;
        
        Node* cur1 = head , *cur2 = head1 ;
        
        while(cur2!=NULL){
            
            if(cur1->data!=cur2->data){
                ans = false ;
            }
            
            cur1=cur1->next ;
            cur2=cur2->next ;
        }
        
        
        revLL(head1) ;
        slow->next = head1 ;
        
        return ans ;
        
    }
    
    
    Node* fold(Node* head){
        
        if(head==NULL || head->next==NULL){
            return head ;
        }
        
        
        Node* slow = head , *fast = head ;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        
        Node* shead = slow->next ;
        slow->next = NULL ;
        
        revLL(shead) ;
        
        Node* cur1 = head ;
        Node* cur2 = shead ;
        
        
        while(cur2!=NULL){
            Node* ahead1 = cur1->next ;
            Node* ahead2 = cur2->next ;
            
            cur1->next = cur2 ;
            cur2->next = ahead1 ;
            
            cur1 = ahead1 ;
            cur2 = ahead2 ;
        }
        
        return head ;
        
        
        
    }
    
    void unfold(Node* & head){
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return ;
        }
        
        
        Node* cur = head ;
        Node* ahead = head->next ;
        
        Node* shead = ahead ;
        
        
        
        while(ahead!=NULL){
            cur->next = ahead->next ;
            cur = ahead ;
            ahead=ahead->next ;
            
        }
        
        
        revLL(shead) ;
        Node* tail = head ;
        while(tail->next){
            tail=tail->next ;
        }
        tail->next = shead ;
        
    }
    void printCyclic(Node* head){
        if(head==NULL){
            
            return ;
        }
        
        
        cout << head->data << " " ;
        Node* cur=head->next ;
        while(cur!=head){
            cout << cur->data << " " ;
            cur=cur->next ;
        }
        cout << endl ;
    }
    
    void divideCircularLLinto2(Node* head){
        if(head==NULL){
            return ;
        }
        if(head->next==head){
            cout << head->data << endl ;
            return ;
        }
        
        Node *slow=head , *fast=head ;
        
        while(fast->next!=head && fast->next->next!=head){
            slow=slow->next ;
            fast = fast->next->next ;
        }
        
        Node* shead = slow->next ;
        slow->next = head ;
        
        if(fast->next->next==head){
            fast=fast->next ;
        }
        fast->next = shead ;
        
        printCyclic(head) ;
        printCyclic(shead) ;
    }
    
    Node* detectStartLoopPt(Node* head){
        
        Node* slow = head , *fast=head ;
        Node* mynode = NULL ;
        while(fast->next && fast->next->next){
            slow=slow->next ;
            fast=fast->next->next ;
            if(slow==fast){
                mynode = slow ;
                break ;
            }
        }
        
        Node* cur = head ;
        while(cur!=mynode){
            cur=cur->next ;
            mynode=mynode->next ;
        }
        return mynode ;
        
    }
    
    void makeCyclic(Node* & head , int pos){
        Node* tail = head ;
        int ct=0 ;
        Node* s = NULL ;
        while(tail->next){
            if(ct==pos){
                s = tail ;
            }
            tail=tail->next ;
            ++ct ;
        }
        if(s==NULL){
            tail->next = tail ;
        } else tail->next = s ;
    }
    
    
    void delMid(Node* & head){
        
        if(head==NULL || head->next==NULL){
            head = NULL ;
            return ;
        }
        Node* sp = NULL ;
        Node *slow=head , *fast=head ;
        while(fast && fast->next && fast->next->next){
            sp = slow ;
            slow=slow->next ;
            fast=fast->next->next ;
        }
        
        if(fast->next==NULL){
            // odd number of elements
            
            // remove slow node
            sp->next = slow->next ;
            
        } else if(fast->next->next==NULL){
            // even elements
            
            // remove slow->next
            slow->next = slow->next->next ;
        }
        
        
        
    }
    
    
    void delLastOcc(Node* & head , int k){
        if(head==NULL){
            return ;
        }
        
        Node *prev=NULL , *cur=head ;
        Node *sp=NULL , *sc=NULL ;
        while(cur!=NULL){
            
            if(cur->data==k){
                sc=cur ;
                sp=prev ;
            }
            prev=cur ;
            cur=cur->next ;
        }
        if(sp!=NULL && sc!=NULL){
            sp->next = sc->next ;
            
        } else if(sp==NULL && sc!=NULL){
            head = sc->next ;
        }
    }
    
    int findModNode(Node* head , int n , int k){
        
        
        int r = n%k ;
        int pos = n-r ;
        int cur=1 ;
        while(head!=NULL){
            if(cur==pos){
                return head->data ;
            }
            ++cur ;
            head=head->next ;
        }
        return -1 ;
    }
    
};

int main(){
    int n ;
    cin >> n ;
    linkedList l ;
    Node* head = l.createLL(n) ;
    //    int n2 ;
    //    cin >> n2 ;
    //    Node* head2 = l.createLL(n2) ;
    //    l.altMergeLL(head, head2) ;
    
    //    int k ;
    //    cin >> k ;
    //    Node* rhead = l.reverse(head, k) ;
    //    l.printLL(rhead) ;
    
    int n2 ;
    cin >> n2 ;
    Node* head1 = l.createLL(n2) ;
    
    
    
}


// Node* copyList(Node* n) {
//         // your code here
//         cout << n->data << endl ;
//         Node* cur = n ;
//         while(cur!=NULL){

//             cout << cur->data << endl ;
//             Node* tmp = new Node(cur->data) ;
//             Node* ahead = cur->next ;
//             cur->next = tmp ;
//             tmp->next = ahead ;
//             cur = ahead ;
//         }
//         printLL(n) ;
//         cur = n ;
//         while(cur!=NULL){
//             cur->next->arb = cur->arb->next ;
//             cur=cur->next->next ;
//         }

//         cur = n ;
//         Node* nhead = n->next ;


//         while(cur->next!=NULL){
//             Node* ahead = cur->next ;
//             cur->next = ahead->next ;
//             cur=ahead ;

//         }
//         return nhead ;

//     }



