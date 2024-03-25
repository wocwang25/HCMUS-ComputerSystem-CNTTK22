//		YU SATO CODE SAMPLE - 22120299 - HCMUS
#include <iostream>
 
void dumpFloat(float *p) {
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

int main() {
    float x;
    std::cout << "Enter a floating-point number: ";
    std::cin >> x;
    std::cout<<"Binary Representation: ";
    dumpFloat(&x);
    return 0;
}