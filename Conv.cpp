 //
//  Conv.cpp
//  Kursach
//
//  Created by администратор on 10.11.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Conv.hpp"
#include "Comm.hpp"
#include "Random.hpp"
#include <iostream>
using namespace std;
Conveyor::Conveyor(int Comm, int P1, int P2, int Appeal, int Calc): totCommands(Comm), appealTact(Appeal), calcTact(Calc){
    
    for(int i=0;i<5;++i){
        stages[i]=-1;
    }
    
    currCommand=-1;
    
    nextStage=0;
    
    executionTime=new int[totCommands];
    
    commFlow=new Commands[totCommands];
    for(int i=0;i<totCommands;++i){
        new (commFlow + i) Commands(P1, P2, Appeal, Calc);
    }
    execution();
    for(int i=0;i<totCommands;i++){
        cout<<executionTime[i]<<"  ";
    }
}

Conveyor::~Conveyor(){
    delete [] executionTime;
    delete [] commFlow;
}

void Conveyor::execution(){
    int i=0,j=0;
    if(currCommand==-1){
        currCommand++;
        commFlow[currCommand].nextStage();
        stages[commFlow[currCommand].getStage()]=currCommand;
        printConv();
        commFlow[currCommand]++;
    }
    printConv();
    while(!checkConv()){
        parallelExec();
        printConv();
        if(commFlow[currCommand].getTFS(4)==0){
            commFlow[currCommand].setStatus();
            executionTime[currCommand]=commFlow[currCommand].getTime();
            stages[4]=-1;
            currCommand++;
        }
    }
}

void Conveyor::parallelExec(){
    checkStages();
    if(commFlow[currCommand].getStage()!=3){
        for(int i=4;i>=0;--i){
            if(stages[i]!=-1){
                commFlow[stages[i]]++;
            }
        }
    }else{
        for(int i=0;i<5;++i){
            if(stages[i]!=-1){
                if(i==3){
                    commFlow[stages[i]]++;
                }else{
                    ++commFlow[stages[i]];
                }
            }
        }
    }
}

void Conveyor::checkStages(){
    int temp=commFlow[currCommand].getStage();
    int j=0,m=0;
    bool flag=checkStagesStatus();
    if(flag){
        if(temp!=2&&(temp!=3||stages[1]==-1)){
            if(commFlow[totCommands-1].getStage()>0){
                m=commFlow[totCommands-1].getStage();
            }
            for(int i=temp+1;i>=m;i--){
                if(j<=nextStage+1-currCommand){
                    commFlow[currCommand+j].nextStage();
                }
                if(i>=1){
                    stages[i]=stages[i-1];
                }else{
                    stages[i]=stages[i+1]+1;
                    nextStage=stages[i];
                }
                j++;
            }
            for(m=0;m<commFlow[totCommands-1].getStage();++m){
                stages[m]=-1;
            }
        }else{
            if(temp==2){
                commFlow[currCommand].nextStage();
                stages[temp+1]=currCommand;
                stages[temp]=-1;
            }else{
                commFlow[currCommand].nextStage();
                commFlow[stages[1]].nextStage();
                stages[2]=stages[1];
                stages[temp+1]=currCommand;
                stages[temp]=-1;
                stages[1]=-1;
            }
        }
        printConv();
    }
}

bool Conveyor::checkStagesStatus(){
    bool flag=true;
    for(int i=0;i<5;++i){
        if(commFlow[stages[i]].getTFS(i)!=0&&stages[i]!=-1){
            flag=false;
            break;
        }
    }
    return flag;
}
bool Conveyor::checkConv(){
    for(int i=0;i<totCommands;++i){
        if(!commFlow[i].getStatus()){
            return false;
        }
    }
    return true;
}
void Conveyor::printExecution(int curComm){
    for(int i=0;i<=curComm;++i){
        cout<<"i="<<i<<"  "<<executionTime[i]<<endl;
    }
}

void Conveyor::printConv(){
    for(int i=0;i<5;++i){
        if(stages[i]==-1){
            cout<<"stage "<<i<<" ("<<stages[i]<<" NaN NaN)"<<endl;
        }else{
             cout<<"stage "<<i<<" ("<<stages[i]<<" "<<commFlow[stages[i]].getTFS(i)<<" "<<commFlow[stages[i]].getTime()<<")"<<endl;
        }
    }
    cout<<endl<<endl<<endl;
}
