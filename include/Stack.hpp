#pragma once

#include <iostream>
#include <type_traits>
#include <exception>
#include <utility>

template <typename  T>
class StackOne {
private :
    struct Node {
        T _data;
        Node *next;
    };
    Node *_head;
public:
    StackOne() {
        _head = nullptr;
    }
    StackOne(const StackOne&) = delete;
    StackOne(StackOne &&StackOne) noexcept = default;
    StackOne& operator=(const StackOne&) = delete;

    void push(T&& value){
        Node *newNode = new Node{std::forward<T>(value), _head};
        _head = newNode;
    }
    void push(const T& value){
        Node *newNode = new Node{value, _head};
        _head = newNode;
    }
    void pop(){
        if(!_head)
            throw std::exception();
        _head = _head->next;
    }
    const T& head() const{
        if(!_head)
            throw std::exception();
        return _head->_data;
    }
    ~StackOne(){
        while (_head) {
            auto *curr = _head;
            _head = curr->next;

            delete curr;
        }
    }
};


template <typename T>
class StackTwo
{
private:
struct Node {
    T _data;
    Node *next;
};
Node *_head;
public:
    StackTwo() {
        _head = nullptr;
    }
    StackTwo(const StackTwo&) = delete;
    StackTwo(StackTwo &&StackTwo) noexcept = default;
    StackTwo& operator=(const StackTwo&) = delete;

    void push(T&& value){
        Node *newNode = new Node{std::forward<T>(value), _head};
        _head = newNode;
    }
    template <typename ... Args>
    void push_emplace(Args&&... value){
        auto *_next = _head;
        _head = new Node{std::forward<Args>(value)..., _next};
    }
    const T& head() const{
        if(!_head)
            throw std::exception();
        return _head->_data;
    }
    T pop()  {
        if(!_head)
            throw std::exception();
        T data = _head->_data;
        _head = _head->next;
        return data;
    }
    ~StackTwo(){
        while (_head) {
            auto *curr = _head;
            _head = curr->next;

            delete curr;
        }
    }
};