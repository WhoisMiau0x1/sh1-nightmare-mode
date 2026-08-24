/* PSY-Q to PsyCross compatibility shim */
#ifndef _PSYQ_COMPAT_LIBGPU_H
#define _PSYQ_COMPAT_LIBGPU_H
#include <libgpu.h>

/* The decomp's original psyq/libgpu.h defined RECT ({short x,y,w,h}); PsyCross
 * renamed the identical struct to RECT16. On Windows the name RECT also happens
 * to resolve via a transitive <windows.h>, so the desktop build never noticed
 * the shim dropped it. On Android/Linux there is no windows.h, so alias it here.
 * Layout is identical and the game only uses PSX fields (x,y,w,h), passing it to
 * StoreImage/LoadImage/SetDrawArea which take RECT16*. Guard against the Win32
 * RECT to avoid a redefinition when <windows.h> is present. */
#if !defined(_WIN32) && !defined(RECT)
typedef RECT16 RECT;
#endif
#endif
