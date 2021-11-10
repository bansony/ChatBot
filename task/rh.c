/**
* \file
* \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
* \copyright MIT-style license
* \warning Перед использование функции загрузите текстовый файл (load название файла)
* \date 6.10.2021
* \brief Функция реализует команду удаления первой строки текста
*/
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void rh_line(int index, char *contents, int cursor, void *data);

/**
 *\param[in] text txt Текстовый файл
 *\return void
 *\brief Вызывает функцию rh_line
 */
void rh(text txt)
{
    /* Применяем функцию rh_line к каждой строке текста */
    process_rh(txt, rh_line, NULL);
}

/**
*\param[in]int index
*\param[in]char *contents
*\param[in]int cursor
*\param[in] void *data
*\return void
*\brief Вызывает функцию rh_line
*/
static void rh_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    UNUSED(cursor);
    UNUSED (index);
}
