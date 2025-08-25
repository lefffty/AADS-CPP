#include <iostream>


template <typename T>
struct Node
{
    Node(T value){
        this->value = value;
    };

    T value;
    Node* next = nullptr;
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    unsigned int size;
public:
    LinkedList(): head(nullptr), size(0) {}

    unsigned int _size(){
        return this->size;
    }

    void push(T value){
        if (this->head == nullptr) {
            head = new Node<T>(value);
            this->size++;
        }
        else {
            Node<T>* node = new Node<T>(value);
            Node<T>* current = head;
            while (current->next){
                current = current->next;
            }
            current->next = node;
            this->size++;
        }
    }

    T pop(){
        Node<T>* temp = this->head;
        this->head = this->head->next;
        return temp->value;
    }

    T get(){
        return this->head->value;
    }

    bool find(T value){
        auto current = this->head;
        while (current) {
            if (current.value == value) {
                return true;
            }
        }
        return false;
    }

    void reverse(){
        if (this->head){
            Node<T>* current = nullptr;
            while (head) {
                Node<T>* temp = this->head->next;
                this->head->next = current;
                current = head;
                head = temp;
            }
        }
    }

    bool is_empty(){
        return this->size < 0;
    }

    void print(){
        Node<T>* current = this->head;
        while (current){
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << "NULL";
    }

    ~LinkedList(){
        Node<T>* current = this->head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};


int main(){
    LinkedList<int>* list = new LinkedList<int>();
    for (size_t i = 0; i < 10; i++)
    {
        list->push(i);
    }
    int result = list->pop();
    std::cout << result << std::endl;
    list->print();
}