/*
 * tg_controller.h - tinyg controller and top level parsers
 * Part of TinyG project
 *
 * Copyright (c) 2010 - 2011 Alden S. Hart Jr.
 *
 * TinyG is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 *
 * TinyG is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with TinyG  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef controller_h
#define controller_h

#include <stdio.h>					// needed for FILE def'n

enum tgCommunicationsMode {
	TG_TEXT_MODE = 0,				// default
	TG_JSON_MODE,
	TG_GRBL_MODE
};

#define TG_FLAG_PROMPTS_bm (1<<0)	// prompt enabled if set
#define INPUT_BUFFER_LEN 255		// text buffer size (255 max)
#define OUTPUT_BUFFER_LEN 255		// text buffer size (255 max)
#define STATUS_MESSAGE_LEN 32		// status message string storage

struct controllerSingleton {		// main TG controller struct
	double version;					// tinyg version number
	double build;					// tinyg build number
	double null;					// dumping ground for items with no target
	uint8_t test;
	uint8_t communications_mode;	// command line, JSON, grbl
	uint8_t prompt_enabled;			// TRUE = enables prompts
	uint8_t src;					// active source device
	uint8_t default_src;			// default source device
	char in_buf[INPUT_BUFFER_LEN];	// input text buffer
	char out_buf[OUTPUT_BUFFER_LEN];// output text buffer
};
struct controllerSingleton tg;		// controller state structure

void tg_init(uint8_t default_src);
void tg_reset(void);
void tg_ready(void);
void tg_announce(void); 
void tg_controller(void);
void tg_application_startup(void);
void tg_set_active_source(uint8_t dev);
void tg_reset_source(void);
char *tg_get_status_message(uint8_t status, char *msg);
//void tg_json_gcode_return(uint8_t status, char *in_buf, char *out_buf);
//void tg_json_gcode_return(uint8_t status, char *block, char *out_buf);
void tg_make_json_gcode_response(uint8_t status, char *block, char *out_buf);


#ifdef __DEBUG
void tg_dump_controller_state(void);
#endif

#endif
