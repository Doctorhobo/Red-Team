//
//  FileManager.h
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//
// Version History: use git.
// Created by Donald Timpson on 9/19/17.
// Added comments 11/31/17

#ifndef FileManager_h
#define FileManager_h

#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>

// This class is used to read in and extract the desired data from the binary file.
// It has the ability to interprit the data as binary, or hex. It can get the ascii
// value for some range of in the file. It has the ability to extract double values
// as 32 or 64 bit, and as little endian or big endian.
// Requirements: This class helps satisfy all requirements related to interpreting
// data as binary or hex, interpreting values as 32 bit or 64 bit, and interpreting
// values as little endian or big endian

class FileManager {
    
public:
    // Constructs a file manager with a binary file as input.
    // Input: name of the file to extract data from.
    // Output: A instance of a FileManger representing the file passed in.
    FileManager(const std::string fileName);
    
    // Deconstructs the FileManager. This is required to deletes all buffers.
    ~FileManager();
    
    // Get string representation of file as hex string grouping the desired amount of bytes into a single string.
    // Input: number of bytes that each string in the return vector should represent
    // Output: vector of strings where each string represents some number of bytes in hex.
    // Requirements: satisfies the ability to 'display hex text'
    std::vector< std::string > GetHexFileContents(int byteGroupSize);
    
    // Get string representation of file as binary string grouping the desired amount of bytes into a single string.
    // Input: number of bytes that each string in the return vector should represent
    // Output: vector of strings where each string represents some number of bytes in binary.
    // Requirements: satisfies the ability to 'display binary text'
    std::vector< std::string > GetBinaryFileContents(int byteGroupSize);
    
    // Get string asci value for bytes in desired range. Note: each index represents a byte, not a bit.
    // Input: 'startIndex' is the byte in the file to start getting ascii from, inclusive.
    // If startIndex < 0, we treat it as 0.
    // Input: 'endIndex' is the byte in the file to end getting ascii from, not inclusive.
    // If endIndex > the file size, we treat it as the end of the file.
    // Output: string of ascii values for bytes in desired range.
    // Requirements: satisfies the ability to 'get ascii values from file'
    std::string GetAsciiForRange(long startIndex, long endIndex);
    
    // Get string time stamp value for bytes in desired range. Note: each index represents a byte, not a bit.
    // Input: 'startIndex' is the byte in the file to start getting time stamps from, inclusive.
    // If startIndex < 0, we treat it as 0.
    // Input: 'endIndex' is the byte in the file to end getting time stamps from, not inclusive.
    // If endIndex > the file size, we treat it as the end of the file.
    // Input: 'maxTimeStamp' scopes the time stamps returned such that each time stamp is less than or equal to it.
    // Input: 'is64Bit' interprets the time stamps in 64 bit chunks. If fales, it is assumed that 32 bits is desired.
    // Input: 'isLittleEndian' interprets the time stamps in little endian. If fales, it is assumed that big endian is desired.
    // Output: returns a vector of positive time stamps interpreted as desired by inout parameters.
    // Requirements: satisfies the ability to 'interpret as big E' and 'interpret as little E' and 'interpret as 64-bit' and 'interpret as 32-bit'
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
