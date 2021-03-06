#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <semaphore.h>
#include <chrono>
#include <thread>
#include <signal.h>
#include <sys/time.h>
#include <random>

using namespace std;

sem_t **sems;
bool terminate_checkpoint;
pthread_mutex_t output_mutex;
pthread_mutex_t terminate_mutex;
void run(int phil_num, int dinner_duration);
int phil_num;
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(0,100);

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
    timeval t0, t1, dt;
    gettimeofday(&t0, NULL);
    for (;;) {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        gettimeofday(&t1, NULL);
        timersub(&t1, &t0, &dt);
        if (dt.tv_sec * 1000 > arguments->time_to_eat) {
            pthread_exit(0);
        }
        int thinking_duration = static_cast<int>(dist6(rng));
        int fork1 = (arguments->phil_id + 1) % phil_num, fork2 = arguments->phil_id;
        if (fork1 > fork2) {
            swap(fork1,fork2);
        }
        pthread_mutex_lock(&output_mutex);
        cout << arguments->phil_id << " thinks " << thinking_duration << "ms\n";
        pthread_mutex_unlock(&output_mutex);
        this_thread::sleep_for(chrono::milliseconds(thinking_duration));
        pthread_mutex_lock(&output_mutex);
        cout << arguments->phil_id << " waiting for " << arguments->phil_id << " fork.\n";
        pthread_mutex_unlock(&output_mutex);
        sem_wait(sems[fork1]);
        pthread_mutex_lock(&output_mutex);
        cout << arguments->phil_id << " grabbed " << arguments->phil_id << " fork. Waiting for " << arguments->phil_id + 1 << " fork.\n";
        pthread_mutex_unlock(&output_mutex);
        sem_wait(sems[fork2]);
        pthread_mutex_lock(&output_mutex);
        cout << arguments->phil_id << " got both forks! Beginning eating immediately!\n";
        pthread_mutex_unlock(&output_mutex);
        sem_post(sems[fork1]);
        sem_post(sems[fork2]);
    }
}

    int main() {
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
            sem_init(sems[i], 0, 1);
        }
        auto **phil_array = new pthread_t*[phil_num];
        for (int i = 0; i < phil_num; ++i) {
            phil_array[i] = new pthread_t;
            pthread_create(phil_array[i], NULL, &eat_think_repeat, (new args(dinner_duration * 1000, i)));
        }
        this_thread::sleep_for(chrono::milliseconds(dinner_duration * 1000));
        for (int i = 0; i < phil_num; ++i) {
            pthread_join(*phil_array[i], NULL);
        }
        cout << "All philosophers stopped eating.\n";
    }


