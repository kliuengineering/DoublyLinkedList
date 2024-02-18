//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Kevin Liu on 2024-02-18.
//

#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
class DoublyLinkedList
{
private:
    
    typedef struct Node
    {
        Node* previous;
        Node* next;
        T data;
        
        // node constructor
        Node(const T &data) : previous(nullptr), next(nullptr), data(data) {};
    }
    Node;
    
    Node *head;
    Node *tail;
    
public:
    
    // d-list constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {};
    
    // d-list destructor
    ~DoublyLinkedList()
    {
        Node *current = head;

        while(current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
    
    void InsertFront(const T &data)
    {
        Node *new_node = new Node(data);
        
        if(!head && !tail)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->previous = new_node;
            head = new_node;
        }
    }
    
    void InsertBack(const T &data)
    {
        Node *new_node = new Node(data);
        
        if(!head && !tail)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->previous = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    T PopFront(void)
    {
        Node *ptr;
        T rc;
        
        if(!head && !tail)
        {
            rc = T{};
        }
        else if( head == tail )
        {
            rc = head->data;
            ptr = head;
            head = nullptr;
            tail = nullptr;
            delete ptr;
        }
        else
        {
            rc = head->data;
            ptr = head;
            head = head->next;
            head->previous = nullptr;
            delete ptr;
        }
        
        return rc;
    }
    
    T PopBack(void)
    {
        Node *ptr;
        T rc;
        
        if(!head && !tail)
        {
            rc = T{};
        }
        else if( head == tail )
        {
            rc = tail->data;
            ptr = tail;
            head = nullptr;
            tail = nullptr;
            delete ptr;
        }
        else
        {
            rc = tail->data;
            ptr = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete ptr;
        }
        
        return rc;
    }
    
    void Print(void)
    {
        Node *itr = head;
        while(itr)
        {
            std::cout << itr->data << " ";
            itr = itr->next;
        }
        puts("");
    }
    
};

int main(int argc, const char * argv[]) 
{
    DoublyLinkedList<std::string> dlist;
    
    dlist.InsertFront("hello");
    dlist.InsertBack("world");
    dlist.InsertFront("begin -> ");
    dlist.InsertBack(", I am reviewing");
    
    dlist.Print();
    
    return 0;
}
