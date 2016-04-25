#include <stdio.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "helpers.h"
#include "markov.h"

using namespace std;

map<string, std::set<std::string>> chain;
vector<string> words;
pthread_mutex_t lock;

int main(int argc, char **argv) {
    args a = parse_args(argc, argv);
    cout << "Num threads: " << a.nthreads << "\n";
    cout << "Order: " << a.order << "\n";
    cout << "File name: " << a.fname << "\n";

    //vector<string> words;
    ifstream file;
    file.open(a.fname, ifstream::in);
    words = read_data(file);
    file.close();

    long int chunks[a.nthreads+1];
    get_chunks(words.size(), a.nthreads, chunks);
    pthread_t threads[a.nthreads];
    pthread_mutex_init(&lock, NULL);
    params p[a.nthreads];

    // for (vector<string>::iterator i=words.begin(); i<words.end(); i++) {
    //     cout << *i << " ";
    // }
    // cout << "\n";

    for (int i=0; i<a.nthreads; i++) {
        p[i].index = i;
        p[i].start = chunks[i];
        p[i].end = chunks[i+1];
        p[i].order = a.order;
        p[i].lock = &lock;
        pthread_create(&threads[i], NULL, generate_chain, (void *) &p[i]);
    }
    for (int i=0; i<a.nthreads; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);

    

    return 0;
}
