#include <stdio.h>
#include <pthread.h>

// Thread function to calculate double of CGPA
void* calculate_double(void* arg) {
    float cgpa = *(float*)arg;  // Cast void* back to float*
    printf("Thread received CGPA: %.2f\n", cgpa);
    printf("Double of CGPA: %.2f\n", cgpa * 2);
    return NULL;
}

int main() {
    pthread_t thread_id;
    float cgpa = 3.37;

    printf("Creating thread with CGPA: %.2f\n", cgpa);

    // Pass address of 'cgpa' to thread
    pthread_create(&thread_id, NULL, calculate_double, &cgpa);
    pthread_join(thread_id, NULL);

    printf("Main thread done.\n");
    return 0;
}