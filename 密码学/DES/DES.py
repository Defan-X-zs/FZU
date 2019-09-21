#DES by defanive

#压缩选择表1
PC_1 = [ 
  57, 49, 41, 33, 25, 17,  9, 
   1, 58, 50, 42, 34, 26, 18, 
  10,  2, 59, 51, 43, 35, 27,
  19, 11,  3, 60, 52, 44, 36,
  63, 55, 47, 39, 31, 23, 15,
   7, 62, 54, 46, 38, 30, 22,
  14,  6, 61, 53, 45, 37, 29,
  21, 13,  5, 28, 20, 12,  4
]
#压缩选择表2
PC_2 = [ 
  14, 17, 11, 24,  1,  5,
   3, 28, 15,  6, 21, 10,
  23, 19, 12,  4, 26,  8,
  16,  7, 27, 20, 13,  2,
  41, 52, 31, 37, 47, 55,
  30, 40, 51, 45, 33, 48,
  44, 49, 39, 56, 34, 53,
  46, 42, 50, 36, 29, 32
]
#IP置换表
IP_table = [
  58, 50, 42, 34, 26, 18, 10, 2,
  60, 52, 44, 36, 28, 20, 12, 4,
  62, 54, 46, 38, 30, 22, 14, 6,
  64, 56, 48, 40, 32, 24, 16, 8,
  57, 49, 41, 33, 25, 17,  9, 1,
  59, 51, 43, 35, 27, 19, 11, 3,
  61, 53, 45, 37, 29, 21, 13, 5,
  63, 55, 47, 39, 31, 23, 15, 7
]
#逆IP置换表
_IP_table = [
  40,  8, 48, 16, 56, 24, 64, 32,
  39,  7, 47, 15, 55, 23, 63, 31,
  38,  6, 46, 14, 54, 22, 62, 30,
  37,  5, 45, 13, 53, 21, 61, 29,
  36,  4, 44, 12, 52, 20, 60, 28,
  35,  3, 43, 11, 51, 19, 59, 27,
  34,  2, 42, 10, 50, 18, 58, 26,
  33,  1, 41,  9, 49, 17, 57, 25
]
#E拓展置换
Eextend_table = [
  32,  1,  2,  3,  4,  5,
   4,  5,  6,  7,  8,  9,
   8,  9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21,
  20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32,1
]
#S盒中的S1盒
S1 = [
  14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
   0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
   4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
  15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
]
#S盒中的S2盒
S2 = [
  15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
   3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
   0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
  13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
]
#S盒中的S3盒
S3 = [
  10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
]
#S盒中的S4盒
S4 = [
   7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
   3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
]
#S盒中的S5盒
S5 = [
   2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
   14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
   4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
   11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
]
#S盒中的S6盒
S6 = [
  12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
  10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
   9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
   4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
]
#S盒中的S7盒
S7 = [
   4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
  13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
   1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
   6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
]
#S盒中的S8盒
S8 = [
  13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
   1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
   7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
   2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
]
# S盒
S = [S1,S2,S3,S4,S5,S6,S7,S8]
#P盒
P_table = [
  16,  7, 20, 21,
  29, 12, 28, 17,
   1, 15, 23, 26,
   5, 18, 31, 10,
   2,  8, 24, 14,
  32, 27,  3,  9,
  19, 13, 30,  6,
  22, 11,  4, 25
]

def createSubkeys(inkey):
	subkeys=[]
	key0=[0 for i in range(56)]
	key1=[0 for i in range(48)]
	keyinit = inkey[:]
	#print(keyinit)
	for i in range(56):
		key0[i] = keyinit[PC_1[i]-1]
	for i in range(16):
		if(i==0 or i==1 or i==8 or i==15):
			movestep = 1
		else:
			movestep = 2
		C = key0[0:28]
		D = key0[28:56]
		for j in range(movestep):
			tempC = C[1:28]
			tempC.append(C[0])
			tempD = D[1:28]
			tempD.append(D[0]) 
			C = tempC[:]
			D = tempD[:]
		key0 = C + D
		for j in range(48):
			key1[j] = key0[PC_2[j]-1]
		str=''
		tempK = str.join(key1)
		subkeys.append(tempK)
	return subkeys

