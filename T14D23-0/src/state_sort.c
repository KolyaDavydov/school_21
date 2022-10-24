#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void keyMenu();     // Выбор пункта меню
int readFile(char* fileName);   // чтение бинерного файла в консоль
int writeToFile(char* fileName, int* arr);  // запись в конец файла


int main() {
    keyMenu();
    return 0;
}

void keyMenu() {
    char* fileName;     //  Для хранения имени файла
    int button;   //  для занесения кнопки меню
    int flag = 1;
    // создаем динамический массив размером 50 символов
    fileName = (char*)malloc(50 * sizeof(char));
    // записываем в массив имя файла из стандартного потока ввода
    fgets(fileName, 50, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    scanf("%d", &button);
    if (button == 0) {
        readFile(fileName);
    } else if (button == 1) {
        readFile(fileName);
    } else if (button == 2) {
        int inArr[8];   // Для хранения чисел в строке бинерного файла
        for (int i = 0; i < 8 && flag; i++) {
            if (scanf("%d", &inArr[i]) != 1)
                flag = 0;
        }
        if (flag == 1) {
            writeToFile(fileName, inArr);
            readFile(fileName);
        }
    } else {
        flag = 0;
    }
    if (flag == 0) {
        printf("n/a");
    }
    free(fileName);
}

int readFile(char* fileName) {
    FILE* fp;
    int flag, inFlag;
    flag = 1; inFlag = 0;
    if ((fp = fopen(fileName, "rb")) == NULL) {
        flag = 0;
    }
    if (flag == 1) {
        int number;
        int i = 0;
        while (!feof(fp) && !ferror(fp)) {
            inFlag = 1;
            if (fread(&number, sizeof(int), 1, fp) == 1) {
                printf("%d", number);
                if (i % 8 != 7) printf(" ");
                if (i % 8 == 7) printf("\n");
                i++;
            }
        }
    }
    if (inFlag == 0 || flag == 0)
        printf("n/a");
    fclose(fp);
    return flag;
}

int writeToFile(char* fileName, int* arr) {
    FILE* fp;
    int flag;
    flag = 1;
    if ((fp = fopen(fileName, "ab")) == NULL) {
        printf("n/a");
        flag = 0;
    }
    if (flag == 1) {
        for (int i = 0; i < 8; i++) {
            fwrite(&arr[i], sizeof(int), 1, fp);
        }
    }
    if (fp) fclose(fp);
    return flag;
}

