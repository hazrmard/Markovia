#include <string>
#include <map>
#include <set>
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
    std::map<std::string, std::set<std::string>> localchain;
    std::string key;
    std::string suffix;
    for (std::vector<std::string>::iterator i=words.begin()+p->start; i<words.begin()+p->end; i++) {
        for (std::vector<std::string>::iterator j=i; j<i+p->order; j++) {
            key = key + " " + *j;
        }
        suffix = *(i+p->order);
        localchain[key].insert(suffix);

    }

    pthread_mutex_lock(p->lock);
    for (auto i=localchain.begin(); i!=localchain.end(); i++) {
        chain[i->first].insert(i->second.begin(), i->second.end());
    }
    pthread_mutex_unlock(p->lock);
    return 0;
}


void random_walk(long int length) {

}
