
 /**
* \file
* \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
* \copyright MIT-style license
* \bug Курсор исчезает, если введены некорректные параметры или осуществился выход за границы массива(в правой части нето больше символов)
* \warning Перед использование функции загрузите текстовый файл (load название файла)
* \date 6.10.2021
* \brief Функция,  реализует команду перемещения курсора вправо, если это возможно
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void mcf_line(int index, char *contents, int cursor, void *data);

/**
 * Вызывает функцию mcf_line(перемещения курсора) 
 * \param[in] text txt Текстовый файл
 * \return void
 */

void mcf(text txt)
{
    process_mcf(txt, mcf_line, NULL);
}


/**
 * Перемещает курсор на одну позицию вправо
 * \static
 * \param[in] int index 
 * \param[in] char *contents
 * \param[in] int cursor
 * \param[in]  void *data
 * \return void
 */
static void mcf_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    UNUSED(cursor);
    UNUSED (index);
}

