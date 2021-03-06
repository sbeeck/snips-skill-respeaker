#ifndef __COMMON_H__
#define __COMMON_H__

#include <fcntl.h>
#include <pthread.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define APP "snips-led-animation"
#define VERSION "1.6.3"
#define LAST_UPDATE "Jan-28-2019"
#define AUTHOR "KE FANG (SNIPS)"

#define NUM_TOPIC       10
#define HOT_ON          "hermes/hotword/toggleOn"
#define HOT_OFF         "hermes/hotword/toggleOff"
#define STA_LIS         "hermes/asr/startListening"
#define END_LIS         "hermes/asr/stopListening"
#define STA_SAY         "hermes/tts/say"
#define END_SAY         "hermes/tts/sayFinished"
#define SUD_ON          "hermes/feedback/sound/toggleOn"
#define SUD_OFF         "hermes/feedback/sound/toggleOff"
#define LED_ON          "hermes/feedback/led/toggleOn"
#define LED_OFF         "hermes/feedback/led/toggleOff"

#define STATE_NUM       6
#define ON_IDLE_STR     "on_idle"
#define ON_LISTEN_STR   "on_listen"
#define ON_SPEAK_STR    "on_speak"
#define TO_MUTE_STR     "to_mute"
#define TO_UNMUTE_STR   "to_unmute"
#define ON_DISABLED_STR "on_disabled"

typedef enum {
    ON_IDLE = 0,
    ON_LISTEN,
    ON_SPEAK,
    TO_MUTE,
    TO_UNMUTE,
    ON_DISABLED
}STATE;

#define C_MODEL_STR             "model"
#define C_LED_BRI_STR           "led_bri"
#define C_MQTT_HOST_STR         "mqtt_host"
#define C_MQTT_PORT_STR         "mqtt_port"
#define C_MQTT_USER_STR         "mqtt_username"
#define C_MQTT_PASS_STR         "mqtt_password"
#define C_ON_IDLE_STR           "on_idle"
#define C_ON_LISTEN_STR         "on_listen"
#define C_ON_SPEAK_STR          "on_speak"
#define C_TO_MUTE_STR           "to_mute"
#define C_TO_UNMUTE_STR         "to_unmute"
#define C_IDLE_COLOUR_STR       "idle_colour"
#define C_LISTEN_COLOUR_STR     "listen_colour"
#define C_SPEAK_COLOUR_STR      "speak_colour"
#define C_MUTE_COLOUR_STR       "mute_colour"
#define C_UNMUTE_COLOUR_STR     "unmute_colour"
#define C_NIGHTMODE_STR         "nightmode"
#define C_GO_SLEEP_STR          "go_sleep"
#define C_GO_WEAK_STR           "go_wake"
#define C_ON_DISABLED_STR       "on_disabled"
#define C_SITE_ID_STR           "site_id"
#define C_FEEDBACK_SOUND_STR    "feedback_sound"

#define CONFIG_FILE "config.ini"

#define CLIENT_ID_LEN 10

#define RED_C    0xFF0000
#define GREEN_C  0x00FF00
#define BLUE_C   0x0000FF
#define YELLOW_C 0xFFFF00
#define PURPLE_C 0xFF00FF
#define TEAL_C   0x00FFFF
#define ORANGE_C 0xFF8000

#define GLOBAL_BRIGHTNESS 31

typedef struct{
    uint32_t idle;
    uint32_t listen;
    uint32_t speak;
    uint32_t mute;
    uint32_t unmute;
}COLOURS;

typedef struct{
    int number;
    int spi_bus;
    int spi_dev;
}HW_LED_SPEC;

typedef struct{
    int pin;
    int val;
}HW_GPIO_SPEC;

typedef struct{
    /* Hardware */
    char hardware_model[50];
    HW_LED_SPEC LEDs;
    HW_GPIO_SPEC power;
    HW_GPIO_SPEC button;

    /* Brightness */
    uint8_t max_brightness;
    /* MQTT connection */
    char mqtt_host[50];
    char mqtt_port[50];
    char mqtt_user[50];
    char mqtt_pass[50];

    /* SiteId */
    char snips_site_id[50];

    /* Client ID */
    char *client_id;

    /* Animation thread */
    pthread_t curr_thread;
    STATE     curr_state;

    /* Colour */
    COLOURS animation_color;

    /* Sleep mode */
    uint8_t sleep_hour;
    uint8_t sleep_minute;
    uint8_t wake_hour;
    uint8_t wake_minute;

    /* Flags */
    volatile sig_atomic_t   if_terminate;
    uint8_t                 if_update;
    uint8_t                 if_sleepmode;
    uint8_t                 if_disable;

    /* Animation Enable */
    uint8_t animation_enable[STATE_NUM];

    /* Feedback sound */
    uint8_t if_mute;
}SNIPS_RUN_PARA;

#define CLIENT_ID_LEN 10

#endif