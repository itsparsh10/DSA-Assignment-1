// Single linklist

// Library Management System 
#include<iostream>
#include<string>
using namespace std;

class node {
public:
    string data;
    node* next;

    node(string data) {
        this->data = data;
        this->next = NULL;
    }
};

void bookAtHead(node*& head, string bookname) {
    node* newnode = new node(bookname);
    newnode->next = head;
    head = newnode;
}

void bookAtlead(node*& tail, string bookname) {
    node* newnode = new node(bookname);
    if (tail == NULL) {
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void bookAtspecificPosition(node*& head, string bookname, int position) {
    int count = 0;
    node* temp = head;
    node* newnode = new node(bookname);
    while (count < position - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFirstbook(node*& head) {
    if (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteAtSpecificPosition(node*& head, int position) {
    if (head == NULL) {
        return;
    }
    if (position == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int count = 0;
    node* temp = head;
    while (count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void deletAtlast(node*& head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void Display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool searchBook(node* head, string bookname) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == bookname) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    node* head = NULL;
    node* tail = NULL;

    // Hard code two books into the linked list
    bookAtHead(head, "Gold");
    bookAtlead(tail, "Silver");

    int choice;
    string bookname;
    int position;

    while (true) {
        cout << "Menu:\n1. Add book at head\n2. Add book at tail\n3. Add book at specific position\n4. Delete first book\n5. Delete last book\n6. Delete book at specific position\n7. Search for a book\n8. Display\n9. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter book name: ";
            cin >> bookname;
            bookAtHead(head, bookname);
            break;
        case 2:
            cout << "Enter book name: ";
            cin >> bookname;
            bookAtlead(tail, bookname);
            break;
        case 3:
            cout << "Enter book name: ";
            cin >> bookname;
            cout << "Enter position: ";
            cin >> position;
            bookAtspecificPosition(head, bookname, position);
            break;
        case 4:
            deleteFirstbook(head);
            break;
        case 5:
            deletAtlast(head);
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            deleteAtSpecificPosition(head, position);
            break;
        case 7:
            cout << "Enter book name to search: ";
            cin >> bookname;
            if (searchBook(head, bookname)) {
                cout << "Book found ." << endl;
            } else {
                cout << "Book not foundn." << endl;
            }
            break;
        case 8:
            Display(head);
            break;
        case 9:
            return 0;
        default:
            cout << "Wrong choice!.\n";
        }
    }

    return 0;
}
