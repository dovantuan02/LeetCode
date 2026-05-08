int reverse(int x){
    int ret = 0;
    while (x != 0) {
        int digit = x % 10;
        if (ret > (INT_MAX / 10) || ret < (INT_MIN / 10)) {
            return 0;
        }
        ret = ret * 10 + digit;
        x = x / 10;
    }
    return ret;
}