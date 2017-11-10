// Version History: use git.
// Created by Donald Timpson on 9/19/17.
// Added comments 11/31/17

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

// This class is used to read in and extract the desired data from the binary file.
// It has the ability to interpret the data as binary, or hex. It can get the ascii
// value for some range of in the file. It has the ability to extract double values
// as 32 or 64 bit, and as little endian or big endian.
// Requirements: This class helps satisfy all requirements related to interpreting
// data as binary or hex, interpreting values as 32 bit or 64 bit, and interpreting
// values as little endian or big endian

namespace DataDump {
	
	class FileManager {

		// Buffer storing binary from passed in file.
		byte[] buffer;

		// Buffer converted to 64 bits.
		long[] doubleBuffer;

		// Buffer converted to 32 bits.
		int[] floatBuffer;

		// Constructs a file manager with a binary file as input.
		// Input: name of the file to extract data from.
		// Output: A instance of a FileManger representing the file passed in.
		public FileManager(string filePath) {
			buffer = System.IO.File.ReadAllBytes(filePath);
			doubleBuffer = new long[buffer.Length / 8];
			floatBuffer = new int[buffer.Length / 4];

			Buffer.BlockCopy(buffer, 0, doubleBuffer, 0, doubleBuffer.Length * 8);
			Buffer.BlockCopy(buffer, 0, floatBuffer, 0, doubleBuffer.Length * 4);

		}

    public int GetBufferSize()
    {
        return buffer.Length;
    }

		// Get string representation of file as hex string grouping the desired amount of bytes into a single string.
		// Input: number of bytes that each string in the return vector should represent
		// Output: list of strings where each string represents some number of bytes in hex.
		// Requirements: satisfies the ability to 'display hex text'
		public List<string> GetHexFileContents(int byteGroupSize) {
			List<string> hexStrings = new List<string>();

			if (byteGroupSize <= 0) {
				System.Console.WriteLine("WARNING: byte group size must be a positive integer.");
				return hexStrings;
			}

			// Loop through each byte group
			for (int i = 0; i < buffer.Length; i += byteGroupSize) {
				StringBuilder hex = new StringBuilder(byteGroupSize * 2);

				// Loop through each byte in a byte group
				for (int j = 0; j < byteGroupSize; j++) {
					byte b = buffer[i + j];
					hex.AppendFormat("{0:x2}", b); // Interprets byte as hexdecimal
				}

				hexStrings.Add(hex.ToString());
			}

			return hexStrings;
		}

		// Get string representation of file as binary string grouping the desired amount of bytes into a single string.
		// Input: number of bytes that each string in the return vector should represent
		// Output: list of strings where each string represents some number of bytes in binary.
		// Requirements: satisfies the ability to 'display binary text'
		public List<string> GetBinaryFileContents(int byteGroupSize) {
			List<string> binaryStrings = new List<string>();

			if (byteGroupSize <= 0) {
				System.Console.WriteLine("WARNING: byte group size must be a positive integer.");
				return binaryStrings;
			}

			// Loop through each byte group
			for (int i = 0; i < buffer.Length; i += byteGroupSize) {
				string binaryString = "";

				// Loop through each byte in a byte group
				for (int j = 0; j < byteGroupSize; j++) {
					byte b = buffer[i + j];
					binaryString = string.Concat(binaryString, Convert.ToString(b, 2).PadLeft(8, '0')); // Interprets byte as binary
				}

				binaryStrings.Add(binaryString);
			}

			return binaryStrings;
		}

		// Get string asci value for bytes in desired range. Note: each index represents a byte, not a bit.
		// Input: 'startIndex' is the byte in the file to start getting ascii from, inclusive.
		// If startIndex < 0, we treat it as 0.
		// Input: 'endIndex' is the byte in the file to end getting ascii from, not inclusive.
		// If endIndex > the file size, we treat it as the end of the file.
		// Output: string of ascii values for bytes in desired range.
		// Requirements: satisfies the ability to 'get ascii values from file'
		public string GetAsciiForRange(long startIndex, long endIndex) {
			string asciiString = "";

			if (startIndex > endIndex) {
				System.Console.WriteLine("WARNING: start index should be before end index.");
			}

			if (startIndex < 0) {
				startIndex = 0;
				System.Console.WriteLine("WARNING: start index should be greater than 0.");
			}

			if (endIndex > buffer.Length) {
				endIndex = buffer.Length;
				System.Console.WriteLine("WARNING: end index outside of buffer.");
			}

			byte[] subBuffer = new byte[(endIndex + 1) - startIndex];
			Array.Copy(buffer, startIndex, subBuffer, 0, (endIndex) - startIndex);
			asciiString = System.Text.Encoding.ASCII.GetString(subBuffer);

			return asciiString;
		}

