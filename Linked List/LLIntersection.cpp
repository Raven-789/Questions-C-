#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
        Node(int val) {
            data = val;
            next = nullptr;
        }
    };
    
    int getLength(Node* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
    Node* getIntersectionNode(Node* headA, Node* headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        int diff = abs(lenA - lenB);
    
        if (lenB > lenA) swap(headA, headB);
    
        for (int i = 0; i < diff; i++)
            headA = headA->next;
    
        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
    
        return nullptr;
    }
    
    void createIntersection(Node* headA, Node* headB, int pos) {
        Node* tempA = headA;
        Node* tempB = headB;
    
        for (int i = 1; i < pos; i++) {
            if (tempA != nullptr) tempA = tempA->next;
        }
    
        while (tempB->next != nullptr) tempB = tempB->next;
        tempB->next = tempA;
    }
    
    int main() {
        // List A: 1 -> 2 -> 3 -> 6 -> 7
        Node* headA = new Node(1);
        headA->next = new Node(2);
        headA->next->next = new Node(3);
        headA->next->next->next = new Node(6);
        headA->next->next->next->next = new Node(7);
    
        // List B: 4 -> 5
        Node* headB = new Node(4);
        headB->next = new Node(5);
    
        // Create intersection at position 3 (node with value 3)
        createIntersection(headA, headB, 3);
    
        Node* intersection = getIntersectionNode(headA, headB);

        if (intersection)
            cout << "Intersection Node: " << intersection->data << endl;
        else
            cout << "No intersection "<<endl;

}
            