#include <cstddef>
using namespace std;

template <typename Object>

class stack {
private:
    struct node{
        node() {
            next = NULL;
        }
        node(Object obj) : data(obj) {}                         //Node structure initialization list for data object
        node(Object obj, node* ptr) : data(obj), next(ptr) {}   //and for both data object and pointer
        Object data;
        node* next;
    };

public:
    stack(){
        head = NULL;                                    //Stack constructor to initialize head pointer and size
        SIZE = 0;
    };

    void push(Object obj){                              //Push implementation, create new node for first
        node* itr = new node(obj,head);                 //added object and make it the head
        head = itr;
        ++SIZE;
    }
    void pop(){                                         //Pop implementation, assign new node the value of the
        node* itr = head->next;                         //node head is linked with. Delete head and set head to the
        delete head;                                    //created node
        head = itr;
        --SIZE;
    }

private:
    node * head;
    int SIZE;

};
