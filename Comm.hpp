//
//  Comm.hpp
//  Kursach
//
//  Created by администратор on 15.11.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#ifndef Comm_hpp
#define Comm_hpp

#include <stdio.h>
#include "Random.hpp"
class Commands{
private:
    int stage=-1;
    bool status;
    int tactsForStage[5];
    int tactsIter;
public:
    Commands();
    
    Commands(int prob1, int prob2, int Appeal, int Calc);
    
    int getStage();
    
    int getTFS(int i);
    
    void nextStage();
    
    void setStatus();
    
    bool getStatus();
    
    int getTime();
    
    void setTactsForStage();
    
    Commands operator++();
    
    Commands operator++(int);
};
#endif /* Comm_hpp */
