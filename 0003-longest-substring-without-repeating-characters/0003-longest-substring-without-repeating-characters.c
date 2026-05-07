#define DEF_MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    if (!s || !*s) {
        return 0;
    }

    int arrayASCI[128];
    for (int i = 0; i < 128; i++) {
        arrayASCI[i] = -1;
    }

    int begin = 0;
    int ret = 0;

    for (int i = 0; s[i]; i++) {
        begin = DEF_MAX(begin, arrayASCI[(unsigned char)s[i]] + 1);
        ret = DEF_MAX(ret, i - begin + 1);
        arrayASCI[(unsigned char)s[i]] = i;
    }

    return ret;
}