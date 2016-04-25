#ifndef MARKOV_H
#define MARKOV_H

extern std::map<std::string, std::multiset<std::string>> chain;
extern std::vector<std::string> words;

void *generate_chain(void *parameters);
void random_walk(int length, int order);

#endif
