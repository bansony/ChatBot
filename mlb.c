
/**
 * mlb.c -- реализует команду перемещения курсора в начало строки
 *
 * Copyright (c) 2020, Tikkoeva Anastasia <tikkoeva@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "text/_text.h"
#include "common.h"


/**
 * Перемещает курсор в начало строки
 */
void mlb(text txt)
{
	
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
	fprintf(stderr, "There are already no any lines in the text!\n");
	return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

        /* Если курсор находится в начале текста, то двинуть его мы не можем*/
    if (txt->cursor->position == -1) {
	printf("Another command needed to jump between lines\n");
    } else 

    txt->cursor->position = 0; //сдвигаем курсор в начало строки
    

}
