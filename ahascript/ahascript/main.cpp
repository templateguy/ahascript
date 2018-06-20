//
//  main.cpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#include <iostream>
#include "Preprocessor.hpp"


int main(int argc, const char * argv[])
{
    aha::Preprocessor preprocessor("scripts/main.aha");
    auto preprocessed(preprocessor());
    std::cout << preprocessed;
    return 0;
}
