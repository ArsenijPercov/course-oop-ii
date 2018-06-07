#include <bits/stdc++.h>
using namespace std;

template<class T>
class QueueItem{
public: 
    T data;
    QueueItem *next;
    QueueItem *prev;
    QueueItem(){
        next = prev = NULL;
    }
};

template<class T>
class Queue {
private:
    QueueItem<T> *front;
    QueueItem<T> *back;
public:
    Queue(){
        front = back = NULL;
    }
    ~Queue(){
        while(!is_empty()){
            cout << this->remove(0) << endl;
        }
        front = back = NULL;
    }
    T remove(int pos){
        QueueItem<T> *curr = front;
        while(curr != NULL && pos--) curr = curr->next;
        T ret;
        if(curr == NULL){
            return ret;
        }
        if(curr == front){
            QueueItem<T> *tmp = curr;
            front = front->next;
            ret = tmp->data;
            delete tmp;
        } else if(curr == back){
            curr->prev->next = NULL;
            ret = curr->data;
            delete curr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            ret = curr->data;
            delete curr;
        }
        return ret;
    }
    void add (const T& el){
        if(front == NULL){
            front = new QueueItem<T>();
            front->data = el;
            back = front;
            return;
        }
        back->next = new QueueItem<T>();
        back->next->data = el;
        back->next->prev = back;
        back = back->next;
        return;
    }
    bool is_empty() const {
        return front == NULL;
    }
};

int main(){

    Queue<int> q;
    for(int i = 1; i <= 10; i++){
        q.add(i);
    }

    return 0;
}