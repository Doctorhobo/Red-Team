//
//  FileManager.h
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//

#ifndef FileManager_h
#define FileManager_h

#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>

class FileManager {
public:
    // Constructs a file manager with a binary file as input.
    FileManager(const std::string fileName);
    
    // Deletes all buffers.
    ~FileManager();
    
    // Get string representation of file as hex string grouping the desired amount of bytes into a single string.
    std::vector< std::string > GetHexFileContents(int byteGroupSize);
    
    // Get string representation of file as binary string grouping the desired amount of bytes into a single string.
    std::vector< std::string > GetBinaryFileContents(int byteGroupSize);
    
    // Get string asci value for bytes in desired range. Note: each index represents a byte, not a bit.
    // If startIndex < 0, we treat it as 0. If endIndex > the file size, we treat it as the end of the file.
    std::string GetAsciiForRange(long startIndex, long endIndex);
    
    // Get string time stamp value for bytes in desired range. Note: each index represents a byte, not a bit.
    // If 'is64Bit' = false, then it is assumed you wanted 32bit values.
    // If 'isLittleEndian' = false, then it is assumed you wanted values interpreted using big endian.
    std::vector<double> GetTimeStampsForRange(long startIndex, long endIndex, double maxTimeStamp, bool is64Bit, bool isLittleEndian);
    
private:
    // Prints contents of file to cout. Used for debugging purposes only.
    void PrintFile();
    
    // Buffer storing binary from passed in file.
    u_char* buffer;
    
    // Sinze of the buffer.
    long size;
    
    // Buffer converted to 32 bits.
    float* floatBuffer;
    
    // Buffer converted to 64 bits.
    double* doubleBuffer;
};

#endif /* FileManager_h */
