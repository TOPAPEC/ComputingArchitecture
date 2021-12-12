#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <semaphore.h>
#include <chrono>
#include <thread>
#include <signal.h>

using namespace std;

sem_t *sems;
bool terminate_checkpoint;
pthread_mutex_t output_mutex;
pthread_mutex_t terminate_mutex;
void run(int phil_num, int dinner_duration);

// Arg - philosopher id.
void *eat_think_repeat(void *arg) {
    int phil_id = *(int *) (arg);
    for (;;) {
        if (terminate_checkpoint) {
            return NULL;
        }
        int thinking_duration = rand() % 100 + 1;
        pthread_mutex_lock(&output_mutex);
        cout << phil_id << " thinks " << thinking_duration << "ms\n";
        cout << phil_id << " waiting for " << phil_id << " fork.\n";
        pthread_mutex_unlock(&output_mutex);
        sem_wait(&sems[phil_id]);
        pthread_mutex_lock(&output_mutex);
        cout << phil_id << " grabbed " << phil_id << " fork. Waiting for " << phil_id + 1 << " fork.\n";
        pthread_mutex_unlock(&output_mutex);
        sem_wait(&sems[phil_id + 1]);
        pthread_mutex_lock(&output_mutex);
        cout << phil_id << " got both forks! Beginning eating immediately!\n";
        pthread_mutex_unlock(&output_mutex);
        sem_post(&sems[phil_id]);
        sem_post(&sems[phil_id + 1]);
    }
}

    int main() {
        int phil_num;
        int dinner_duration;
        terminate_checkpoint = false;
        cout << "Enter philosopher number:";
        cin >> phil_num;
        cout << "Now duration of dinner in seconds:";
        cin >> dinner_duration;
        pthread_mutex_init(&output_mutex, NULL);
        pthread_mutex_init(&terminate_mutex, NULL);
        sems = new sem_t[phil_num];
        run(phil_num, dinner_duration);
        cout << "Dinner is over!\n";

    }
    void run(int phil_num, int dinner_duration) {
        for (int i = 0; i < phil_num; ++i) {
            sem_init(&sems[i], 1, 1);
        }
        auto *phil_array = new pthread_t[phil_num];
        for (int i = 0; i < phil_num; ++i) {
            pthread_create(&phil_array[i], NULL, &eat_think_repeat, &i);
        }
        this_thread::sleep_for(chrono::milliseconds(dinner_duration * 1000));
        pthread_mutex_lock(&terminate_mutex);
        terminate_checkpoint = true;
        pthread_mutex_unlock(&terminate_mutex);
        for (int i = 0; i < phil_num; ++i) {
            pthread_join(phil_array[i], NULL);
        }
        cout << "All philosophers stopped eating.\n";
    }


