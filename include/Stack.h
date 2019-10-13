#pragma once
#include "MainStack.h"

template<class T>
class Stack : public StackMain<T>{
public:
    void push(const T& value){
        auto *newNode = new typename StackMain<T>::Node{value, StackMain<T>::_head};
        StackMain<T>::_head = newNode;
    }
    void pop(){
        if(!StackMain<T>::_head)
            throw std::exception();
        StackMain<T>::_head = StackMain<T>::_head->next;
    }
};
