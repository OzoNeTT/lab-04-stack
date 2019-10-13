#pragma once

#include <iostream>
#include <type_traits>
#include <exception>
#include <utility>

template<class T>
class StackMain {
protected:
    struct Node {
        T _data;
        Node *next;
    };
    Node *_head;
public:
    StackMain() = default;
    StackMain(const StackMain &stack) = delete;
    StackMain(StackMain &&stack) noexcept = default;

    StackMain &operator=(const StackMain &stack) = delete;
    StackMain &operator=(StackMain &&stack) noexcept = default;

    void push(T&& value){
        Node *newNode = new Node{std::forward<T>(value), _head};
        _head = newNode;
    }

    const T& head() const{
        if(!_head)
            throw std::exception();
        return _head->_data;
    }
    ~StackMain(){
        while (_head) {
            auto *curr = _head;
            _head = curr->next;

            delete curr;
        }
    }
};