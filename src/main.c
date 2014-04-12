/*
Past Events
Written by Edwin Finch

Credits:
Animated action bar by Pedrolane: https://github.com/gregoiresage/pebble_animated_actionbar
Original idea by Terje Leiros: http://forums.getpebble.com/discussion/comment/104498/#Comment_104498

#sixseasonsandamovie
#savegreendale
*/

#include <pebble.h>
#include "elements.h"

int fetchTime(int type){
	if(type == 1){
		return second;
	}
	else if(type == 2){
		return minute;
	}
	else if(type == 3){
		return hour;
	}
	else{
		return 0;
	}
}
	
void tick_handler(struct tm *tick_time, TimeUnits units_changed){
	second = tick_time->tm_sec;
	minute = tick_time->tm_min;
	hour = tick_time->tm_hour;
	day = tick_time->tm_mday;
	month = tick_time->tm_mon;
}
	
void updateDesText(){
	if(desText == 0){
		text_layer_set_text(des_text_layer, "Put in slot");
		text_layer_set_text(select_char_text_layer, "1");
		eventEditing = 1;
	}
	else if(desText == 1){
		text_layer_set_text(des_text_layer, "Char. 1/5");
		text_layer_set_text(select_char_text_layer, "A");
	}
	else if(desText == 2){
		text_layer_set_text(des_text_layer, "Char. 2/5");
	}
	else if(desText == 3){
		text_layer_set_text(des_text_layer, "Char. 3/5");
	}
	else if(desText == 4){
		text_layer_set_text(des_text_layer, "Char. 4/5");
	}
	else if(desText == 5){
		text_layer_set_text(des_text_layer, "Char. 5/5");
	}
	else if(desText == 6){
		text_layer_set_text(des_text_layer, "Recorded.");
	}
}
	
void on_animation_stopped(Animation *anim, bool finished, void *context)
{
    //Free the memory used by the Animation
    property_animation_destroy((PropertyAnimation*) anim);
	updateDesText();
}
 
void animate_layer(Layer *layer, GRect *start, GRect *finish, int duration, int delay)
{
    //Declare animation
    PropertyAnimation *anim = property_animation_create_layer_frame(layer, start, finish);

    animation_set_duration((Animation*) anim, duration);
    animation_set_delay((Animation*) anim, delay);
     
	AnimationHandlers handlers = {
    .stopped = (AnimationStoppedHandler) on_animation_stopped
    };
    animation_set_handlers((Animation*) anim, handlers, NULL);
     
    animation_schedule((Animation*) anim);
}

