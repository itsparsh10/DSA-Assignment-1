// Double Linklist Question


// // Music playlist creation
// -Design a system to keep track of songs in a playlist
// -Song details are represented by nodes in a doubly linked list.
// -Navigate through previous and next song in the list
// -Display the songs according to producer, singer and genre.

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    string producer;
    string singer;
    string genre;
    Node *next;
    Node *prev;
    Node()
    {
        cout << "Enter song name: ";
        getline(cin >> ws, name);
        cout << "Enter producer: ";
        getline(cin >> ws, producer);
        cout << "Enter singer: ";
        getline(cin >> ws, singer);
        cout << "Enter genre: ";
        getline(cin >> ws, genre);
        next = NULL;
        prev = NULL;
    }
};

Node *Create_Playlist(int n)
{
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newnode = new Node();
        if (start == NULL)
        {
            start = newnode;
            newnode->prev = NULL;
            ptr = newnode;
        }
        else
        {
            newnode->prev = ptr;
            ptr->next = newnode;
            ptr = newnode;
        }
    }
    return start;
}

void Add_New_Song(Node *&a)
{
    Node *ptr = a;
    Node *newnode = new Node();
    if (newnode == NULL)
    {
        cout << "Overflow\n";
        return;
    }
    if (a == NULL)
    {
        newnode->prev = NULL;
        a = newnode;
        cout << " Song Added Successfully \n";
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->prev = ptr;
        ptr->next = newnode;
        cout << " Song Added Successfully \n";
    }
}

void Delete_Song(Node *&a)
{
    Node *ptr = a;
    Node *temp = NULL;
    string sname;
    if (a == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }
    cout << "Enter song to remove: ";
    cin.ignore();
    getline(cin, sname);
    while (ptr != NULL)
    {
        if (ptr->name == sname)
        {
            if (ptr->prev == NULL)
            {
                a = ptr->next;
                if (a != NULL)
                {
                    a->prev = NULL;
                }
            }
            else if (ptr->next == NULL)
            {
                temp = ptr->prev;
                temp->next = ptr->next;
            }
            else
            {
                temp = ptr->prev;
                temp->next = ptr->next;
                ptr->next->prev = temp;
            }
            delete ptr;
            cout << "Song removed successfully\n";
            return;
        }
        ptr = ptr->next;
    }
    cout << "Song not found\n";
}

void displayPlaylistMenu(Node *&a)
{
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }
    else
    {
        int choice = 0;
        cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
             << endl;
    b:
        cout << "1.Previous Song\n2.Next Song\n3.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (ptr == a)
            {
                cout << "This is the first song\n";
                goto b;
            }
            else
            {
                ptr = ptr->prev;
                cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
                     << endl;
                goto b;
            }
            break;
        case 2:
            if (ptr->next == NULL)
            {
                cout << "This is the last song\n";
                goto b;
            }
            else
            {
                ptr = ptr->next;
                cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
                     << endl;
                goto b;
            }
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice\n";
            goto b;
        }
    }
}

void Display_Playlist(Node *&a)
{
    int count = 0;
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
                 << endl;
            count++;
            ptr = ptr->next;
        }
        cout << "Number of songs: " << count << endl;
    }
}

void Display_Particular_Songs(Node *&a)
{
    int count = 0;
    Node *ptr = a;
    string sname;
    if (a == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }
    else
    {
        int choice;
    b:
        cout << "Display songs according to:\n1.Singer\n2.Producer\n3.Genre\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter singer name: ";
            cin.ignore();
            getline(cin, sname);
            count = 0;
            ptr = a;
            while (ptr != NULL)
            {
                if (ptr->singer == sname)
                {
                    cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
                         << endl;
                    count++;
                }
                ptr = ptr->next;
            }
            if (count == 0)
            {
                cout << "No songs found\n";
            }
            break;
        case 2:
            cout << "Enter producer name: ";
            cin.ignore();
            getline(cin, sname);
            count = 0;
            ptr = a;
            while (ptr != NULL)
            {
                if (ptr->producer == sname)
                {
                    cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
                         << endl;
                    count++;
                }
                ptr = ptr->next;
            }
            if (count == 0)
            {
                cout << "No songs found\n";
            }
            break;
        case 3:
            cout << "Enter genre: ";
            cin.ignore();
            getline(cin, sname);
            count = 0;
            ptr = a;
            while (ptr != NULL)
            {
                if (ptr->genre == sname)
                {
                    cout << ptr->name << "\nSinger: " << ptr->singer << "\nProducer: " << ptr->producer << "\nGenre: " << ptr->genre << endl
                         << endl;
                    count++;
                }
                ptr=ptr->next;
            }
            if (count == 0)
            {
                cout << "No songs found\n";
            }
            break;
        default:
            cout << "Invalid choice\n";
            goto b;
        }
    }
}

void Delete_Playlist(Node *&a)
{
    Node *ptr = a;
    Node *temp = ptr;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    a=NULL;
}
int main()
{
    int n;
    cout << "Enter number of songs to add to playlist: ";
    cin >> n;
    Node *start = Create_Playlist(n);
    int choice;
    char ans = 'y';
    do
    {
        cout << "Enter your choice: \n1.Add a song\n2.Remove a song\n3.Show full playlist\n4.Show playlist menu\n5.Show specific songs\n6.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_New_Song(start);
            break;
        case 2:
            Delete_Song(start);
            break;
        case 3:
            Display_Playlist(start);
            break;
        case 4:
            displayPlaylistMenu(start);
            break;
        case 5:
            Display_Particular_Songs(start);
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
    Delete_Playlist(start);
    return 0;
}