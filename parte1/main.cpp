#include <iostream>
#include <ctime>
#include <list>


using namespace std;

class Node {
private:
    int value;
    Node* next;

public:
    Node(int val) : value(val), next(nullptr) {}
    ~Node() {}

    int getValue() const {
        return value;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* node) {
        next = node;
    }

    // Sobrecarga de operador new
    void* operator new(size_t size);

    // Sobrecarga de operador delete
    void operator delete(void* ptr);

};
class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}
    ~List() = default;

    Node* getHead() const {
        return head;
    }

    void setHead(Node* node) {
        head = node;
    }

    void insert(int val) {
        Node* node = new Node(val);
        node->setNext(head);
        head = node;
    }
};
class Collector {
private:
    std::list<void*> memory_pool;

public:
    Collector() : memory_pool() {}
    ~Collector() {}

    void* allocate(size_t size) {
        if (memory_pool.empty()) {
            return ::operator new(size);
        } else {
            void* ptr = memory_pool.front();
            memory_pool.pop_front();
            return ptr;
        }
    }

    void deallocate(void* ptr) {
        memory_pool.push_back(ptr);
    }

    void printMemoryPool() {
        std::cout << "Memory pool:" << std::endl;
        for (void* ptr : memory_pool) {
            std::cout << "  " << ptr << std::endl;
        }
    }
};