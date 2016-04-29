#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <iostream>
#include "helpers.h"

long int file_size(std::ifstream &f) {
    long int s = 0;
    f.seekg(0, std::ios_base::end);
    s = f.tellg();
    return s;
}

std::vector<std::string> read_data (std::ifstream &f) {
    std::string word;
    std::vector<std::string> words;
    while (f >> word) {
        words.push_back(word);
        if (f.peek()=='\n') {
            words.push_back("\n");
        }
    }
    return words;
}

void get_chunks(long int fsize, int nthreads, long int *chunks) {
    long int surplus = fsize % nthreads;
    long int chunk_size = (fsize - surplus) / nthreads;
    chunks[0] = 0;
    for (int i=1; i<=nthreads; i++) {
        chunks[i] = chunk_size * i;
    }
    chunks[nthreads] = chunks[nthreads] + surplus;
}

args parse_args(int argc, char **argv) {
    args a;
    a.nthreads = NUM_THREADS;
    a.order = ORDER;
    a.fname = DATA_FILE;
    a.length = LENGTH;
    for (int i=1; i<argc; i++) {
        std::string arg(argv[i]);
        if (arg=="-n") {
            a.nthreads = std::stoi(argv[i+1]);
        } else if (arg=="-o") {
            a.order = std::stoi(argv[i+1]);
        } else if (arg=="-f") {
            a.fname = std::string(argv[i+1]);
        } else if (arg=="-l") {
            a.length = std::stoi(argv[i+1]);
        }
    }
    return a;
}
