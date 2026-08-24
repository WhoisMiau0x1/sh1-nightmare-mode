/* pc_touch.h — on-screen (touch) gamepad for the Android/touch builds.
 *
 * The port drives the game through the emulated PSX pad word in PsyX_pad.cpp,
 * so the touch layer deliberately produces exactly that: an active-low 16-bit
 * button word plus left-stick bytes. Nothing about the game or the PSX input
 * path needs to know a finger produced them.
 *
 * Finger state is READ, not evented: SDL_GetNumTouchFingers/SDL_GetTouchFinger
 * expose the current down-fingers as state, which the pad tick can sample the
 * same way it samples SDL_GetKeyboardState. That keeps this out of the event
 * loop entirely (main_pc.c's loop needs no change) and makes the pad word a
 * pure function of what is on the glass this frame.
 */
#ifndef PC_TOUCH_H
#define PC_TOUCH_H

#ifdef __cplusplus
extern "C"
{
#endif

    /* Master switch. Defaults to 1 on Android, 0 elsewhere (a desktop with a
     * touchscreen should not grow a thumb-stick overlay unasked). */
    extern int g_PcTouchEnabled;

    /* Touch camera drag delta for right-screen look control */
    extern float g_PcTouchLookDx;
    extern float g_PcTouchLookDy;

    /* Sample the glass. Call once per pad tick, before the getters below. */
    void PcTouch_Update(void);

    /* Active-low PSX button word (PADstart/PADRdown/... from libetc.h), 0xFFFF when
     * nothing is pressed — the same convention the keyboard/controller word uses,
     * so callers just AND it in. */
    unsigned short PcTouch_PadWord(void);

    /* Left-stick position as PSX pad bytes (0..255, 128 = centered). Returns 1 when
     * the stick is actually being held (so the caller knows to switch the emulated
     * pad into analog mode), 0 when it is parked. */
    int PcTouch_LeftStick(unsigned char* outX, unsigned char* outY);

    /* Draw the overlay. Call with the default framebuffer bound, right before the
     * swap. Saves and restores every GL state it touches. */
    void PcTouch_Draw(void);

#ifdef __cplusplus
}
#endif

#endif /* PC_TOUCH_H */
