#pragma once

namespace my
{
template<class T>
class vector
{
private:
    T* ptr_ = nullptr;
    size_t acctualSize_ = 0;
    size_t capacity = 2;
public:
    vector(){};
    vector(const vector &obj){}; // copy constructor
    vector(vector &&obj){}; // move constructor
    vector& operator=(const vector &obj){}; // copy assignment operator
    vector& operator=(vector &&obj){};// move assignment operator
    T& operator[](const size_t& index){};
    T& at(const size_t& index){};
    ~vector(){}; //destructor
    void push_back(const T& obj){}; //push_back function

};
} // namespace my
