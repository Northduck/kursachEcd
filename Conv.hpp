//
//  Conv.hpp
//  Kursach
//
//  Created by администратор on 10.11.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#ifndef Conv_hpp
#define Conv_hpp

#include <stdio.h>
#include <iostream>
#include "Comm.hpp"
class Conveyor {
private:
    int totCommands;
    int appealTact;
    int calcTact;
    int *executionTime;
    Commands *commFlow;
    int stages[5];
    int currCommand;
    int nextStage;
public:
    Conveyor(int Commands, int P1, int P2, int Appeal, int Calc);
    
    ~Conveyor();
    
    void execution();
    
    void printExecution(int curComm);
    
    void parallelExec();
    
    void checkStages();
    
    bool checkStagesStatus();
    
    void printConv();
    
    bool checkConv();
};

#endif /* Conv_hpp */
