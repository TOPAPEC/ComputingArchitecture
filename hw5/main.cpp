#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <semaphore.h>
#include <chrono>
#include <thread>
#include <signal.h>

using namespace std;

sem_t **sems;
bool terminate_checkpoint;
pthread_mutex_t output_mutex;
pthread_mutex_t terminate_mutex;
void run(int phil_num, int dinner_duration);

struct args {
    args(int ttl, int id) {
        time_to_eat = ttl;
        phil_id = id;
    }
    int time_to_eat;
    int phil_id;
};
// Arg - philosopher id.
void *eat_think_repeat(void *arg) {
    args *arguments = ((struct args *) (arg));
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    try {
        for (;;) {
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() > arguments->time_to_eat) {
                pthread_exit(0);
            }
            int thinking_duration = rand() % 100 + 1;
//            pthread_mutex_lock(&output_mutex);
//            cout << phil_id << " thinks " << thinking_duration << "ms\n";
//            pthread_mutex_unlock(&output_mutex);
            this_thread::sleep_for(chrono::milliseconds(thinking_duration));
//            cout << phil_id << " waiting for " << phil_id << " fork.\n";
            sem_wait(sems[arguments->phil_id]);
//            pthread_mutex_lock(&output_mutex);
//            cout << phil_id << " grabbed " << phil_id << " fork. Waiting for " << phil_id + 1 << " fork.\n";
//            pthread_mutex_unlock(&output_mutex);
            sem_wait(sems[arguments->phil_id + 1]);
//            pthread_mutex_lock(&output_mutex);
//            cout << phil_id << " got both forks! Beginning eating immediately!\n";
//            pthread_mutex_unlock(&output_mutex);
            sem_post(sems[arguments->phil_id]);
            sem_post(sems[arguments->phil_id + 1]);
        }
    }
    catch (exception ex) {
//        pthread_mutex_lock(&output_mutex);
//        cout << to_string(phil_id) + " posted segabort\n";
//        pthread_mutex_unlock(&output_mutex);
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
        sems = new sem_t*[phil_num];
        run(phil_num, dinner_duration);
        cout << "Dinner is over!\n";
        return 0;
    }
    void run(int phil_num, int dinner_duration) {
        for (int i = 0; i < phil_num; ++i) {
            sems[i] = new sem_t;
            sem_init(sems[i], 1, 1);
        }
        auto **phil_array = new pthread_t*[phil_num];
        for (int i = 0; i < phil_num; ++i) {
//            pthread_mutex_lock(&output_mutex);
//            cout << "New thread " + to_string(i) + "\n";
//            pthread_mutex_unlock(&output_mutex);
            phil_array[i] = new pthread_t;
            pthread_create(phil_array[i], NULL, &eat_think_repeat, (new args(dinner_duration * 1000, i)));
        }
        this_thread::sleep_for(chrono::milliseconds(dinner_duration * 1000));
//        pthread_mutex_lock(&terminate_mutex);
        terminate_checkpoint = true;
//        pthread_mutex_unlock(&terminate_mutex);
        try {
            for (int i = 0; i < phil_num; ++i) {
                pthread_join(*phil_array[i], NULL);
            }
        } catch (exception ex) {
//            pthread_mutex_lock(&output_mutex);
            cout << "loop segabort\n";
//            pthread_mutex_unlock(&output_mutex);
        }
        cout << "All philosophers stopped eating.\n";
    }


