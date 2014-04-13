/*
To do:
-Nothing
*/

#define NUM_OPTIONS_SECTIONS 2
#define NUM_OPTIONS_FIRST_ITEMS 3
#define NUM_OPTIONS_SECOND_ITEMS 2
#define NUM_EVENTS_SECTIONS 1
#define NUM_EVENTS_FIRST_ITEMS 5
#define SETTINGS_KEY 0

ActionBarLayer *main_action_bar;
Window *main_window, *options_window, *events_window;
SimpleMenuLayer *options, *events;
bool initialScreen = 1;
InverterLayer *theme;
TextLayer *option_text_layer1, *option_text_layer2, *option_text_layer3, *select_char_text_layer, *des_text_layer;
BitmapLayer *success_layer;
GBitmap *actionIconPlus, *actionIconSettings, *actionIconCal, *actionIconUp, *actionIconDown, *actionIconCheckmark, *actionIconNext;
GBitmap *edited, *success;

typedef struct persist {
	bool theme;
	int animationSpeed;
	char events[5][5];
	int eventTimes[5][4];
	int eventRecorded[1][6];
}__attribute__((__packed__)) persist;

persist settings = {
	.theme = 0,
	.animationSpeed = 0,
	.events = {
		{'B', 'l','a','n','k'}, 
		{'B', 'l','a','n','k'}, 
		{'B', 'l','a','n','k'}, 
		{'B', 'l','a','n','k'}, 
		{'B', 'l','a','n','k'},
	},
	.eventTimes = {
		{13, 37, 68, 23}, 
		{4, 20, 11, 11}, 
		{13, 37, 11, 12}, 
		{4, 20, 23, 32}, 
		{13, 37, 23, 65},
	},
	.eventRecorded = {
		{0, 0, 0, 0, 0, 0},
	},
};

int times = 0;
bool char1Set, char2Set, char3Set, char4Set, char5Set, eventRec, eventEdit;
int letterNum, eventSetting, second, minute, hour, day, month, staticSec, staticMin, staticHour;
int eventEditing = 1;
int desText = 0;
int settingEvent = 0;
int animationSpeed = 300;
int eventAmount, valueRead, valueWritten, one, two;

static SimpleMenuSection op_menu_sections[2];
static SimpleMenuItem op_first_menu_items[3];
static SimpleMenuItem op_second_menu_items[2];

static SimpleMenuSection ev_menu_sections[1];
static SimpleMenuItem ev_first_menu_items[5];

GRect start;
int clear1, clear2, clear3, clear4, clear5;
char eventBuffer[] = "blank";
char eventBuffer1[] = "blank";
char eventBuffer2[] = "blank";
char eventBuffer3[] = "blank";
char eventBuffer4[] = "blank";
char textBuffer[] = "A";
char timeSetBuffer[] = "Time: NA:NA DD/MM";
char timeSetBuffer1[] = "Time: NA:NA DD/MM";
char timeSetBuffer2[] = "Time: NA:NA DD/MM";
char timeSetBuffer3[] = "Time: NA:NA DD/MM";
char timeSetBuffer4[] = "Time: NA:NA DD/MM";
char charFix[1][1] = {{'b'},};
char charArray[1][37] = {{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '},};
bool event1, event2, event3, event4, event5;