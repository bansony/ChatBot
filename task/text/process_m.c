/**
 * process_m.c - реализует функцию передвижения курсора по строке
 *
 * Copyright (c) 2020, Sonya Bankovskaya, <bankovskaasona37@gmail.com>
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
void process_m(text txt, int num_str, int num_pos)
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

    
    for (int i=1; i<num_str; i++)
	current = current ->next;
    
    /*Присваиваем курсору запрошенный номер строки и позицию */
    txt -> cursor -> line = current;
    txt -> cursor ->position = num_pos;
}

