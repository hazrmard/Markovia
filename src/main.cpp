#include <stdio.h>
#include <pthread.h>
#include <string>
#include "helpers.h"

using namespace std;

int main(int argc, char **argv) {
    printf("Hello. This is the main function\n");
    pthread_t t1, t2;
    FILE *f = fopen(".gitignore", "rb");
    long int s = fsize(f);
    printf("Size is: %ld\n", s);
    fclose(f);

    args a = parse_args(argc, argv);
    printf("Num threads: %d\n", a.nthreads);
    printf("Order: %d\n", a.order);

    return 0;
}
