bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int tmp = x;
    int reverse_number = 0;
    while (tmp != 0) {
        int digit = tmp % 10;
        
        if (reverse_number > (INT_MAX / 10)) {
            return false;
        }
        reverse_number = reverse_number * 10 + digit;
        
        tmp = tmp / 10;
    }
    printf("reverse_number %d\n", reverse_number);
    // reverse number
    return ((x - reverse_number) == 0);
}