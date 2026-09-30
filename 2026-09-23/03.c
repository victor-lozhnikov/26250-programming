// найти максимальное произведение пары чисел из массива
#include <math.h>

long long max(long long a, long long b){
    if (a >= b){
        return a;
    }
    else{
        return b;
    }
}

long long max_prod(int *a, int n) {
    if (n < 2) {
        printf("Error");
        return 0;
    }
    int mx1 = a[0], mx2 = a[1];
    for(int i = 1; i < n; i++){
        if (a[i] > mx1){
            mx2 = mx1;
            mx1 = a[i];
        }
        else if (a[i] > mx2){
            mx2 = a[i];
        }
    }
    int mn1 = a[0], mn2 = a[1];
    for(int i = 1; i < n; i++){
        if (a[i] < mn1){
            mn2 = mn1;
            mn1 = a[i];
        }
        else if (a[i] < mn2){
            mn2 = a[i];
        }
    }
    return max((long long)mx1*mx2, (long long)mn1*mn2);
}
