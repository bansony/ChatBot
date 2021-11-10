/**
* \file
* \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
* \copyright MIT-style license
* \date 6.10.2021
* \brief Функция  реализует команду сохранения текста в файл
*/
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

/*сохраняет содержимое указанного файла в файл*/
static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Загружает содержимое указанного файла 
* \param text txt
* \param char *filename
* \return void
 */
void save(text txt,char *filename)

{
    FILE *f;
    /*открываем файл для чтения*/
    if ((f=fopen(filename,"w"))==NULL){
	printf("The file %s cannot be opened\n",filename);
	return;
	    }
    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line,(void *)f);
    fclose(f);
}


/**
 * Выводит содержимое указанного файла в файл
*/
static void save_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    FILE *f =(FILE *)data;

    /* Выводим строку на экран */
    fprintf(f,"%s", contents);
}
