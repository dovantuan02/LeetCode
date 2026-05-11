int romanToInt(char* s) {
    if (!s || s[0] == '\0') {
        return 0;
    }
    int len = strlen(s) - 1;

    char symbol[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int value[7] = {1000, 500, 100, 50, 10, 5, 1};

    int total = 0;
    int prev = 0;
    while (len >= 0) {
        printf("Char s[%d]=%c\n", len, s[len]);
        for (int i = 6; i >= 0; i--) {
            // printf("symbol=%c", )
            if (s[len] != symbol[i]) {
                continue;
            }

            if (value[i] < prev) {
                total -= prev;
                prev -= value[i];
                total += prev;
            } else {
                total += value[i];
                prev = value[i];
            }
        }

        len--;
    }
    return total;
}