//
//  main.cpp
//  Kursach
//
//  Created by администратор on 10.11.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include <iostream>
#include "Conv.hpp"
using namespace std;
int main() {
    int com=0, pb1, pb2, N, M;
    cout<<"Enter quantity of commands"<<endl;
    cin>>com;
    cout<<"Enter first probability"<<endl;
    cin>>pb1;
    cout<<"Enter second probability"<<endl;
    cin>>pb2;
    cout<<"Enter quantity of commands"<<endl;
    cin>>N;
    cout<<"Enter quantity of commands"<<endl;
    cin>>M;
    Conveyor Conv(com, pb1, pb2, N, M);
    //Conveyor Conv(50, 50, 60, 2, 4);
    return 0;
}
