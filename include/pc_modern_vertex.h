/* SPDX-License-Identifier: GPL-3.0-or-later */
#ifndef PC_MODERN_VERTEX_H
#define PC_MODERN_VERTEX_H

#include <stddef.h>
#include "PsyX/PsyX_render.h"

typedef GrVertex GrModernVertex;

#ifdef __cplusplus
extern "C" {
#endif

typedef enum PcVertexStream
{
    PC_VERTEX_STREAM_NONE = 0,
    PC_VERTEX_STREAM_LEGACY,
    PC_VERTEX_STREAM_MODERN
} PcVertexStream;

typedef struct PcVertexBatchDiscriminator
{
    PcVertexStream stream;
    size_t vertexCount;
} PcVertexBatchDiscriminator;

typedef void (*PcVertexBatchFlush)(PcVertexStream stream,
                                   size_t vertexCount,
                                   void* userData);

void Pc_ModernVertex_Upload(const GrModernVertex* vertices, int count);
int Pc_ModernVertex_UploadExact(GrModernVertex* vertices,
                                const unsigned short* sz,
                                int count);

void Pc_VertexBatch_Reset(PcVertexBatchDiscriminator* batch);
void Pc_VertexBatch_Select(PcVertexBatchDiscriminator* batch,
                           PcVertexStream stream,
                           PcVertexBatchFlush flush,
                           void* userData);
void Pc_VertexBatch_Add(PcVertexBatchDiscriminator* batch,
                        PcVertexStream stream,
                        size_t vertexCount,
                        PcVertexBatchFlush flush,
                        void* userData);
void Pc_VertexBatch_Flush(PcVertexBatchDiscriminator* batch,
                          PcVertexBatchFlush flush,
                          void* userData);

#ifdef __cplusplus
}
#endif

#endif /* PC_MODERN_VERTEX_H */
