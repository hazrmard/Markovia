#ifndef HELPERS_H
#define HELPERS_H

#define NUM_THREADS 1
#define ORDER 3
#define DATA_FILE "sample.txt"
#define LENGTH 20

struct args {
    int nthreads;
    int order;
    int length;
    std::string fname;
};

struct params {
    int index;
    long int start;
    long int end;
    int order;
    pthread_mutex_t *lock;
};

args parse_args(int argc, char **argv);
void get_chunks(long int fsize, int nthreads, long int *chunks);
long int file_size(std::ifstream &f);
std::vector<std::string> read_data (std::ifstream &f);

#endif
