CC ?= gcc
CFLAGS = -shared -O2 -s -DSH_PC_PORT -DVER_USA -DSKIP_ASM -DPSYX_SKIP_FRAMEBUFFER_STORE -Dstatic_assert=_Static_assert -Iinclude -I../silent-hill-decomp-pc-port/pc_port/include -I../silent-hill-decomp-pc-port/include -I../silent-hill-decomp-pc-port/pc_port/include/psyq_compat -I../silent-hill-decomp-pc-port/pc_port/PsyCross/include/psx -I../silent-hill-decomp-pc-port/pc_port/PsyCross/include
LDFLAGS = -L../silent-hill-decomp-pc-port/pc_port/dist -lSilentHillPC

TARGET_DIR = bin/plugins
TARGET = $(TARGET_DIR)/nightmare_mode.dll

all: $(TARGET)

$(TARGET): src/nightmare_plugin.c
	@mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $(TARGET) || $(CC) -shared -O2 -s -DSH_PC_PORT -DVER_USA -DSKIP_ASM -DPSYX_SKIP_FRAMEBUFFER_STORE -Dstatic_assert=_Static_assert -Iinclude $< -o $(TARGET)
	@echo "[SUCCESS] Built $(TARGET)"

clean:
	rm -rf bin/