void transition(int transition, int invert){
	if(transition == 1){
		GRect finish = GRect(-150, 55, 144, 168);
		GRect start = GRect(-8, 10, 144, 168);
		GRect start1 = GRect(-2, 55, 144, 168);
		GRect start2 = GRect(8, 103, 144, 168);
		animate_layer(text_layer_get_layer(option_text_layer1), &start, &finish, animationSpeed, 100);
		animate_layer(text_layer_get_layer(option_text_layer2), &start1, &finish, animationSpeed, 200);
		animate_layer(text_layer_get_layer(option_text_layer3), &start2, &finish, animationSpeed, 300);
	}
	else if(transition == 2){
		text_layer_set_text(select_char_text_layer, "1");
		GRect start = GRect(55, -70, 144, 168);
		GRect finish = GRect(0, 0, 144, 168);
		GRect finish1 = GRect(0, 40, 144, 168);
		animate_layer(text_layer_get_layer(des_text_layer), &start, &finish, animationSpeed, animationSpeed+200);
		animate_layer(text_layer_get_layer(select_char_text_layer), &start, &finish1, animationSpeed, animationSpeed+300);
	}
	else if(transition == 3){
		if(invert == 2){
			start = GRect(0, 0, 144, 168);
		}
		else if(invert == 1){
			GRect start1 = GRect(0, 40, 144, 168);
			GRect finish = GRect(-150, 100, 144, 168);
			GRect finish1 = GRect(-150, 40, 144, 168);
			GRect finish11 = GRect(0, 100, 144, 168);
			GRect start11 = GRect(300, 100, 144, 168);
			GRect start12 = GRect(300, 40, 144, 168);
			animate_layer(text_layer_get_layer(des_text_layer), &start, &start11, animationSpeed, 100);
			animate_layer(text_layer_get_layer(select_char_text_layer), &start1, &start12, animationSpeed, 200);
			animate_layer(text_layer_get_layer(des_text_layer), &finish, &finish11, animationSpeed, animationSpeed+100);
			animate_layer(text_layer_get_layer(select_char_text_layer), &finish1, &start1, animationSpeed, animationSpeed+200);
		}
		else if(invert == 0){
			start = GRect(0, 100, 144, 168);
		}
		if(invert != 1 && invert != 3){
			GRect start1 = GRect(0, 40, 144, 168);
			GRect finish = GRect(-150, 100, 144, 168);
			GRect finish1 = GRect(-150, 40, 144, 168);
			GRect finish11 = GRect(0, 100, 144, 168);
			GRect start11 = GRect(300, 100, 144, 168);
			GRect start12 = GRect(300, 40, 144, 168);
			animate_layer(text_layer_get_layer(des_text_layer), &start, &finish, animationSpeed, 100);
			animate_layer(text_layer_get_layer(select_char_text_layer), &start1, &finish1, animationSpeed, 200);
			animate_layer(text_layer_get_layer(des_text_layer), &start11, &finish11, animationSpeed, animationSpeed+100);
			animate_layer(text_layer_get_layer(select_char_text_layer), &start12, &start1, animationSpeed, animationSpeed+200);
		}
	}
	else if(transition == 4){
		start = GRect(0, 100, 144, 168);
		GRect start1 = GRect(0, 40, 144, 168);
		GRect finish = GRect(-150, 100, 144, 168);
		GRect finish1 = GRect(-150, 40, 144, 168);
		GRect finish11 = GRect(0, 100, 144, 168);
		GRect start11 = GRect(0, 300, 144, 168);
		GRect finish21 = GRect(0, -20, 144, 168);
		animate_layer(text_layer_get_layer(des_text_layer), &start, &finish, animationSpeed, 100);
		animate_layer(text_layer_get_layer(select_char_text_layer), &start1, &finish1, animationSpeed, 200);
		animate_layer(bitmap_layer_get_layer(success_layer), &start11, &finish21, animationSpeed, animationSpeed+200);
		animate_layer(text_layer_get_layer(des_text_layer), &start11, &finish11, animationSpeed, animationSpeed+300);
	}
	else if(transition == 5){
		start = GRect(0, 100, 144, 168);
		GRect finish11 = GRect(0, 100, 144, 168);
		GRect finish21 = GRect(0, -20, 144, 168);
		GRect finish1 = GRect(0, 300, 144, 168);
		animate_layer(bitmap_layer_get_layer(success_layer), &finish21, &start, animationSpeed, 100);
		animate_layer(text_layer_get_layer(des_text_layer), &finish11, &finish1, animationSpeed, 200);
		GRect finish = GRect(-150, 55, 144, 168);
		GRect start0 = GRect(-8, 10, 144, 168);
		GRect start1 = GRect(-2, 55, 144, 168);
		GRect start2 = GRect(8, 103, 144, 168);
		animate_layer(text_layer_get_layer(option_text_layer1), &finish, &start0, animationSpeed, animationSpeed+100);
		animate_layer(text_layer_get_layer(option_text_layer2), &finish, &start1, animationSpeed, animationSpeed+200);
		animate_layer(text_layer_get_layer(option_text_layer3), &finish, &start2, animationSpeed, animationSpeed+300);
	}
	else if(transition == 6){
		GRect finish = GRect(-150, 55, 144, 168);
		GRect start0 = GRect(-8, 10, 144, 168);
		GRect start1 = GRect(-2, 55, 144, 168);
		GRect start2 = GRect(8, 103, 144, 168);
		animate_layer(text_layer_get_layer(option_text_layer1), &finish, &start0, animationSpeed, animationSpeed+100);
		animate_layer(text_layer_get_layer(option_text_layer2), &finish, &start1, animationSpeed, animationSpeed+200);
		animate_layer(text_layer_get_layer(option_text_layer3), &finish, &start2, animationSpeed, animationSpeed+300);
		GRect start = GRect(55, -70, 144, 168);
		GRect finish11 = GRect(0, 0, 144, 168);
		GRect finish12 = GRect(0, 40, 144, 168);
		animate_layer(text_layer_get_layer(des_text_layer), &finish11, &start, animationSpeed, 100);
		animate_layer(text_layer_get_layer(select_char_text_layer), &finish12, &start, animationSpeed, 200);
	}
	else if(transition == 7){
		GRect start = GRect(55, -70, 144, 168);
		GRect finish = GRect(0, 100, 144, 168);
		GRect finish1 = GRect(0, 40, 144, 168);
		animate_layer(text_layer_get_layer(des_text_layer), &finish, &start, animationSpeed, 100);
		animate_layer(text_layer_get_layer(select_char_text_layer), &finish1, &start, animationSpeed, 200);
		GRect finish11 = GRect(0, 40, 144, 168);
		GRect finish12 = GRect(0, 0, 144, 168);
		GRect start11 = GRect(300, 100, 144, 168);
		GRect start12 = GRect(300, 40, 144, 168);
		animate_layer(text_layer_get_layer(des_text_layer), &start11, &finish12, animationSpeed, animationSpeed+200);
		animate_layer(text_layer_get_layer(select_char_text_layer), &start12, &finish11, animationSpeed, animationSpeed+300);
	}
}

