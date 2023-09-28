#ifndef TRAINER_HPP
#define TRAINER_HPP
#include "profemon.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Trainer {
protected:
    vector <Profemon> profedex;
    Profemon team[3];
    Profemon *currentProfemon;

public:

Trainer();

Trainer(vector <Profemon> profemons);

bool contains(string name);

bool addProfemon(Profemon profemon);

bool removeProfemon(string name);

void setTeamMember(int slot, string name);

bool chooseProfemon(int slot);

Profemon getCurrent();

void printProfedex();

void printTeam();
    
};

#endif
