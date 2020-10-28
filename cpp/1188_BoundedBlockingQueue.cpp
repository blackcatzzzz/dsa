#include<pthread.h>

class BoundedBlockingQueue {
private:
    pthread_mutex_t mutex;
    pthread_cond_t de_cond;
    pthread_cond_t en_cond;
    int cap;
    queue<int> q;    
public:
    BoundedBlockingQueue(int capacity) {
        int cap=capacity;
        pthread_cond_init(& de_cond,0);
        pthread_cond_init(&en_cond,0);
        pthread_mutex_init(& mutex,0);
    }
    
    void enqueue(int element) {
        pthread_mutex_lock(&mutex);//使用互斥量和条件变量配合，需要先对互斥量加锁
        while(q.size()==cap){//注意将wait函数放入到while循环中，避免惊群现象
            pthread_cond_wait(&en_cond,&mutex);
        }
        q.push(element);
        pthread_cond_signal(&de_cond);//此时队列中有元素，故可以给入队的信号量发信号，解除阻塞
        pthread_mutex_unlock(&mutex);//解锁互斥量
    }
    
    int dequeue() {
        pthread_mutex_lock(& mutex);
        while(q.empty()){//避免惊群现象
            pthread_cond_wait(&de_cond,& mutex);
        }
        int tmp=q.front();
        q.pop();
        pthread_cond_signal(&en_cond);//此时队列中有空间存在，可以给出队的信号量发信号，解除阻塞
        pthread_mutex_unlock(& mutex);//解除信号量
        return tmp;
    }
    
    int size() {
        return q.size();
    }
};