/**
* \file
* \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
* \copyright MIT-style license
* \warning Перед использование функции загрузите текстовый файл (load название файла)
* \date 6.10.2021
* \brief Функция реализует команду вывода хранимого текста на экран c нумерацией строк
 */

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void shownum_line(int index, char *contents, int cursor, void *data);

/**
 * Вызывает функцию shownuum_line, которая выводит содержимое указанного файла с нумерацией строк на экран
 * \param text txt Текстовый файл
 * \return void
 */
void shownum(text txt)
{
    /* Применяем функцию shownuum_line к каждой строке текста */
    process_forward(txt, shownum_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void shownum_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    UNUSED(cursor);

    printf ("%d " "%s", index+1,contents);
}

