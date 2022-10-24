#include <stdio.h>

int move();
int field(int right, int down, int up, int left, int centr, int point_l, int point_r,
          int lrock_pos, int rrock_pos, int ball_x, int ball_y);

int main() {
    printf("Игра началась!\n");
    move();
    return 0;
}

int move() {
    int right = 81;     // правая граница поля - на ней рисуются звездочки
    int down = 26;      // нижняя граница поля - на ней рисуются звездочки
    int up = 0;         // верхняя граница поля - на ней рисуются звездочки
    int left = 0;       // левая граница поля - на ней рисуются звездочки
    int centr = 40;     // центр поля - на ней рисуются вертикальные палки
    int point_l = 0;    // количество очков левого игрока
    int point_r = 0;    // количество очков правого игрока
    int lrock_pos = 13;     // начальная позиция левой ракетки по оси Y.
    int rrock_pos = 13;     // начальная позиция правой ракетки по оси Y.
    int ball_x = right / 2;     // начальная позиция мяча по оси Х
    int ball_y = down / 2;  // начальная позиция мяча по оси Y
    int ball_x_prev = ball_x - 1;   // в переменной хранится позиция мяча предыдущего хода
                                    // (исходя из этой позиции определяется направление движение мяча)
    int ball_y_prev = ball_y - 1;   // в переменной хранится позиция мяча предыдущего хода
                                    // (исходя из этой позиции определяется направление движение мяча)
    int maxpoint = 21;
    while (point_l <= maxpoint || point_r <= maxpoint) {
        while (1 > 0) {
            field(right, down, up, left, centr, point_l, point_r, lrock_pos, rrock_pos, ball_x, ball_y);
            char ch;
            scanf("%c", &ch);
     // в зависимости от нажатой клавиши происходит движение ракеток(lrock_pos и rrock_pos)
            if (ch == 'a') {
                lrock_pos--;
            } else if (ch == 'z') {
                lrock_pos++;
            } else if (ch == 'k') {
                rrock_pos--;
            } else if (ch == 'm') {
                rrock_pos++;
            }
    // если ракетки упираются вверх или вниз то дальше двигаться не могут
            if (lrock_pos < up + 2)
                lrock_pos = up + 2;
            if (lrock_pos > down - 2)
                lrock_pos = down - 2;
            if (rrock_pos < up + 2)
                rrock_pos = up + 2;
            if (rrock_pos > down - 2)
                rrock_pos = down - 2;
    // движение мяча
            if (ch == 'a' || ch == 'z' || ch == 'k' || ch == 'm' || ch == ' ') {
                if (ball_x_prev < ball_x) {     // если предыдущая позиция мяча по оси Х левее настоящей
                                                // - двигаем вправо и обновляем текущую и предыдущую позиции
                    ball_x++;
                    ball_x_prev = ball_x - 1;
                } else {                        // если предыдущая позиция мяча по оси Х правее настоящей
                                                // - двигаем влево и обновляем текущую и предыдущую позиции
                    ball_x--;
                    ball_x_prev = ball_x + 1;
                }
                if (ball_y_prev < ball_y) {     // если предыдущая позиция мяча по оси Y выше настоящей
                                            // - двигаем вниз и обновляем текущую и предыдущую позиции
                    ball_y++;
                    ball_y_prev = ball_y - 1;
                } else {                // если предыдущая позиция мяча по оси Y ниже настоящей
                                        // - двигаем вверх и обновляем текущую и предыдущую позиции
                    ball_y--;
                    ball_y_prev = ball_y + 1;
                }
            }
            // если шар выходит за пределы верхнего или нижнего предела то меняем направление движения
            if (ball_y <= up) {
                ball_y = ball_y + 2;
                ball_y_prev = ball_y - 1;
            } else if (ball_y >= down) {
                ball_y = ball_y - 2;
                ball_y_prev = ball_y + 1;
            }
            // если шар по Y на уровне ракетки и находится на второй столбце слева то меняем направление
            if ((ball_y == lrock_pos + 1 || ball_y == lrock_pos - 1 || ball_y == lrock_pos)
                && ball_x == left + 2) {
                ball_x = ball_x + 2;
                ball_x_prev = ball_x - 1;
                // если шар по Y на уровне ракетки и находится на втором столбце справа то меняем направление
            } else if ((ball_y == rrock_pos + 1 || ball_y == rrock_pos - 1 || ball_y == rrock_pos)
                       && ball_x == right - 2) {
                ball_x = ball_x - 2;;
                ball_x_prev = ball_x + 1;
            } else if (ball_x == left + 1) {
                point_l++;
                ball_x = right / 2;     // начальная позиция мяча по оси Х
                ball_y = down / 2;      // начальная позиция мяча по оси Y
                ball_x_prev = ball_x - 1;   // в переменной хранится позиция мяча предыдущего хода
                ball_y_prev = ball_y - 1;   // в переменной хранится позиция мяча предыдущего хода
                break;
            } else if (ball_x == right - 1) {
                point_r++;
                ball_x = right / 2;     // начальная позиция мяча по оси Х
                ball_y = down / 2;      // начальная позиция мяча по оси Y
                ball_x_prev = ball_x - 1;   // в переменной хранится позиция мяча предыдущего хода
                                            // (исходя из этой позиции определяется направление движение мяча)
                ball_y_prev = ball_y - 1;   // в переменной хранится позиция мяча предыдущего хода
                                            // (исходя из этой позиции определяется направление движение мяча)
                break;
            }
        }
        if (point_l == maxpoint) {
            printf("Поздравляем! Победил левый игрок");
            break;
        } else if (point_r == maxpoint) {
            printf("Поздравляем! Победил правый игрок игрок");
            break;
        }
    }
    return 0;
}

int field(int right, int down, int up, int left, int centr, int point_l, int point_r, int lrock_pos,
          int rrock_pos, int ball_x, int ball_y) {
    for (int i = up; i <= down; i++) {
        for (int j = left; j <= right; j++) {
            if (i == up || i == down || j == left || j == right) {
                printf("*");
            } else if (j == 1 && (i == lrock_pos || i == lrock_pos + 1 || i == lrock_pos - 1)) {
                printf("x");
            } else if (j == 80 && (i == rrock_pos || i == rrock_pos + 1 || i == rrock_pos - 1)) {
                printf("x");
            } else if (j == centr && (i !=  up || i != down)) {
                if (j == ball_x && i == ball_y) {
                    printf("O");
                } else {
                    printf("|");
                }
            } else if (j == ball_x && i == ball_y) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("points        %d______________________________________________%d\n", point_l, point_r);
    return 0;
}
