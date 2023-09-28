/*
Author: Saim Imran
Course: CSCI-135
Instructor: Maryash
Assignment: PROJECT 3B
*/

#include "department.hpp"
using namespace std;

MLDepartment::MLDepartment(vector<Profemon> profemons) //ML
{
    for (int i = 0; i < profemons.size(); i++) 
    {
        if (profemons[i].getSpecialty() == ML)
        {
            MLDepartment::addProfemon(profemons[i]);
        }
                
    }
}

bool MLDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() != ML)
    {
        return false;
    }

    Trainer::addProfemon(profemon);
    return true;
}

SoftwareDepartment::SoftwareDepartment(vector<Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++) 
    {
        if (profemons[i].getSpecialty() == SOFTWARE)
        {
            SoftwareDepartment::addProfemon(profemons[i]);
        }
        
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon) //BOOL
{
    if (profemon.getSpecialty() != SOFTWARE)
    {
        return false;
    }

    Trainer::addProfemon(profemon);
    return true;
    
}

HardwareDepartment::HardwareDepartment(vector<Profemon> profemons) //HARDWARE
{
    for (int i = 0; i < profemons.size(); i++) 
    {
        if (profemons[i].getSpecialty() == HARDWARE)
        {
            HardwareDepartment::addProfemon(profemons[i]);
        }
        
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() != HARDWARE)
    {
        return false;
    }

    Trainer::addProfemon(profemon);
    return true;
}