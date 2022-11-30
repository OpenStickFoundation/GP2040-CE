#ifndef _DirectLEDs_H
#define _DirectLEDs_H

#include "gpaddon.h"

#include "GamepadEnums.h"

typedef enum
{
    DIRECTLED_TYPE_NONE = -1,
    DIRECTLED_TYPE_DIRECT = 0,
} DirectLEDType;

#define DIRECTLED_COUNT 4

#ifndef DIRECTLED_TYPE
#define DIRECTLED_TYPE DIRECTLED_TYPE_NONE
#endif

#ifndef DIRECTLED1_PIN
#define DIRECTLED1_PIN -1
#endif

#ifndef DIRECTLED2_PIN
#define DIRECTLED2_PIN -1
#endif

#ifndef DIRECTLED3_PIN
#define DIRECTLED3_PIN -1
#endif

#ifndef DIRECTLED4_PIN
#define DIRECTLED4_PIN -1
#endif

#ifndef DIRECTLED1_BUTTON
#define DIRECTLED1_BUTTON 0
#endif

#ifndef DIRECTLED2_BUTTON
#define DIRECTLED2_BUTTON 0
#endif

#ifndef DIRECTLED3_BUTTON
#define DIRECTLED3_BUTTON 0
#endif

#ifndef DIRECTLED4_BUTTON
#define DIRECTLED4_BUTTON 0
#endif

#ifndef DIRECTLED1_DPAD
#define DIRECTLED1_DPAD 0
#endif

#ifndef DIRECTLED2_DPAD
#define DIRECTLED2_DPAD 0
#endif

#ifndef DIRECTLED3_DPAD
#define DIRECTLED3_DPAD 0
#endif

#ifndef DIRECTLED4_DPAD
#define DIRECTLED4_DPAD 0
#endif

#if DIRECTLED1_BUTTON != 0 && DIRECTLED1_DPAD != 0
#error Cannot map Direct LED1 to both dpad and button
#endif

#if DIRECTLED2_BUTTON != 0 && DIRECTLED2_DPAD != 0
#error Cannot map Direct LED2 to both dpad and button
#endif

#if DIRECTLED3_BUTTON != 0 && DIRECTLED3_DPAD != 0
#error Cannot map Direct LED3 to both dpad and button
#endif

#if DIRECTLED4_BUTTON != 0 && DIRECTLED4_DPAD != 0
#error Cannot map Direct LED4 to both dpad and button
#endif

// Button Mask
#define DIRECTLED_BUTTON_MASK (GAMEPAD_MASK_B1 | GAMEPAD_MASK_B2 | GAMEPAD_MASK_B3 | GAMEPAD_MASK_B4 | \
                               GAMEPAD_MASK_L1 | GAMEPAD_MASK_R1 | GAMEPAD_MASK_L2 | GAMEPAD_MASK_R2)

const int DIRECTLED_PINS[] = {DIRECTLED1_PIN, DIRECTLED2_PIN, DIRECTLED3_PIN, DIRECTLED4_PIN};
const int DIRECTLED_BUTTONMAP[] = {DIRECTLED1_BUTTON, DIRECTLED2_BUTTON, DIRECTLED3_BUTTON, DIRECTLED4_BUTTON};
const int DIRECTLED_DPADMAP[] = {DIRECTLED1_DPAD, DIRECTLED2_DPAD, DIRECTLED3_DPAD, DIRECTLED4_DPAD};

// Direct LED Module Name
#define DirectLedName "Direct LEDs"

class DirectLEDAddon : public GPAddon
{
public:
    virtual bool available(); // GPAddon available
    virtual void setup();     // DirectLED Setup
    virtual void process();   // DirectLED Process
    virtual std::string name() { return DirectLedName; }

private:
};

#endif // _DirectLEDs_H_
