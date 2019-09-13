#pragma once

#include <iostream>
#include <type_traits>
#include <exception>
#include <utility>

template <typename T>
class Stack
{
private:
struct Node {
    T _data;
    Node *next;
};
Node *_head;
public:
    Stack() {
        _head = nullptr;
    }
    Stack(const Stack&) = delete;
    Stack(Stack &&stack) noexcept = default;

    Stack& operator=(const Stack&) = delete;

    void push(T&& value){
        Node *newNode = new Node{std::forward<T>(value), _head};
        _head = newNode;
    }
    void push(const T& value){
        Node *newNode = new Node{value, _head};
        _head = newNode;
    }

    //void pop(){
    //    if(!_head)
    //        throw std::exception();
    //    _head = _head->next;
    //}

    const T& head() const{
        if(!_head)
            throw std::exception();
        return _head->_data;
    }
    template <typename ... Args>
    void push_emplace(Args&&... value){
        auto *_next = _head;
        _head = new Node{std::forward<Args>(value)..., _next};
    }

    T pop()  {
        if(!_head)
            throw std::exception();
        T data = _head->_data;
        _head = _head->next;
        return data;
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