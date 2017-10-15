//
//  FileManager.hpp
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>

class FileManager {
public:
    FileManager(const std::string fileName);
    ~FileManager();
    void PrintFile();
    std::string GetHexFileContents();
    std::string GetBinaryFileContents();
    std::string GetAsciiForRange(long startIndex, long endIndex);
    std::vector<double> GetTimeStampsForRange(long startIndex, long endIndex, double maxTimeStamp, bool is64Bit, bool isLittleEndian);
    
private:
    float* floatBuffer;
    double* doubleBuffer;
    u_char* buffer;
    long size;
};

#endif /* FileManager_hpp */
