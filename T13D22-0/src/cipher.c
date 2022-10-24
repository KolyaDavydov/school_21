// "Copyright [year] <Copyright Owner>"
#include <stdio.h>
#include <stdlib.h>

void read(char nameFile[1000]);
void write(char nameFile[1000]);
void shifr();


int main() {
    int num = 0;
    int flagError = 0;
    char nameFile[1000];     // для хранения имени файла
    while (flagError == 0) {
        scanf("%d", &num);
        if (num == 1) {
            read(nameFile);
        } else if (num == 2) {
            write(nameFile);
        } else if (num == 3) {
            shifr();
        } else if (num == -1) {
            exit(0);
        } else {
            flagError = 1;
        }
        if (flagError == 1)
            printf("n/a");
        printf("\n");
    }
    return 0;
}

void read(char nameFile[1000]) {
    char contentOfFile[1000];   // для хранения тектста файла
    scanf("%s", nameFile);  //  сканируем имя файла
    FILE *file;
    if ((file = fopen(nameFile, "r")) == NULL) {
        printf("n/a");
    } else {
        // проверка на пустоту файла
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (pos == 0) {
            printf("n/a");
        } else {
            fseek(file, 0, SEEK_SET);   //  устанавливаем ридер в начало файла
            while (!feof(file)) {
                if (fgets(contentOfFile, 1000, file) != NULL) {
                    printf("%s", contentOfFile);
                }
            }
        }
    }
    fclose(file);
}


void write(char nameFile[1000]) {
    char contentOfFile[1000];   // для хранения тектста в файл
    char ch;
    scanf("%c", &ch);
    fgets(contentOfFile, 999, stdin);
    FILE *file;
    if ((file = fopen(nameFile, "r")) != NULL) {
    file = fopen(nameFile, "a");
    fprintf(file, "%s", contentOfFile);
    fclose(file);
    file = fopen(nameFile, "r");
    while (!feof(file)) {
                if (fgets(contentOfFile, 1000, file) != NULL) {
                    printf("%s", contentOfFile);
                }
            }
    fclose(file);
    } else {
        printf("n/a");
    }
}


void shifr() {
    int shift;
    scanf("%d", &shift);
    FILE *fileIn, *fileOut;
    fileIn = fopen("test.c", "r");
    fileOut = fopen("test2.c", "w");
    int flag;
    char c;
    c = getc(fileIn);
    while (!feof(fileIn)) {  //  пока не конец файла
        flag = 0;
        if (c >= 'A' && c <= 'Z') {
            c = c + shift;
            if (c > 'Z')
                c = 'A' + (c - 'Z') - 1;
            fprintf(fileOut, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            c = c + shift;
            if (c > 'z')
                c = 'a' + (c - 'z') - 1;
            fprintf(fileOut, "%c", c);
            flag = 1;
        }
        if (!flag)
            fprintf(fileOut, "%c", c);
        c = getc(fileIn);
    }
    fclose(fileIn);
    fclose(fileOut);
}
