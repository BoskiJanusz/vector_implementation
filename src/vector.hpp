#pragma once

#define SIZE_OF_MEMORY 64

#include <exception>
#include <iostream>

namespace my {
template <class T>
class vector {
private:
    T* begin_ = nullptr;
    T* end_ = nullptr;
    T* capacity_ = nullptr;

public:
    vector()
        : begin_(new T[0]{}), end_(begin_), capacity_(begin_){};
    vector(const T& obj)
        : begin_(new T[1]{}), end_(begin_ + 1), capacity_(begin_ + 1) {
        *begin_ = obj;
    }
    vector(const vector& obj)
        : begin_(new T[obj.size()]{}), end_(begin_ + 1), capacity_(begin_ + obj.capacity()) {
        for (size_t i = 0; i < obj.size(); ++i) {
            begin_[i] = obj.begin_[i];
        }
    };  // copy constructor
    vector(vector&& obj)
        : begin_(obj.begin_), end_(obj.end_), capacity_(obj.capacity_) {
        obj.begin_ = nullptr;
    };  // move constructor
    vector& operator=(const vector& obj) {
        if (this != &obj) {
            delete[] begin_;
            begin_ = new T[obj.size()]{};
            for (size_t i = 0; i < obj.size(); ++i) {
                begin_[i] = obj.begin_[i];
            }
            end_ = begin_ + 1;
            capacity_ = begin_ + obj.capacity();
        }
        return *this;
    };  // copy assignment operator
    vector& operator=(vector&& obj) {
        if (this != &obj) {
            delete[] begin_;
            begin_ = obj.begin_;
            end_ = obj.end_;
            capacity_ = obj.capacity_;
            obj.begin_ = nullptr;
        }
        return *this;
    };  // move assignment operator
    ~vector() {
        delete[] begin_;
    };  // destructor
    T& operator[](const size_t& index) {
        return begin_[index];
    };
    size_t size() const {
        return (end_ - begin_);
    }
    size_t capacity() const {
        return (capacity_ - begin_);
    }
    T& at(const size_t& index) {
        if (index < size()) {
            return begin_[index];
        }
        throw std::out_of_range("Index out of range");
    };
    T& front() {
        return *begin_;
    };
    T& back() {
        return *(end_ - 1);
    };
    void push_back(const T& obj) {
        if (size() == capacity()) {
            auto newCapacity = capacity() == 0 ? 1 : capacity() * 2;
            auto tempPtr = new T[newCapacity]{};
            size_t oldSize = size();
            for (size_t i = 0; i < oldSize; ++i) {
                tempPtr[i] = begin_[i];
            }
            delete[] begin_;
            begin_ = tempPtr;
            end_ = begin_ + oldSize;
            capacity_ = begin_ + newCapacity;
        }
        begin_[size()] = obj;
        ++end_;
    };  // push_back function
};
template <>
class vector<bool> {
    u_int64_t* begin_ = nullptr;
    u_int64_t* end_ = nullptr;
    u_int64_t* capacity_ = nullptr;
    u_int64_t acctualSize_ = 0;

public:
    class reference {
        friend class vector<bool>;
        u_int64_t* referencePtr_ = nullptr;
        size_t bitIndex_ = 0;
        reference(u_int64_t* referencePtr, size_t bitIndex)
            : referencePtr_(referencePtr), bitIndex_(bitIndex) {}

    public:
        reference& operator=(bool obj) {
            if (obj) {
                *referencePtr_ |= (1 << bitIndex_);
            } else {
                *referencePtr_ &= ~(1 << bitIndex_);
            }
            return *this;
        }
        operator bool() const {
            return ((*referencePtr_ >> bitIndex_) & 1) != 0;
        }
    };
    vector()
        : begin_(new u_int64_t[0]{}), end_(begin_), capacity_(begin_), acctualSize_(0){};
    vector(bool obj)
        : begin_(new u_int64_t[1]{}), end_(begin_ + 1), capacity_(begin_ + 1) {
        *begin_ = obj;
        ++acctualSize_;
    }
    vector(const vector& obj)
        : begin_(new u_int64_t[obj.size()]{}), end_(begin_ + 1), capacity_(begin_ + 1), acctualSize_(obj.acctualSize_) {
        for (size_t i = 0; i < obj.size(); ++i) {
            begin_[i] = obj.begin_[i];
        }
    };
    vector(vector&& obj)
        : begin_(obj.begin_), end_(obj.end_), capacity_(obj.capacity_), acctualSize_(obj.acctualSize_) {
        obj.begin_ = nullptr;
    };
    vector& operator=(const vector& obj) {
        if (this != &obj) {
            delete[] begin_;
            begin_ = new u_int64_t[obj.size()]{};
            for (size_t i = 0; i < obj.size(); ++i) {
                begin_[i] = obj.begin_[i];
            }
            end_ = begin_ + 1;
            capacity_ = begin_ + capacity();
            acctualSize_ = obj.acctualSize_;
        }
        return *this;
    };
    vector& operator=(vector&& obj) {
        if (this != &obj) {
            delete[] begin_;
            begin_ = obj.begin_;
            end_ = obj.end_;
            capacity_ = obj.capacity_;
            acctualSize_ = obj.acctualSize_;
            obj.begin_ = nullptr;
        }
        return *this;
    };
    ~vector() {
        delete[] begin_;
    };
    void push_back(bool obj) {
        if (acctualSize_ == capacity() * SIZE_OF_MEMORY) {
            auto tempPtr = new u_int64_t[capacity() * 2]{};
            for (size_t i = 0; i < acctualSize_ / SIZE_OF_MEMORY; ++i) {
                tempPtr[i] = begin_[i];
            }
            delete[] begin_;
            begin_ = tempPtr;
        }
        if (obj) {
            begin_[acctualSize_ / SIZE_OF_MEMORY] = begin_[acctualSize_ / SIZE_OF_MEMORY] << 1;
            begin_[acctualSize_ / SIZE_OF_MEMORY] |= (1 << 0);
        }
        acctualSize_++;
    };
    size_t size() const {
        return acctualSize_;
    }
    size_t capacity() const {
        return (capacity_ - begin_);
    }
    reference operator[](const size_t& index) {
        return reference(&begin_[index / SIZE_OF_MEMORY], index % SIZE_OF_MEMORY);
    };
    reference at(const size_t& index) {
        if (index < acctualSize_) {
            return reference(&begin_[index / SIZE_OF_MEMORY], index % SIZE_OF_MEMORY);
        }
        throw std::out_of_range("Index out of range");
    };
    reference front() {
        return reference(&begin_[0], 0);
    };
    reference back() {
        return reference(&begin_[acctualSize_ - 1], (acctualSize_ % SIZE_OF_MEMORY) - 1);
    };
};
}  // namespace my
