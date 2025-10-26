#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* greet(void* arg) {
    char* name = (char*) arg;
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread; 
    printf("Fatima Bashir\n");
    printf("23-NTU-CS-1153\n");
    char* name = "Fatima Bashir";
    if (pthread_create(&thread, NULL, greet, name) != 0) {
        perror("Failed to create thread");
        return 1;
    }
    printf("Main thread: Waiting for greeting...\n");
    pthread_join(thread, NULL);
    printf("Main thread: Greeting completed!\n");
    return 0;
}
