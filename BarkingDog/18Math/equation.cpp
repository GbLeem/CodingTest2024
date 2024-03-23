//연립합동방정식

//6으로 나눈 나머지가 3
//5로 나눈 나머지가 2
//30명 이하의 수

int f()
{
	for (int i = 0; i < 30; ++i)
	{
		if (i % 6 == 3 && i % 5 == 2)
			return i;
	}
	return -1;
}

int f2()
{
	for (int i = 3; i < 30; i+=6) //6으로 나눈 나머지가 3인 수들 -> 3에서 시작해서 6씩 더하기
	{
		if (i % 5 == 2)
			return i;
	}
	return -1;
}