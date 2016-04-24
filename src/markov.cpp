#include <string>
#include <map>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <fstream>
#include <cctype>
#include "helpers.h"
#include "markov.h"

void *generate_chain(void *parameters) {
    params *p;
    p = (params *) parameters;


    pthread_mutex_lock(p->lock);
    std::cout << "Thread id: " << p->index << " " << "\n";
    pthread_mutex_unlock(p->lock);
    return 0;
}
