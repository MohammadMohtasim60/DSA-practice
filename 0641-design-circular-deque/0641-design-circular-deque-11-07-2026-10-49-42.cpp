class MyCircularDeque {
public:

    class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int value) {
            data = value;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        head = tail = NULL;
        size = 0;
        capacity = k;
    }

    // Insert at Front
    bool insertFront(int value) {
        if(size == capacity)
            return false;

        Node* NEW = new Node(value);

        if(size == 0) {
            head = tail = NEW;
        }
        else {
            NEW->next = head;
            head->prev = NEW;
            head = NEW;
        }

        size++;
        return true;
    }

    // Insert at Rear
    bool insertLast(int value) {
        if(size == capacity)
            return false;

        Node* NEW = new Node(value);

        if(size == 0) {
            head = tail = NEW;
        }
        else {
            tail->next = NEW;
            NEW->prev = tail;
            tail = NEW;
        }

        size++;
        return true;
    }

    // Delete from Front
    bool deleteFront() {
        if(size == 0)
            return false;

        Node* temp = head;

        head = head->next;

        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        size--;

        return true;
    }

    // Delete from Rear
    bool deleteLast() {
        if(size == 0)
            return false;

        Node* temp = tail;

        tail = tail->prev;

        if(tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
        size--;

        return true;
    }

    // Get Front Element
    int getFront() {
        if(size == 0)
            return -1;

        return head->data;
    }

    // Get Rear Element
    int getRear() {
        if(size == 0)
            return -1;

        return tail->data;
    }

    // Check Empty
    bool isEmpty() {
        return size == 0;
    }

    // Check Full
    bool isFull() {
        return size == capacity;
    }

    // Display
    void Display() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }

        cout << endl;
    }
};
