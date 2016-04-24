#ifndef HELPERS_H
#define HELPERS_H

struct args {
    int nthreads;
    int order;
    std::string fname;
};

struct params {
    long int start;
    long int end;
    int order;
    std::string fname;
};

long int fsize(FILE *f);
args parse_args(int argc, char **argv);
void find_next_starting_point(FILE *f, long int offset);
void get_chunks(long int fsize, int nthreads, long int *chunks);

#endif
