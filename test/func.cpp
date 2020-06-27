//
//  func.cpp
//  test
//
//  Created by Henry on 2020/6/27.
//  Copyright © 2020 Henry. All rights reserved.
//

#include "func.hpp"

bool lambda(){
    return  [](int x = 3, int y = 2){ return x < y;};
}

