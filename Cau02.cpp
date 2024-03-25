//		YU SATO CODE SAMPLE - 22120299 - HCMUS
#include <iostream>
#include <cstring> 
#include <cmath>   

void forceFloat(float *p, const char *s) {
    if(strlen(s) != 32) 
    {
        std::cerr << "Error: Input string must be 32 bits long." << std::endl;
        return;
    }
    int sign = (s[0] == '1') ? -1 : 1; 
    int exponent = 0; 
    float mantissa = 1.0f; 
    for(int i = 1; i <= 8; i++) 
    {
        exponent += (s[i] - '0') * std::pow(2, 8 - i);
    }
    exponent -= 127;
    for(int i = 9; i < 32; i++)
     {
        mantissa += (s[i] - '0') * std::pow(2, 8 - i);
    }
    *p = sign * mantissa * std::pow(2, exponent);
}

int main() {
    float myFloat;
    char binaryString[] = "01000100001101100001000000000000";

    forceFloat(&myFloat, binaryString);

    std::cout << "The float is: " << myFloat << std::endl;

    return 0;
}