#include <stdio.h>

int coder() {
    printf("Введите символы через пробел: ");
    int a;
    do {
        scanf("%d", &a);
        a = getchar();
        printf("%X ", a);
    } while (a != '\n');
    return 0;
}

int decoder() {
    printf("Введите шестнадцатиричные числа через пробел: ");
    int a;
    do {
        scanf("%X", &a);
        putchar(a);
        printf(" ");
    } while (a != '\n');
    return 0;
}

int main() {
    printf("Введите 0 - для кодирование символов, и 1 - для декодирования чисел: ");
    int num;
    scanf("%d", &num);
    if (num == 0) {
        coder();
    } else if (num == 1) {
        decoder();
    } else {
        printf("n/a");
        return 0;
    }
    return 0;
}
