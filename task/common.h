/**
 *\file
 *\brief Прототипы функций реализации команд редактора
 *\author Sonya Bankovskaya <bankovskaasona37@gmail.com>
 * \copyright MIT-style license 
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 *Перемещает курсор на заданую позицию
 */
void m(text txt,int num_str, int num_pos);

/**
 *Выводит содержимое указанного файла с нумерацией строк
 */
void shownum(text txt);

/**
 *Перемещает курсор на одну позицию вправо
 */
void mcf(text txt);

/**
 *Удаляет первую строку текста */
void rh(text txt);

/**
 *Сохраняет содержимое указанного файла в файл
 */
void save(text txt, char *filename);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

#endif
