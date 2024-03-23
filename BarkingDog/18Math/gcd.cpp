//유클리드 호제법
//GCD(A,B) = GCD(B,r)
//A를 B에 대해 나눈 나머지를 r

//A*B = GCD(A,B) * LCM(A,B)

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b; //먼저 나누고 곱하는게 굿
}