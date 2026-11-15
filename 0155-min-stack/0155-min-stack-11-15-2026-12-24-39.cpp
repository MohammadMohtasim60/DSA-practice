class MinStack {
     struct Node {
        int val;
        int minVal;
        Node* next;

        Node(int x, int m) {
            val = x;
            minVal = m;
            next = NULL;
        }
    };

    Node* topNode;
    public:
    MinStack() {
        topNode = NULL;
    }

    void push(int val) {
        if (topNode == NULL) {
            topNode = new Node(val, val);
        }
        else {
            int mini = min(val, topNode->minVal);
            Node* temp = new Node(val, mini);
            temp->next = topNode;
            topNode = temp;
        }
    }

    void pop() {
        if (topNode == NULL) return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (topNode == NULL) return -1;
        return topNode->val;
    }

    int getMin() {
        if (topNode == NULL) return -1;
        return topNode->minVal;
    }
};