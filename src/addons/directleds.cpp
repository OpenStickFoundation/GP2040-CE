#include "addons/directleds.h"
#include "storagemanager.h"

bool DirectLEDAddon::available()
{
    return DIRECTLED_TYPE != DIRECTLED_TYPE_NONE;
}

void DirectLEDAddon::setup()
{
    for (int i = 0; i < DIRECTLED_COUNT; i++)
    {
        int p = DIRECTLED_PINS[i];
        if (p != -1)
        {
            gpio_init(p);
            gpio_set_dir(p, GPIO_OUT);
            gpio_put(p, 0); // default off
        }
    }
}

void DirectLEDAddon::process()
{
    Gamepad *gamepad = Storage::getInstance().GetGamepad();
    uint16_t buttonsPressed = gamepad->state.buttons & DIRECTLED_BUTTON_MASK;
    uint16_t dpadPressed = gamepad->state.dpad & GAMEPAD_MASK_DPAD;

    for (int i = 0; i < DIRECTLED_COUNT; i++)
    {
        int p = DIRECTLED_PINS[i];
        int b = DIRECTLED_BUTTONMAP[i];
        int d = DIRECTLED_DPADMAP[i];

        if (p == -1)
            continue;

        int ledVal = ((buttonsPressed & b) || (dpadPressed & d));

        gpio_put(p, ledVal);
    }
}
