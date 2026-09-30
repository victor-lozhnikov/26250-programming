// Первый неповторяющийся символ. Найти первый слева символ строки str,
// который встречается в ней ровно один раз.
// Вернуть его индекс, считая с нуля, или -1, если такого символа нет.
// Строка состоит из строчных латинских букв.

int firstUniqueChar(const char *str) {
    int size = strlen(str);
    bool isRepeatSymbol = false;
    for (int i=0; i < size; i++) {
        isRepeatSymbol = false;
        for (int j=0; j<size, j++) {
            if (j == i) {
                continue;
            }
            if (str[i] == str[j]) {
                isRepeatSymbol = true;
            }
        }
        if (!isRepeatSymbol) {
            return i;
        }
    }
    return -1;
}


int firstUniqueChar(const char *str){
    char alf[26] = {0};

    memset(alf, 0, 26);

    int size = strlen(str);
    if (size == 0) { return -1; }
    for (int i = 0; i < size; i++){
        if (alf[str[i] - 'a'] <= 2){
            alf[str[i] - 'a']++;
        }
    }
    for (int i = 0; i < size; i++){
        if (alf[str[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}
