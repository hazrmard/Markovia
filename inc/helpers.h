#ifndef HELPERS_H
#define HELPERS_H

struct args {
    int nthreads;
    int order;
    std::string fname;
};

long int fsize(FILE *f);
args parse_args(int argc, char **argv);

#endif
