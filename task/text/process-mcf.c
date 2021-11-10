/**
 * process_mcf.c -- реализует функцию перемещения курсора вправо
 *
 * Copyright (c) 2020, Sonya Bankovskaya <bankovskaasona37@gmail.com>
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
void process_mcf(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
        void *data
    )
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
    int index = 0;
    int cursor_position = -1;


    /* К каждой строке текста применяем обработчик */
    while (current) {
	if (txt->cursor->line == current)
	    cursor_position = txt->cursor->position;
	else
	    cursor_position = -1;
	process(index, current->contents, cursor_position, data);
	current = current->next;
	index++;
    }

    //Перемещаем курсор на одну позицию вправо
    txt -> cursor -> position = txt ->cursor -> position+1; 

    /*Проверяем есть ли справа символ*/
    if (txt -> cursor-> position==(int)strlen(txt->cursor->line->contents)) printf ("Line end. The function is not possible\n");

}

