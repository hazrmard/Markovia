#ifndef MARKOV_H
#define MARKOV_H

extern std::string STOP_CHARS;
extern std::map<std::string, std::multiset<std::string>> chain;
extern std::vector<std::string> words;

void *generate_chain(void *parameters);
void random_walk(int length, int order);
void print_chain();

#endif
