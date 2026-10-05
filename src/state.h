#ifndef STATE_H
#define STATE_H

#include "Arduino.h"
#include "types.h"

// PINS ATTENTION CE SERA A CHANGER  C'EST JUSTE POUR MON CODE QUE JE METS CA

#define LED_ROUGE 1
#define LED_VERTE 2
#define LED_BLEU 3
#define PIN_IO 4
#define PIN_CLK 5
#define PIN_CE 6

// 𝐅𝐥𝐚𝐠𝐬
typedef u8 ComponentFlag;

#define COMPONENT_NONE      ((ComponentFlag)0)
#define COMPONENT_RTC       ((ComponentFlag)(1u << 0))
#define COMPONENT_RGB_LED   ((ComponentFlag)(1u << 1))
#define COMPONENT_BUZZER    ((ComponentFlag)(1u << 2))
#define COMPONENT_DISPLAY1  ((ComponentFlag)(1u << 3))
#define COMPONENT_DISPLAY2  ((ComponentFlag)(1u << 4))

// 𝐅𝐥𝐚𝐠𝐬: 𝐑𝐞𝐛𝐨𝐫𝐧
#define COMPONENT_DETECTED    (1u << 0)
#define COMPONENT_OPERATIONAL (1u << 1)

// Zustand deine Gesundheitz
typedef enum HealthState {
    HEALTH_LOW,
    HEALTH_NORMAL,
    HEALTH_HIGH,
    HEALTH_UNKNOWN
} HealthState;

// Main system state
typedef struct CoreState {
    // À changer en fonction de si ce sera du raw data ou du normalized 
    f32 ppgValue;

    u8 bpm;
    bool bpmValid;

    HealthState healthState;
} CoreState;

// État par composant
typedef struct ComponentStatus {
    u8 flags;
} ComponentStatus;

#endif