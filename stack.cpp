#include <iostream>

using namespace std;


struct Node {

    int data;

    Node* next;

    Node(int value) : data(value), next(nullptr) {}

};



class LinkedList {

private:

    Node* head;

public:

    LinkedList() : head(nullptr) {}



    void insert(int value) {

        Node* newNode = new Node(value);

        if (!head) {

            head = newNode;

        } else {

            Node* current = head;

            while (current->next) {

                current = current->next;

            }

            current->next = newNode;

        }

    }

    // Function to delete a value from the linked list

    void deleteValue(int value) {

        Node* current = head;

        Node* prev = nullptr;

        while (current && current->data != value) {

            prev = current;

            current = current->next;

        }

        if (current) {

            if (prev) {

                prev->next = current->next;

            } else {

                head = current->next;

            }

            delete current;

            cout << "Value " << value << " deleted from the linked list.\n";

        } else {

            cout << "Value " << value << " not found in the linked list.\n";

        }

    }



    void display() {

        Node* current = head;

        while (current) {

            cout << current->data << " ";

            current = current->next;

        }

        cout << "\n";

    }



    ~LinkedList() {

        Node* current = head;

        Node* next = nullptr;

        while (current) {

            next = current->next;

            delete current;

            current = next;

        }

    }

};

int main() {

    LinkedList myList;


    myList.insert(23);

    myList.insert(22);

    myList.insert(15);

    myList.insert(12);
    myList.insert(1);
    myList.insert(29);
     myList.insert(1);



    cout << "Original Linked List: ";

    myList.display();


    myList.deleteValue(15);


    cout << "Updated Linked List: ";

    myList.display();

    return 0;

}
