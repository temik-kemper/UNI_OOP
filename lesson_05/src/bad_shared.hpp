#pragma once

struct badCounter
{
    int sharedCounter;
    int weakCounter;
};

template<typename T>
class SharedBadPtr
{
public:
    SharedBadPtr():ptr_{nullptr}, counter_{nullptr}{}
    SharedBadPtr(T* nptr):ptr_{nullptr}, counter_{nullptr}{reset(nptr);}
    SharedBadPtr( SharedBadPtr& r):ptr_{nullptr}, counter_{nullptr}{
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->sharedCounter+= 1;
        }
    }


    ~SharedBadPtr(){
        reset();
    }

    T* get(){return ptr_;}

    void reset(T* nptr){
        if(ptr_){
            if(counter_->sharedCounter == 1){
                delete ptr_;
                counter_->sharedCounter--;
                if(counter_->weakCounter == 0){
                    delete counter_;
                    counter_ = nullptr;
                }
            }else{
                counter_->sharedCounter--;
            }
        }
        if(nptr){
            ptr_ = nptr;
            counter_ = new badCounter{1, 0};
        }
    }

    void reset(){reset(nullptr);}

    //SharedBadPtr& operator=( SharedBadPtr&& r ) = delete;
    SharedBadPtr& operator=( SharedBadPtr& r ) 
    {
        reset();
        if(r.get()){
            ptr_ = r.get();
            counter_ = r.count_ref();
            counter_->sharedCounter+= 1;
        }
        return *this;
    }


    badCounter count(){return *counter_;}
    badCounter* count_ref(){return counter_;}


private:
    T* ptr_;
    badCounter* counter_;
};


template <typename T>
SharedBadPtr<T> make_badShared(T* ptr){
    return SharedBadPtr<T>(ptr);
}

