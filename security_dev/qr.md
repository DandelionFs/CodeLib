# QR

THX FOR:

- **[ qrbtf](https://github.com/ciaochaos/qrbtf)**
- [二维码的生成细节和原理](https://coolshell.cn/articles/10590.html)



```cpp
作者：biubiubiu
链接：https://www.zhihu.com/question/38816557/answer/1573957124
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QR_SIZE 21
#define PRINT_SIZE 31
#define GF_SIZE 256
#define DATACODE_SIZE 129
#define DEBUG 0

int mat[QR_SIZE][QR_SIZE];
int vis[QR_SIZE][QR_SIZE];
int output[PRINT_SIZE][PRINT_SIZE];
int GF256[GF_SIZE], RGF256[GF_SIZE];

int posMat[9][9];
int errorCodeNum[12];

char dataCode[DATACODE_SIZE];
char errorCodeChar[DATACODE_SIZE];
const char blue[] = "101010000010010";
const char dict[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
const int codePoly[] = {0, 251, 67, 46, 61, 118, 70, 64, 94, 32, 45};
const int bluePos[2][15][2] = {
        8, 0, 8, 1, 8, 2, 8, 3, 8, 4, 8, 5, 8, 7, 8, 8, 7, 8, 5, 8, 4, 8, 3, 8, 2, 8, 1, 8, 0, 8,
        20, 8, 19, 8, 18, 8, 17, 8, 16, 8, 15, 8, 14, 8, 8, 13, 8, 14, 8, 15, 8, 16, 8, 17, 8, 18, 8, 19, 8, 20
};

void PrepareDingWei() {
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            if (i == 1 || j == 1 || i == 7 || j == 7) {
                posMat[i][j] = 1;
            }
        }
    }
    for (int i = 3; i <= 5; i++) {
        for (int j = 3; j <= 5; j++) {
            posMat[i][j] = 1;
        }
    }
}

void DrawDingWei(int x1, int y1, int x2, int y2) {
    for (int i = x1, i2 = x2; i < 9; i++, i2++) {
        if (i2 >= QR_SIZE) continue;
        for (int j = y1, j2 = y2; j < 9; j++, j2++) {
            if (j2 >= QR_SIZE) continue;
            mat[i2][j2] = posMat[i][j];
            vis[i2][j2] = 1;
        }
    }
}

// 最终的打印，显示构造二维码矩阵，然后用一个大的矩阵包住小矩阵
void Print() {
    int sum = 0;
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if (vis[i][j]) {
                sum++;
            }
        }
    }
    int id = 0;
    int x = QR_SIZE - 1, y = QR_SIZE - 1, flag = 1;
    for (int j = QR_SIZE - 1; j >= 0; j--) {
        int pos = 0;
        if (flag == 1) {
            for (;;) {
                mat[x][y] = dataCode[id++] - '0';
                if (pos == 0) {
                    y--;
                } else {
                    if (x == 0) {
                        y--;
                        flag = 0;
                        break;
                    } else if (vis[x - 1][y + 1]) {
                        if (!vis[x - 2][y + 1]) {
                            x -= 2;
                            y += 1;
                        } else {
                            y--;
                            flag = 0;
                            break;
                        }
                    } else {
                        x--;
                        y++;
                    }
                }
                pos = 1 - pos;
            }
        } else {
            for (;;) {
                mat[x][y] = dataCode[id++] - '0';
                if (pos == 0) {
                    y--;
                } else {
                    if (x == QR_SIZE - 1) {
                        if (y == 9) {
                            x = 12;
                            y--;
                            flag = 1;
                            break;
                        } else {
                            y--;
                            flag = 1;
                            break;
                        }
                    } else if (vis[x + 1][y + 1]) {
                        if (!vis[x + 2][y + 1]) {
                            x += 2;
                            y += 1;
                        } else {
                            flag = 1;
                            break;
                        }
                    } else {
                        x += 1;
                        y += 1;
                    }
                }
                pos = 1 - pos;
            }
        }
        if (j == 8) j -= 2, y--;
        else j--;
    }
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if (!vis[i][j] && (i + j) % 2 == 0) {
                mat[i][j] = 1 - mat[i][j];
            }
        }
    }

    char black = ' ';
    char white = 219;
    for (int i = 0; i < PRINT_SIZE; i++) {
        for (int j = 0; j < PRINT_SIZE; j++) {
            output[i][j] = 0;
        }
    }

    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            output[i + 5][j + 5] = mat[i][j];
        }
    }

    for (int i = 0; i < PRINT_SIZE; i++) {
        for (int j = 0; j < PRINT_SIZE; j++) {
            if (output[i][j]) {
                printf("%c%c", black, black);
            } else {
                printf("%c%c", white, white);
            }
        }
        printf("\n");
    }
}

// 画出二维码中固定的部分，例如定位符和掩码

void DrawBackground() {
    // 准备定位符的一份矩阵，然后直接copy三份到左上，右上，右下
    PrepareDingWei();
    DrawDingWei(1, 1, 0, 0);
    DrawDingWei(1, 0, 0, 13);
    DrawDingWei(0, 1, 13, 0);


    // 开始画背景中的掩码
    {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 15; j++) {
                vis[bluePos[i][j][0]][bluePos[i][j][1]] = 1;
                mat[bluePos[i][j][0]][bluePos[i][j][1]] = blue[j] - '0';
            }
        }
        for (int i = 8; i <= 12; i++) {
            mat[6][i] = !((i + 6) & 1);
            vis[6][i] = 1;
            mat[i][6] = !((i + 6) & 1);
            vis[i][6] = 1;
        }
    }
}


// 查找字符c所对应的权值
int FindIndex(char c) {
    int len = strlen(dict);
    for (int i = 0; i < len; i++) {
        if (dict[i] == c) {
            return i;
        }
    }
    return -1;
}

// 得到数值num所对应的len长度的二进制编码
char *GetLenBinString(int num, int len) {
    char *rtn = (char *) malloc(len);
    rtn[len] = '\0';
    int idx = len - 1;
    while (idx >= 0) {
        rtn[idx] = (num % 2) + '0';
        num /= 2;
        idx--;
    }
    return rtn;
}

// 得到数据的数据码 数据码 + 补码
void GetDataCode(char *text) {
    int len = strlen(text);
    char headCode[14] = "0010";
    char *textLen = GetLenBinString(strlen(text), 9);
    strcat(headCode, textLen);
    strcat(dataCode, headCode);
    for (int i = 0; i < len - 1; i += 2) {
        char *result = GetLenBinString(FindIndex(text[i]) * 45 + FindIndex(text[i + 1]), 11);
        strcat(dataCode, result);
        free(result);
    }
    if (len & 1) {
        char *result = GetLenBinString(FindIndex(text[len - 1]), 6);
        strcat(dataCode, result);
        free(result);
    }
    if (DATACODE_SIZE - strlen(dataCode) >= 4) {
        strcat(dataCode, "0000");
    }
    int currentLen = strlen(dataCode);
    while (currentLen % 8 != 0) {
        strcat(dataCode, "0");
        currentLen++;
    }
    char appendCode1[9] = "11101100";
    char appendCode2[9] = "00010001";
    while (currentLen < 128) {
        strcat(dataCode, appendCode1);
        currentLen += 8;
        if (currentLen < 128) {
            strcat(dataCode, appendCode2);
            currentLen += 8;
        }
    }
}

void PrepareGF256() {
    GF256[0] = 1;
    RGF256[1] = 0;
    for (int i = 1; i < GF_SIZE; i++) {
        GF256[i] = GF256[i - 1] * 2;
        if (GF256[i] > 255) {
            GF256[i] = (GF256[i] ^ 285);
        }
        RGF256[GF256[i]] = i;
    }
}

// Reed-Solomon纠错码 “HELLO WORLD” -> 196  35  39  119  235  215  231  226  93  23
// 算法细节参考: https://www.thonky.com/qr-code-tutorial/error-correction-coding
void GetErrorCode() {
    int infoPolyCoefficient[30];
    for (int i = 0; i <= 25; i++) {
        infoPolyCoefficient[i] = 0;
    }
    for (int i = 0; i < strlen(dataCode); i += 8) {
        int num = 0;
        for (int j = i; j < i + 8; j++) {
            num = num * 2 + (int) (dataCode[j] - '0');
        }
        infoPolyCoefficient[i / 8] = num;
    }
    int GenPolyCoefficient[15];
    for (int i = 0; i <= 10; i++) {
        GenPolyCoefficient[i] = codePoly[i];
    }
    for (int i = 0; i < 16; i++) {
        int mul = RGF256[infoPolyCoefficient[i]];
        for (int j = i; j <= i + 10; j++) {
            infoPolyCoefficient[j] = (infoPolyCoefficient[j] ^ GF256[(GenPolyCoefficient[j - i] + mul) % 255]);
        }
    }
    for (int j = 0; j < 10; j++) {
        errorCodeNum[j] = infoPolyCoefficient[j + 16];
    }

    if (DEBUG) {
        for (int i = 0; i < 10; i ++) {
            printf("%d ",errorCodeNum[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        char *result = GetLenBinString(errorCodeNum[i], 8);
        strcat(errorCodeChar, result);
        free(result);
    }
}

int main(int argc, char **argv) {
    SetConsoleOutputCP(437);
    char *text = argv[1];
    DrawBackground();
    GetDataCode(text);
    PrepareGF256();
    GetErrorCode();
    strcat(dataCode, errorCodeChar);
    if (DEBUG) {
        printf("ErrorCode : %s \n len : %llu \n",dataCode, strlen(errorCodeChar));
        printf("DataCode : %s \n len : %llu \n",dataCode, strlen(dataCode));
    }
    Print();
    return 0;
}
```






```cpp
//#include <iostream>
//#include <fstream>
//#include <bitset>
//#include <string>
//using namespace std;
//
//bitset<64> key;                // 64位密钥
//bitset<48> subKey[16];         // 存放16轮子密钥
//
//// 初始置换表
//int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
//            60, 52, 44, 36, 28, 20, 12, 4,
//            62, 54, 46, 38, 30, 22, 14, 6,
//            64, 56, 48, 40, 32, 24, 16, 8,
//            57, 49, 41, 33, 25, 17, 9,  1,
//            59, 51, 43, 35, 27, 19, 11, 3,
//            61, 53, 45, 37, 29, 21, 13, 5,
//            63, 55, 47, 39, 31, 23, 15, 7};
//
//// 结尾置换表
//int IP_1[] = {40, 8, 48, 16, 56, 24, 64, 32,
//              39, 7, 47, 15, 55, 23, 63, 31,
//              38, 6, 46, 14, 54, 22, 62, 30,
//              37, 5, 45, 13, 53, 21, 61, 29,
//              36, 4, 44, 12, 52, 20, 60, 28,
//              35, 3, 43, 11, 51, 19, 59, 27,
//              34, 2, 42, 10, 50, 18, 58, 26,
//              33, 1, 41,  9, 49, 17, 57, 25};
//
///*------------------下面是生成密钥所用表-----------------*/
//
//// 密钥置换表，将64位密钥变成56位
//int PC_1[] = {57, 49, 41, 33, 25, 17, 9,
//              1, 58, 50, 42, 34, 26, 18,
//              10,  2, 59, 51, 43, 35, 27,
//              19, 11,  3, 60, 52, 44, 36,
//              63, 55, 47, 39, 31, 23, 15,
//              7, 62, 54, 46, 38, 30, 22,
//              14,  6, 61, 53, 45, 37, 29,
//              21, 13,  5, 28, 20, 12,  4};
//
//// 压缩置换，将56位密钥压缩成48位子密钥
//int PC_2[] = {14, 17, 11, 24,  1,  5,
//              3, 28, 15,  6, 21, 10,
//              23, 19, 12,  4, 26,  8,
//              16,  7, 27, 20, 13,  2,
//              41, 52, 31, 37, 47, 55,
//              30, 40, 51, 45, 33, 48,
//              44, 49, 39, 56, 34, 53,
//              46, 42, 50, 36, 29, 32};
//
//// 每轮左移的位数
//int shiftBits[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
//
///*------------------下面是密码函数 f 所用表-----------------*/
//
//// 扩展置换表，将 32位 扩展至 48位
//int E[] = {32,  1,  2,  3,  4,  5,
//           4,  5,  6,  7,  8,  9,
//           8,  9, 10, 11, 12, 13,
//           12, 13, 14, 15, 16, 17,
//           16, 17, 18, 19, 20, 21,
//           20, 21, 22, 23, 24, 25,
//           24, 25, 26, 27, 28, 29,
//           28, 29, 30, 31, 32,  1};
//
//// S盒，每个S盒是4x16的置换表，6位 -> 4位
//int S_BOX[8][4][16] = {
//        {
//                {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
//                {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
//                {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
//                {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
//        },
//        {
//                {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
//                {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
//                {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
//                {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
//        },
//        {
//                {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
//                {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
//                {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
//                {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
//        },
//        {
//                {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
//                {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
//                {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
//                {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
//        },
//        {
//                {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
//                {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
//                {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
//                {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
//        },
//        {
//                {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
//                {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
//                {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
//                {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
//        },
//        {
//                {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
//                {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
//                {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
//                {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
//        },
//        {
//                {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
//                {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
//                {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
//                {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
//        }
//};
//
//// P置换，32位 -> 32位
//int P[] = {16,  7, 20, 21,
//           29, 12, 28, 17,
//           1, 15, 23, 26,
//           5, 18, 31, 10,
//           2,  8, 24, 14,
//           32, 27,  3,  9,
//           19, 13, 30,  6,
//           22, 11,  4, 25 };
//
///**********************************************************************/
///*                                                                    */
///*                            下面是DES算法实现                        */
///*                                                                    */
///**********************************************************************/
//
///**
// *  密码函数f，接收32位数据和48位子密钥，产生一个32位的输出
// */
//bitset<32> f(bitset<32> R, bitset<48> k)
//{
//    bitset<48> expandR;
//    // 第一步：扩展置换，32 -> 48
//    for(int i=0; i<48; ++i)
//        expandR[47-i] = R[32-E[i]];
//    // 第二步：异或
//    expandR = expandR ^ k;
//    // 第三步：查找S_BOX置换表
//    bitset<32> output;
//    int x = 0;
//    for(int i=0; i<48; i=i+6)
//    {
//        int row = expandR[47-i]*2 + expandR[47-i-5];
//        int col = expandR[47-i-1]*8 + expandR[47-i-2]*4 + expandR[47-i-3]*2
//                  + expandR[47-i-4];
//        int num = S_BOX[i/6][row][col];
//        bitset<4> binary(num);
//        output[31-x] = binary[3];
//        output[31-x-1] = binary[2];
//        output[31-x-2] = binary[1];
//        output[31-x-3] = binary[0];
//        x += 4;
//    }
//    // 第四步：P-置换，32 -> 32
//    bitset<32> tmp = output;
//    for(int i=0; i<32; ++i)
//        output[31-i] = tmp[32-P[i]];
//    return output;
//}
//
///**
// *  对56位密钥的前后部分进行左移
// */
//bitset<28> leftShift(bitset<28> k, int shift)
//{
//    bitset<28> tmp = k;
//    for(int i=27; i>=0; --i)
//    {
//        if(i-shift<0)
//            k[i] = tmp[i-shift+28];
//        else
//            k[i] = tmp[i-shift];
//    }
//    return k;
//}
//
///**
// *  生成16个48位的子密钥
// */
//void generateKeys()
//{
//    bitset<56> realKey;
//    bitset<28> left;
//    bitset<28> right;
//    bitset<48> compressKey;
//    // 去掉奇偶标记位，将64位密钥变成56位
//    for (int i=0; i<56; ++i)
//        realKey[55-i] = key[64 - PC_1[i]];
//    // 生成子密钥，保存在 subKeys[16] 中
//    for(int round=0; round<16; ++round)
//    {
//        // 前28位与后28位
//        for(int i=28; i<56; ++i)
//            left[i-28] = realKey[i];
//        for(int i=0; i<28; ++i)
//            right[i] = realKey[i];
//        // 左移
//        left = leftShift(left, shiftBits[round]);
//        right = leftShift(right, shiftBits[round]);
//        // 压缩置换，由56位得到48位子密钥
//        for(int i=28; i<56; ++i)
//            realKey[i] = left[i-28];
//        for(int i=0; i<28; ++i)
//            realKey[i] = right[i];
//        for(int i=0; i<48; ++i)
//            compressKey[47-i] = realKey[56 - PC_2[i]];
//        subKey[round] = compressKey;
//    }
//}
//
///**
// *  工具函数：将char字符数组转为二进制
// */
//bitset<64> charToBitset(const char s[8])
//{
//    bitset<64> bits;
//    for(int i=0; i<8; ++i)
//        for(int j=0; j<8; ++j)
//            bits[i*8+j] = ((s[i]>>j) & 1);
//    return bits;
//}
//
///**
// *  DES加密
// */
//bitset<64> encrypt(bitset<64>& plain)
//{
//    bitset<64> cipher;
//    bitset<64> currentBits;
//    bitset<32> left;
//    bitset<32> right;
//    bitset<32> newLeft;
//    // 第一步：初始置换IP
//    for(int i=0; i<64; ++i)
//        currentBits[63-i] = plain[64-IP[i]];
//    // 第二步：获取 Li 和 Ri
//    for(int i=32; i<64; ++i)
//        left[i-32] = currentBits[i];
//    for(int i=0; i<32; ++i)
//        right[i] = currentBits[i];
//    // 第三步：共16轮迭代
//    for(int round=0; round<16; ++round)
//    {
//        newLeft = right;
//        right = left ^ f(right,subKey[round]);
//        left = newLeft;
//    }
//    // 第四步：合并L16和R16，注意合并为 R16L16
//    for(int i=0; i<32; ++i)
//        cipher[i] = left[i];
//    for(int i=32; i<64; ++i)
//        cipher[i] = right[i-32];
//    // 第五步：结尾置换IP-1
//    currentBits = cipher;
//    for(int i=0; i<64; ++i)
//        cipher[63-i] = currentBits[64-IP_1[i]];
//    // 返回密文
//    return cipher;
//}
//
///**
// *  DES解密
// */
//bitset<64> decrypt(bitset<64>& cipher)
//{
//    bitset<64> plain;
//    bitset<64> currentBits;
//    bitset<32> left;
//    bitset<32> right;
//    bitset<32> newLeft;
//    // 第一步：初始置换IP
//    for(int i=0; i<64; ++i)
//        currentBits[63-i] = cipher[64-IP[i]];
//    // 第二步：获取 Li 和 Ri
//    for(int i=32; i<64; ++i)
//        left[i-32] = currentBits[i];
//    for(int i=0; i<32; ++i)
//        right[i] = currentBits[i];
//    // 第三步：共16轮迭代（子密钥逆序应用）
//    for(int round=0; round<16; ++round)
//    {
//        newLeft = right;
//        right = left ^ f(right,subKey[15-round]);
//        left = newLeft;
//    }
//    // 第四步：合并L16和R16，注意合并为 R16L16
//    for(int i=0; i<32; ++i)
//        plain[i] = left[i];
//    for(int i=32; i<64; ++i)
//        plain[i] = right[i-32];
//    // 第五步：结尾置换IP-1
//    currentBits = plain;
//    for(int i=0; i<64; ++i)
//        plain[63-i] = currentBits[64-IP_1[i]];
//    // 返回明文
//    return plain;
//}
//
//
///**********************************************************************/
///* 测试：                                                             */
///*     1.将一个 64 位的字符串加密， 把密文写入文件 a.txt              */
///*     2.读取文件 a.txt 获得 64 位密文，解密之后再写入 b.txt          */
///**********************************************************************/
//
//int main() {
//    string s = "romantic";
//    string k = "12345678";
//    bitset<64> plain = charToBitset(s.c_str());
//    key = charToBitset(k.c_str());
//    // 生成16个子密钥
//    generateKeys();
//    // 密文写入 a.txt
//    bitset<64> cipher = encrypt(plain);
//    fstream file1;
//    file1.open("D://a.txt", ios::binary | ios::out);
//    file1.write((char*)&cipher,sizeof(cipher));
//    file1.close();
//
//    // 读文件 a.txt
//    bitset<64> temp;
//    file1.open("D://a.txt", ios::binary | ios::in);
//    file1.read((char*)&temp, sizeof(temp));
//    file1.close();
//
//    // 解密，并写入文件 b.txt
//    bitset<64> temp_plain = decrypt(temp);
//    file1.open("D://b.txt", ios::binary | ios::out);
//    file1.write((char*)&temp_plain,sizeof(temp_plain));
//    file1.close();
//
//    return 0;
//}

```