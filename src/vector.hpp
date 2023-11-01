#pragma once

#include <iostream>

namespace my
{
template<class T>
class vector
{
private:
    T* ptr_ = nullptr;
    size_t acctualSize_ = 0;
    size_t capacity_ = 2;
public:
    vector(){
        ptr_ = new T[capacity_];
    };

    vector(const T &obj){
        ptr_ = new T[capacity_];
        ptr_[0] = obj;
        acctualSize_ ++;
    }
    vector(const vector &obj){
        acctualSize_ = obj.acctualSize_;
        capacity_ = obj.capacity_;
        ptr_ = new T[capacity_];
        for(size_t i = 0; i < acctualSize_; ++i){
            ptr_[i] = obj.ptr_[i];
        }
    }; // copy constructor
    vector(vector &&obj){}; // move constructor
    vector& operator=(const vector &obj){}; // copy assignment operator
    vector& operator=(vector &&obj){};// move assignment operator
    ~vector(){
        delete []ptr_;
    }; //destructor
    T& operator[](const size_t& index){
        return ptr_[index];
    };
    T& at(const size_t& index){};
    T& front(){};
    T& back(){};
    void push_back(const T& obj){
        if(acctualSize_ == capacity_){
            capacity_ *= 2;
            auto tempPtr = new T[capacity_];
            for(size_t i = 0; i < acctualSize_; ++i){
                tempPtr[i] = ptr_[i];
            }
            delete []ptr_;
            ptr_ = tempPtr;
        }
            ptr_[acctualSize_] = obj;
            acctualSize_++;
    }; //push_back function
};
} // namespace my
