// Round-Robin Scheduling: (Please follow the different constraints as
// discussed in the class)
// -Simulate a round-robin scheduling for a set of users in an department for
// printing task.
// -Users are represented by nodes in a circular linked list, and each iteration
// of the algorithm selects the next user in the circle.

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string User_ID;
    float time;
    Node *next;
    Node()
    {
        cout << "Enter User ID: ";
        cin >> User_ID;
        cout << "Enter time for the User (in HH.MM format): ";
        cin >> time;
        next = NULL;
    }
};

Node *createList(int n)
{
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newnode = new Node();
        if (start == NULL)
        {
            start = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = ptr->next;
        }
    }
    ptr->next = start;
    return start;
}

void Scheduling(Node *&a, float &n)
{
    float b;
    cout << "Enter how much time to give to each user (in HH.MM format): ";
    cin >> b;
    while (b >= n || b <= 00.00)
    {
        cout << "Invalid time. Enter appropriate time for each user (in HH.MM format) : ";
        cin >> b;
    }
    Node *ptr = a;
    Node *preptr = ptr;
    Node *temp = ptr;
    if (a == NULL)
    {
        cout << "No users available for scheduling.\n";
        return;
    }
    else
    {
        while (n > 00.00 && a != NULL)
        {
            if (ptr->time <= b)
            {
                if (ptr->time > n)
                {
                    ptr->time -= n;
                    n = 00.00;
                }
                else
                {
                    n -= ptr->time;
                    ptr->time = 0;
                }
            }
            else
            {
                ptr->time -= b;
                n -= b;
            }
            if (ptr->time <= 00.00)
            {
                cout << "User " << ptr->User_ID << " Task completed successfully \n";
                if (ptr == a && ptr->next == a)
                {
                    delete ptr;
                    a = NULL;
                    cout << "All users work is done\nTotal time left: " << n << endl;
                    return;
                }
                if (ptr->next == a)
                {
                    preptr->next = a;
                }
                else if (ptr == a)
                {
                    temp = ptr;
                    while (temp->next != a)
                    {
                        temp = temp->next;
                    }
                    a = ptr->next;
                    temp->next = a;
                }
                else
                {
                    preptr->next = ptr->next;
                }
                temp = ptr;
                ptr = ptr->next;
                delete temp;
            }
            else
            {
                preptr = ptr;
                ptr = ptr->next;
            }
        }
        if (n <= 0.00 && a != NULL)
        {
            cout << "Time over\n";
            ptr = a;
            do
            {
                if (ptr == a && ptr->next == a)
                {
                    cout << "User " << ptr->User_ID << " work is left(" << (ptr->time) << " hours)\n";
                    return;
                }
                cout << "User " << ptr->User_ID << " work is left(" << (ptr->time) << " hours)\n";
                ptr = ptr->next;
            } while (ptr->next != a);
        }
    }
}

void deleteList(Node *&a)
{
    if (a == NULL)
    {
        return;
    }
    Node *ptr = a;
    Node *temp = NULL;
    do
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    } while (ptr != a);
    a = NULL;
}

int main()
{
    float time;
    cout << " Enter total printing time available (in HH.MM format) : ";
    cin >> time;
    while (time <= 00.00)
    {
        cout << "Invalid time. Enter total appropriate time(in HH.MM format): ";
        cin >> time;
    }
    int n;
    cout << "Enter number of users: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Invalid number of users. Enter appropriate number of users: ";
        cin >> n;
    }
    Node *start = createList(n);
    Scheduling(start, time);
    deleteList(start);
    return 0;
}