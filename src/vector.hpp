#pragma once

#define SIZE_OF_MEMORY 64

#include <exception>
#include <iostream>

namespace my {
template <class T>
class vector {
private:
    T* ptr_ = nullptr;
    size_t acctualSize_ = 0;
    size_t capacity_ = 1;

public:
    vector() {
        ptr_ = new T[capacity_]{};
    };

    vector(const T& obj) {
        ptr_ = new T[capacity_]{};
        ptr_[0] = obj;
        acctualSize_++;
    }
    vector(const vector& obj) {
        acctualSize_ = obj.acctualSize_;
        capacity_ = obj.capacity_;
        ptr_ = new T[capacity_]{};
        for (size_t i = 0; i < acctualSize_; ++i) {
            ptr_[i] = obj.ptr_[i];
        }
    };  // copy constructor
    vector(vector&& obj) {
        acctualSize_ = obj.acctualSize_;
        capacity_ = obj.capacity_;
        ptr_ = obj.ptr_;
        obj.ptr_ = nullptr;
    };  // move constructor
    vector& operator=(const vector& obj) {
        if (this != &obj) {
            delete[] ptr_;
            capacity_ = obj.capacity_;
            acctualSize_ = obj.acctualSize_;
            ptr_ = new T[capacity_]{};
            for (size_t i = 0; i < acctualSize_; ++i) {
                ptr_[i] = obj.ptr_[i];
            }
        }
        return *this;
    };  // copy assignment operator
    vector& operator=(vector&& obj) {
        if (this != &obj) {
            delete[] ptr_;
            ptr_ = obj.ptr_;
            capacity_ = obj.capacity_;
            acctualSize_ = obj.acctualSize_;
            obj.ptr_ = nullptr;
        }
        return *this;
    };  // move assignment operator
    ~vector() {
        delete[] ptr_;
    };  // destructor
    T& operator[](const size_t& index) {
        return ptr_[index];
    };
    T& at(const size_t& index) {
        if (index < acctualSize_) {
            return ptr_[index];
        }
        throw std::out_of_range("Index out of range");
    };
    T& front() {
        return ptr_[0];
    };
    T& back() {
        return ptr_[acctualSize_ - 1];
    };
    void push_back(const T& obj) {
        if (acctualSize_ == capacity_) {
            capacity_ *= 2;
            auto tempPtr = new T[capacity_]{};
            for (size_t i = 0; i < acctualSize_; ++i) {
                tempPtr[i] = ptr_[i];
            }
            delete[] ptr_;
            ptr_ = tempPtr;
        }
        ptr_[acctualSize_] = obj;
        acctualSize_++;
    };  // push_back function
};
template <>
class vector<bool> {
    u_int64_t* ptr_ = nullptr;
    size_t acctualSize_ = 0;
    size_t capacity_ = 1;

public:
    class reference{
        friend class vector<bool>;
        u_int64_t* referencePtr_ = nullptr;
        size_t bitIndex_ = 0;
        reference(u_int64_t* referencePtr, size_t bitIndex) 
            : referencePtr_(referencePtr), bitIndex_(bitIndex){}
    public:
        reference& operator=(bool obj){
            if(obj){
                *referencePtr_ |= (1 << bitIndex_);
            }
            else{
                *referencePtr_ &= ~(1 << bitIndex_);
            }
            return *this;
        }
        operator bool() const {
        return ((*referencePtr_ >> bitIndex_) & 1) != 0;
    }
    };
    vector() {
        ptr_ = new u_int64_t[capacity_]{};
    };
    vector(bool obj) {
        ptr_ = new u_int64_t[capacity_]{};
        ptr_[0] = obj;
        acctualSize_++;
    }
    vector(const vector& obj){
        acctualSize_ = obj.acctualSize_;
        capacity_ = obj.capacity_;
        ptr_ = new u_int64_t[capacity_]{};
        for (size_t i = 0; i < acctualSize_; ++i) {
            ptr_[i] = obj.ptr_[i];
        }
    };
    vector(vector&& obj){
        acctualSize_ = obj.acctualSize_;
        capacity_ = obj.capacity_;
        ptr_ = obj.ptr_;
        obj.ptr_ = nullptr;
    };
    vector& operator=(const vector& obj){
         if (this != &obj) {
            delete[] ptr_;
            capacity_ = obj.capacity_;
            acctualSize_ = obj.acctualSize_;
            ptr_ = new u_int64_t[capacity_]{};
            for (size_t i = 0; i < acctualSize_; ++i) {
                ptr_[i] = obj.ptr_[i];
            }
        }
        return *this;
    };
    vector& operator=(vector&& obj){
        if (this != &obj) {
            delete[] ptr_;
            ptr_ = obj.ptr_;
            capacity_ = obj.capacity_;
            acctualSize_ = obj.acctualSize_;
            obj.ptr_ = nullptr;
        }
        return *this;
    };  
    ~vector(){
        delete []ptr_;
    };
    void push_back(bool obj) {
        if (acctualSize_ == capacity_ * SIZE_OF_MEMORY) {
            capacity_ *= 2;
            auto tempPtr = new u_int64_t[capacity_]{};
            for (size_t i = 0; i < acctualSize_ / SIZE_OF_MEMORY; ++i) {
                tempPtr[i] = ptr_[i];
            }
            delete[] ptr_;
            ptr_ = tempPtr;
        }
        if (obj) {
            ptr_[acctualSize_ / SIZE_OF_MEMORY] = ptr_[acctualSize_ / SIZE_OF_MEMORY] << 1;
            ptr_[acctualSize_ / SIZE_OF_MEMORY] |= (1 << 0);
        }
        acctualSize_++;
    };
    reference operator[](const size_t& index) {
        return reference(&ptr_[index / SIZE_OF_MEMORY], index % SIZE_OF_MEMORY);
    };
    reference at(const size_t& index){
        if (index < acctualSize_) {
            return reference(&ptr_[index / SIZE_OF_MEMORY], index % SIZE_OF_MEMORY);
        }
        throw std::out_of_range("Index out of range");
    };
    reference front() {
        return reference(&ptr_[0], 0);
    };
    reference back() {
        return reference(&ptr_[acctualSize_ - 1], (acctualSize_ % SIZE_OF_MEMORY) - 1);
    };
};
}  // namespace my
