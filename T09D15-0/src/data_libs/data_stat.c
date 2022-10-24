#include "data_stat.h"


double max(double *data, int n) {
    double num = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > num) {
            num = data[i];
        }
    }
    return num;
}

double min(double *data, int n) {
    double num = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < num) {
            num = data[i];
        }
    }
    return num;
}

double mean(double *data, int n) {
    double m = 0.0f;
    double num = (double) n;    // переводим инт в дабл

    for (int i = 0; i < n; i++) {
        m = m + data[i] * (1 / num);
    }
    return m;
}

double variance(double *data, int n) {
    double var = 0.0f;
    double num = (double) n;    // переводим инт в дабл
    for (int i = 0; i < n; i++) {
        var = var + (1 / num * (data[i] - mean(data, n)) * (data[i] - mean(data, n)));
    }
    return var;
}

void sort(double *data, int n) {
    for (int i = 1; i < n; i++) {
        int k = i;
        while (k > 0 && data[k - 1] > data[k]) {
            double tmp = data[k - 1];
            data[k - 1] = data[k];
            data[k] = tmp;
            k--;
        }
    }
}
