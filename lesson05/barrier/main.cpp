#include <pthread.h>
#include <iostream>

class Barrier {
public:
    explicit Barrier(int N) : N(N) {
        pthread_mutex_init(&mutex, nullptr);
        pthread_cond_init(&cond, nullptr);
    }

    ~Barrier() {
        pthread_cond_destroy(&cond);
        pthread_mutex_destroy(&mutex);
    }

    void wait() {
        pthread_mutex_lock(&mutex);
        if (N == 0) {
            return;
        }
        if (--N) {
            pthread_cond_wait(&cond, &mutex);
        } else {
            pthread_cond_broadcast(&cond);
        }
        pthread_mutex_unlock(&mutex);
    }

private:
    int N = 0;
    pthread_mutex_t mutex{};
    pthread_cond_t cond{};
};

void* get_stuck(void* barrier_void) {
    auto *barrier = static_cast<Barrier*>(barrier_void);
    std::cout << "Hey there!" << std::endl;
    barrier->wait();
    std::cout << "Bye!" << std::endl;
    return nullptr;
}

int main() {
    int n = 100;
    pthread_t threads[n];
    Barrier barrier(n);

    for (int i = 0; i < n; i++)
        pthread_create(&threads[i], nullptr, get_stuck, &barrier);
    for (int i = 0; i < n; i++)
        pthread_join(threads[i], nullptr);

    return 0;
}
