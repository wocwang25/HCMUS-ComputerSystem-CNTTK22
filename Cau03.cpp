//		YU SATO CODE SAMPLE - 22120299 - HCMUS
#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>
void forceFloat(float *p, const char *s) 
{
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

void dumpFloat(float *p) 
{
    unsigned int val = *(unsigned int*)p;
    unsigned int sign = val >> 31;
    unsigned int exponent = (val >> 23) & 0xFF;
    unsigned int significand = val & 0x7FFFFF;
    std::cout <<sign << " ";
    for (int i = 7; i >= 0; --i) {
        std::cout << ((exponent >> i) & 1);
    }
    std::cout << " ";
    for (int i = 22; i >= 0; --i) {
        std::cout << ((significand >> i) & 1);
    }
    std::cout << '\n';
}
 
int main()
{
    std::cout<<"The binary representation of 1.3E+20: ";
    float number = 1.3e+20f;
    dumpFloat(&number);
    std::cout<<"\n";
    number = std::numeric_limits<float>::min();
    std::cout << "The smallest positive float greater than 0: ";
    dumpFloat(&number);

    // infinity number
    number = std::numeric_limits<float>::infinity();
    std::cout << "The binary representation of positive infinity (inf): ";
    dumpFloat(&number);

    // NaN (Not a Number)
    number = std::numeric_limits<float>::quiet_NaN();
    std::cout << "The binary representation of NaN: ";
    dumpFloat(&number);

    // X/0 (chia cho 0)
    number = 1.0f / 0.0f;
    std::cout << "The result of X/0 (should be inf): ";
    dumpFloat(&number);

    // 0/0
    number = 0.0f / 0.0f;
    std::cout << "The result of 0/0 (should be NaN): ";
    dumpFloat(&number);

    // sqrt(positive number)
    number = -1.0f;
    number = sqrt(number);
    std::cout << "The result of sqrt(-1): ";
    dumpFloat(&number);    


}