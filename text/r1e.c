/**
 * r1e.c -- реализует команду удаления первой пустой строки
 *
 * Copyright (c) 2020, Tikkoeva Anastasia <tikkoeva@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "_text.h"

/**
 * удаляет первую пустую строку
 */

void r1e(text txt)
{	
	/* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
	fprintf(stderr, "There are already no any lines in the text!\n");
	return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Стартуем с начальной строки текста */
    node *current = txt->begin;

   /* К каждой строке текста применяем обработчик */
    while (current) {
        if (txt->cursor->line != current && (current->contents[0] == '\0' || current->contents[0] == '\n')){
	    /* Освобождаем память, выделенную под текущий элемент */
            if (current != txt->begin && current != txt->end){
		current->next->previous = current->previous;
		current->previous->next = current->next;
	 	free(current);
		txt->length--;
	 	break;
	    }
		/* Если курсор находится в первой строке, то перемещаем его в следующую строку */
	    else if (current == txt->begin && txt->begin != txt->end){
	        current->next->previous = NULL;
		txt->begin = current->next;
	 	free(current);
		txt->length--;
	 	break;
	    }
		
		/* Если курсор находится в последней строке, то перемещаем его в верхнюю строку */
	    else if (current == txt->end && txt->begin != txt->end){	
	        current->previous->next = NULL;
		txt->end = current->previous;
	 	free(current);
		txt->length--;
	 	break;
	    }
		/* Если в тексте одна строка и она пустая, то удаляем указатель на неё и удаляем курсор */
	    else if (txt->begin == txt->end){	
	        txt->end = txt->begin = NULL;
	 	free(current);
		txt->length--;
	 	break;
	    }
	}
	/* Продвигаемся к следующему элементу */
	current = current->next;
    }
}
