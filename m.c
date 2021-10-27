#include <stdio.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

/**
 * Выводим содержимое указанного файла на экран
 */

void m(text txt, int num_str, int num_pos)
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
    
    /* Проверяем корректность введёного номера строки */
    if (num_str > (int)txt->length || num_str <= 0)
    {
        printf("This num_str does not exist. The value is out of the range. \n");
        return;
    }
    
    /* Запоминаем номер строки */
    int ln = 1;
    
    /* "Бежим", пока не дойдём до нужной строки */
    while (ln != num_str)
    {
        ln++;
        current = current->next;   
    }

    /* Проверяем корректность введённой позиции курсора */
    if (num_pos > (int)strlen(current->contents) || num_pos < 0)
    {
        printf("This position does not exist. The value is out of the range. \n");
        return; 
    }
    else
    {
        /* Переприсваиваем строку, в которой находится курсор */
        txt->cursor->line = current;
        
        /* Переприсваиваем позицию, в которой находится курсор */
        txt->cursor->position = num_pos;
    }
}