#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Default constructor
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        
        // Parameterized constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        // Destructor
        ~Node()
        {
            if(this->next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout << "Node with value: " << this->data << " deleted." << endl;
        }
};

int findLength(Node* &tail)
{
    int len = 0;
    Node* temp = tail;
    while(temp->next != tail)
    {
        temp = temp->next;
        len++;
    }
    return len+1;
}

void addToEmpty(Node* &tail, int dataToInsert)
{
    // Check if the list is actually empty -> if it is not we are in the wrong function
    if(tail != NULL)
    {
        cout << "List is not empty! Use other functions for insertion." << endl;
        return;
    }

    // List was indeed empty
    Node* newNode = new Node(dataToInsert);
    tail = newNode;
    newNode->next = newNode;
}

void addAtBegin(Node*& tail, int dataToInsert)
{
    if (tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->next = tail->next;
    tail->next = newNode;
}

void addAtEnd(Node* &tail, int dataToInsert)
{
    if (tail == NULL)
    {
        return addToEmpty(tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void deleteNodePos(int position, Node* &tail)
{
    // Check if the Linked List is empty
    if(tail == NULL)
    {
        cout << "Cannot delete as the Circular Linked List is empty!" << endl;
        return;
    }

    if(position <= 0)
    {
        cout << "Deletion starts from position 1" << endl;
        return;
    }

    if(position == 1)
    {
        Node* temp = tail->next;
        tail->next = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // If you want to delete the last node(tail)
    int len = findLength(tail);
    if(position > len)
    {
        cout << "Out of range position asked to be deleted" << endl;
        return;
    }

    if(position == len)
    {
        // Find prev
        int i=1;
        Node* temp = tail;
        Node* prev = tail;
        while(i < position)
        {
            temp = temp->next;
            i++;
        }
        tail = temp;
        temp->next = prev->next;
        prev->next = NULL;
        delete prev;
        return;
    }

    // Deleting any node in the middle
    int i=1;
    Node* temp = tail;
    while(i < position)
    {
        temp = temp->next;
        i++;
    }
    Node* curr = temp->next;
    temp->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void deleteAfterValue(int valueToDeleteAfter, Node* &tail)
{
    // Check for empty Linked List
    if(tail == NULL)
    {
        cout << "Cannot delete as Linked List is empty!" << endl;
        return;
    }
    if(tail->next == tail)
    {
        cout << "Cannot delete after as there is only 1 element in the CLL." << endl;
        return;
    }

    if(tail->data == valueToDeleteAfter)
    {
        Node* temp = tail->next;
        // deleting just after tail
        tail->next = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* find = tail;
    while(find->next!=tail && find->data != valueToDeleteAfter)
    {
        find = find->next;
    }
    if(find->data == valueToDeleteAfter)
    {
        Node* temp = find->next;
        if(find->next == tail)
        {
            tail = find;
        }
        find->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else cout << "Value to delete after not present inside the Linked List." << endl;
}

void deleteBeforeValue(int valueToDeleteBefore, Node* &tail)
{
    // Check for empty Linked List
    if(tail == NULL)
    {
        cout << "Cannot delete as Linked List is empty!" << endl;
        return;
    }

    if(tail->next == tail)
    {
        cout << "Cannot delete before as there is only 1 element in the CLL." << endl;
        return;
    }

    if(tail->data == valueToDeleteBefore)
    {
        Node* temp = tail;
        while(temp->next->next != tail)
        {
            temp = temp->next;
        }   
        Node* curr = temp->next;
        temp->next = curr->next;
        curr->next = NULL;
        delete curr;
        return;
    }

    Node* curr = tail->next;
    Node* temp = tail;
    while(temp->next!=tail && curr->next->data != valueToDeleteBefore)
    {
        curr = curr->next;
        temp = temp->next;
    }
    if(curr->next->data == valueToDeleteBefore)
    {
        if(temp->next == tail)
        {
            tail = temp;
        }
        temp->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    else cout << "Value to delete before not present inside the Linked List." << endl;
}

void deleteValue(int valueToDelete, Node* &tail)
{
    // Check for empty Linked List
    if(tail == NULL)
    {
        cout << "Cannot delete as Linked List is empty!" << endl;
        return;
    }

    if(tail->next == tail && tail->data == valueToDelete)
    {
        tail->next = NULL;
        delete tail;
        cout << "Now the LL is empty!" << endl;
        return;
    }

    if(tail->data == valueToDelete)
    {
        Node* temp = tail;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        
        tail = temp;
        Node* curr = temp->next;
        temp->next = curr->next;
        curr->next = NULL;
        delete curr;
        return;
    }

    Node* curr = tail->next;
    Node* temp = tail;
    while(temp->next!=tail && curr->data != valueToDelete)
    {
        curr = curr->next;
        temp = temp->next;
    }
    if(curr->data == valueToDelete)
    {
        if(curr == tail->next)
        {
            tail->next = curr->next;
        }
        temp->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    else cout << "Value to delete is not present inside the Linked List." << endl;
}

void print(Node* &tail)
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // We will traverse each node from head and keep printing until we reach the tail.
    Node* temp = tail->next;
    
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != tail->next);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    addToEmpty(tail, 10);
    print(tail);

    addAtBegin(tail, 20);
    print(tail);

    addAtBegin(tail, 30);
    print(tail);

    addAtEnd(tail, 40);
    print(tail);

    addAtEnd(tail, 50);
    print(tail);

    deleteNodePos(1, tail);
    print(tail);

    deleteAfterValue(50, tail);
    print(tail);

    deleteBeforeValue(40, tail);
    print(tail);

    deleteValue(50, tail);
    print(tail);

    deleteValue(40, tail);
    print(tail);

    return 0;
}
