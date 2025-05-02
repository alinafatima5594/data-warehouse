#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
}
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


Merge Sort for Linked List:
Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

    Node* left = head;
    Node* right = slow->next;
    slow->next = nullptr;

    /    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}
Insertion Sort for Linked List:

Node* insertionSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* sorted = nullptr; 
    Node* current = head;   

    while (current != nullptr) {
        Node* next = current->next; 

        
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sorted;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);
std::cout << "orignal linkedwha list: ";
    printList(head);

    head = mergeSort(head);
    cout << "Sorted using Merge Sort: ";
    printList(head)
    head = insertionsort (head)
    cout << "Sorted using Insertion Sort: ";
    printList(head);

    return 0;
}
