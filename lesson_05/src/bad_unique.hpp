#pragma once

template<typename T>
class UniqueBadPtr
{
public:

    UniqueBadPtr():ptr_(nullptr){}
    UniqueBadPtr(UniqueBadPtr&& r):ptr_(nullptr){this->reset(r.relese());}

    ~UniqueBadPtr(){if(ptr_) delete ptr_;}

    T* relese(){
        T* tmp_ptr = ptr_;
        ptr_ = nullptr;
        return tmp_ptr;
    }

    T* get(){return ptr_;}

    void reset(T* nptr){
        if(ptr_) delete ptr_;
        ptr_ = nptr;
    }

    UniqueBadPtr& operator=( const UniqueBadPtr& ) = delete;
    UniqueBadPtr& operator=( UniqueBadPtr&& r ){
        this->reset(r.relese());
        return *this;
    }

private:
    T* ptr_;

};

template<typename T>
UniqueBadPtr<T> make_badUnique(T* ptr){
    UniqueBadPtr<T> ans;
    ans.reset(ptr);
    return ans;
}
