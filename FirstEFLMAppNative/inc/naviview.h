/*
 * naviview.h
 *
 *  Created on: Feb 20, 2017
 *      Author: Sergei Papulin
 */

#ifndef NAVIVIEW_H_
#define NAVIVIEW_H_

#include "main.h"

void show_first_view_btn_clicked_cb(void *data, Evas_Object *obj, void *event_info);
void show_second_view_btn_clicked_cb(void *data, Evas_Object *obj, void *event_info);
void start_counter_btn_clicked_cb(void *data, Evas_Object *obj, void *event_info);
void create_first_view(appdata_s *ad);
void create_second_view(appdata_s *ad);

#endif /* NAVIVIEW_H_ */
