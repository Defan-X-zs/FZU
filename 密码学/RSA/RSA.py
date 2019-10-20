#RSA by defanive
import random
#米勒罗宾概率素性检测
def miller_rabin_test(n):
	p = n - 1
	r = 0
	while p % 2 == 0:#最后得到为奇数的p(即m)
		r += 1
		p /= 2
	b = random.randint(2, n - 2)#随机取b=(0,n)
	#如果情况1 b得p次方与1同余mod n
	if fastExpMod(b, int(p), n) == 1:
		return True
	#情况2 b的(2^r *p)次方与-1 (n-1)同余mod n
	for i in range(0,7):#检验六次
		if fastExpMod(b, (2 ** i) * p, n) == n - 1:
			return True
	return False
#随机生成大素数
def create_prime_num(minlen, maxlen):
	while True:
		n = random.randint(2**minlen, 2**maxlen)
		if n % 2 != 0:
			found = True
			# 如果经过10次素性检测，那么很大概率上，这个数就是素数
			for i in range(0, 10):
				if miller_rabin_test(n):
					pass
				else:
					found = False
					break
			if found:
				return n
#欧几里得算法
def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)
#扩展欧几里得算法
def ext_gcd(a, b):
	if b == 0:
		x1 = 1
		y1 = 0
		x = x1
		y = y1
		r = a
		return r, x, y
	else:
		r, x1, y1 = ext_gcd(b, a % b)
		x = y1
		y = x1 - a // b * y1
		return r, x, y
#快速幂模算法
def fastExpMod(b, e, m):
	result = 1
	e = int(e)
	while e != 0:
		if e % 2 != 0:#按位与
			e -= 1
			result = (result * b) % m
			continue
		e >>= 1
		b = (b * b) % m
	return result
#生成密钥
def createkey(p, q):
	n = p*q
	fn = (p-1)*(q-1)
	e = selectE(fn)
	d = findD(e, fn)
	return (n, e, d)
#确定E
def selectE(fn):
	while True:
		e = random.randint(0, fn)
		if gcd(e, fn) == 1:
			return e
#确定D
def findD(e, fn):
	d = 0
	r, x, y = ext_gcd(e, fn)
	d = x
	if d < 0:
		d = d + fn
	return d
#加密
def encrypt(m, e, n):
	c = fastExpMod(m, e, n)
	return c
#解密
def decrypt(c, d, n):
	m = fastExpMod(c, d, n)
	return m
#main函数
if __name__ == "__main__":
	minlen, maxlen = map(int, input('请输入p q的长度(bit)范围(最大支持60bit)(空格隔开):').split())
	print('p q长度:'+str(minlen)+'bit-'+str(maxlen)+'bit')
	p = create_prime_num(minlen, maxlen)
	q = create_prime_num(minlen, maxlen)
	print('p:',p,'q:',q)
	n, e, d = createkey(p, q)
	print('n:', n)
	print('e:', e)
	print('d:', d)
	print('请输入长度不超过'+str(len(str(n)))+'位的明文(数字):')
	cleartext = int(input())
	print('输入的s明文为:', cleartext)
	cipher = encrypt(cleartext, e, n)
	print('加密完成-密文为:', cipher)
	message = decrypt(cipher, d, n)
	print('解密完成-明文为:', message)
	print('See You ~~')
#defanive