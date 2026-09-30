int isPalindrome(const char *str) {
    int l = strlen(str);
    bool flag = true;
    for (int i = 0; i < l / 2; i++ ){
        if (str[i] == str[l - 1 - i]){
            flag = true;
        }
        else{
            return false;
        }
    }
    return flag;
}
