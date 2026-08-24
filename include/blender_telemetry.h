#ifndef _BLENDER_TELEMETRY_H
#define _BLENDER_TELEMETRY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SH1_TELEMETRY_PORT 40960
#define SH1_MAX_STREAMED_NPCS 8

#pragma pack(push, 1)
typedef struct {
    uint8_t  charaId;  // e_CharaId
    uint8_t  slot;     // NPC slot index
    int16_t  health;   // NPC health
    float    posX;     // Blender X (PSX X)
    float    posY;     // Blender Y (PSX Z)
    float    posZ;     // Blender Z (-PSX Y)
    float    rotY;     // Rotation in degrees
} s_Sh1NpcTelemetry;
#pragma pack(pop)

void BlenderTelemetry_Init(void);
void BlenderTelemetry_Send(float px, float py, float pz, float rotDeg, float cx, float cy, float cz, float wx, float wy, float wz, int cellX, int cellZ, const char* mapName, int health);
void BlenderTelemetry_SendWithMatrices(float px, float py, float pz, float rotDeg, float cx, float cy, float cz, float wx, float wy, float wz, int cellX, int cellZ, const char* mapName, int health, const int16_t* boneMats);
void BlenderTelemetry_SendFull(float px, float py, float pz, float rotDeg, float cx, float cy, float cz, float wx, float wy, float wz, int cellX, int cellZ, const char* mapName, int health, const int16_t* boneMats, uint8_t npcCount, const s_Sh1NpcTelemetry* npcs);
void BlenderTelemetry_Shutdown(void);

#ifdef __cplusplus
}
#endif

#endif // _BLENDER_TELEMETRY_H
