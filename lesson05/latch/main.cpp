#include <pthread.h>
#include <iostream>

class Latch {
public:
    explicit Latch(int N) {
        // your code here
    }

    ~Latch() {
        // your code here
    }

    void wait() {
        // your code here
    }

    void unlock(int n) {
        // your code here
    }

private:
    // your code here
};

void* get_stuck(void* latch_void) {
    auto *latch = static_cast<Latch*>(latch_void);
    std::cout << "Help, i'm stuck!" << std::endl;
    latch->wait();
    std::cout << "Bye!" << std::endl;
    return nullptr;
}

void* unlatch(void* latch_void) {
    auto *latch = static_cast<Latch*>(latch_void);
    std::cout << "Unlatching a bit!" << std::endl;
    latch->unlock(5);
    return nullptr;
}

int main() {
    int n = 100, m = 20;
    pthread_t stucks[n];
    pthread_t unlockers[m];
    Latch latch(n);

    for (int i = 0; i < n; i++)
        pthread_create(&stucks[i], nullptr, get_stuck, &latch);
    for (int i = 0; i < m; i++)
        pthread_create(&unlockers[i], nullptr, unlatch, &latch);

    for (int i = 0; i < n; i++)
        pthread_join(stucks[i], nullptr);
    for (int i = 0; i < m; i++)
        pthread_join(unlockers[i], nullptr);

    return 0;
}
