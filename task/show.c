/**
* \file
* \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
* \copyright MIT-style license
* \warning Перед использование функции загрузите текстовый файл (load название файла)
* \date 6.10.2021
* \brief Функция реализует команду вывода хранимого текста на экран
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Вызывает функцию show_line, которая ыыводит содержимое указанного файла на экран
 * \param text txt Текстовый файл
 * \return void
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
    printf ("\n");
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /*Выводим обозначение курсора на экран*/
    if(cursor!=-1) {
	int curr_pos=0;
	while (*contents) {
	    if (curr_pos++==cursor) printf ("|");
	    printf("%c",*contents++);
	}
	if (curr_pos++==cursor) printf("|");
    }
    else printf("%s", contents); 
 }
