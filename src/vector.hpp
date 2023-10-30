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
    vector(){
        ptr_ = new T[capacity];
    };
    vector(const vector &obj){}; // copy constructor
    vector(vector &&obj){}; // move constructor
    vector& operator=(const vector &obj){}; // copy assignment operator
    vector& operator=(vector &&obj){};// move assignment operator
    ~vector(){}; //destructor
    T& operator[](const size_t& index){
        return ptr_[index];
    };
    T& at(const size_t& index){};
    T& front(){};
    T& back(){};
    void push_back(const T& obj){
        ptr_[acctualSize_] = obj;
    }; //push_back function
};
} // namespace my