void updateEvent(int event){
	if(event == 0){
		snprintf(eventBuffer, sizeof(eventBuffer), "%c%c%c%c%c", settings.events[event][0], settings.events[event][1], settings.events[event][2], settings.events[event][3], settings.events[event][4]);
		ev_first_menu_items[event].title = eventBuffer;
		snprintf(timeSetBuffer, sizeof(timeSetBuffer), "Time: %d:%d %d/%d", settings.eventTimes[event][0], settings.eventTimes[event][1], settings.eventTimes[event][2], settings.eventTimes[event][3]);
		ev_first_menu_items[event].subtitle = timeSetBuffer;
	}
	else if(event == 1){
		snprintf(eventBuffer1, sizeof(eventBuffer1), "%c%c%c%c%c", settings.events[event][0], settings.events[event][1], settings.events[event][2], settings.events[event][3], settings.events[event][4]);
		ev_first_menu_items[event].title = eventBuffer1;
		snprintf(timeSetBuffer1, sizeof(timeSetBuffer1), "Time: %d:%d %d/%d", settings.eventTimes[event][0], settings.eventTimes[event][1], settings.eventTimes[event][2], settings.eventTimes[event][3]);
		ev_first_menu_items[event].subtitle = timeSetBuffer1;
	}
	else if(event == 2){
		snprintf(eventBuffer2, sizeof(eventBuffer2), "%c%c%c%c%c", settings.events[event][0], settings.events[event][1], settings.events[event][2], settings.events[event][3], settings.events[event][4]);
		ev_first_menu_items[event].title = eventBuffer2;
		snprintf(timeSetBuffer2, sizeof(timeSetBuffer2), "Time: %d:%d %d/%d", settings.eventTimes[event][0], settings.eventTimes[event][1], settings.eventTimes[event][2], settings.eventTimes[event][3]);
		ev_first_menu_items[event].subtitle = timeSetBuffer2;
	}
	else if(event == 3){
		snprintf(eventBuffer3, sizeof(eventBuffer3), "%c%c%c%c%c", settings.events[event][0], settings.events[event][1], settings.events[event][2], settings.events[event][3], settings.events[event][4]);
		ev_first_menu_items[event].title = eventBuffer3;
		snprintf(timeSetBuffer3, sizeof(timeSetBuffer3), "Time: %d:%d %d/%d", settings.eventTimes[event][0], settings.eventTimes[event][1], settings.eventTimes[event][2], settings.eventTimes[event][3]);
		ev_first_menu_items[event].subtitle = timeSetBuffer3;
	}
	else if(event == 4){
		snprintf(eventBuffer4, sizeof(eventBuffer4), "%c%c%c%c%c", settings.events[event][0], settings.events[event][1], settings.events[event][2], settings.events[event][3], settings.events[event][4]);
		ev_first_menu_items[event].title = eventBuffer4;
		snprintf(timeSetBuffer4, sizeof(timeSetBuffer4), "Time: %d:%d %d/%d", settings.eventTimes[event][0], settings.eventTimes[event][1], settings.eventTimes[event][2], settings.eventTimes[event][3]);
		ev_first_menu_items[event].subtitle = timeSetBuffer4;
	}
}

void setLetter(int event, int arrayPlace, int position){
	charFix[0][0] = charArray[0][arrayPlace];
	settings.events[event][position] = charFix[0][0];
}

void setTime(int event){
	settings.eventTimes[event][0] = hour;
	settings.eventTimes[event][1] = minute;
	settings.eventTimes[event][2] = day;
	settings.eventTimes[event][3] = month;
}
	
