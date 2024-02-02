// atharva kshirsagar
// team 17

/* use the following tools to make it work */


/* use this to convert image to c array  amd sure you resize it before converting */
/* https://lvgl.io/tools/imageconverter_v9 */

/* paste the code and make it work ig good luck */



#include "oled.h"
#include "sra_board.h"

static const char *TAG = "oled_example";

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_ORIGINAL
#define LV_ATTRIBUTE_IMG_ORIGINAL
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ORIGINAL uint8_t original_map[] = {
  0xfd, 0xfd, 0xfd, 0xff, 	/*Color of index 0*/
  0x50, 0x4f, 0x51, 0xff, 	/*Color of index 1*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x10, 0x30, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x2c, 0x68, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x6b, 0xc8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x67, 0x8c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xc0, 0x06, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xc0, 0x04, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x80, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x11, 0x13, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x91, 0x13, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x26, 0xcb, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x80, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0x00, 0x00, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x00, 0x01, 0x87, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0x00, 0x00, 0x8d, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x00, 0x01, 0x99, 0x80, 0x00, 
  0x00, 0x00, 0x06, 0x00, 0x00, 0x85, 0x80, 0x00, 
  0x00, 0x00, 0x02, 0x60, 0x09, 0x85, 0x80, 0x00, 
  0x00, 0x00, 0x06, 0x28, 0x68, 0xfd, 0x80, 0x00, 
  0x00, 0x00, 0x03, 0x6c, 0x6b, 0xf3, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0x6c, 0x6b, 0x0a, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xef, 0xef, 0xfc, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7c, 0x78, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x28, 0x28, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t original = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 64,
  .header.h = 64,
  .data_size = 520,
  .data = original_map,
};

LV_IMG_DECLARE(original);

void app_main()
{
    // Initialising the OLED
    init_oled();
    vTaskDelay(100);

    // Clearing the screen
    lv_obj_clean(lv_scr_act());

	// rendering the image
	lv_obj_t *logo = lv_img_create(lv_scr_act());
	lv_img_set_src(logo, &original);
	// setting dims
	lv_obj_set_size(logo, 64, 64);
	// centring
	lv_obj_align(logo, LV_ALIGN_CENTER, 0, 0);

	// Printing the team name on screen
	lv_obj_t *text_msg = lv_label_create(lv_scr_act());
	lv_label_set_text(text_msg, "team 17");
	lv_obj_align(text_msg, LV_ALIGN_CENTER, 0, 0);


    // Refresh Display
    lv_refr_now(NULL);

	ESP_LOGI(TAG, "Successfully displayed Hello World on the OLED Screen");
}
