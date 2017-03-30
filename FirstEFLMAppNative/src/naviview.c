/*
 * naviview.c
 *
 *  Created on: Feb 20, 2017
 *      Author: Sergei Papulin
 *
 *  ETL API:
 *  https://developer.tizen.org/development/guides/native-application/user-interface/efl
 *  https://developer.tizen.org/development/ui-practices/native-application/efl/ui-components
 *  https://developer.tizen.org/development/ui-practices/native-application/efl/scaling/scalability-support
 *  https://developer.tizen.org/development/ui-practices/native-application/efl/ui-containers/box
 *
 */

#include "naviview.h"

// Создание формы first view
void create_first_view(appdata_s *ad)
{
	Evas_Object *content, *btn_nav, *btn_cont, *entry, *lbl;
	Elm_Object_Item *nf_it;

	// Создаем кнопку Next
	btn_nav = elm_button_add(ad->nf); // создаем кнопку для элемента naviframe
	elm_object_style_set(btn_nav, "naviframe/title_right"); // устанавливаем стиль кнопки
	elm_object_text_set(btn_nav, "Next"); // уcтанавливаем текст кнопки
	evas_object_smart_callback_add(btn_nav, "clicked", show_second_view_btn_clicked_cb, ad); // определяем функцию, которая будет выполнена при событии clicked

	// Box
	content = elm_box_add(ad->nf); // создаем контейнер типа box
	elm_box_align_set(content, 0, 0); // устанавливает его положение (верхний левый угол)
	evas_object_show(content);	// устанавливаем свойство visible в true

	// Кнопка в box'е
	btn_cont = elm_button_add(ad->nf); // создаем кнопку в content для перехода на следующую страницу
	elm_object_text_set(btn_cont, "Start Counter"); // уcтанавливаем текст
	evas_object_size_hint_min_set(btn_cont, 400, 128); // уcтанавливаем размер
	evas_object_size_hint_align_set(btn_cont, 0.5, 1); // определяем положение кнопки (внизу в центре)
	evas_object_size_hint_weight_set(btn_cont, EVAS_HINT_EXPAND, 0.3); // размещение элемента в пространстве с максимальной величиной по горизонтали  и на 0.5 по вертикали
	evas_object_smart_callback_add(btn_cont, "clicked", start_counter_btn_clicked_cb, ad); // устанавливаем обработчик события clicked
	evas_object_show(btn_cont); // устанавливаем свойство кнопки visible=true
	elm_box_pack_end(content, btn_cont); // добавляем кнопку в конец контейнера box

	// Кнопка в box'е
	btn_cont = elm_button_add(ad->nf); // создаем кнопку в content для перехода на следующую страницу
	elm_object_text_set(btn_cont, "Go To Second View"); // уcтанавливаем текст
	evas_object_size_hint_min_set(btn_cont, 400, 128); // уcтанавливаем размер
	evas_object_size_hint_align_set(btn_cont, 0.5, 1); // определяем положение кнопки (внизу в центре)
	evas_object_size_hint_weight_set(btn_cont, EVAS_HINT_EXPAND, 0.3); // размещение элемента в пространстве с максимальной величиной по горизонтали  и на 0.5 по вертикали
	evas_object_smart_callback_add(btn_cont, "clicked", show_second_view_btn_clicked_cb, ad); // устанавливаем обработчик события clicked
	evas_object_show(btn_cont); // устанавливаем свойство кнопки visible=true
	elm_box_pack_end(content, btn_cont); // добавляем кнопку в конец контейнера box

	// Текстовое поле
	entry = elm_entry_add(content); // создаем текстовое поле ввода

	elm_entry_entry_set(entry, "0"); // устанавливаем исходный текст поля
	evas_object_size_hint_align_set(entry, EVAS_HINT_FILL, EVAS_HINT_FILL); // текстовое поле будет заполнять родительский элемент
	evas_object_size_hint_weight_set(entry, EVAS_HINT_EXPAND, 0.3); // размещение элемента в пространстве с максимальной величиной по горизонтали  и на 0.5 по вертикали
	evas_object_show(entry); // устанавливаем свойство текстового поля visible=true
	elm_box_pack_start(content, entry); // добавляем поле в начало контейнера box
	ad->txt = entry;

	// Label
	lbl = elm_label_add(content);
	evas_object_size_hint_weight_set(lbl, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(lbl, 1, 1);
	elm_object_text_set(lbl, "Counter");
	evas_object_show(lbl);
	elm_box_pack_end(content, lbl);
	ad->lbl = lbl;


	// Добавляем naviframe в массив naviframe (верхний view отображается на экране)
	nf_it = elm_naviframe_item_push(ad->nf, "First View", NULL, NULL, content, NULL); // добавляем nf в массив элементов naviframe
	elm_object_item_part_content_set(nf_it, "title_right_btn", btn_nav); // назначаем контент nf_it и имя title_right_btn для копки btn_nav

}

// Создание формы second view
void create_second_view(appdata_s *ad)
{
	Evas_Object *content, *btn_prev;
	Elm_Object_Item *nf_it;

    // Создаем контейнер layout
    content = elm_layout_add(ad->nf);
    elm_layout_theme_set(content, "layout", "nocontents", "default"); // Определеям тему layout
    elm_object_part_text_set(content, "elm.text", "Second View"); // Устанавливаем текст

    // Создаем кнопку Prev
    btn_prev = elm_button_add(ad->nf);
    elm_object_style_set(btn_prev, "naviframe/title_left");
    elm_object_text_set(btn_prev, "Prev");
    evas_object_smart_callback_add(btn_prev, "clicked", show_first_view_btn_clicked_cb, ad->nf);

    // Добавляем второй naviframe в массив naviframe (верхний view отображается на экране)
    nf_it = elm_naviframe_item_push(ad->nf, "Second View", NULL, NULL, content, NULL); // добавляем nf второго view в массив элементов naviframe
    elm_object_item_part_content_set(nf_it, "title_left_btn", btn_prev);

}

// Обработка события перехода на first view
void show_first_view_btn_clicked_cb(void *data, Evas_Object *obj, void *event_info)
{
	Evas_Object *nf = data;

   // Извлекаем второй view из naviframe
   elm_naviframe_item_pop(nf);

}

// Обработка события перехода на second view
void show_second_view_btn_clicked_cb(void *ad, Evas_Object *obj, void *event_info)
{
	// Создаем второй view
	create_second_view(ad);
}

// Таймер
void _one_second_timer()
{
	int trigger = 1;
	clock_t before = clock();

	float msec = 0;


	while ( msec < trigger) {

		clock_t difference = clock() - before;
		msec = difference / CLOCKS_PER_SEC;
	}
}
void _long_function(void *data, Ecore_Thread *thread)
{

	appdata_s *ad = data;

	int trigger = atoi(elm_object_text_get(ad->txt));

	for(int i=0; i < trigger; i++)
	{
		_one_second_timer();

		ecore_thread_feedback(thread, (void*)(uintptr_t)(i+1));
	}
}
void _set_label_text(void *data, Ecore_Thread *thread, void *msgdata)
{
	appdata_s *ad = data;

	char buf[64];
	snprintf(buf, sizeof(buf), "<font=Sans:style=Regular font_size=150>%d</font>", (int)(uintptr_t)msgdata);

	elm_object_text_set(ad->lbl, buf);
}
void _end_func(void *data, Ecore_Thread *thread)
{
	appdata_s *ad = data;
	elm_object_text_set(ad->lbl, "Ticks over");
}
void start_counter_btn_clicked_cb(void *data, Evas_Object *obj, void *event_info) {

	appdata_s *ad = data;

	// в отдельном потоке
	ecore_thread_feedback_run(_long_function, _set_label_text, _end_func, NULL, ad, EINA_FALSE);
}




