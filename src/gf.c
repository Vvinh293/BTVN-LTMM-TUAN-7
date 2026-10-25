#include "gf.h"

unsigned int nhan(unsigned int a, unsigned int b,  int bac, unsigned int da_thuc)
{
    unsigned int kq = 0;
    unsigned int bit_cao = 1u << bac;
    unsigned int mask = bit_cao - 1;

    while (b > 0) {
        if (b & 1) {
            kq ^= a;
        }

        b >>= 1;

        a <<= 1;

        if (a & bit_cao) {
            a ^= da_thuc;
        }

        a &= mask;
    }

    return kq;
}