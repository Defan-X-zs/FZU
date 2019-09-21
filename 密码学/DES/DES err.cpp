#include <iostream>
using namespace std;

bool Bit_Key[64];    //64λ��ʼ��Կ
bool Round_Key[16][48];    //16������Կ��ÿ������Կ��48λ,ÿλΪ0/1
void DES_Key(char Char_Key[8]);  //����Կ���ɺ���
void RotateL(bool *Input,int len);    //ѭ������
void Transform(bool *Output, bool *Input, const int *Table, int Tablelen);    //ת��
void Xor(bool *InputA, const bool *InputB, int len);   //���                 
void Des_Run(char *Mingwen, char *DES_Key);   //���ļ����㷨
void F_func(bool *R, bool *Key);    //F����
void S_func(bool *Output, bool *Input);    //S����
void ShowInHex(const bool Input[64]);    //��������ʾΪ16����
void CharToBit(bool *Output, const char *Input);   // �ֽ���ת����λ��
//�û�IP��
const static int IP_Table[64] = {
    58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
};
//���û�IP-1��
const static int IPR_Table[64] = {
    40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25
};
//Eλѡ���(��չ�û���)
static const int E_Table[48] = {
    32,1,2,3,4,5,4,5,6,7,8,9,
    8,9,10,11,12,13,12,13,14,15,16,17,
    16,17,18,19,20,21,20,21,22,23,24,25,
    24,25,26,27,28,29,28,29,30,31,32,1
};
//P��λ��(������λ��)
const static int P_Table[32] = {
    16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25
};
//PC1ѡλ��(��Կ�����û���1)
const static int PC1_Table[56] = {
    57,49,41,33,25,17,9,1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,21,13,5,28,20,12,4
};
//PC2ѡλ��(��Կ�����û���2)
const static int PC2_Table[48] = {
    14,17,11,24,1,5,3,28,15,6,21,10,
    23,19,12,4,26,8,16,7,27,20,13,2,
    41,52,31,37,47,55,30,40,51,45,33,48,
    44,49,39,56,34,53,46,42,50,36,29,32
};
//����λ���� 
const static int LOOP_Table[16] = {
    1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
};
// S��
const static int S_Box[8][4][16] = {
    // S1 
    14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
    0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
    4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
    15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13,
    //S2
    15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
    3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
    0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
    13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9,
    //S3
    10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
    13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
    13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12,
    //S4
    7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
    13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
    10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
    3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14,
    //S5
    2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
    14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
    4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
    11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,
    //S6
    12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
    10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
    9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
    4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13,
    //S7
    4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
    13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
    1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
    6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12,
    //S8
    13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
    1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
    7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
    2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};

int main() {
    //******************Input*********************
    char Char_Key[9] = {0,};
    char Input_Key[9] = {0,};
    cout << "plz input Char_Key[8]" << endl;
    cin >> Input_Key;
    char Char_Mingwen[9] = { 0, };
    cout << "plz input Char_Mingwen[8]" << endl;
    cin >> Char_Mingwen;
    //******************Input********************
    Des_Run(Char_Mingwen, Input_Key);
    return 0;
}

void DES_Key(char Char_Key[8]) {
    //��char���͵�����ת��ΪBit��ʽ
    CharToBit(Bit_Key, Char_Key);
    //�û�ѡ��1
    Transform(Bit_Key, Bit_Key, PC1_Table, 56);
    bool *C0 = &Bit_Key[0];  //0~27
    bool *D0 = &Bit_Key[28]; //28~55
    for (int i = 0; i < 16; i++) {
        RotateL(C0, LOOP_Table[i]);
        RotateL(D0, LOOP_Table[i]);
        Transform(Round_Key[i], Bit_Key, PC2_Table, 48);
    }
}

void Xor(bool *InputA, const bool *InputB, int len) {
    for (int i = 0; i < len; i++) {
        InputA[i] = InputA[i] ^ InputB[i];
    }
}

void CharToBit(bool *Output, const char *Input) {
    for (int i = 0; i<64; i++) {
        Output[i] = (Input[i / 8] << (i % 8)) & 0x80;
    }
}

void Transform(bool *Output, bool *Input, const int *Table, int Tablelen) {
    bool temp[256];
    for (int i = 0; i < Tablelen; i++) {
        temp[i] = Input[Table[i] - 1];
    }
    memcpy(Output, temp, Tablelen);
}

void RotateL(bool *Input, int len) {
    bool temp[28];
    memcpy(temp, &Input[len], 28 - len);
    memcpy(&temp[28 - len], Input, len);
    memcpy(Input, temp, 28);
}

void S_func(bool *Output, bool *Input) {
    for (int i = 0; i < 8; i++) {
        int row = 2 * Input[6*i] + 1 * Input[6 * i+5];
        int col = 8 * Input[6*i+1] + 4 * Input[6 * i+2] + 2 * Input[6 * i+3] + 1 * Input[6 * i+4];
        int s_result = S_Box[i][row][col];
        for (int j = 0; j < 4; j++) {
            Output[4*i+j] = (s_result << j) & 0x8;
        }
    }
}

void F_func(bool *R, bool *Key) {
    bool Ex_R[48];
    //��չ�û�
    Transform(Ex_R, R, E_Table, 48);
    Xor(Ex_R, Key, 48);
    S_func(R, Ex_R);
    Transform(R, R, P_Table, 32);
}

void Des_Run(char *Mingwen, char *DES_Key) {
    bool Bit_Mingwen[64];
    CharToBit(Bit_Mingwen, Mingwen);
    //�û�IP
    Transform(Bit_Mingwen, Bit_Mingwen, IP_Table, 64);
    bool *L0 = &Bit_Mingwen[0];
    bool *R0 = &Bit_Mingwen[32];
    //16�ֵ���
    for (int i = 0; i < 16; i++) {
        bool temp[32];
        memcpy(temp, R0, 32);
        F_func(R0, Round_Key[i]);
        Xor(R0, L0, 32);
        memcpy(L0, temp, 32);
    }
    bool temp[32];
    memcpy(temp, R0, 32);
    memcpy(R0, L0, 32);
    memcpy(L0, temp, 32);
    Transform(Bit_Mingwen, Bit_Mingwen, IPR_Table, 64);
    ShowInHex(Bit_Mingwen);
}

void ShowInHex(const bool Input[64]) {
    unsigned int Hex[16] = { 0 };
    for (int i = 0; i<16; i++) {
        Hex[i] = 8 * Input[0 + i * 4] + 4 * Input[1 + i * 4] + 2 * Input[2 + i * 4] + 1 * Input[3 + i * 4];
    }
    for (int i = 0; i<16; i++) {
        cout << hex << Hex[i];
    }
    cout << endl;
}



