#include "Stack.h"

template <typename T> Stack<T>::Stack() {}

template <typename T> size_t Stack<T>::size() const { return elements.size(); }

template <typename T> void Stack<T>::push(const T &elem) {
    elements.push_back(elem);
}

template <typename T> bool Stack<T>::pop(T &elem) {
    size_t s = elements.size();
    if (!s) return false;

    elem = elements[s - 1];
    elements.pop_back();
    return true;
}

template <typename T> bool Stack<T>::peek(T &elem) const {
    size_t s = elements.size();
    if (!s) return false;

    elem = elements[s - 1];
    return true;
}