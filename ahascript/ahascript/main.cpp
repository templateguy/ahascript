//
//  main.cpp
//  ahascript
//
//  Created by Priyanshi Thakur on 19/06/18.
//  Copyright © 2018 Priyanshi Thakur. All rights reserved.
//

#include <fstream>
#include <sstream>
#include "Lexer.hpp"


int main(int argc, const char * argv[])
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open("scripts/main.aha");
    std::stringstream fileStream;
    fileStream << file.rdbuf();
    file.close();
    std::string input(fileStream.str());
    
    aha::Lexer lexer(input);
    lexer.print();
    return 0;
}
