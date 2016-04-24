#ifndef MARKOV_H
#define MARKOV_H

struct corpus {
    std::string suffix;
    float freq;
};

extern std::map<std::string, corpus> chain;

void *generate_chain(void *parameters);

#endif
