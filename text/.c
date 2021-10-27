/**
 * process_rt.c -- реализует обобщенную функцию обработки текста (rt.c)
 *
 * Copyright (c) 2020, Tikkoeva Anastasia <tikkoeva@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Обрабатывает список, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_r1e(text txt)
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
	    else if (current == txt->begin && txt->begin != txt->end){	// Если строка первая
	        current->next->previous = NULL;
		txt->begin = current->next;
	 	free(current);
		txt->length--;
	 	break;
	    }
	    else if (current == txt->end && txt->begin != txt->end){	// Если строка последняя
	        current->previous->next = NULL;
		txt->end = current->previous;
	 	free(current);
		txt->length--;
	 	break;
	    }
	    else if (txt->begin == txt->end){	// Если всего одна строка
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

