#include "quack.hpp"
#include <iostream>
using namespace std;

template <typename T>
Quack<T>::Quack() : queue_{}, stack_{},size_{0} {
}

template <typename T>
T Quack<T>::pop(){
    if (size_ == 0){
        std::cerr << "Popping an empty quack" << endl;
        throw("Popping an empty quack");
        exit(1);
    }
    int value;
    if (stack_.size() == 0)
    {
        reshuffleStack();
    }
    value = stack_.back();
    stack_.pop_back();
    --size_;
    return value;
}

template <typename T>
T Quack<T>::dequeue(){
    if (size_ == 0){
        cerr << "Dequeue on empty quack" << endl;
        throw("Dequeue on empty quack");
        exit(1);
    }
    int value;
    if (queue_.size() == 0){
        reshuffleQueue();
    }
    value = queue_.back();
    queue_.pop_back();
    --size_;
    return value;
}

template <typename T>
void Quack<T>::push(T val){
    stack_.push_back(val);
    ++size_;
}

template <typename T>
void Quack<T>::reshuffleQueue(){
    // Queue is empty case
    if (size_ == 1){
        queue_.push_back(stack_.back());
        stack_.pop_back();
    } else {
        size_t numItems = size_ / 2;
        queue_.resize(numItems);
        std::reverse_copy(begin(stack_), begin(stack_) + numItems, begin(queue_));
        std::move(begin(stack_) + numItems, end(stack_), begin(stack_));
        stack_.resize(size_ - numItems);
    }
    return;
}
template <typename T>
void Quack<T>::reshuffleStack(){
    // Stack is empty case
    if (size_ == 1){
        stack_.push_back(queue_.back());
        queue_.pop_back();
    } else {
        size_t numItems = size_ / 2;
        stack_.resize(numItems);
        std::reverse_copy(begin(queue_), begin(queue_) + numItems, begin(stack_));
        std::move(begin(queue_) + numItems, end(queue_), begin(queue_));
        queue_.resize(size_ - numItems);
    }
    return;
}

template <typename T>
void Quack<T>::printToStream(ostream& out) const{
    out << "Queue: ";
    for (auto &e : queue_) {
        out << e << " ";
    }
    out << "\nStack: ";
    for (auto&e : stack_){
        out << e << " ";
    }
    out << "\n";

}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Quack<T>& q){
    q.printToStream(os);
    return os;
}