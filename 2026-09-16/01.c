#include <stdbool.h>

struct triangle {
    int a;
    int b;
    int c;
};

bool is_triangle(int a, int b, int c) {
    if (
        (((long long)a + b) > c) &&
        (((long long)b + c) > a) && 
        (((long long)a + c) > b)
    ) {
        return true;
    }
    else {
        return false;
    }
}



// и - &&
// или - ||
// a= -1 , b=-1, c=-1


int main() {


    int aaaa, bbbb, cccc;
    
    int result = scanf("%d %d %d", &aaaa, &bbbb, &cccc);
    
    if (result != 3) {
        printf("произошла чудовищная ошибка");
        return 1;
    }
    
    printf("%d", is_triangle(aaaa, bbbb, cccc));
}

https://interview.yandex-team.ru/room/KOuMc7Jrrj
