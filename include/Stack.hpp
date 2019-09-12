#pragma once

#include <iostream>
#include <type_traits>
#include <exception>
#include <algorithm> //мало ли понадобится

template <typename T>
class Stack
{
private:
struct Node {
    T Data;
    Node *next;
};
Node *_head;
public:
    Stack() {
        _head = nullptr;
    }
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    void push(T&& value){
        Node *newNode = new Node{value, _head};
        _head = newNode;
    }
    void push(const T& value){
        Node *newNode = new Node{value, _head};
        _head = newNode;
    }
    void pop(){
        _head = _head->next;
    }
    const T& head() const{
        if(!_head)
            throw std::exception();
        return _head->Data;
    }
    ~Stack()
    {
        while (_head) {
            auto *curr = _head;
            _head = curr->next;

            delete curr;
        }
    }
};