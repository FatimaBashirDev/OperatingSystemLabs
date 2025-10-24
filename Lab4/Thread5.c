#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* calculate_sum(void* arg) {
    int n = *(int*)arg;
    int* result = malloc(sizeof(int));  // Allocate memory for result

    *result = 0;
    for (int i = 1; i <= n; i++) {
        *result += i;
    }

    printf("Thread calculated sum of 1 to %d is %d\n", n, *result);
    return (void*)result;  // Return the result
}

int main() {
    pthread_t thread_id;
    int n = 100;
    void* sum;

    // Create the thread
    pthread_create(&thread_id, NULL, calculate_sum, &n);

    // Wait for thread to finish and collect the result
    pthread_join(thread_id, &sum);

    // Corrected print message
    printf("Main received result: %d\n", *(int*)sum);

    free(sum);  // Free allocated memory
    return 0;
}
