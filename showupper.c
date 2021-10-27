/**
 * showupper.c -- реализует команду вывода хранимого текста в верхнем регистре на экран
 *
 * Copyright (c) 2020, Tikkoeva Anastasia  <tikkoeva@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"


static void show_upper(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void to_upper(text txt)
{
    /* Применяем функцию show_upper к каждой строке текста */
    process_forward(txt, show_upper, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_upper(int index, char *contents, int cursor, void *data)
{
    int i = 0;

    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
	UNUSED(cursor);
    UNUSED(data);
	    
    /* Меняем регистр и выводим строку на экран */
    while (i < MAXLINE){
	if (*(contents + i) >= 'a' && *(contents + i) <= 'z')
	    *(contents + i) += 'A' - 'a';
	i++;
    }
	
	/* Выводим строку на экран */
    /* Если в сроке есть курсор */
    if (cursor != -1)
    {     
        /* Выводим то, что до курсора */
        for (int i = 0; i < cursor; i++)
            printf("%c", contents[i]);

        /* Выводим курсор*/    
        printf("|");

        /* Выводим то, что после курсора*/
        for (int i = cursor; i < (int)strlen(contents); i++)
            printf("%c", contents[i]);   
    }
    else
    {
  
    printf("%s", contents);
}
}