void theme_callback(int index, void *ctx){
	settings.theme = !settings.theme;
	if(settings.theme){
		op_first_menu_items[0].subtitle = "White on black";
	}
	else{
		op_first_menu_items[0].subtitle = "Black on white";
	}
	layer_mark_dirty(simple_menu_layer_get_layer(options));
}

void animationspeed_callback(int index, void *ctx){
	settings.animationSpeed++;
	if(settings.animationSpeed == 0){
		op_first_menu_items[1].subtitle = "Quick (300ms)";
		animationSpeed = 300;
	}
	else if(settings.animationSpeed == 1){
		op_first_menu_items[1].subtitle = "Medium (600ms)";
		animationSpeed = 600;
	}
	else if(settings.animationSpeed == 2){
		op_first_menu_items[1].subtitle = "Slow (900ms)";
		animationSpeed = 900;
	}
	else if(settings.animationSpeed == 3){
		settings.animationSpeed = 0;
		op_first_menu_items[1].subtitle = "Quick (300ms)";
		animationSpeed = 300;
	}
	layer_mark_dirty(simple_menu_layer_get_layer(options));
}

void events_clear_callback(int index, void *ctx){
	times++;
	if(times == 1){
		op_first_menu_items[2].subtitle = "Press two more times";
	}
	else if(times == 2){
		op_first_menu_items[2].subtitle = "Press once more...";
	}
	else if(times == 3){
		op_first_menu_items[2].subtitle = "Events cleared.";
		settings.eventRecorded[0][0] = 0;
		settings.eventRecorded[0][1] = 0;
		settings.eventRecorded[0][2] = 0;
		settings.eventRecorded[0][3] = 0;
		settings.eventRecorded[0][4] = 0;
	}
	layer_mark_dirty(simple_menu_layer_get_layer(options));
}

void window_unload_options(Window *window){
	simple_menu_layer_destroy(options);
	if(settings.theme == 0){
		layer_set_hidden(inverter_layer_get_layer(theme), true);
	}
	else{
		layer_set_hidden(inverter_layer_get_layer(theme), false);
	}
}
	
void window_load_options(Window *window){
	Layer *window_layer = window_get_root_layer(window);
	times = 0;
	op_first_menu_items[0] = (SimpleMenuItem){
    	.title = "Theme",
		//I GOT A CALLBACK! 
		// https://www.youtube.com/watch?v=GgGy_ToeYtc
    	.callback = theme_callback,
    };
	op_first_menu_items[1] = (SimpleMenuItem){
    	.title = "Animation Speed",
		.subtitle = "Quick (300ms)",
    	.callback = animationspeed_callback,
    };
	op_first_menu_items[2] = (SimpleMenuItem){
		.title = "Clear all events",
		.subtitle = "Press 3 times",
		.callback = events_clear_callback,
	};
	
	op_second_menu_items[0] = (SimpleMenuItem){
		.title = "By: Edwin Finch",
		.subtitle = "edwinfinch.com",
	};
	op_second_menu_items[1] = (SimpleMenuItem){
		.title = "Events Version",
		.subtitle = "0.7b Stable",
	};
	
	op_menu_sections[0] = (SimpleMenuSection){
		.title = "General",
  		.num_items = NUM_OPTIONS_FIRST_ITEMS,
    	.items = op_first_menu_items,
    };
  	op_menu_sections[1] = (SimpleMenuSection){
    	.title = "Aboot",
    	.num_items = NUM_OPTIONS_SECOND_ITEMS,
    	.items = op_second_menu_items,
    };
	if(settings.theme){
		op_first_menu_items[0].subtitle = "White on black";
	}
	else{
		op_first_menu_items[0].subtitle = "Black on white";
	}
	
	if(settings.animationSpeed == 0){
		op_first_menu_items[1].subtitle = "Quick (300ms)";
		animationSpeed = 300;
	}
	else if(settings.animationSpeed == 1){
		op_first_menu_items[1].subtitle = "Medium (600ms)";
		animationSpeed = 600;
	}
	else if(settings.animationSpeed == 2){
		op_first_menu_items[1].subtitle = "Slow (900ms)";
		animationSpeed = 900;
	}
	else{
		settings.animationSpeed = 0;
		animationSpeed = 300;
	}
	GRect bounds = layer_get_frame(window_layer);
	options = simple_menu_layer_create(bounds, window, op_menu_sections, NUM_OPTIONS_SECTIONS, NULL);
	layer_add_child(window_layer, simple_menu_layer_get_layer(options));
}
	
