/**
 * \file
 * \param text txt
 * \param char *filename
 * \return void
 * \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
 * \copyright MIT-style license
 * \bug Курсор исчезает, если введены некорректные параметры
 * \warning Перед использование функции загрузите текстовый файл (load название файла)
 * \date 6.10.2021
 * \brief Функция загрузки текста из файла
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename)
{
    FILE *f;

    char buf[MAXLINE + 1];

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "r")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);

    /* Считываем содержимое строка за строкой */
    while (fgets(buf, MAXLINE, f)) {
        append_line(txt, buf);
    }
}
