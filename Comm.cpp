//
//  Comm.cpp
//  Kursach
//
//  Created by администратор on 15.11.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Comm.hpp"
Commands::Commands(){
    stage=-1;
}
Commands::Commands(int prob1, int prob2, int Appeal, int Calc){
    stage=-1;
    status=false;
    tactsForStage[0]=1;
    tactsForStage[1]=Random(prob1,Appeal);
    tactsForStage[2]=Random(prob1,Appeal);
    tactsForStage[3]=Random(prob2,Calc);
    tactsForStage[4]=tactsForStage[2];
    tactsIter=0;
}

int Commands::getStage(){return stage;}

int Commands::getTFS(int i){return tactsForStage[i];}

void Commands::nextStage(){
    if(stage<5){
        stage++;
    }
}

void Commands::setStatus(){status=true;}

bool Commands::getStatus(){return status;}

int Commands::getTime(){return tactsIter;}

Commands Commands::operator++(int)
{
    if(tactsForStage[stage]>0){
        tactsForStage[stage]--;
    }
    tactsIter++;
    return *this;
}

Commands Commands::operator++(){
    tactsIter++;
    return *this;
}
