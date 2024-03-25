//		YU SATO CODE SAMPLE - 22120299 - HCMUS
#include <iostream>
#include <cstring> 
#include <cmath>   

void forceFloat(float *p, char *s) {
    if(strlen(s) != 32) {
        std::cerr << "Error: Input string must be 32 bits long." << std::endl;
        return;
    }

    unsigned int intValue = 0; 
    for(int i = 0; i < 32; i++) {
        if(s[i] == '1') {
            intValue += 1 << (31 - i);
        } else if(s[i] != '0') {
            std::cerr << "Error: Input string must contain only '0's and '1's." << std::endl;
            return;
        }
    }
    *p = *reinterpret_cast<float*>(&intValue);
}

int main() {
    float myFloat;
    char binaryString[] = "01000001001101100000000000000000";

    forceFloat(&myFloat, binaryString);

    std::cout << "The float is: " << myFloat << std::endl;

    return 0;
}