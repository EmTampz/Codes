/*you can save it as rw.c */
/*you can compile this using gcc -lpthread rw.c */
/*and then run it using ./a.out */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
/*
This program provides a possible solution for first readers writers problem using mutex and semaphore.
I have used 5 readers and 3 writers to demonstrate the solution.
*/
sem_t wrt; // A binary semaphore that will be used both for mutual exclusion and signalling
pthread_mutex_t mutex; // Provides mutual exclusion when readcount is being modified
int cnt = 1;
int numreader = 0;
void *writer(void *wno)
    {
        sem_wait(&wrt);
        cnt = cnt*2;
        printf("Writer %d modified cnt to %d\n",(*((int *)wno)),cnt);
        sem_post(&wrt);
    }
void *reader(void *rno)
{
    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
        if(numreader == 1) 
        {
        sem_wait(&wrt); // If this id the first reader, then it will block the writer
        }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    printf("Reader %d: read cnt as %d\n",*((int *)rno),cnt);
    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
        if(numreader == 0) 
        {
        sem_post(&wrt); // If this is the last reader, it will wake up the writer.
        }
    pthread_mutex_unlock(&mutex);
}

int main()
    {
    pthread_t read[5],write[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; //Just used for numbering the reader and writer
    for(int i = 0; i < 5; i++) 
    {
    pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }

    for(int i = 0; i < 3; i++) 
    {
    pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) 
    {
    pthread_join(read[i], NULL);
    }

    for(int i = 0; i < 3; i++) 
    {
    pthread_join(write[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}