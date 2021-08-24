#pragma once

#include<iostream>

template<class T>
class SharedPtr
{
    T* sharedPtr;
    int* refCount;

public:
    SharedPtr(T* ptr)
    {
        sharedPtr = ptr;
        refCount = new int(1);
    }
    ~SharedPtr()
    {
        --(*refCount);
        if (*refCount == 0)
        {
            delete sharedPtr;
            delete refCount;
        }
    }

    T* operator->() { return sharedPtr; }
    const T* operator->() const { return sharedPtr; }
    T& operator*() { return *sharedPtr; }
    const T& operator*() const { return *sharedPtr; }

    SharedPtr<T>& operator=(const SharedPtr<T>& ptr);
    SharedPtr(const SharedPtr<T>& ptr);
};

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr)
{
    if (this != &ptr)
    {
        --*(this->refCount);
        if (*(this->refCount) == 0)
        {
            delete (this->sharedPtr);
            delete (this->refCount);
        }


        this->sharedPtr = ptr.sharedPtr;
        this->refCount = ptr.refCount;
        ++(*(ptr.refCount));
    }

    return *this;
}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& ptr)
{
    this->sharedPtr = ptr.sharedPtr;
    this->refCount = ptr.refCount;
    ++(*(ptr.refCount));
}

