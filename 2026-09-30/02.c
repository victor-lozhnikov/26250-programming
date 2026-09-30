"abc4d56e" -> 3

int countDigits(const char *str) {
    // for (int i = 0; str[i] != '\0'; ++i) {

    // }

    int i = 0;
    int c = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9'){
            c++;
        }
        i++;
    }
    return c;
}
