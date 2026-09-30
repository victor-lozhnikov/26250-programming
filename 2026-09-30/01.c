// реализовать программу, которая читает квадратную матрицу и выполняет её поворот на 90 градусов

#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void transpose(int n, int (*a)[n]) {
    /*
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n; j++) {
            tmp = a[i][j];
            a[i][j] = a[i][n-1-j];
            a[i][n-1-j] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[n-1-i][j];
            a[n-1-i][j] = tmp;

            swap(&a[i][j], &a[i][n-1-j]);
            swap(&a[i][j], &a[n-1-i][n-1-j]);
            swap(&a[i][j], &a[n-1-i][j]);
        }
    }
    */
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            swap(&a[i][j], &a[j][i]);
        }
    }
}


void reverse(int n, int a[][n]) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(&a[i][j], &a[i][n-1-j]);
        }
    }  
}


void rotate(int n, int a[][n]) {
    transpose(n, a);
    reverse(n, a);
}


int main() {
    int n;
    scanf("%d", &n);
    int m[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &m[i][j]);
        
        }
    }
    rotate(n, m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
