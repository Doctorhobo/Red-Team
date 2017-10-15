//
//  main.cpp
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//

#include "FileManager.hpp"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main(int argc, char *argv[]) {
    
    
    
    FileManager manager = FileManager("testInput.cpgz");
//    manager.PrintFile();
//    std::cout << manager.GetBinaryFileContents() ;
//    std::cout << manager.GetAsciiForRange(0, 5000);
    std::vector<double> v = manager.GetTimeStampsForRange(16, 31, 0, false, false);
    
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    
    return 0;
}
