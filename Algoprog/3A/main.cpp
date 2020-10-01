#include <malloc.h>
#include <stdio.h>
#include <bits/stdc++.h>

#define buff 256

using namespace std;

char *delimiters = new char[buff]; //строка разделителей
int lenDelimiters = 0, number, countLine; // длина строки разделителей, число пользователя, кол-во строк
char **line, **sourceText; // текст для обработки, текст исходный
int *sourceLenLine, *lenLine;   // длины текстов
int **countDelimitersPerLine;  // матрица, считает кол-во каждого разделителя в каждой строке текста - для сортировки
int *lineIndex;
int *countDelimiters;

/***
 * Процедура чтения строки
 */
void readDelims(char *string, int *len) {
    printf("Enter a string of delimiters: ");
    while (1) {
        char symbol;
        symbol = getc(stdin);
        if (symbol == '\n') {
            if (string == NULL) {
                continue;
            } else {
                break;
            }
        }
        string[*len] = symbol; // записали символ
        (*len)++;
    }
}

/***
 * Процедура считывания текста как и с учетом разделителей, так и без
 */
void readSourceText() {
    line = new char *[countLine]; // строки без лишних разделителей
    lenLine = new int[countLine];

    sourceText = new char *[countLine]; // введеные строки
    sourceLenLine = new int[countLine];

    countDelimitersPerLine = new int *[countLine]; // количество разделителей в каждой строке
    for (int i = 0; i < countLine; i++) {
        line[i] = NULL;
        sourceText[i] = NULL;
        lenLine[i] = 0;
        sourceLenLine[i] = 0;
        countDelimitersPerLine[i] = new int[lenDelimiters];

        for (int j = 0; j < lenDelimiters; j++) {
            countDelimitersPerLine[i][j] = 0;
        }

        while (1) {
            char symbol;
            symbol = getc(stdin);
            if (symbol == '\n') {
                if (line[i] == NULL) {
                    continue;
                } else {
                    break;
                }
            }

            // считаем кол-во разделителей
            bool isAdd = true;
            for (int j = 0; j < lenDelimiters; j++) {
                if (symbol == delimiters[j]) {
                    countDelimitersPerLine[i][j]++;
                    if (countDelimitersPerLine[i][j] > number) {
                        isAdd = false;
                    }
                    break;
                }
            }

            // В line добавляем только если количество разделителей
            // меньше введенного числа
            if (isAdd) {
                line[i] = (char *) realloc(line[i], (lenLine[i] + 1) * sizeof(char));
                line[i][lenLine[i]] = symbol;
                lenLine[i]++;
            }

            //исходный текст запоминается весь
            sourceText[i] = (char *) realloc(sourceText[i], (sourceLenLine[i] + 1) * sizeof(char));
            sourceText[i][sourceLenLine[i]] = symbol;
            sourceLenLine[i]++;
        }
    }
}


void procedureCountDelimiters() {
    lineIndex = new int[countLine];
    countDelimiters = new int[countLine]; // количество разделителей в каждой строке
    for (int i = 0; i < countLine; i++) {
        bool *isDelimiters = new bool[lenDelimiters];
        countDelimiters[i] = 0;
        for (int j = 0; j < lenDelimiters; j++) {
            isDelimiters[j] = false;
        }

        lineIndex[i] = 0;
        //Итерируемся по строке текста
        for (int j = 0; j < lenLine[i]; j++) {

            //Итерируемся по строке разделителей и смотрим,
            //является ли [i][j] символ текста разделителем,
            for (int q = 0; q < lenDelimiters; q++) {
                if (line[i][j] == delimiters[q]) {
                    countDelimiters[i]++;
                    // Если разделитель повторился - строка больше не интересует,
                    // и выведена не будет
                    if (isDelimiters[q]) {
                        lineIndex[i] = -1;
                        break;
                    } else {
                        // Первое вхождение разделителя
                        isDelimiters[q] = true;
                        break;
                    }
                }
            }
        }
        if (lineIndex[i] == -1) { // В этой строке разделитель повторился -> баним ее
            countDelimiters[i] = -1;
        }
        lineIndex[i] = i;
    }
}


void freeText(char **text, int n) {
    for (int i = 0; i < n; i++) {
        free(text[i]);
    }
    free(text);
}

void freeIntMatrix(int **m, int n) {
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sort() {
    // Сортируем все строки по кол-ву разделителей.
    // Строки с повторяющимися разделителями просто не будут выводиться далее.
    for (int i = 0; i < countLine; i++) {
        for (int j = countLine - 1; j > i; j--) {
            if (countDelimiters[j - 1] > countDelimiters[j]) {
                swap(&countDelimiters[j - 1], &countDelimiters[j]);
                swap(&lineIndex[j - 1], &lineIndex[j]);
            }
        }
    }
}


int main() {
    readDelims(delimiters, &lenDelimiters);

    printf("Enter number: ");
    scanf("%d", &number);
    printf("Enter the number of lines: ");
    scanf("%d", &countLine);

    //Чтение двух текстов : 1) В котором учитываются разделители
    // 2) исходного текста для итогового сравнения
    readSourceText();

    //Проверка каждой строки на повторяющиеся разделители
    procedureCountDelimiters();

    // Сортировка массива с порядком строк по количеству разделителей
    sort();

    // Вывод отсортированного, обработанного текста
    printf("Formatted text:\n");
    for (int i = 0; i < countLine; i++) {
        if (countDelimiters[i] != -1) { // Если в строке не повторяются разделители, можно выводить
            int index = lineIndex[i];
            for (int j = 0; j < lenLine[index]; j++) {
                printf("%c", line[index][j]);
            }
            printf("\n");
        }
    }

    // Вывод исходного, нетронутого текста
    printf("Source text:\n");
    for (int i = 0; i < countLine; i++) {
        for (int j = 0; j < sourceLenLine[i]; j++) {
            printf("%c", sourceText[i][j]);
        }
        printf("\n");
    }

    // Очищаем выделенную память, чтобы не было ее утечки
    freeText(line, countLine);
    free(delimiters);
    freeText(sourceText, countLine);
    free(sourceLenLine);
    free(lenLine);
    freeIntMatrix(countDelimitersPerLine, countLine);

    return 0;
}
