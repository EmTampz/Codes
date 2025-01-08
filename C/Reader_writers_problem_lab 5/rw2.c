#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t wrt; // Semaphore for controlling access to the resource
pthread_mutex_t mutex; // Mutex for mutual exclusion
int cnt = 1;
int numreader = 0;

void *writer(void *wno) 
{
    sem_wait(&wrt); // This lock resource for writing
    printf("\n", (*((int *)wno)));
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", (*((int *)wno)), cnt);
    sem_post(&wrt); // It unlocks resource
    }

void *reader(void *rno) 
{
    int readerNum = *((int *)rno);
    // Entry Section
    pthread_mutex_lock(&mutex);
    numreader++; // Increment  of teh number of readers
        if (numreader == 1) 
        {
            sem_wait(&wrt); // If first reader, lock the resource from writers
        }
    pthread_mutex_unlock(&mutex);

    // for te Reading Section
    printf("Reader %d: read cnt as %d\n", readerNum, cnt);

    // Exit Section
    pthread_mutex_lock(&mutex);
    numreader--; // Decrement number of readers
        if (numreader == 0) 
        {
            sem_post(&wrt); // If it is the last reader, release the resource lock for writers
        }
    pthread_mutex_unlock(&mutex);
}

int main() 
{
    pthread_t read[5], write[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array of the number readers and writers

    // Creating writer threads
    for (int i = 0; i < 3; i++) 
    {
        pthread_create(&write[i], NULL, writer, (void *)&a[i]);
        sleep(1); // to prioritize the creation of writer threads
    }

    // Creating reader threads
    for (int i = 0; i < 5; i++) 
    {
        pthread_create(&read[i], NULL, reader, (void *)&a[i]);
    }

    // Joining writer threads
    for (int i = 0; i < 3; i++)
    {
        pthread_join(write[i], NULL);
    }

    // Joining reader threads
    for (int i = 0; i < 5; i++) 
    {
        pthread_join(read[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
