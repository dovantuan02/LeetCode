char* longestCommonPrefix(char** strs, int strsSize) {
    

    if (strsSize == 0 || strs == NULL) {
        return (char*) '\0';
    }

    int minSize = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minSize) {
            minSize = len;
        }
    }
    printf("min size=%d\n",minSize );
    static char res[201];
    for (int i = 0; i < minSize; i++) {
        for (int j = 0; j < strsSize - 1; j++) {
            if (strs[j][i] != strs[j + 1][i]) {
                strncpy(res, strs[0], i);
                res[i] = '\0';
                return res;
            }
        }
    }

    strncpy(res, strs[0], minSize);
    res[minSize] = '\0';
    return res;
}