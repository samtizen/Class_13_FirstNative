#ifndef __main_H__
#define __main_H__

#include <app.h>
#include <Elementary.h>
#include <system_settings.h>
#include <efl_extension.h>
#include <dlog.h>
#include <time.h>

typedef struct appdata {
	Evas_Object *win;
	Evas_Object *conform;
	Evas_Object *nf;
	Evas_Object *txt;
	Evas_Object *lbl;
} appdata_s;

#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG "FirstEflNative"

#if !defined(PACKAGE)
#define PACKAGE "org.example.firsteflmappnative"
#endif


#endif /* __basicui_H__ */