void event1_callback(int index, void *ctx){
	clear1++;
	if(clear1 == 1){
		ev_first_menu_items[0].subtitle = "Press twice to delete";
	}
	else if(clear1 == 2){
		ev_first_menu_items[0].subtitle = "Once more to delete";
	}
	else if(clear1 == 3){
		settings.eventRecorded[0][0] = 0;
		ev_first_menu_items[0].title = "Blank Event";
		ev_first_menu_items[0].subtitle = "Time: NA:NA DD/MM";
	}
	layer_mark_dirty(simple_menu_layer_get_layer(events));
}

void event2_callback(int index, void *ctx){
	clear2++;
	if(clear2 == 1){
		ev_first_menu_items[1].subtitle = "Press twice to delete";
	}
	else if(clear2 == 2){
		ev_first_menu_items[1].subtitle = "Once more to delete";
	}
	else if(clear2 == 3){
		settings.eventRecorded[0][1] = 0;
		ev_first_menu_items[1].title = "Blank Event";
		ev_first_menu_items[1].subtitle = "Time: NA:NA DD/MM";
	}
	layer_mark_dirty(simple_menu_layer_get_layer(events));
}

void event3_callback(int index, void *ctx){
	clear3++;
	if(clear3 == 1){
		ev_first_menu_items[2].subtitle = "Press twice to delete";
	}
	else if(clear3 == 2){
		ev_first_menu_items[2].subtitle = "Once more to delete";
	}
	else if(clear3 == 3){
		settings.eventRecorded[0][2] = 0;
		ev_first_menu_items[2].title = "Blank Event";
		ev_first_menu_items[2].subtitle = "Time: NA:NA DD/MM";
	}
	layer_mark_dirty(simple_menu_layer_get_layer(events));
}

void event4_callback(int index, void *ctx){
	clear4++;
	if(clear4 == 1){
		ev_first_menu_items[3].subtitle = "Press twice to delete";
	}
	else if(clear4 == 2){
		ev_first_menu_items[3].subtitle = "Once more to delete";
	}
	else if(clear4 == 3){
		settings.eventRecorded[0][3] = 0;
		ev_first_menu_items[3].title = "Blank Event";
		ev_first_menu_items[3].subtitle = "Time: NA:NA DD/MM";
	}
	layer_mark_dirty(simple_menu_layer_get_layer(events));
}

void event5_callback(int index, void *ctx){
	clear5++;
	if(clear5 == 1){
		ev_first_menu_items[4].subtitle = "Press twice to delete";
	}
	else if(clear5 == 2){
		ev_first_menu_items[4].subtitle = "Once more to delete";
	}
	else if(clear5 == 3){
		settings.eventRecorded[0][4] = 0;
		ev_first_menu_items[4].title = "Blank Event";
		ev_first_menu_items[4].subtitle = "Time: NA:NA DD/MM";
	}
	layer_mark_dirty(simple_menu_layer_get_layer(events));
}

