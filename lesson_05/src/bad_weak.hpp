#pragma once

#include "bad_shared.hpp"

template <typename T>
class WeakBadPtr
{
public:
    WeakBadPtr(): ptr_(nullptr), counter_(nullptr){}
    WeakBadPtr(SharedBadPtr<T> bad_ptr): ptr_(nullptr), counter_(nullptr){
        if (bad_ptr.get() == nullptr) return;
        ptr_ = bad_ptr.get();
        counter_ = bad_ptr.count_ref();
        counter_->weakCounter++;
    }
    WeakBadPtr( WeakBadPtr& r):ptr_{nullptr}, counter_{nullptr}{
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->weakCounter++;
        }
    }
    

    WeakBadPtr& operator=( WeakBadPtr& r ) 
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->weakCounter+= 1;
        }
        return *this;
    }
    WeakBadPtr& operator=( SharedBadPtr<T>& r ) 
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->weakCounter+= 1;
        }
        return *this;
    }

    ~WeakBadPtr(){reset();}


    bool valid(){
        if(counter_ == nullptr) return false;
        if(counter_->sharedCounter == 0) return false;
        return true;
    }

    T* get(){return ptr_;}

    badCounter count(){return *counter_;}
    badCounter* count_ref(){return counter_;}

    void reset(){
        if(!(ptr_)) return;
        counter_->weakCounter--;
        if ((counter_->weakCounter == 0)&&(counter_->sharedCounter == 0)) delete counter_;
        ptr_ = nullptr;
        counter_ = nullptr;
    }
private:
    T* ptr_;
    badCounter* counter_;
};