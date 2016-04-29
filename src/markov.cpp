#include <string>
#include <map>
#include <set>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <fstream>
#include <time.h>
#include "helpers.h"
#include "markov.h"

std::string STOP_CHARS = ".\n";

void *generate_chain(void *parameters) {
    params *p;
    p = (params *) parameters;
    std::map<std::string, std::multiset<std::string>> localchain;
    std::string key;
    std::string suffix;
    for (std::vector<std::string>::iterator i=words.begin()+p->start; i<words.begin()+p->end; i++) {
        key = *i;
        for (std::vector<std::string>::iterator j=i+1; j<i+p->order; j++) {
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


void random_walk(int length, int order) {
    int count = order;
    std::string suffix = "";
    std::string prefix;
    std::srand(time(0));
    auto i = chain.begin();
    std::advance(i, rand() % chain.size());
    prefix = i->first;
    std::cout << prefix << " ";
    while (count < length || STOP_CHARS.find(suffix.back())==std::string::npos) {

        auto j = (i->second).begin();
        std::advance(j, rand() % (i->second).size());
        suffix = *j;
        std::cout << suffix << " ";
        count ++;

        std::string::size_type n = 0;
        n = prefix.find_first_not_of( " \t", n );
        n = prefix.find_first_of( " \t", n );
        prefix.erase( 0,  prefix.find_first_not_of( " \t", n ) );
        prefix = prefix + " " + suffix;

        i = chain.find(prefix);
        if (i==chain.end()) {
            i = chain.begin();
            std::advance(i, rand() % chain.size());
        }
    }
}

void print_chain() {
    std::cout << "Prefix\t\tSuffix\n";
    for (auto i= chain.begin(); i!=chain.end(); i++) {
        std::cout << i->first << ":\t";
        for (auto j=(i->second).begin(); j!=(i->second).end(); j++) {
            std::cout << *j << ", ";
        }
        std::cout << "\n";
    }
}
