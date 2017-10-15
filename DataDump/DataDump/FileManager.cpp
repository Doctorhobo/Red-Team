//
//  FileManager.cpp
//  DataDump
//
//  Created by Donald Timpson on 9/19/17.
//  Copyright © 2017 Donald Timpson. All rights reserved.
//

#include "FileManager.hpp"
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
}

void FileManager::PrintFile() {
    for (long i = 0; i < this->size; i++) {
        cout << setfill ('0') << setw(2) << hex << (uint) this->buffer[i];
        
        if ((i + 1) % 4 == 0) {
            cout << endl;
        }
    }
}

string FileManager::GetHexFileContents() {
    string returnString = "";
    
    for (long i = 0; i < this->size; i++) {
        string fourString = "";
        
        for (long j = i; j < i + 4; j++) {
            stringstream stream;
            stream << setfill ('0') << setw(2) << hex << (uint) this->buffer[j];
            string result( stream.str() );
            fourString.append(result);
        }
        fourString.append(" ");
        
        returnString.append(fourString);
        i += 4;
    }
    
    return returnString;
}

string FileManager::GetBinaryFileContents() {
    string returnString = "";
    
    for (long i = 0; i < this->size; i++) {
        string fourString = "";
        
        for (long j = i; j < i + 4; j++) {
            string result = bitset<8>( (uint) this->buffer[j] ).to_string();
            fourString.append(result);
        }
        fourString.append(" ");
        
        returnString.append(fourString);
        i += 4;
    }
    
    return returnString;
}

std::string FileManager::GetAsciiForRange(long startIndex, long endIndex) {
    
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
    
    if (is64Bit) {
        startIndex = startIndex / 8;
        endIndex = endIndex / 8;
        
        for (long i = startIndex; i <= endIndex; i++) {
            if (isLittleEndian) {
                timeStamps.push_back(doubleBuffer[i]);
            } else {
                timeStamps.push_back(changeEndian(doubleBuffer[i]));
            }
        }
        
    } else {
        startIndex = startIndex / 4;
        endIndex = endIndex / 4;
        
        for (long i = startIndex; i <= endIndex; i++) {
            if (isLittleEndian) {
                timeStamps.push_back(floatBuffer[i]);
            } else {
                timeStamps.push_back(changeEndian(floatBuffer[i]));
            }
        }
    }
    
    return timeStamps;
}
