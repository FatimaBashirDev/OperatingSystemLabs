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
int balance=5000;
pthread_mutex_t lock;
//deposit function to deposit amount
void* deposit(void* arg){
  int amount=*(int*)arg;
  for(int i=0;i<5;i++){
    //frst we we lock the thread to avoide race condition
    pthread_mutex_lock(&lock);
    balance+=amount;
    printf("Thread %lu| Deposit: %d| New Balance: %d\n", pthread_self(),
      amount,balance);
      //i will unlock the thread
      pthread_mutex_unlock(&lock);
      // thread will sleep for 0.1s
      usleep(100000);
  }
  return NULL;
}

void* withdraw(void* arg){
  int amount=*(int*)arg;
  for(int i=0;i<5;i++){
    pthread_mutex_lock(&lock);
    if(balance>=amount){
      balance-=amount;
      printf("Thread %lu | withdraw:%d | New Balance: %d\n) \n",pthread_self(),amount,balance);
    }
    pthread_mutex_unlock(&lock);
    usleep(10000);
  }
  return NULL;
}
int main(){
  // amounts for threads
  pthread_t t1,t2,t3,t4;
  int dep1=1000, dep2=800;
  int wd1=500, wd2=300;
  pthread_mutex_init(&lock,NULL);
  printf("iniliaze Balance: %d\n\n",balance);
// i created 4 threads
  pthread_create(&t1,NULL,deposit,&dep1);
  pthread_create(&t2,NULL,withdraw,&wd1);
  pthread_create(&t3,NULL,deposit,&dep2);
  pthread_create(&t4,NULL,withdraw,&wd2);
// it will wait for thread to finish
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  pthread_join(t4,NULL);
  
  pthread_mutex_destroy(&lock);

  printf("\n Balance:%d\n",balance);
  return 0;
}
