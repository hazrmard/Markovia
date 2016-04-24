#include <stdio.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>
#include <vector>
#include "helpers.h"

using namespace std;

int main(int argc, char **argv) {
    printf("Hello. This is the main function\n");
    //pthread_t t1, t2;

    args a = parse_args(argc, argv);
    cout << "Num threads: " << a.nthreads << "\n";
    cout << "Order: " << a.order << "\n";
    cout << "File name: " << a.fname << "\n";

    FILE *f = fopen(a.fname.c_str(), "r");
    long int s = fsize(f);
    printf("Size is: %ld\n", s);
    fclose(f);

    cout <<"\nChunks:\n";
    long int chunks[a.nthreads+1];
    get_chunks(s, a.nthreads, chunks);
    ifstream file;
    file.open(a.fname, ifstream::in);
    char buff[chunks[a.nthreads]-chunks[a.nthreads-1]];
    int i;
    for (i=0; i<a.nthreads; i++) {
        cout << chunks[i] << "\n";
        file.seekg(chunks[i], ios_base::beg);
        file.read(buff, chunks[i+1]-chunks[i]-1);
        cout << buff << "\n";
    }
    file.close();

    return 0;
}
