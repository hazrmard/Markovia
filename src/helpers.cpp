#include <stdio.h>
#include <string>
#include "helpers.h"

long int fsize(FILE *f) {
    long int prev_pos = ftell(f);
    fseek(f, 0L, SEEK_END);
    long int s = ftell(f);
    fseek(f, prev_pos, SEEK_SET);
    return s;
}

void find_next_starting_point(FILE *f, long int offset) {

}

args parse_args(int argc, char **argv) {
    args a;
    int i;
    for (i=1; i<argc; i++) {
        std::string arg(argv[i]);
        if (arg=="-n") {
            a.nthreads = std::stoi(argv[i+1]);
        } else if (arg=="-o") {
            a.order = std::stoi(argv[i+1]);
        }
    }
    return a;
}
