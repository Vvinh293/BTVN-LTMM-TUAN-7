#include <stdio.h>
#include "gf.h"

int main(void)
{
    int chon;
    unsigned int a, b, kq;
    int bac;
    unsigned int da_thuc;

    printf("NHAN DA THUC TRONG TRUONG HUU HAN\n");
    printf("1. GF(2^4)\n");
    printf("2. GF(2^8)\n");
    printf("Chon truong: ");

    if (scanf("%d", &chon) != 1) {
        printf("Du lieu khong hop le!\n");
        return 1;
    }

    if (chon == 1) {
        bac = 4;
        da_thuc = 0x13;
    } else if (chon == 2) {
        bac = 8;
        da_thuc = 0x11B;
    } else {
        printf("Lua chon khong hop le!\n");
        return 1;
    }

    printf("Nhap a (he 16): ");
    if (scanf("%x", &a) != 1) {
        printf("Gia tri a khong hop le!\n");
        return 1;
    }

    printf("Nhap b (he 16): ");
    if (scanf("%x", &b) != 1) {
        printf("Gia tri b khong hop le!\n");
        return 1;
    }

    unsigned int gioi_han = (1u << bac) - 1;

    if (a > gioi_han || b > gioi_han) {
        printf("Gia tri vuot qua gioi han cua truong!\n");
        printf("Gia tri cho phep: 0 den 0x%X\n", gioi_han);
        return 1;
    }

    kq = nhan(a, b, bac, da_thuc);

    printf("\nDa thuc toi gian: 0x%X\n", da_thuc);
    printf("a = 0x%X\n", a);
    printf("b = 0x%X\n", b);
    printf("Ket qua a * b = 0x%X\n", kq);

    return 0;
}
