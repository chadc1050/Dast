#pragma once
#include <stdexcept>

template<typename T>
struct Node<T> {
    T data;
    Node* next;

    Node(T data, Node* next) : data(data), next(next) {}
    Node(T data) : data(data), next(nullptr) {}
    Node() : data(nullptr), next(nullptr) {}
};

template<typename T>
class LinkedList<T> {
public:
    LinkedList() = default;

    T get_head() {
        return head->data;
    }

    T get_tail() {
        Node<T>* curr = head;
        while (head->next != nullptr) {
            curr = curr->next;
        }
        return curr->data;
    }

    T at(const size_t index) {
        Node<T>* curr = head;
        for (size_t i = 0; i < index; i++) {
            if (curr->next == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            curr = curr->next;
        }

        return curr->data;
    }

    bool contains(const T item) {
        Node<T>* curr = head;
        while (curr != nullptr) {
            if (curr->data == item) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void insert(const size_t index, T item) {
        Node<T>* curr = head;
        for (size_t i = 0; i < index; i++) {
            if (curr->next == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            curr = curr->next;
        }
        curr->next = new Node<T>(item, curr->next);
    }

    void push_back(T item) {
        Node<T>* curr = head;
        while (true) {
            curr = curr->next;
            if (curr == nullptr) {
                curr = new Node<T>(item);
                curr->next = nullptr;
                break;
            }
        }
    }

    void clear() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }

    ~LinkedList() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
    }

private:
    Node<T>* head = nullptr;
};

