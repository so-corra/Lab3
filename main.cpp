/*
# Lab: (Lab Number): 3
# Author(s): Evan Sanford, Socorra McLaughlin
# Due Date: (09/23/2024)
#
# Description: does multiple things with linked lists while being edited by multiple authors
               using git.
# Comments:
# Honor Pledge: I have abided by the Wheaton Honor Code and
# some work below was performed by (Evan Sanford & Socorra McLaughlin).
*/

#include <iostream>
#include <vector>

using namespace std;

// Node class to represent a node of the linked list.
class Node {
  public:
    int data;
    Node *next;

    Node(int data) { // parameterized contructor
        this->data = data;
        this->next = nullptr;
    }
};

// linked list class
class MyList {
protected:
   Node *head;                   // always points to beginning of list

public:
    MyList();                    // implied "create" function
    ~MyList();                   // implied "delete" function
    // TODONEs
    void Traverse () const;      // traverse list
    void Insert (int);           // insert into list in sorted order
    bool IsEmpty() const;        // check if list is empty
    void Reverse () const;       // traverse list with a helper function
    void reverse () const;       // traverse list with a vector
    int Size() const;            // returns the size of the list
    bool Find(int);              // find a node in the list
    int peekHead();//E           // this function returns the data at the head node





    // TODOs
    void Delete (int);           // delete from list
    void reset();//E             // this function reset the list to empty
    int peekTail();              // this function returns the data at the tail node
    int& at(int i);              // this function returns the data at a given position (index)
    int& operator[](int i);      // same as above, operator[]
    int remove(int target);//E   // remove a target node and returns it if successful
    int removeHead();            // remove the head node in the list
    int removeTail();            // remove the tail node in the list

    bool operator==(const MyList& toCompare);
    // operator==, returns true if the calling object is exactly the same as toCompare
    Node* merge(Node* left, Node* right);
    // merge two sorted lists and returns the head of the merged linked list


private:
   void reverse_helper(Node* ) const;
};

// Constructor
MyList :: MyList() {
   head = nullptr;
}

// Destructor. Delete all of the items in the list
MyList :: ~MyList() {
   Node *temp;  // temporary to delete each node
   Node *cur;   // for traversing
   cur = this->head;

   while (cur != nullptr) {
      // delete one node at a time
      temp = cur;
      cur = cur->next;
      delete temp;
   }
   head = nullptr;
}

// Traverse the list - display each item
void MyList :: Traverse() const {
   Node *curr = this->head;    // pointer for traversing the list

   cout << "\nThe list:" << endl;
   while (curr != nullptr) {
      cout << curr->data << " --> ";
      curr = curr->next;
   }
   cout << "nullptr" << endl;
}

// Insert new node into list in sorted order
// This will also update head pointers
void MyList :: Insert (int newdata) {
   Node *prev = nullptr;      // pointer to previous node
   Node *curr = this->head;   // pointer for traversing
   bool found = false;        // if position in list is found

   // create a new node with the newdata (int)
   Node *newNode = new Node(newdata);

   // find the correct spot in list to insert the new node
   while (curr != nullptr && !found) {
      // compare newdata to the data stored in the current node
      if (newNode->data < curr->data)
         found = true;
      else {
         prev = curr;
         curr = curr->next;
      }
   }

   // insert the new node into the right spot
   if (prev != nullptr) {
      newNode->next = curr;
      prev->next = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
}


// Reversely traverse the list in descending order
// This will not change the list in any way.
// It calls the reverse_helper() function to traverse
// the list recursively.
void MyList :: Reverse () const {
    reverse_helper(this->head);
}

// helper function to traverse the list recursivly
// by traversing all the way to the tail end and then
// print the data of each node in backwards.
void MyList :: reverse_helper(Node* curr) const {
    if (curr != nullptr) {
        reverse_helper(curr->next);
        cout << curr->data << " -- ";
    }
    return;
}

void MyList :: reverse () const {
    vector<int> myvector;
    vector<int>::iterator it;

    Node *curr = this->head;
    while (curr != nullptr) {
        myvector.push_back(curr->data);
        curr = curr->next;
    }

    // Printing all elements in reverse order
    cout << "Elements of vector in reverse order : ";
    for (it=myvector.end()-1; it >= myvector.begin(); it--)
        cout << *it << " -- ";
    cout << '\n';

    //alternatively,  you can use a simple for loop with size() function
    cout << "Elements of vector in reverse order : ";
    for (int i = myvector.size() - 1; i >= 0; i--)
        cout << myvector[i] << " -- ";
}

// Deletes the entire linked list and sets head to point at a nullptr
void MyList :: reset() {
    Node *curr = this->head;
    Node *prev = nullptr;
    Node *saveHead = this->head;

    while(head != nullptr) {
        //Dewete uwu
    }

}


// returns the size of the list
int MyList :: Size() const {
    Node *curr = this->head;
    int size = 0;
    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }
    return size;
}

// find if a node exists in the list
// returns true if found, false otherwise
bool MyList :: Find(int target) {
     Node *curr = this->head;
     bool found = false;
     while (curr != nullptr && !found) {
         if (curr->data == target)
             found = true;
         else
             curr = curr->next;
     }
    return found;
}

// check if list is empty, returns true if so, false otherwise
bool MyList :: IsEmpty() const {
    return (this->head == nullptr);

    // if(this->head == nullptr)
    //     return true;
    //  return false;
}

//Looks at the first node in the list if the list is not empty
int MyList :: peekHead() {
    if(IsEmpty() == false) {
        return this->head->data;
    }
    else {
        cerr << "List is empty." << endl;
    }
}






int main () {
    MyList list;        // list of MyList nodes containing simple int
    cout << "IsEmpty: " << list.IsEmpty() << endl;  // 1
    cout << "Size: " << list.Size() << endl; //0

    // test insertion, traverse, and reverse
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Traverse();     // 1 --> 2 --> 3 --> nullptr

    // test IsEmpty
    cout << "IsEmpty: " << list.IsEmpty() << endl;  // 0

    // test Size
    cout << "Size: " << list.Size() << endl; //3

    // test Reverse
    cout << "Reverse: ";
    list.Reverse();
    cout << endl; // 3 - 2 - 1

    //test peekHead
    cout << "Current Head: " << list.peekHead() << endl; // 1

   return 0;
}