int myAtoi(char* s) {
    if (!s) {
        return 0;
    }
    int num = strlen(s);
    printf("Length string: %d\n", num);
    int i = 0;
    while (i < num && s[i] == ' ') {
        i++; // clear space
    }
    char sign = 1; // +
    if (s[i] == '-' || s[i] == '+' ) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    long total = 0;
    for (;i < num; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            total = total * 10 + digit;
            if (total > (INT_MAX)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            printf("Loop %d, %c, t=%d\n", i, s[i], total);
        }
        else {
            goto RET;
        }
    }
    RET:
    return total*sign;
}