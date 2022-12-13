#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int _data)
    {
        next = prev = NULL;
        data = _data;
    }
};

class LinkedList
{
public:
    Node *head, *tail;
    int counter;

    LinkedList()
    {
        head = tail = NULL;
        counter = 0;
    }

    void Add(int _data)
    {
        counter++;

        Node *node = new Node(_data);

        if(head == NULL){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void Display(){
        Node *curr = head;

        while(curr != NULL){
            cout << curr->data << "   ";
            curr = curr->next;
        }
    }

    int Search(int _data)
    {
        Node *node = getNodeByData(_data);

        if(node){
            return 1;
        }else {
            return 0;
        }
    }

    void Remove(int _data)
    {
        Node *node = getNodeByData(_data);

        if(node == NULL){
            return;
        }

        if(node == head)
        {
            if(head == tail){
                head = tail = NULL;
            }else
            {
                head = head->next;
                head->prev = NULL;
            }
        }else if( node == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        delete node;
    }

    /*
        int GetCount();
        T GetDataByIndex(int index);
        void InsertAfter(T data, T afterData);
        LinkedList<T>* Reverse();
        void InPlaceReverse();
    */

    int GetCounter()
    {
        return counter;
    }

    //convert linked list to an array.
    int GetDataByIndex(int index)
    {
        Node *curr = head;
        int arr[counter] = {};

        int i=0;
        while(curr != NULL){
            arr[i] = curr->data;

            curr = curr->next;
            i++;
        }
        return arr[index];
    }

    void InsertAfter(int _data, int after_data)
    {
        Node *A = getNodeByData(after_data);
        Node *new_node = new Node(_data);

        if(A == tail){
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        else if(A != NULL){
            Node *B = A->next;

            A->next = new_node;
            B->prev = new_node;
            new_node->next = B;
            new_node->prev = A;

        }else{
            cout << "can't do that"<< endl;
        }
    }

    LinkedList Reverse()
    {
        LinkedList reversedList;
        Node *curr = tail;

        while(curr != NULL){
            reversedList.Add(curr->data);
            curr = curr->prev;
        }

        return reversedList;
    }

    void InplaceReverse()
    {

    }

private:
    Node* getNodeByData(int _data)
    {
        Node *curr = head;

        while(curr != NULL)
        {
            if(curr->data == _data){
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
};

int main()
{
    LinkedList list1;

    list1.Add(1);
    list1.Add(2);
    list1.Add(3);
    list1.Add(4);
    list1.Add(5);

    //list1.Remove(5);
    //list1.Display();
    //cout << list1.Search(0) <<endl;
    //cout << list1.GetCounter() << endl;
    //cout << list1.GetDataByIndex(0);

    //list1.InsertAfter(6, 5);
    //list1.Display();

    LinkedList rev = list1.Reverse();
    rev.Display();

    cout <<  endl;

    //list1.Display();



    return 0;
}
