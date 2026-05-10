char* intToRoman(int num) {
    typedef struct {
        int value;
        char *symbol;
    } Roman;

    static Roman roman[13] = {
        {.value = 1, .symbol = "I"},
        {.value = 4, .symbol = "IV"},
        {.value = 5, .symbol = "V"},
        {.value = 9, .symbol = "IX"},
        {.value = 10, .symbol = "X"},
        {.value = 40, .symbol = "XL"},
        {.value = 50, .symbol = "L"},
        {.value = 90, .symbol = "XC"},
        {.value = 100, .symbol = "C"},
        {.value = 400, .symbol = "CD"},
        {.value = 500, .symbol = "D"},
        {.value = 900, .symbol = "CM"},
        {.value = 1000, .symbol = "M"},
    };
    static char res[128];
    res[0] = '\0';
    int i = 13 - 1;
    while (i >= 0) {
        while (num >= roman[i].value) {
            strcat(res, roman[i].symbol);
            num -= roman[i].value;
        }
        i--;
    }
    return res;
}