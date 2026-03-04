int numeral_value (char s)
{
	switch (s) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int romanToInt(char* s)
{
    int num = 0;
	int cur = numeral_value(*s);
    while (*s != '\0') {
		int next = numeral_value(*(++s));
		if (cur >= next)
			num += cur;
		else
			num -= cur;
		cur = next;
    }
    return num;
}
