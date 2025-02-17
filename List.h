#include <iostream>

//добавить удалить определить наличие элемента
template <class T>
struct Node{
    T Data;
    Node* Next;
};

template <class T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;
    ListIterator(Node<T>* node){_node(node)};

    ListIterator operator++(Node<T>){
        ListIterator tmp = *this; //сохранили текущий итератор
        ++(*this);
        return tmp;
    }
    ListIterator operator++(){
        _node++;
        return *this;
    }
    friend bool operator==(const ListIterator& a, const ListIterator& b){
        return a._ptr == b._ptr;
    }
    friend bool operator!=(const ListIterator& a, const ListIterator& b){
        return a._ptr != b._ptr;
    }

private:
    pointer _node;

};


template <class T>
class MyForwardLists{
    private:
        Node<T>* _head;
        Node<T>* _hwost; 
    public:
//cbegin, cend сюда
//указатель на последний элемент. итератор на конец списка  

        MyForwardLists(){
            _head->Data = nullptr;
            
        }

        void Add(Node<T> newNode){
            if (_head = nullptr){
                _head->Data = newNode;
                _hwost->Data = newNode;
            }
            else{

            }
        }
        void Delete(Node<T> node){
            if (_head = nullptr)
        }
        bool Conteins(Node<T> node){
            return false;
        }
};