#include "avlTree.h"
 avlTree::Node::Node(int value){
     val=value;
 }

    void avlTree::rotateLeft(Node *x){
        Node *y=x->right;

        if(x==root){
            root=y;
            root->prev= nullptr;
        }
        else {
            if (x->prev->right==x) {
                // right case
                x->prev->right=y;
                y->prev=x->prev;
            } else if (x->prev->left==x) {
                // left case
                x->prev->left = y;
                y->prev=x->prev;
            }
        }

        x->right=y->left;
        if(x->right!= nullptr) {
            x->right->prev = x;
        }
        y->left=x;
        x->prev=y;
        x->bal=0;
        y->bal=0;
    }

    void avlTree::rotateRight(Node *y){
        Node *x=y->left;

        if(y==root){
            root=x;
            root->prev= nullptr;
        }
        else {
            if (y->prev->right == y) {
                // right case
                y->prev->right = x;
                x->prev=y->prev;
            } else if (y->prev->left == y) {
                // left case
                y->prev->left = x;
                x->prev=y->prev;
            }
        }

        y->left=x->right;
        if(y->left!= nullptr) {
            y->left->prev = y;
        }
        x->right=y;
        y->prev=x;
        x->bal=0;
        y->bal=0;
    }

    void avlTree::upin(Node * p){
        if(p == root){
            return;
        }

        Node *prev=p->prev;
        if(prev->right==p){
            // right case
            prev->bal++;
            if(prev->bal==0){
                return;
            }
            else if(prev->bal==1){
                upin(prev);
            }
            else if(prev->bal>1){
                if(p->bal==1) {
                    rotateLeft(prev);
                    return;
                }
                else if(p->bal==-1){
                    rotateRight(p);
                    rotateLeft(prev);
                    return;
                }
            }
        }
        else if(prev->left==p){
            // left case
            prev->bal--;
            if(prev->bal==0){
                return;
            }
            else if(prev->bal==-1){
                upin(prev);
            }
            else if(prev->bal<-1){
                if(p->bal==-1) {
                    rotateRight(prev);
                    return;
                }
                else if(p->bal==1){
                    rotateLeft(p);
                    rotateRight(prev);
                    return;
                }
            }
        }


    }

    void avlTree::upout(Node *p){
        if(p==root){
            return;
        }
        Node *prev=p->prev;
        if(prev->left==p){
            // left case
            if(prev->bal==-1) {
                prev->bal++;
                upout(prev);
            }
            else if(prev->bal==0){
                prev->bal++;
                return;
            }
            else if(prev->bal==1){
                if(prev->right->bal==0){
                    rotateLeft(prev);
                    prev->bal=1;
                    prev->prev->bal=-1;
                    return;
                }
                else if(prev->right->bal==1){
                    rotateLeft(prev);
                    upout(prev->prev);
                    return;
                }
                else if(prev->right->bal==-1){
                    rotateRight(prev->right);
                    rotateLeft(prev);
                    upout(prev->prev);
                    return;
                }
            }
        }
        else if(prev->right==p){
            // right case
            if(prev->bal==1) {
                prev->bal--;
                upout(prev);
            }
            else if(prev->bal==0){
                prev->bal--;
                return;
            }
            else if(prev->bal==-1) {
                if (prev->left->bal == 0) {
                    rotateRight(prev);
                    prev->bal = -1;
                    prev->prev->bal = 1;
                    return;
                } else if (prev->left->bal == -1) {
                    rotateRight(prev);
                    upout(prev->prev);
                    return;
                } else if (prev->left->bal == 1) {
                    rotateLeft(prev->left);
                    rotateRight(prev);
                    upout(prev->prev);
                    return;
                }
            }
        }
    }

    bool avlTree::contains(int value){

        Node *current=root;

        while(current!= nullptr){
            if(current->val==value){
                return true;
            }
            else if(value<current->val){
                current=current->left;
            }
            else if(value>current->val){
                current=current->right;
            }
        }
        return false;
    }

    bool avlTree::insert(int value){
        if(contains(value)){
            return false;
        }

        if(root== nullptr){
            root= new Node(value);
            return true;
        }

        Node *current=root;
        Node *prev;

        while(true){
            prev=current;
            if(value<current->val){
                if(current->left== nullptr){
                    current->left=new Node(value);
                    current=current->left;
                    current->prev=prev;
                    break;
                }
                current=current->left;
            }
            else if(value>current->val){
                if(current->right== nullptr){
                    current->right=new Node(value);
                    current=current->right;
                    current->prev=prev;
                    break;
                }
                current=current->right;
            }
        }

        if(prev->bal!=0) {
            // no change in height
            prev->bal=0;
        }
        else{
            // height change
            if(prev->right==current){
                prev->bal=1;
            }
            if(prev->left==current){
                prev->bal=-1;
            }
            upin(prev);
        }
        return true;
    }

    bool avlTree::remove(int value){
        if(!contains(value)){
            return false;
        }

        Node *current=root;

        while(current!= nullptr){
            if(current->val==value){
                break;
            }
            else if(value<current->val){
                current=current->left;
            }
            else if(value>current->val){
                current=current->right;
            }
        }

        // two leaves
        if(current->left== nullptr&&current->right== nullptr) {
            if(current==root){
                root= nullptr;
                return true;
            }

            Node *prev=current->prev;
            if (prev->left == current) {
                // left case
                prev->bal++;
                if(prev->bal==1){
                    // no height change
                    prev->left = nullptr;
                    return true;
                }
                if(prev->bal==0){
                    prev->left = nullptr;
                    upout(prev);
                    return true;
                }
                if(prev->bal==2){
                    prev->bal=1;
                    upout(current);
                    prev->left= nullptr;
                    return true;
                }
            } else if (prev->right == current) {
                // right case
                prev->bal--;
                if(prev->bal==-1){
                    // no height change
                    prev->right = nullptr;
                    return true;
                }
                if(prev->bal==0){
                    prev->right = nullptr;
                    upout(prev);
                    return true;
                }
                if(prev->bal==-2){
                    prev->bal=-1;
                    upout(current);
                    prev->right= nullptr;
                    return true;
                }
            }
        // one leaf
        }else if(current->left== nullptr||current->right== nullptr){
            if(current->left!= nullptr){
                current->val=current->left->val;
                current->left= nullptr;
            }
            else if(current->right!= nullptr){
                current->val=current->right->val;
                current->right= nullptr;
            }
            current->bal=0;
            upout(current);
            return true;
        }
        else if(current->left!= nullptr&&current->right!= nullptr){
            // switch node value with symmetrical successor
            Node *symSuccessor=current->right;
            while(symSuccessor->left!= nullptr){
                symSuccessor=symSuccessor->left;
            }
            int temp=current->val;
            current->val=symSuccessor->val;
            symSuccessor->val=temp;
            remove(temp);
        }

    }