void window_load_events(Window *window){
	Layer *window_layer = window_get_root_layer(window);
	clear1 = 0;
	clear2 = 0;
	clear3 = 0;
	clear4 = 0;
	clear5 = 0;
	ev_first_menu_items[0] = (SimpleMenuItem){
    	.title = "Blank Event",
		.subtitle = "Time: NA:NA DD/MM",
    	.callback = event1_callback,
    };
	ev_first_menu_items[1] = (SimpleMenuItem){
    	.title = "Blank Event",
		.subtitle = "Time: NA:NA DD/MM",
    	.callback = event2_callback,
    };
	ev_first_menu_items[2] = (SimpleMenuItem){
    	.title = "Blank Event",
		.subtitle = "Time: NA:NA DD/MM",
    	.callback = event3_callback,
    };
	ev_first_menu_items[3] = (SimpleMenuItem){
    	.title = "Blank Event",
		.subtitle = "Time: NA:NA DD/MM",
    	.callback = event4_callback,
    };
	ev_first_menu_items[4] = (SimpleMenuItem){
    	.title = "Blank Event",
		.subtitle = "Time: NA:NA DD/MM",
    	.callback = event5_callback,
    };
	
	ev_menu_sections[0] = (SimpleMenuSection){
		.title = "Past Events",
  		.num_items = NUM_EVENTS_FIRST_ITEMS,
    	.items = ev_first_menu_items,
	};
	if(settings.eventRecorded[0][0] == 1){
		updateEvent(0);
	}
	else{
		ev_first_menu_items[0].title = "Blank Event";
		ev_first_menu_items[0].subtitle = "Time: NA:NA DD/MM";
	}
	if(settings.eventRecorded[0][1] == 1){
		updateEvent(1);
	}
	else{
		ev_first_menu_items[1].title = "Blank Event";
		ev_first_menu_items[1].subtitle = "Time: NA:NA DD/MM";
	}

	if(settings.eventRecorded[0][2] == 1){
		updateEvent(2);
	}
	else{
		ev_first_menu_items[2].title = "Blank Event";
		ev_first_menu_items[2].subtitle = "Time: NA:NA DD/MM";
	}

	if(settings.eventRecorded[0][3] == 1){
		updateEvent(3);
	}
	else{
		ev_first_menu_items[3].title = "Blank Event";
		ev_first_menu_items[3].subtitle = "Time: NA:NA DD/MM";
	}

	if(settings.eventRecorded[0][4] == 1){
		updateEvent(4);
	}
	else{
		ev_first_menu_items[4].title = "Blank Event";
		ev_first_menu_items[4].subtitle = "Time: NA:NA DD/MM";
	}
	GRect bounds = layer_get_frame(window_layer);
	events = simple_menu_layer_create(bounds, window, ev_menu_sections, NUM_EVENTS_SECTIONS, NULL);
	layer_add_child(window_layer, simple_menu_layer_get_layer(events));
}

void window_unload_events(Window *window){
	simple_menu_layer_destroy(events);
}

void up(ClickRecognizerRef recognizer, void *context){
	if(initialScreen == 1){
		window_set_window_handlers(events_window, (WindowHandlers) {
    		.load = window_load_events,
    		.unload = window_unload_events,
        });
		window_stack_push(events_window, true);
	}
	else if(eventEdit == 1){
		if(eventEditing != 5){
			eventEditing++;
		}
		else if(eventEditing == 5){
			eventEditing = 1;
		}
		snprintf(textBuffer, sizeof(textBuffer), "%d", eventEditing);
		text_layer_set_text(select_char_text_layer, textBuffer);
	}
	else if(char1Set == 1 || char2Set == 1 || char3Set == 1 || char4Set == 1 || char5Set == 1){
		if(letterNum < 36){
			letterNum++;
		}
		if(letterNum > 35){
			letterNum = 0;
		}
		snprintf(textBuffer, sizeof(textBuffer), "%c", charArray[0][letterNum]);
		text_layer_set_text(select_char_text_layer, textBuffer);
	}
	else if(eventRec == 1){
		transition(5, 0);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, actionIconPlus);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_DOWN, actionIconSettings);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_UP, actionIconCal);
		initialScreen = 1;
		eventRec = 0;
	}
}

void down(ClickRecognizerRef recognizer, void *context){
	if(initialScreen == 1){
		window_set_window_handlers(options_window, (WindowHandlers) {
    		.load = window_load_options,
    		.unload = window_unload_options,
        });
		window_stack_push(options_window, true);
	}
	else if(eventEdit == 1){
		if(eventEditing > 1){
			eventEditing--;
		}
		else if(eventEditing == 1){
			eventEditing = 5;
		}
		snprintf(textBuffer, sizeof(textBuffer), "%d", eventEditing);
		text_layer_set_text(select_char_text_layer, textBuffer);
	}
	else if(char1Set == 1 || char2Set == 1 || char3Set == 1 || char4Set == 1 || char5Set == 1){
		if(letterNum >= 0){
			letterNum--;
		}
		if(letterNum < 0){
			letterNum = 35;
		}
		snprintf(textBuffer, sizeof(textBuffer), "%c", charArray[0][letterNum]);
		text_layer_set_text(select_char_text_layer, textBuffer);
	}
}

