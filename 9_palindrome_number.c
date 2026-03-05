bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int len = 1;
    int left_mask = 1;
	while ((x / 10) / left_mask) {
		len++;
		left_mask *= 10;
	}

    for (int i = 0; i < len / 2; i++) {
        if ((x / left_mask) % 10 != x % 10)
            return false;
        x /= 10;
		left_mask /= 100;
    }
    return true;
}
