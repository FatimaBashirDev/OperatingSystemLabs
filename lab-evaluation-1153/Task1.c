// Write a C program that simulates a bank account with multiple transactions:
// 1.   Create a shared global variable
// 2.  Create 4 threads:
//   Thread 1: Deposits 1000 (repeat 5 times)
//  Thread 2: Withdraws 500 (repeat 5 times)
//   Thread 3: Deposits 800 (repeat 5 times)
//   Thread 4: Withdraws 300 (repeat 5 times)
// 3.  Use mutex to protect balance updates
// 4.  Each thread should print after each transaction:   Thread ID
//   Operation (Deposit/Withdraw)   Amount
// initialized to 5000
//   New balance
// 5.  Main thread prints final balance

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int balance = 5000;
pthread_mutex_t lock;
void* deposit(void* arg) {
  int amount = *(int*)arg;
for (int i = 0; i < 5; i++) {
 pthread_mutex_lock(&lock);
  balance += amount;
    printf("Thread %lu | Deposit: %d | New Balance: %d\n", pthread_self(), amount, balance);
    }
  pthread_mutex_unlock(&lock);  
   usleep(100000); 
    return NULL;
}
