/*
Author: Saim Imran
Course: CSCI-135
Instructor: Maryash
Assignment: PROJECT 3A
*/

#include "profemon.hpp"
#include "skill.hpp"
#include <iostream>

//CONSTRUCTERS
Profemon::Profemon() {
    this->name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this->name = name;
    this->max_health = max_health;
    this->specialty = specialty;
    this->max_experience = 50;
    this->level = 0;
}

//GETTER FUNCTIONS
std::string Profemon::getName() {
    return name;
}

Specialty Profemon::getSpecialty() {
    return specialty;
}

int Profemon::getLevel() {
    return level;
}

double Profemon::getMaxHealth() {
    return max_health;
}

//SETTER FUNCTIONS
void Profemon::setName(std::string name) {
    this->name = name;
}

//OTHER FUNCTIONS
void Profemon::levelUp(int exp) {
    curr_experience += exp;
    while (curr_experience >= max_experience) {
        switch (this->getSpecialty()) {
            case (ML):
                //increment level
                level++;
                //reduce curr_experience by the current max_experience
                curr_experience -= max_experience;
                //increase max_experience by 10
                max_experience += 10;
                //loop if needed
                break;
            case (SOFTWARE):
                //increment level
                level++;
                //reduce curr_experinece by current max_experience
                curr_experience -= max_experience;
                //increase max_experience by 15
                max_experience += 15;
                //loop if needed
                break;
            case (HARDWARE):
                //increment level
                level++;
                //reduce curr_experience by current max_experience
                curr_experience -= max_experience;
                //increase max_experience by 20
                max_experience += 20;
                //loop if needed
                break;
        }
    }
    //end
    return;
}

bool Profemon::learnSkill(int slot, Skill skill) {
    //if in range [0,2] and skill specialty and prof specialty are equal
    if (2 >= slot && slot >= 0 && skill.getSpecialty() == this->getSpecialty()) {
        //ass the skill to the slot index
        skills[slot] = skill;
        //return true if skill got learned
        return true;
    } else {
        //return false if slot is out of range and specialty is not matching
        return false;
    }
    return false;
}

void Profemon::printProfemon(bool print_skills) {
    using namespace std;

    string thisSpecialty = "";
    switch (this->getSpecialty()) {
        case (ML):
            thisSpecialty = "ML";
            break;
        case (SOFTWARE):
            thisSpecialty = "SOFTWARE";
            break;
        case(HARDWARE):
            thisSpecialty = "HARDWARE";
            break;
    }

    cout << this->getName() << " [" << thisSpecialty << "] | lvl " << this->getLevel() << " | exp " << curr_experience << '/' << max_experience << " | hp " << this->getMaxHealth() << endl;
   
    if(print_skills) {
        for(Skill i : skills) {
            if (i.getName() != "Undefined"){
                cout << "    " << i.getName() << " [" << i.getTotalUses() << "] : " << i.getDescription() << endl;
            }
        }
    }
    return;
}