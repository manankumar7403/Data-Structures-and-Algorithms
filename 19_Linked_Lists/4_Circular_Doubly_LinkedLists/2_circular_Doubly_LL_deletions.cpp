#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        // Constructor1: Default Constructor -> When no data is passed.
        Node()
        {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }

        // Constructor2: Parameterized Constructor -> When data is passed.
        Node(int data)
        {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

        // Destructor
        ~Node()
        {
            cout << "Node with value: " << this->data << " deleted." << endl;
        }

};

int findLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
        len++;
    }
    return len+1;
}

void addToEmpty(Node* &head, Node* &tail, int dataToInsert)
{
    // Check if the list is actually empty -> if it is not we are in the wrong function
    if(head != NULL && tail != NULL)
    {
        cout << "List is not empty! Use other functions for insertion." << endl;
        return;
    }

    // List was indeed empty
    Node* newNode = new Node(dataToInsert);
    head = newNode;
    tail = newNode;
    newNode->prev = newNode;
    newNode->next = newNode;
}

void addAtBegin(Node* &head, Node* &tail, int dataToInsert)
{
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

void addAtEnd(Node* &head, Node* &tail, int dataToInsert)
{
    if (head == NULL && tail == NULL)
    {
        return addToEmpty(head, tail, dataToInsert);
    }

    Node* newNode = new Node(dataToInsert);
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
}

void deleteFromPos(Node* &head, Node* &tail, int position)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Cannot delete as List is empty!" << endl;
        return;
    }
    
    int len = findLength(head);
    if (position > len)
    {
        cout << "Position asked to be deleted out of range!" << endl;
        return; 
    }
    
    if(position <= 0)
    {
        cout << "Deletion starts from position 1." << endl;
        return;
    }

    if(position == 1)
    {
        Node* temp = head;
        tail->next = temp->next;
        temp->next->prev = tail;
        head = head->next;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    int i=1;
    Node* temp = head;
    Node* curr = temp->next;
    while(i < position-1)
    {
        temp = temp->next;
        curr = curr->next;
        i++;
    }
    temp->next = curr->next;
    curr->next->prev = temp;
    if(curr == tail)
    {
        tail = temp;
    }
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

void deleteAfterValue(Node* &head, Node* &tail, int valueToDeleteAfter)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Cannot delete as List is empty!" << endl;
        return;
    }

    if(tail->next == tail && head->next == head)
    {
        cout << "Cannot delete after as there is only 1 element in the CDLL." << endl;
        return;
    }

    Node* temp = head;
    while(temp->next != head && temp->data != valueToDeleteAfter)
    {
        temp = temp->next;
    }

    if(temp->data == valueToDeleteAfter)
    {
        Node* curr = temp->next;
        if(curr == tail)
        {
            tail = temp;
        }

        if(curr == head)
        {
            head = curr->next;
        }
    
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
    else cout << "Value to delete after is not present inside the linked list." << endl;
}

void deleteBeforeValue(Node* &head, Node* &tail, int valueToDeleteBefore)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Cannot delete as List is empty!" << endl;
        return;
    }

    if(tail->next == tail && head->next == head)
    {
        cout << "Cannot delete before as there is only 1 element in the CDLL." << endl;
        return;
    }

    Node* temp = head;
    while(temp->next != head && temp->data != valueToDeleteBefore)
    {
        temp = temp->next;
    }

    if(temp->data == valueToDeleteBefore)
    {
        Node* curr = temp->prev;
        if(curr == tail)
        {
            tail = curr->prev;
        }

        if(curr == head)
        {
            head = temp;
        }
    
        temp->prev = curr->prev;
        curr->prev->next = temp;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
    else cout << "Value to delete before is not present inside the linked list." << endl;
}

void deleteValue(Node* &head, Node* &tail, int valueToDelete)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Cannot delete as List is empty!" << endl;
        return;
    }

    if(head == tail && head->data == valueToDelete)
    {
        delete head;
        head = NULL;
        tail = NULL;
        cout << "Now the CDLL is empty!" << endl;
        return;
    }

    Node* temp = head;
    while(temp->next != head && temp->data != valueToDelete)
    {
        temp = temp->next;
    }

    if(temp->data == valueToDelete)
    {
        if(head == temp)
        {
            head = head->next;
            tail->next = temp->next;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
        if(tail == temp)
        {
            tail = tail->prev;
            tail->next = temp->next;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
    
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else cout << "Value to delete is not present inside the linked list." << endl;
}

void print(Node* &head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    addToEmpty(head, tail, 10);
    print(head);

    addAtBegin(head, tail, 20);
    print(head);

    addAtBegin(head, tail, 30);
    print(head);

    addAtEnd(head, tail, 40);
    print(head);

    addAtEnd(head, tail, 50);
    print(head);

    deleteFromPos(head, tail, 4);
    print(head);

    deleteAfterValue(head, tail, 50);
    print(head);

    deleteBeforeValue(head, tail, 50);
    print(head);

    deleteValue(head, tail, 50);
    print(head);

    deleteValue(head, tail, 20);
    print(head);

    return 0;
}
