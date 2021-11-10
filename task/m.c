#include <stdio.h>
#include "common.h"
#include "text/text.h"

/**
 * \file
 * \param text txt
 * \param int num_str
 * \param int num_pos
 * \return void
 * \author Sonya Bankovskaya <bankovskaasona37@gmail.com>
 * \copyright MIT-style license
 * \bug Курсор исчезает, если введены некорректные параметры 
 * \warning Перед использование функции загрузите текстовый файл (load название файла)
 * \date 6.10.2021
 * \brief Функция, реализующая перемещение курсора по строке
 */
 
void m(text txt, int num_str, int num_pos)
{
    /*применение функции перемещения курсора к каждой строке*/
    process_m(txt, num_str, num_pos);
}