		// Get string time stamp value for bytes in desired range. Note: each index represents a byte, not a bit.
		// Input: 'startIndex' is the byte in the file to start getting time stamps from, inclusive.
		// If startIndex < 0, we treat it as 0.
		// Input: 'endIndex' is the byte in the file to end getting time stamps from, not inclusive.
		// If endIndex > the file size, we treat it as the end of the file.
		// Input: 'maxTimeStamp' scopes the time stamps returned such that each time stamp is less than or equal to it.
		// Input: 'is64Bit' interprets the time stamps in 64 bit chunks. If fales, it is assumed that 32 bits is desired.
		// Input: 'isLittleEndian' interprets the time stamps in little endian. If fales, it is assumed that big endian is desired.
		// Output: returns a list of positive time stamps interpreted as desired by input parameters.
		// Requirements: satisfies the ability to 'interpret as big E' and 'interpret as little E' and 'interpret as 64-bit' and 'interpret as 32-bit'
		public List<long> GetTimeStampsForRange(long startIndex, long endIndex, long maxTimeStamp, bool is64Bit, bool isLittleEndian) {
			List<long> timeStamps = new List<long>();
			const int BYTES_IN_64_BITS = 8;
			const int BYTES_IN_32_BITS = 4;
    
			if (startIndex > endIndex) {
				System.Console.WriteLine("WARNING: start index must be before end index.");
				return timeStamps;
			}
    
			if (startIndex < 0) {
				startIndex = 0;
			}
    
			if (endIndex > buffer.Length - 1) {
				endIndex = buffer.Length - 1;
			}
    
			if (is64Bit && (startIndex % BYTES_IN_64_BITS != 0 || (endIndex + 1) % BYTES_IN_64_BITS != 0)) {
				System.Console.WriteLine("WARNING: Both indexes must be some increment of 64 bits if you choose 64 bits.");
				return timeStamps;
			}
    
			if (is64Bit == false && (startIndex % BYTES_IN_32_BITS != 0 || (endIndex + 1) % BYTES_IN_32_BITS != 0)) {
				System.Console.WriteLine("WARNING: Both indexes must be some increment of 32 bits if you choose 32 bits.");
				return timeStamps;
			}
    
			if (is64Bit) {
				startIndex = startIndex / BYTES_IN_64_BITS;
				endIndex = (endIndex + 1) / BYTES_IN_64_BITS;
        
				for (long i = startIndex; i < endIndex; i++) {
					if (isLittleEndian) {
						long timeStamp = doubleBuffer[i];
                
						if (timeStamp >= 0 && timeStamp <= maxTimeStamp) {
							timeStamps.Add(timeStamp);
						}
                
					} else {

						byte[] temp = BitConverter.GetBytes(doubleBuffer[i]);
						Array.Reverse(temp);
						long timeStamp = BitConverter.ToInt64(temp, 0); // Change endian
                
						if (timeStamp >= 0 && timeStamp <= maxTimeStamp) {
							timeStamps.Add(timeStamp);
						}
					}
				}
        
			} else { // is 32 bit
				startIndex = startIndex / BYTES_IN_32_BITS;
				endIndex = (endIndex + 1) / BYTES_IN_32_BITS;
        
				for (long i = startIndex; i < endIndex; i++) {
					if (isLittleEndian) {
						int timeStamp = floatBuffer[i];
                
						if (timeStamp >= 0 && timeStamp <= maxTimeStamp) {
							timeStamps.Add(timeStamp);
						}
                
					} else {
						byte[] temp = BitConverter.GetBytes(floatBuffer[i]);
						Array.Reverse(temp);
						uint timeStamp = BitConverter.ToUInt32(temp, 0); // Change endian
                
						if (timeStamp >= 0 && timeStamp <= maxTimeStamp) {
							timeStamps.Add(timeStamp);
						}
					}
				}
			}
    
			return timeStamps;
		}

		// This method exists only for debugging purposes.
		public void PrintFile () {
			List<string> hexStr = GetBinaryFileContents(4);

			foreach (string line in hexStr) {
				System.Console.WriteLine(line);
			}
		}
	}
}
