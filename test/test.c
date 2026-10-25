#include <stdio.h>
#include "gf.h"

int main(void)
{
    int tong_test = 0;
    int test_dung = 0;
    unsigned int kq;

    // Cac test cho GF(2^4)
    kq = nhan(0x0, 0x7, 4, 0x13);
    tong_test++;
    if (kq == 0x0) {
        printf("[PASS] GF4: 0x0 * 0x7 = 0x0\n");
        test_dung++;
    } else {
        printf("[FAIL] GF4 test 1\n");
    }

    kq = nhan(0x1, 0xA, 4, 0x13);
    tong_test++;
    if (kq == 0xA) {
        printf("[PASS] GF4: 0x1 * 0xA = 0xA\n");
        test_dung++;
    } else {
        printf("[FAIL] GF4 test 2\n");
    }

    kq = nhan(0x2, 0x3, 4, 0x13);
    tong_test++;
    if (kq == 0x6) {
        printf("[PASS] GF4: 0x2 * 0x3 = 0x6\n");
        test_dung++;
    } else {
        printf("[FAIL] GF4 test 3\n");
    }

    kq = nhan(0xA, 0x7, 4, 0x13);
    tong_test++;
    if (kq == 0x3) {
        printf("[PASS] GF4: 0xA * 0x7 = 0x3\n");
        test_dung++;
    } else {
        printf("[FAIL] GF4 test 4, got 0x%X\n", kq);
    }

    kq = nhan(0xF, 0xF, 4, 0x13);
    tong_test++;
    if (kq == 0xA) {
        printf("[PASS] GF4: 0xF * 0xF = 0xA\n");
        test_dung++;
    } else {
        printf("[FAIL] GF4 test 5\n");
    }

    // Cac test cho GF(2^8)
    kq = nhan(0x00, 0x57, 8, 0x11B);
    tong_test++;
    if (kq == 0x00) {
        printf("[PASS] GF8: 0x00 * 0x57 = 0x00\n");
        test_dung++;
    } else {
        printf("[FAIL] GF8 test 1\n");
    }

    kq = nhan(0x01, 0x57, 8, 0x11B);
    tong_test++;
    if (kq == 0x57) {
        printf("[PASS] GF8: 0x01 * 0x57 = 0x57\n");
        test_dung++;
    } else {
        printf("[FAIL] GF8 test 2\n");
    }

    kq = nhan(0x02, 0x03, 8, 0x11B);
    tong_test++;
    if (kq == 0x06) {
        printf("[PASS] GF8: 0x02 * 0x03 = 0x06\n");
        test_dung++;
    } else {
        printf("[FAIL] GF8 test 3\n");
    }

    kq = nhan(0x57, 0x83, 8, 0x11B);
    tong_test++;
    if (kq == 0xC1) {
        printf("[PASS] GF8: 0x57 * 0x83 = 0xC1\n");
        test_dung++;
    } else {
        printf("[FAIL] GF8 test 4, got 0x%X\n", kq);
    }

    kq = nhan(0xFF, 0xFF, 8, 0x11B);
    tong_test++;
    if (kq == 0x13) {
        printf("[PASS] GF8: 0xFF * 0xFF = 0x13\n");
        test_dung++;
    } else {
        printf("[FAIL] GF8 test 5, got 0x%X\n", kq);
    }

    printf("\nSo test dung: %d/%d\n", test_dung, tong_test);

    if (test_dung == tong_test) {
        printf("Tat ca test deu thanh cong!\n");
        return 0;
    }

    printf("Co test chua dung!\n");
    return 1;
}
