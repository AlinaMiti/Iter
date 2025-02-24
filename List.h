#include <iostream>
#include <forward_list>

//добавить удалить определить наличие элемента
template <typename T>
struct Node{
    T Data;
    Node* Next;
    Node(T data, Node* next) {
        Data = data;
        Next = next;
    }
};

template <typename T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    ListIterator(Node<T>* node) : _node(node) {}

    // ListIterator operator++(Node<T>){
    //     ListIterator tmp = *this; //сохранили текущий итератор
    //     ++(*this);
    //     return tmp;
    // }
    // ListIterator operator++(){
    //     _node++;
    //     return *this;
    // }

    reference operator*() {
        return _node->Data;
    }
    pointer operator->() {
        return &(_node->Data);
    }
    
    ListIterator& operator++() {
        _node = _node->Next;
        return *this;
    }

    ListIterator operator++(int) {
        ListIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    friend bool operator==(const ListIterator& a, const ListIterator& b){
        return a._node == b._node;
    }
    friend bool operator!=(const ListIterator& a, const ListIterator& b){
        return a._node != b._node;
    }

private:
    Node<T>* _node;

};

template <typename T>
struct ConstListItearator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = const T*;
    using reference = const T&;
    ConstListItearator(Node<T>* node) : _node(node) {}

    reference operator*() {
        return _node->Data;
    }
    pointer operator->() {
        return &(_node->Data);
    }

private:
    Node<T>* _node;
};


template <typename T>
class MyForwardLists{
    private:
        Node<T>* _head;
        Node<T>* _tail; 
    public:
//cbegin, cend сюда
//указатель на последний элемент. итератор на конец списка  

        MyForwardLists(){
            _head = nullptr;
            _tail = nullptr;
        }

        void Add(T data){   
            if (_head == nullptr) {
            _head = new Node<T>(data, nullptr);
            _tail = _head;
            } else {
                _tail->Next = new Node<T>(data, nullptr);
                _tail = _tail->Next;
            }
        }
        void Delete(T data){   //с итератором. циклом пройтись итератором
            if (_head == nullptr){
                throw "empty";
            }
            Node<T>* tmp = _head;
            Node<T>* a = nullptr;
            while((tmp != nullptr) && (tmp->Data != data)){
                a = tmp;
                tmp = tmp->Next;
            }
            if(tmp != nullptr){
                if(a != nullptr){
                    a->Next = tmp->Next;
                }
                else{
                    _head = _head->Next;
                }
                delete tmp;
            }
            
        }
        bool Conteins(T data){   //есть ли элемент в списке   //с итератором
            // Node<T>* tmp = _head;
            // if(tmp->Data != data){
            //     tmp = tmp->Next;
            // }
            // else{
            //     return true;
            // }
            // return false;

            for(ListIterator<T> it = begin();it != end(); ++it){  //с итератором. Также удаление сделать
                if(*it == data){
                    return true;
                }
            }
            return false;
        }

        ListIterator<T> begin() {
            return ListIterator<T>(_head);
        }

        ListIterator<T> end() {
            return ListIterator<T>(_tail->Next);
        }

        ConstListItearator<T> cbegin() {
            return ConstListItearator<T>(_tail);
        }

        ConstListItearator<T> cend() {
            return ConstListItearator<T>(_tail);
        }
};