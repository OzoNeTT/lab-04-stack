#pragma once
#include "MainStack.h"

template<class T>
class StackNC : public StackMain<T> {
public:
    template <typename ... Args>
    void push_emplace(Args&&... value){
        auto *_next = StackMain<T>::_head;
        StackMain<T>::_head = new typename StackMain<T>::Node{std::forward<Args>(value)..., _next};
    }

    T pop()  {
        if(!StackMain<T>::_head)
            throw std::exception();
        T data = StackMain<T>::_head->_data;
        StackMain<T>::_head = StackMain<T>::_head->next;

        return data;
    }
};