def IP(intext):
	res=''
	for i in range(64):
		res += intext[IP_table[i]-1]
	return res

def E_expand(R):
	res=''
	for i in range(32):
		res += R[Eextend_table[i]-1]
	return res

def S_substitute(Stext):
	res=''
	index=0
	Stext = bin(Stext)[2:] #转换为二进制
	while len(Stext) < 48:
		Stext = '0' + Stext #将S补上前0
	for Si in S:
		row = int(Stext[index] + Stext[index+5], base = 2)
		col = int(Stext[index + 1 : index + 5], base = 2)
		ret = bin(Si[row*16+col])[2:]
		while len(ret) < 4:
			ret = '0' + ret
		res += ret
		index += 6
	return res

def P(L, S, R):
	res=''
	for i in range(32):
		res += S[P_table[i]-1]
	newR = int(res, base = 2) ^ int(L, base = 2)
	newR = bin(newR)[2:]
	while len(newR) < 32:
		newR = '0' + newR
	newL = R
	return (newL, newR)

def IP_inverse(L, R):
	text = L + R
	res=''
	for i in range(64):
		res += text[_IP_table[i]-1]
	return res

def DES(text, key, option=0):
	subkeys = createSubkeys(key)
	initTrans = IP(text)
	L = initTrans[0:32]
	R = initTrans[32:]
	if (option == 1):
		subkeys = subkeys[::-1]
	for subkey in subkeys:
		while len(L) < 32:
			L = '0' + L
		while len(R) < 32:
			R = '0' + R
		R_expand = E_expand(R)
		S = int(R_expand, base = 2) ^ int(subkey, base = 2)
		S_sub = S_substitute(S)
		(L, R) = P(L, S_sub, R)
	(L, R) = (R, L)
	res = IP_inverse(L, R)
	return res

def byte2bin(s):
	res=''
	for i in range(len(s)):
		temp = bin(ord(s[i])).replace('0b', '')
		while len(temp) < 8:
			temp = '0' + temp
		res += temp
	return res

def bin2byte(s):
	res=''
	for i in range(8):
		ress=[0 for i in range(8)]
		ress[i] = int(s[i*8:i*8+8], 2)
		res += chr(ress[i])
	return res

def bin2hex(s):
	res=''
	for i in range(8):
		ress = int(s[i*8:i*8+8], 2)
		temp = hex(ress).replace('0x', '')
		while len(temp) < 2:
			temp = '0' + temp
		res += temp
	return res

def hex2bin(s):
	res=''
	for i in range(8):
		temp = int(s[i*2:i*2+2], 16)
		ress = bin(temp).replace('0b', '')
		while len(ress) < 8:
			ress = '0' + ress
		res+=ress
	return res

if __name__ == '__main__':
	option = int(input('请选择功能: (0)加密 (1)解密：'))
	if option == 0:
		tmptext = input('请输入8位英文-明文 ：')
		text = byte2bin(tmptext)
		tmpkey = input('请输入8位英文-密钥：')
		key = byte2bin(tmpkey)
		tmpciphertext = DES(text, key, option)
		ciphertext = bin2hex(tmpciphertext)
		print('加密完成-十六进制密文：', ciphertext)
	if option == 1:
		tmptext = input('请输入8位十六进制-密文：')
		text = hex2bin(tmptext)
		tmpkey = input('请输入8位英文-密钥：')
		key = byte2bin(tmpkey)
		tmpcleartext = DES(text, key, option)
		print('解密完成-明文：', bin2byte(tmpcleartext))

#defanive