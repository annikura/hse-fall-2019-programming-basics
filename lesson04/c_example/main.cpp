#include <pthread.h>
#include <stdio.h>

int data = 0;

void *inc_data(void *args) {
  data++;
  return nullptr;
}

int main() {
  pthread_t thread1, thread2;
  pthread_create(&thread1, nullptr, inc_data, nullptr);

  pthread_create(&thread2, nullptr, inc_data, nullptr);
  pthread_join(thread1, nullptr);
  pthread_join(thread2, nullptr);

  printf("%d", data);

  return 0;
}
