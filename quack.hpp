
#ifndef QUACK_HPP_INCLUDED
#define QUACK_HPP_INCLUDED

#include <vector>
#include <ostream>

template <typename T>
class Quack
{
private:
    std::vector<T> queue_;
    std::vector<T> stack_;
    size_t size_;
    
    void reshuffleQueue();
    void reshuffleStack();

public:
    Quack();
    ~Quack() = default;
    Quack(const Quack &other) = delete;
    Quack &operator=(Quack &other) = delete;

    void push(T val);
    T pop();
    T dequeue();

    void printToStream(std::ostream &out) const;
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const Quack<T>& q);

#include "quack-private.hpp"

#endif //QUACK_INLCUDED
