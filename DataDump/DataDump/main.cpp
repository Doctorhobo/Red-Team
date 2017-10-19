//
//  main.cpp
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//

#include "FileManager.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main(int argc, char *argv[]) {
    
    
    
    FileManager manager = FileManager("blackberry 8520.bin.cpgz");
//    manager.PrintFile();
//    std::cout << manager.GetBinaryFileContents() ;
//    std::cout << manager.GetAsciiForRange(0, 5000);
    std::vector<double> v = manager.GetTimeStampsForRange(0, 31, 0, true, false);
    std::vector<std::string> hex = manager.GetHexFileContents(4);
    std::vector<std::string> binary = manager.GetBinaryFileContents(1);
    
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    
    for (size_t i = 0; i < hex.size(); i++) {
        std::cout << hex[i] << std::endl;
    }
    
    for (size_t i = 0; i < binary.size(); i++) {
        std::cout << binary[i] << std::endl;
    }
    
    return 0;
}
