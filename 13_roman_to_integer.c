int romanToInt(char* s)
{
    int num = 0;
    while (*s != '\0') {
        int next_letter = *(s + 1);
        switch (*s) {
        case 'I':
            if (next_letter != 'V' && next_letter != 'X')
                num += 1;
            else
                num -= 1;
            break;
        case 'V':
            num += 5;
            break;
        case 'X':
            if (next_letter != 'L' && next_letter != 'C')
                num += 10;
            else
                num -= 10;
            break;
        case 'L':
            num += 50;
            break;
        case 'C':
            if (next_letter != 'D' && next_letter != 'M')
                num += 100;
            else
                num -= 100;
            break;
        case 'D':
            num += 500;
            break;
        case 'M':
            num += 1000;
            break;
        default:
            break;
        }
        s++;
    }
    return num;
}
