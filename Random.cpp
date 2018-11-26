//
//  Random.cpp
//  Kursach
//
//  Created by администратор on 10.11.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Random.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
using namespace std;
int Random(int probability, int badOption){
    int res;
    mt19937 rng;
    rng.seed(std::random_device()());
    uniform_int_distribution<mt19937::result_type> dist6(1,100);
    res=dist6(rng);
    if(res>probability){
        return badOption;
    }else{
        return 1;
    }
}
