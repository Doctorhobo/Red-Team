//
//  FileManager.cpp
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//

#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;


double changeEndian(double in)
{
    char* const p = reinterpret_cast<char*>(&in);
    for (size_t i = 0; i < sizeof(double) / 2; ++i)
        std::swap(p[i], p[sizeof(double) - i - 1]);
    
    return in;
}

float changeEndian(float in)
{
    char* const p = reinterpret_cast<char*>(&in);
    for (size_t i = 0; i < sizeof(float) / 2; ++i)
        std::swap(p[i], p[sizeof(float) - i - 1]);
    
    return in;
}

FileManager::FileManager(const std::string fileName) {
    
    ifstream file (fileName, ios::in|ios::binary|ios::ate);
    this->size = file.tellg();
    file.seekg(0, ios::beg);
    
    this->buffer = new u_char[this->size];
    
    file.read((char *)this->buffer, this->size);
    file.close();
    
    this->doubleBuffer = (double*) this->buffer;
    this->floatBuffer = (float*) this->buffer;
}

FileManager::~FileManager() {
    delete[] this->buffer;
    delete[] this->doubleBuffer;
    delete[] this->floatBuffer;
}

void FileManager::PrintFile() {
    for (long i = 0; i < this->size; i++) {
        cout << setfill ('0') << setw(2) << hex << (uint) this->buffer[i];
        
        if ((i + 1) % 4 == 0) {
            cout << endl;
        }
    }
}

vector< string > FileManager::GetHexFileContents(int byteGroupSize) {
    
    if (byteGroupSize > 0 == false) {
        cout << "byte group size must be a positive integer." << endl;
        return vector< string >();
    }
    
    vector<string> bytesAsStrings = vector<string>();
    
    for (long i = 0; i < this->size; i++) {
        string byteString = "";
        
        for (long j = i; j < i + byteGroupSize; j++) {
            stringstream stream;
            stream << setfill ('0') << setw(2) << hex << (uint) this->buffer[j];
            string result( stream.str() );
            byteString.append(result);
        }
        
        bytesAsStrings.push_back(byteString);
        i += byteGroupSize;
    }
    
    return bytesAsStrings;
}

vector< string > FileManager::GetBinaryFileContents(int byteGroupSize) {
    
    if (byteGroupSize > 0 == false) {
        cout << "byte group size must be a positive integer." << endl;
        return vector< string >();
    }
    
    vector<string> bytesAsStrings = vector<string>();
    
    for (long i = 0; i < this->size; i++) {
        string byteString = "";
        
        for (long j = i; j < i + byteGroupSize; j++) {
            string result = bitset<8>( (uint) this->buffer[j] ).to_string();
            byteString.append(result);
        }
        
        bytesAsStrings.push_back(byteString);
        i += byteGroupSize;
    }
    
    return bytesAsStrings;
}

std::string FileManager::GetAsciiForRange(long startIndex, long endIndex) {
    
    if (startIndex > endIndex) {
        cout << "start index must be before end index." << endl;
        return "";
    }
    
    if (startIndex < 0) {
        startIndex = 0;
    }
    
    if (endIndex > this->size) {
        endIndex = this->size;
    }
    
    string asciiString = "";
    
    for (long i = startIndex; i < endIndex; i++) {
        char c = static_cast<char>( (int) this->buffer[i] );
        asciiString.append(&c);
    }
    
    return asciiString;
}

vector<double> FileManager::GetTimeStampsForRange(long startIndex, long endIndex, double maxTimeStamp, bool is64Bit, bool isLittleEndian) {
    
    vector<double> timeStamps = vector<double>();
    int BYTES_IN_64_BITS = 8;
    int BYTES_IN_32_BITS = 4;
    
    if (startIndex > endIndex) {
        cout << "start index must be before end index." << endl;
        return vector< double >();
    }
    
    if (startIndex < 0) {
        startIndex = 0;
    }
    
    if (endIndex > this->size) {
        endIndex = this->size;
    }
    
    if (is64Bit && (startIndex % BYTES_IN_64_BITS != 0 || (endIndex + 1) % BYTES_IN_64_BITS != 0)) {
        cout << "Both indexes must be some increment of 64 bits if you choose 64 bits" << endl;
        return vector< double >();
    }
    
    if (is64Bit == false && (startIndex % BYTES_IN_32_BITS != 0 || (endIndex + 1) % BYTES_IN_32_BITS != 0)) {
        cout << "Both indexes must be some increment of 32 bits if you choose 32 bits" << endl;
        return vector< double >();
    }
    
    if (is64Bit) {
        startIndex = startIndex / BYTES_IN_64_BITS;
        endIndex = (endIndex + 1) / BYTES_IN_64_BITS;
        
        for (long i = startIndex; i < endIndex; i++) {
            double timeStamp = doubleBuffer[i];
            
            if (timeStamp > 0 && timeStamp < maxTimeStamp) {
                if (isLittleEndian) {
                    timeStamps.push_back(timeStamp);
                } else {
                    timeStamps.push_back(changeEndian(timeStamp));
                }
            }
        }
        
    } else {
        startIndex = startIndex / BYTES_IN_32_BITS;
        endIndex = (endIndex + 1) / BYTES_IN_32_BITS;
        
        for (long i = startIndex; i < endIndex; i++) {
            
            double timeStamp = doubleBuffer[i];
            
            if (timeStamp > 0 && timeStamp < maxTimeStamp) {
                if (isLittleEndian) {
                    timeStamps.push_back(timeStamp);
                } else {
                    timeStamps.push_back(changeEndian(timeStamp));
                }
            }
        }
    }
    
    return timeStamps;
}

