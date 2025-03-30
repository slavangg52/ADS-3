// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdint>

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        ++length;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound,
                        uint64_t rbound) {
    unsigned int bestNumber = 0;
    *maxlen = 0;
    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int currentLen = collatzLen(i);
        if (currentLen > *maxlen) {
            *maxlen = currentLen;
            bestNumber = i;
        }
    }
    return bestNumber;
}

int main() {
    unsigned int maxLen;
    uint64_t lbound = 2, rbound = 1000000;
    unsigned int bestNumber = seqCollatz(&maxLen, lbound, rbound);
    uint64_t maxValue = collatzMaxValue(bestNumber);

    std::cout << "Число: " << bestNumber
              << "\nДлина: " << maxLen
              << "\nМакс. значение: " << maxValue
              << std::endl;
    return 0;
}