void select(ClickRecognizerRef recognizer, void *context){
	if(initialScreen == 1){
		transition(1, 0);
		transition(2, 0);
		desText = 0;
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_UP, actionIconUp);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, actionIconNext);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_DOWN, actionIconDown);
		initialScreen = 0;
		eventEdit = 1;
		eventEditing = 1;
	}
	else if(eventEdit == 1){
		transition(3, 2);
		eventEdit = 0;
		eventEditing = eventEditing-1;
		setTime(eventEditing);
		desText = 1;
		char1Set = 1;
	}
	else if(char1Set == 1){
		setLetter(eventEditing, letterNum, 0);
		transition(3, 0);
		desText = 2;
		char1Set = 0;
		char2Set = 1;
	}
	else if(char2Set == 1){
		setLetter(eventEditing, letterNum, 1);
		transition(3, 0);
		desText = 3;
		char2Set = 0;
		char3Set = 1;
	}
	else if(char3Set == 1){
		setLetter(eventEditing, letterNum, 2);
		transition(3, 0);
		desText = 4;
		char3Set = 0;
		char4Set = 1;
	}
	else if(char4Set == 1){
		setLetter(eventEditing, letterNum, 3);
		transition(3, 0);
		desText = 5;
		char4Set = 0;
		char5Set = 1;
	}
	else if(char5Set == 1){
		setLetter(eventEditing, letterNum, 4);
		settings.eventRecorded[0][eventEditing] = 1;
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_UP, actionIconNext);
		action_bar_layer_clear_icon(main_action_bar, BUTTON_ID_DOWN);
		action_bar_layer_clear_icon(main_action_bar, BUTTON_ID_SELECT);
		desText = 6;
		char5Set = 0;
		eventRec = 1;
		transition(4, 0);
	}
}

void back(ClickRecognizerRef recognizer, void *context){
	if(initialScreen == 1){
		window_stack_pop(true);
	}
	else if(eventEdit == 1){
		transition(6, 0);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, actionIconPlus);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_DOWN, actionIconSettings);
		action_bar_layer_set_icon(main_action_bar, BUTTON_ID_UP, actionIconCal);
		eventEdit = 0;
		initialScreen = 1;
		desText = 0;
	}
	else if(char1Set == 1){
		transition(7, 0);
		desText = 0;
		char1Set = 0;
		eventEdit = 1;
	}
	else if(char2Set == 1){
		transition(3, 1);
		desText = 1;
		char2Set = 0;
		char1Set = 1;
	}
	else if(char3Set == 1){
		transition(3, 1);
		desText = 2;
		char3Set = 0;
		char2Set = 1;
	}
	else if(char4Set == 1){
		transition(3, 1);
		desText = 3;
		char4Set = 0;
		char3Set = 1;
	}
	else if(char5Set == 1){
		desText = 4;
		char5Set = 0;
		char4Set = 1;
		transition(3, 1);
	}
}

void click_config_provider(void *context) {
  	int interval = 50;
  	window_single_repeating_click_subscribe(BUTTON_ID_UP, interval, (ClickHandler) up);
  	window_single_repeating_click_subscribe(BUTTON_ID_DOWN, interval, (ClickHandler) down);
  	window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) select);
	window_single_click_subscribe(BUTTON_ID_BACK, (ClickHandler) back);
}

