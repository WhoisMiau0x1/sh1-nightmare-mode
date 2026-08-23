@echo off
setlocal
echo ========================================================
echo   Building Nightmare Mode Plugin for Silent Hill PC
echo ========================================================

:: Detect MinGW / GCC
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    if exist "C:\msys64\mingw64\bin\gcc.exe" (
        set "PATH=C:\msys64\mingw64\bin;%PATH%"
    ) else (
        echo [ERROR] GCC compiler not found in PATH or C:\msys64\mingw64\bin.
        echo Please install MinGW-w64 or MSYS2 to build this plugin.
        pause
        exit /b 1
    )
)

if not exist "bin" mkdir bin
if not exist "bin\plugins" mkdir bin\plugins

echo [*] Compiling nightmare_mode.dll...
gcc -shared -O2 -s ^
  -DSH_PC_PORT -DVER_USA -DSKIP_ASM -DPSYX_SKIP_FRAMEBUFFER_STORE ^
  -Dstatic_assert=_Static_assert ^
  -I"include" ^
  -I"..\silent-hill-decomp-pc-port\pc_port\include" ^
  -I"..\silent-hill-decomp-pc-port\include" ^
  -I"..\silent-hill-decomp-pc-port\pc_port\include\psyq_compat" ^
  -I"..\silent-hill-decomp-pc-port\pc_port\PsyCross\include\psx" ^
  -I"..\silent-hill-decomp-pc-port\pc_port\PsyCross\include" ^
  src\nightmare_plugin.c ^
  -L"..\silent-hill-decomp-pc-port\pc_port\dist" -lSilentHillPC ^
  -o "bin\plugins\nightmare_mode.dll"

if %errorlevel% equ 0 (
    echo [SUCCESS] nightmare_mode.dll built successfully in bin\plugins\
) else (
    echo [!] Direct link failed. Compiling standalone export DLL...
    gcc -shared -O2 -s ^
      -DSH_PC_PORT -DVER_USA -DSKIP_ASM -DPSYX_SKIP_FRAMEBUFFER_STORE ^
      -Dstatic_assert=_Static_assert ^
      -I"include" ^
      src\nightmare_plugin.c ^
      -o "bin\plugins\nightmare_mode.dll"
    if %errorlevel% equ 0 (
        echo [SUCCESS] Standalone nightmare_mode.dll built successfully in bin\plugins\
    ) else (
        echo [ERROR] Compilation failed!
        pause
        exit /b 1
    )
)

echo.
echo To install, copy bin\plugins\nightmare_mode.dll to your Silent Hill PC 'plugins\' folder.
pause
