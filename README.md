# Bài tập tuần 7 - Nhân đa thức trong trường hữu hạn

## 1. Giới thiệu

Bài tập thực hiện phép nhân hai phần tử trong trường hữu hạn (GF(2^4)) và (GF(2^8)) bằng ngôn ngữ lập trình C.

Chương trình sử dụng phép XOR, dịch bit và đa thức bất khả quy để tính kết quả phép nhân. Người dùng có thể chọn trường hữu hạn, nhập hai giá trị ở hệ thập lục phân và xem kết quả.

## 2. Đa thức sử dụng

- **GF(2^4):** (m(x)=x^4+x+1), biểu diễn bằng `0x13`.
- **GF(2^8):** (m(x)=x^8+x^4+x^3+x+1), biểu diễn bằng `0x11B`.

Các phần tử đầu vào được biểu diễn bằng các bit của đa thức. Phép cộng trong trường GF(2) được thực hiện bằng XOR.

## 3. Thuật toán

1. Khởi tạo kết quả bằng 0.
2. Kiểm tra bit thấp nhất của số (b). Nếu bằng 1, XOR (a) vào kết quả.
3. Dịch phải (b) một bit và dịch trái (a) một bit.
4. Nếu phép dịch trái làm xuất hiện bit vượt quá bậc của trường, XOR với đa thức bất khả quy để rút gọn.
5. Lặp lại cho đến khi (b=0).
6. Trả về kết quả phép nhân.

## 4. Cấu trúc thư mục

```text
Finite Field Polynomial Multiplication/
├── include/
│   └── gf.h
├── src/
│   ├── gf.c
│   └── main.c
├── tests/
│   ├── test_gf.c
|
└── README.md
```

## 5. Biên dịch và chạy chương trình

Sử dụng GCC:

```bash
gcc -Iinclude src/main.c src/gf.c -o main.exe
```

Chạy chương trình trên Windows PowerShell:

```powershell
.\main.exe
```

Chương trình cho phép chọn `GF(2^4)` hoặc `GF(2^8)`, sau đó nhập hai phần tử ở hệ thập lục phân.

## 6. Kiểm thử

Biên dịch chương trình kiểm thử:

```bash
gcc -Iinclude tests/test_gf.c src/gf.c -o test_gf.exe
```

Chạy kiểm thử:

```powershell
.\test_gf.exe
```

Các trường hợp kiểm thử gồm phép nhân với 0, phép nhân với 1, các phép nhân cơ bản, phép nhân có phát sinh bước rút gọn và các giá trị ở giới hạn của trường.

## 7. Kết quả kiểm thử

Bảng dưới đây là kết quả kỳ vọng của 10 trường hợp kiểm thử:

| STT | Trường  |      a |      b | Kết quả kỳ vọng |
| --: | ------- | -----: | -----: | --------------: |
|   1 | GF(2^4) |  `0x0` |  `0x7` |           `0x0` |
|   2 | GF(2^4) |  `0x1` |  `0xA` |           `0xA` |
|   3 | GF(2^4) |  `0x2` |  `0x3` |           `0x6` |
|   4 | GF(2^4) |  `0xA` |  `0x7` |           `0x3` |
|   5 | GF(2^4) |  `0xF` |  `0xF` |           `0xA` |
|   6 | GF(2^8) | `0x00` | `0x57` |          `0x00` |
|   7 | GF(2^8) | `0x01` | `0x57` |          `0x57` |
|   8 | GF(2^8) | `0x02` | `0x03` |          `0x06` |
|   9 | GF(2^8) | `0x57` | `0x83` |          `0xC1` |
|  10 | GF(2^8) | `0xFF` | `0xFF` |          `0x13` |

Kết quả thực tế cần được xác nhận bằng cách chạy chương trình kiểm thử. Một trường hợp được đánh dấu `PASS` khi kết quả thực tế trùng với kết quả kỳ vọng.

[PASS] GF(2^4): 0x0 * 0x7 = 0x0
[PASS] GF(2^4): 0x1 * 0xA = 0xA
[PASS] GF(2^4): 0x2 * 0x3 = 0x6
[PASS] GF(2^4): 0xA * 0x7 = 0x3
[PASS] GF(2^4): 0xF * 0xF = 0xA
[PASS] GF(2^8): 0x00 * 0x57 = 0x00
[PASS] GF(2^8): 0x01 * 0x57 = 0x57
[PASS] GF(2^8): 0x02 * 0x03 = 0x06
[PASS] GF(2^8): 0x57 * 0x83 = 0xC1
[PASS] GF(2^8): 0xFF * 0xFF = 0x13

Ket qua: 10/10 test PASS

## 8. Kết luận

Chương trình áp dụng phép nhân đa thức trong trường hữu hạn bằng các phép toán bit. Việc sử dụng đa thức bất khả quy giúp rút gọn kết quả về đúng phạm vi của (GF(2^4)) và (GF(2^8)). Bộ kiểm thử được sử dụng để kiểm tra tính đúng đắn của thuật toán với nhiều trường hợp đầu vào.