static TextLayer* textLayerInit(GRect location, GColor colour, GColor background, GTextAlignment alignment, int font)
{
	TextLayer *layer = text_layer_create(location);
	text_layer_set_text_color(layer, colour);
	text_layer_set_background_color(layer, background);
	text_layer_set_text_alignment(layer, alignment);
	if(font == 1){
		text_layer_set_font(layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
	}
	else if(font == 2){
		text_layer_set_font(layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	}
	else if(font == 3){
		text_layer_set_font(layer, fonts_get_system_font(FONT_KEY_GOTHIC_28));
	}
	return layer;
}

void add_children(){
	Layer *window_layer = window_get_root_layer(main_window);
	action_bar_layer_add_to_window(main_action_bar, main_window);
	layer_add_child(window_layer, (Layer*) option_text_layer1);
	layer_add_child(window_layer, (Layer*) option_text_layer2);
	layer_add_child(window_layer, (Layer*) option_text_layer3);
	layer_add_child(window_layer, (Layer*) des_text_layer);
	layer_add_child(window_layer, (Layer*) select_char_text_layer);
	layer_add_child(window_layer, (Layer*) success_layer);
	
	layer_add_child(window_layer, (Layer*) theme);
	if(settings.theme == 0){
		layer_set_hidden(inverter_layer_get_layer(theme), true);
	}
}

void window_load(Window *window){
	tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
	main_action_bar = action_bar_layer_create();
	actionIconPlus = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PLUS);
	actionIconSettings = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SETTINGS);
	actionIconCal = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CAL);
	actionIconCheckmark = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CHECKMARK);
	actionIconNext = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NEXT);
	actionIconUp = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_UP);
	actionIconDown = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DOWN);
	success = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SUCCESS);
	success_layer = bitmap_layer_create(GRect(300, 50, 50, 50));
	bitmap_layer_set_bitmap(success_layer, success);
	option_text_layer1 = textLayerInit(GRect(10, -70, 144, 168), GColorBlack, GColorClear, GTextAlignmentCenter, 2);
	option_text_layer2 = textLayerInit(GRect(10, -70, 144, 168), GColorBlack, GColorClear, GTextAlignmentCenter, 2);
	option_text_layer3 = textLayerInit(GRect(10, -70, 144, 168), GColorBlack, GColorClear, GTextAlignmentCenter, 2);
	des_text_layer = textLayerInit(GRect(10, -70, 144, 168), GColorBlack, GColorClear, GTextAlignmentCenter, 3);
	select_char_text_layer = textLayerInit(GRect(10, -70, 144, 168), GColorBlack, GColorClear, GTextAlignmentCenter, 1);
	action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, actionIconPlus);
	action_bar_layer_set_icon(main_action_bar, BUTTON_ID_DOWN, actionIconSettings);
	action_bar_layer_set_icon(main_action_bar, BUTTON_ID_UP, actionIconCal);
	text_layer_set_text(option_text_layer1, "Past events");
	text_layer_set_text(option_text_layer2, "Add event");
	text_layer_set_text(option_text_layer3, "Options");
	text_layer_set_text(des_text_layer, "Char. 1/5");
	text_layer_set_text(select_char_text_layer, "A");
	action_bar_layer_set_click_config_provider(main_action_bar, click_config_provider);
	theme = inverter_layer_create(GRect(0, 0, 144, 168));
	add_children();
	GRect finish = GRect(-8, 10, 144, 168);
	GRect finish1 = GRect(-2, 55, 144, 168);
	GRect finish2 = GRect(8, 103, 144, 168);
	GRect start = GRect(200, 55, 144, 168);
	animate_layer(text_layer_get_layer(option_text_layer1), &start, &finish, animationSpeed, 100);
	animate_layer(text_layer_get_layer(option_text_layer2), &start, &finish1, animationSpeed, 200);
	animate_layer(text_layer_get_layer(option_text_layer3), &start, &finish2, animationSpeed, 300);
}
	
void window_unload(Window *window){
	action_bar_layer_destroy(main_action_bar);
	text_layer_destroy(option_text_layer1);
	text_layer_destroy(option_text_layer2);
	text_layer_destroy(option_text_layer3);
	gbitmap_destroy(actionIconCal);
	gbitmap_destroy(actionIconPlus);
	gbitmap_destroy(actionIconSettings);
	gbitmap_destroy(actionIconUp);
	gbitmap_destroy(actionIconDown);
	gbitmap_destroy(actionIconCheckmark);
	gbitmap_destroy(actionIconNext);
	gbitmap_destroy(success);
	inverter_layer_destroy(theme);
}

void handle_init(void) {
  	main_window = window_create();
	options_window = window_create();
	events_window = window_create();
	window_set_window_handlers(main_window, (WindowHandlers) {
    	.load = window_load,
    	.unload = window_unload,
    });
	valueRead = persist_read_data(SETTINGS_KEY, &settings, sizeof(settings));
	if(settings.animationSpeed == 0){
		op_first_menu_items[1].subtitle = "Quick (300ms)";
		animationSpeed = 300;
	}
	else if(settings.animationSpeed == 1){
		op_first_menu_items[1].subtitle = "Medium (600ms)";
		animationSpeed = 600;
	}
	else if(settings.animationSpeed == 2){
		op_first_menu_items[1].subtitle = "Slow (900ms)";
		animationSpeed = 900;
	}
	else{
		settings.animationSpeed = 0;
		animationSpeed = 300;
	}
	APP_LOG(APP_LOG_LEVEL_INFO, "Read %d bytes from settings", valueRead);
	window_stack_push(main_window, true);
}

void handle_deinit(void) {
	valueWritten = persist_write_data(SETTINGS_KEY, &settings, sizeof(settings));
	APP_LOG(APP_LOG_LEVEL_INFO, "Wrote %d bytes into settings", valueWritten);
  	window_destroy(main_window);
}

int main(void) {
  	handle_init();
  	app_event_loop();
  	handle_deinit();
}