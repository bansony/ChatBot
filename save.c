/**
 * save.c -- реализует команду сохранения файла
 * 
 * Copyright (c) 2020, Tikkoeva Anastasia  <tikkoeva@cspetrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

/**
 * Загружает содержимое указанного файла
 */

static void save_line(int index, char *contents, int cursor, void *data);


/**
 * Сохраняет содержимое указанного файла
 */

void save(text txt, char *filename)
{
    FILE *f = fopen("f.txt", "a+");

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
	/* Применяем функцию save_line к каждой строке текста */
	return;
    }
    process_forward(txt, save_line, (void*)f);
	fclose(f);
    }

/**
 * Выводит содержимое указанного файла на экран
 */
    static void save_line(int index, char *contents, int cursor, void *data)
    {
	FILE *f = (FILE*)data;
	
	/* Функция обработчик всегда получает существующую строку */
	assert(contents != NULL);
	
	/* Декларируем неиспользуемые параметры */
	UNUSED(index);
	UNUSED(cursor);
    
	/* Выводим строку на экран */
	fprintf(f, "%s",  contents);
    }
