/*===================== begin_copyright_notice ==================================

Copyright (c) 2023-2025 Intel Corporation

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

======================= end_copyright_notice ==================================*/

#ifndef __MOS_MOCK_DEF_H__
#define __MOS_MOCK_DEF_H__

//
// Include standard headers for Ubuntu compatibility
//
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// Basic Types and Constants
//==============================================================================

/**
 * @brief MOS status codes
 */
typedef enum _MOS_STATUS
{
    MOS_STATUS_SUCCESS = 0,
    MOS_STATUS_NO_SPACE = 1,
    MOS_STATUS_INVALID_PARAMETER = 2,
    MOS_STATUS_INVALID_HANDLE = 3,
    MOS_STATUS_INVALID_FILE_SIZE = 4,
    MOS_STATUS_NULL_POINTER = 5,
    MOS_STATUS_FILE_EXISTS = 6,
    MOS_STATUS_FILE_NOT_FOUND = 7,
    MOS_STATUS_FILE_OPEN_FAILED = 8,
    MOS_STATUS_FILE_READ_ONLY = 9,
    MOS_STATUS_FILE_READ_FAILED = 10,
    MOS_STATUS_FILE_WRITE_FAILED = 11,
    MOS_STATUS_DIR_CREATE_FAILED = 12,
    MOS_STATUS_SET_FILE_POINTER_FAILED = 13,
    MOS_STATUS_LOAD_LIBRARY_FAILED = 14,
    MOS_STATUS_MORE_DATA = 15,
    MOS_STATUS_USER_CONTROL_MAX_NAME_SIZE = 16,
    MOS_STATUS_USER_CONTROL_MIN_DATA_SIZE = 17,
    MOS_STATUS_USER_CONTROL_MAX_DATA_SIZE = 18,
    MOS_STATUS_USER_FEATURE_KEY_READ_FAILED = 19,
    MOS_STATUS_USER_FEATURE_KEY_WRITE_FAILED = 20,
    MOS_STATUS_EVENT_WAIT_REGISTER_FAILED = 21,
    MOS_STATUS_EVENT_WAIT_UNREGISTER_FAILED = 22,
    MOS_STATUS_USER_FEATURE_KEY_OPEN_FAILED = 23,
    MOS_STATUS_HLT_INIT_FAILED = 24,
    MOS_STATUS_UNIMPLEMENTED = 25,
    MOS_STATUS_EXCEED_MAX_BB_SIZE = 26,
    MOS_STATUS_PLATFORM_NOT_SUPPORTED = 27,
    MOS_STATUS_CLIENT_AR_NO_SPACE = 28,
    MOS_STATUS_HUC_KERNEL_FAILED = 29,
    MOS_STATUS_NOT_ENOUGH_BUFFER = 30,
    MOS_STATUS_UNINITIALIZED = 31,
    MOS_STATUS_GPU_CONTEXT_ERROR = 32,
    MOS_STATUS_STILL_DRAWING = 33,
    MOS_STATUS_USER_FEATURE_READ_FAILED = 34,
    MOS_STATUS_UNKNOWN = 35
} MOS_STATUS;

/**
 * @brief Invalid handle definition
 */
#define MOS_INVALID_HANDLE  (void*)(-1)

/**
 * @brief Maximum engine instances per class
 */
#define MOS_MAX_ENGINE_INSTANCE_PER_CLASS 8
#define MAX_ENGINE_INSTANCE_PER_CLASS 8

//==============================================================================
// Hardware-related Enums
//==============================================================================

/**
 * @brief GPU node types
 */
typedef enum _GPUNODE_ORDINAL
{
    GPUNODE_3D = 0,    // Render engine
    GPUNODE_VIDEO = 1, // Video decode engine
    GPUNODE_VE = 2,    // Video enhancement engine
    GPUNODE_BLT = 3,   // Blitter engine
    GPUNODE_CCS0 = 4,  // Compute engine
    GPUNODE_VCS2 = 5,  // Video decode engine 2
    GPUNODE_GSC = 6,   // GSC engine
    GPUNODE_MAX = 7    // Max GPU node
} GPUNODE_ORDINAL;

#define MOS_GPU_NODE GPUNODE_ORDINAL
#define MOS_GPU_NODE_3D GPUNODE_3D         // render engine
#define MOS_GPU_NODE_COMPUTE GPUNODE_CCS0  // compute engine
#define MOS_GPU_NODE_VE GPUNODE_VE         // vebox engine
#define MOS_GPU_NODE_VIDEO GPUNODE_VIDEO   // vdbox0 engine
#define MOS_GPU_NODE_VIDEO2 GPUNODE_VCS2   // vdbox1 engine
#define MOS_GPU_NODE_BLT GPUNODE_BLT       // copy engine
#define MOS_GPU_NODE_GSC GPUNODE_GSC       // gsc engine
#define MOS_GPU_NODE_MAX GPUNODE_MAX

/**
 * @brief GPU context types
 */
typedef enum _MOS_GPU_CONTEXT
{
    MOS_GPU_CONTEXT_RENDER = 0,
    MOS_GPU_CONTEXT_RENDER2 = 1,
    MOS_GPU_CONTEXT_VIDEO = 2,
    MOS_GPU_CONTEXT_VIDEO2 = 3,
    MOS_GPU_CONTEXT_VIDEO3 = 4,
    MOS_GPU_CONTEXT_VIDEO4 = 5,
    MOS_GPU_CONTEXT_VEBOX = 6,
    MOS_GPU_OVERLAY_CONTEXT = 7,
    MOS_GPU_CONTEXT_VDBOX2_VIDEO = 8,  // VDBox2 Decode
    MOS_GPU_CONTEXT_VDBOX2_VIDEO2 = 9, // VDBox2 Decode Was
    MOS_GPU_CONTEXT_VDBOX2_VIDEO3 = 10, // VDBox2 PAK
    MOS_GPU_CONTEXT_RENDER3 = 11,      // MDF(aka. CM)
    MOS_GPU_CONTEXT_RENDER4 = 12,      // MDF Custom context
    MOS_GPU_CONTEXT_VEBOX2 = 13,       // Vebox2
    MOS_GPU_CONTEXT_COMPUTE = 14,      // Compute Context
    MOS_GPU_CONTEXT_CM_COMPUTE = 15,   // MDF Compute
    MOS_GPU_CONTEXT_RENDER_RA = 16,    // render context for RA mode
    MOS_GPU_CONTEXT_COMPUTE_RA = 17,   // compute context for RA mode
    MOS_GPU_CONTEXT_VIDEO5 = 18,       // Decode Node 0 Split 2
    MOS_GPU_CONTEXT_VIDEO6 = 19,       // Encode Node 0 Split 2
    MOS_GPU_CONTEXT_VIDEO7 = 20,       // Decode Node 0 Split 3
    MOS_GPU_CONTEXT_BLT = 21,
    MOS_GPU_CONTEXT_TEE = 22,          // TEE context
    MOS_GPU_CONTEXT_MAX = 23,
    MOS_GPU_CONTEXT_INVALID_HANDLE = 0xFFFFA
} MOS_GPU_CONTEXT, *PMOS_GPU_CONTEXT;

/**
 * @brief Component types
 */
typedef enum _MOS_COMPONENT
{
    COMPONENT_UNKNOWN = 0,
    COMPONENT_LibVA,
    COMPONENT_EMULATION,
    COMPONENT_CM,
    COMPONENT_Encode,
    COMPONENT_Decode,
    COMPONENT_VPCommon,
    COMPONENT_VPreP,
    COMPONENT_CP,
    COMPONENT_MEMDECOMP,
    COMPONENT_MCPY,
    COMPONENT_OCA,
    COMPONENT_MOS,
} MOS_COMPONENT;

/**
 * @brief VDBOX node index
 */
typedef enum _MOS_VDBOX_NODE_IND
{
    MOS_VDBOX_NODE_INVALID = -1,
    MOS_VDBOX_NODE_1 = 0,
    MOS_VDBOX_NODE_2 = 1
} MOS_VDBOX_NODE_IND;

/**
 * @brief VEBOX node index
 */
typedef enum _MOS_VEBOX_NODE_IND
{
    MOS_VEBOX_NODE_INVALID = -1,
    MOS_VEBOX_NODE_1 = 0,
    MOS_VEBOX_NODE_2 = 1
} MOS_VEBOX_NODE_IND;

/**
 * @brief Resource types
 */
typedef enum _MOS_GFXRES_TYPE
{
    MOS_GFXRES_INVALID = -1,
    MOS_GFXRES_BUFFER,
    MOS_GFXRES_2D,
    MOS_GFXRES_VOLUME,
    MOS_GFXRES_MAX
} MOS_GFXRES_TYPE;

/**
 * @brief Resource flags
 */
typedef enum _MOS_GFXRES_FLAGS
{
    MOS_GFXRES_FLAG_NONE = 0,
    MOS_GFXRES_FLAG_CACHED = 1,
    MOS_GFXRES_FLAG_SHARED = 2,
    MOS_GFXRES_FLAG_COMPRESSED = 4,
    MOS_GFXRES_FLAG_PERSISTENT = 8
} MOS_GFXRES_FLAGS;

/**
 * @brief Tile types
 */
typedef enum _MOS_TILE_TYPE
{
    MOS_TILE_LINEAR = 0,
    MOS_TILE_X,
    MOS_TILE_Y,
    MOS_TILE_YF,
    MOS_TILE_YS,
    MOS_TILE_MAX
} MOS_TILE_TYPE;

/**
 * @brief Tile mode GMM
 */
typedef enum _MOS_TILE_MODE_GMM
{
    MOS_TILE_LINEAR_GMM = 0,
    MOS_TILE_X_GMM,
    MOS_TILE_Y_GMM,
    MOS_TILE_YF_GMM,
    MOS_TILE_YS_GMM,
    MOS_TILE_MAX_GMM
} MOS_TILE_MODE_GMM;

/**
 * @brief Pixel formats
 */
typedef enum _MOS_FORMAT
{
    MOS_FORMAT_INVALID = 0,
    MOS_FORMAT_NV12,
    MOS_FORMAT_YUY2,
    MOS_FORMAT_YUYV,
    MOS_FORMAT_UYVY,
    MOS_FORMAT_AYUV,
    MOS_FORMAT_BUFFER,
    MOS_FORMAT_L8,
    MOS_FORMAT_A8,
    MOS_FORMAT_BGRA,
    MOS_FORMAT_RGBA,
    MOS_FORMAT_R32U,
    MOS_FORMAT_R32F,
    MOS_FORMAT_R8G8B8A8,
    MOS_FORMAT_R8U,
    MOS_FORMAT_P010,
    MOS_FORMAT_P016,
    MOS_FORMAT_Y210,
    MOS_FORMAT_Y216,
    MOS_FORMAT_Y410,
    MOS_FORMAT_Y416,
    Format_Buffer,          //!< Used for creating buffer resource (linear)
    Format_Buffer_2D,          //!< Encoder 2D linear buffer.

    MOS_FORMAT_MAX
} MOS_FORMAT;

/**
 * @brief S3D channel types
 */
typedef enum _MOS_S3D_CHANNEL
{
    MOS_S3D_NONE = 0,
    MOS_S3D_LEFT,
    MOS_S3D_RIGHT,
    MOS_S3D_MAX
} MOS_S3D_CHANNEL;

/**
 * @brief Resource MMC modes
 */
typedef enum _MOS_RESOURCE_MMC_MODE
{
    MOS_MMC_DISABLED = 0,
    MOS_MMC_VERTICAL,
    MOS_MMC_HORIZONTAL,
    MOS_MMC_MAX
} MOS_RESOURCE_MMC_MODE;

/**
 * @brief Memory compression states
 */
typedef enum _MOS_MEMCOMP_STATE
{
    MOS_MEMCOMP_DISABLED = 0,
    MOS_MEMCOMP_RC,
    MOS_MEMCOMP_MC,
    MOS_MEMCOMP_RC_RENDERTARGET,
    MOS_MEMCOMP_HORIZONTAL,
    MOS_MEMCOMP_VERTICAL,
    MOS_MEMCOMP_MAX
} MOS_MEMCOMP_STATE;

/**
 * @brief Hardware resource definitions
 */
typedef enum _MOS_HW_RESOURCE_DEF
{
    // PAT Media Usages
    MOS_HW_RESOURCE_USAGE_MEDIA_BATCH_BUFFERS,
    // DECODE
    MOS_HW_RESOURCE_USAGE_DECODE_INTERNAL_READ_WRITE_CACHE,
    MOS_HW_RESOURCE_USAGE_DECODE_INTERNAL_READ_WRITE_NOCACHE,
    MOS_HW_RESOURCE_USAGE_DECODE_INPUT_BITSTREAM,
    MOS_HW_RESOURCE_USAGE_DECODE_OUTPUT_PICTURE,
    // ENCODE
    MOS_HW_RESOURCE_USAGE_ENCODE_INPUT_RAW,
    MOS_HW_RESOURCE_USAGE_ENCODE_INPUT_RECON,
    MOS_HW_RESOURCE_USAGE_ENCODE_OUTPUT_PICTURE,
    MOS_HW_RESOURCE_USAGE_ENCODE_OUTPUT_BITSTREAM,
    MOS_HW_RESOURCE_DEF_MAX
} MOS_HW_RESOURCE_DEF;

/**
 * @brief Hardware command types
 */
typedef enum _MOS_HW_COMMAND_ENUM
{
    MOS_HW_COMMAND_NULL = 0, //!<-- This stays zero.
    MOS_MI_BATCH_BUFFER_START,
    MOS_MI_CLFLUSH,
    MOS_MI_CONDITIONAL_BATCH_BUFFER_END,
    MOS_MI_COPY_MEM_MEM,
    MOS_MI_FLUSH_DW,
    MOS_MI_LOAD_REGISTER_MEM,
    MOS_MI_REPORT_PERF_COUNT,
    MOS_MI_SEMAPHORE_MBOX,
    MOS_MI_SEMAPHORE_SIGNAL,
    MOS_MI_SEMAPHORE_WAIT,
    MOS_MI_STORE_DATA_IMM,
    MOS_MI_STORE_DATA_INDEX,
    MOS_MI_STORE_REGISTER_MEM,
    MOS_MI_UPDATE_GTT,
    MOS_PIPE_CONTROL,
    MOS_HW_COMMANDS, //!<-- This stays last.

    // Those commands below are not included in GMM
    MOS_MI_BATCH_BUFFER_START_RCS,
    MOS_MFX_PIPE_BUF_ADDR,
    MOS_MFX_INDIRECT_OBJ_BASE_ADDR,
    MOS_MFX_BSP_BUF_BASE_ADDR,
    MOS_MFX_AVC_DIRECT_MODE,
    MOS_MFX_VC1_DIRECT_MODE,
    MOS_MFX_VP8_PIC,
    MOS_MFX_DBK_OBJECT,
    MOS_HUC_DMEM,
    MOS_HUC_VIRTUAL_ADDR,
    MOS_HUC_IND_OBJ_BASE_ADDR,
    MOS_VDENC_PIPE_BUF_ADDR,
    MOS_SURFACE_STATE,
    MOS_SURFACE_STATE_ADV,
    MOS_STATE_BASE_ADDR,
    MOS_COMPUTE_WALKER,
    MOS_VEBOX_STATE,
    MOS_VEBOX_DI_IECP,
    MOS_VEBOX_TILING_CONVERT,
    MOS_SFC_STATE,
    MOS_MI_ATOMIC,
    MOS_MFX_CC_BASE_ADDR_STATE,
    MOS_VEBOX_SURFACE_STATE,
    MOS_OCA_RESERVED,
    MOS_HW_COMMAND_MAX
} MOS_HW_COMMAND;

/**
 * @brief VDBOX address shift
 */
typedef enum _MHW_VDBOX_ADDRESS_SHIFT
{
    MHW_VDBOX_SURFACE_STATE_SHIFT = 0,
    MHW_VDBOX_MFX_GENERAL_STATE_SHIFT = 6,
    MHW_VDBOX_HCP_GENERAL_STATE_SHIFT = 6,
    MHW_VDBOX_HUC_GENERAL_STATE_SHIFT = 6,
    MHW_VDBOX_MFX_UPPER_BOUND_STATE_SHIFT = 12,
    MHW_VDBOX_STATE_BASE_ADDRESS_SHIFT = 12,
    MHW_VDBOX_HCP_UPPER_BOUND_STATE_SHIFT = 12,
    MHW_VDBOX_HUC_UPPER_BOUND_STATE_SHIFT = 12,
    MHW_VDBOX_HUC_IMEM_STATE_SHIFT = 15,
    MHW_VDBOX_HCP_DECODED_BUFFER_SHIFT = 12
} MHW_VDBOX_ADDRESS_SHIFT;

/**
 * @brief Patch type
 */
typedef enum _MOS_PATCH_TYPE
{
    MOS_PATCH_TYPE_BASE_ADDRESS = 0,
    MOS_PATCH_TYPE_PITCH,
    MOS_PATCH_TYPE_UV_Y_OFFSET,
    MOS_PATCH_TYPE_BIND_ONLY,
    MOS_PATCH_TYPE_UV_BASE_ADDRESS,
    MOS_PATCH_TYPE_V_BASE_ADDRESS,
    MOS_PATCH_TYPE_MAX
} MOS_PATCH_TYPE;

//==============================================================================
// Forward Declarations
//==============================================================================

typedef struct _MOS_SPECIFIC_RESOURCE MOS_RESOURCE, *PMOS_RESOURCE;
typedef struct _MOS_COMMAND_BUFFER MOS_COMMAND_BUFFER, *PMOS_COMMAND_BUFFER;
typedef struct _MOS_INTERFACE MOS_INTERFACE, *PMOS_INTERFACE;
typedef struct _MOS_VIRTUALENGINE_INTERFACE MOS_VIRTUALENGINE_INTERFACE, *PMOS_VIRTUALENGINE_INTERFACE;
typedef struct MosVeInterface MosVeInterface;
typedef struct MosStreamState MosStreamState;
typedef struct _MOS_CMD_BUF_ATTRI_VE MOS_CMD_BUF_ATTRI_VE, *PMOS_CMD_BUF_ATTRI_VE;
typedef struct MosSpecificCommandBufferHandle* COMMAND_BUFFER_HANDLE;
typedef struct _MHW_BATCH_BUFFER MHW_BATCH_BUFFER, *PMHW_BATCH_BUFFER;
typedef struct _MOS_TEE_INPUT_OUTPUT_BUFFER_PARAMS MOS_TEE_INPUT_OUTPUT_BUFFER_PARAMS;
typedef uint32_t GPU_CONTEXT_HANDLE;

//==============================================================================
// Structure Definitions
//==============================================================================

/**
 * @brief Mock implementation of MOS_TEE_INPUT_OUTPUT_BUFFER_PARAMS
 */
struct _MOS_TEE_INPUT_OUTPUT_BUFFER_PARAMS
{
    uint32_t dummy;                 // Placeholder for TEE parameters
};

/**
 * @brief Mock implementation of MosVeInterface
 */
struct MosVeInterface
{
    uint32_t dummy;                 // Placeholder for VE interface
};

/**
 * @brief Mock implementation of MOS_VIRTUALENGINE_INTERFACE
 */
struct _MOS_VIRTUALENGINE_INTERFACE
{
    uint32_t dummy;                 // Placeholder for VE interface
};

/**
 * @brief MOCS parameters
 */
typedef struct _MOS_MOCS_PARAMS
{
    uint32_t index;
    uint32_t value;
} MOS_MOCS_PARAMS;

/**
 * @brief Resource offset
 */
typedef struct _MOS_RESOURCE_OFFSETS
{
    uint32_t BaseOffset;  //!< Nearest page aligned byte offset to surface origin
    uint32_t XOffset;     //!< X coordinate to surface origin. In Bytes
    uint32_t YOffset;     //!< Y coordinate to surface origin. In rows.
} MOS_RESOURCE_OFFSETS;

/**
 * @brief Plane offset
 */
typedef struct _MOS_PLANE_OFFSET
{
    uint32_t iSurfaceOffset;
    uint32_t iXOffset;
    uint32_t iYOffset;
} MOS_PLANE_OFFSET;

/**
 * @brief Resource free flags
 */
typedef struct _MOS_GFXRES_FREE_FLAGS
{
    union
    {
        struct
        {
            uint32_t AssumeNotInUse : 1;
            uint32_t SynchronousDestroy : 1;
            uint32_t Reserved : 30;
        };
        uint32_t Value;
    };
} MOS_GFXRES_FREE_FLAGS;

/**
 * @brief Lock parameters
 */
typedef struct _MOS_LOCK_PARAMS
{
    union
    {
        struct
        {
            uint32_t ReadOnly : 1;      //!< Lock only for reading.
            uint32_t WriteOnly : 1;     //!< Lock only for writing.
            uint32_t TiledAsTiled : 1;  //!< Means that you want to lock a tiled surface as tiled, not linear.
            uint32_t NoOverWrite : 1;   //!< No Over write for async locks
            uint32_t NoDecompress : 1;  //!< No decompression for memory compressed surface
            uint32_t Uncached : 1;      //!< Use uncached lock
            uint32_t ForceCached : 1;   //!< Prefer normal map to global GTT map(Uncached) if both can work
            uint32_t DumpBeforeSubmit : 1; //!< Lock only for dump before submit
            uint32_t DumpAfterSubmit : 1;  //!< Lock only for dump after submit
            uint32_t Reserved : 23;     //!< Reserved for expansion.
        };
        uint32_t Value;
    };
} MOS_LOCK_PARAMS, *PMOS_LOCK_PARAMS;

/**
 * @brief Resource allocation parameters
 */
typedef struct _MOS_ALLOC_GFXRES_PARAMS
{
    MOS_GFXRES_TYPE Type;           //!< [in] Basic resource geometry
    MOS_GFXRES_FLAGS Flags;         //!< [in] Flags to describe attributes
    union
    {
        uint32_t dwWidth;           //!< [in] Type == 2D || VOLUME, width in pixels.
        uint32_t dwBytes;           //!< [in] Type == BUFFER, # of bytes
    };
    uint32_t dwHeight;              //!< [in] Type == 2D || VOLUME, height in rows. Type == BUFFER, n/a
    uint32_t dwDepth;               //!< [in] 0: Implies 2D resource. >=1: volume resource
    uint32_t dwArraySize;           //!< [in] 0,1: 1 element. >1: N elements
    MOS_TILE_TYPE TileType;         //!< [in] Defines the layout of a physical page. Optimal choice depends on usage model.
    MOS_TILE_MODE_GMM m_tileModeByForce; //!< [in] Indicates a tile Encoding (aligned w/ GMM defination) needs set by force
    MOS_FORMAT Format;              //!< [in] Pixel format
    void *pSystemMemory;            //!< [in] Optional parameter. If non null, TileType must be set to linear.
    const char *pBufName;           //!< [in] Optional parameter. A string indicates the buffer name and is used for debugging. nullptr is OK.
    int32_t bIsCompressible;        //!< [in] Resource is compressible or not.
    MOS_RESOURCE_MMC_MODE CompressionMode; //!< [in] Compression mode.
    int32_t bIsPersistent;          //!< [in] Optional parameter. Used to indicate that resource can not be evicted
    int32_t bBypassMODImpl;
    int32_t dwMemType;              //!< [in] Optional paramerter. Prefer memory type
    MOS_HW_RESOURCE_DEF ResUsageType; //!< [in] the resource usage type to determine the cache policy
    bool hardwareProtected;         //!< [in] Flag as hint that Resource can be used as hw protected
} MOS_ALLOC_GFXRES_PARAMS, *PMOS_ALLOC_GFXRES_PARAMS;

/**
 * @brief Resource parameters
 */
typedef struct _MOS_RESOURCE_PARAMS
{
    PMOS_RESOURCE presResource;
    uint32_t dwOffset;
    uint32_t* pdwCmd;
    uint32_t dwLocationInCmd;
    uint32_t dwLsbNum;
    uint32_t dwOffsetInSSH;

    // Location of upper bound value relative to
    // allocated resource address. The upper bound
    // value will be set if this parameter is > zero
    uint32_t dwUpperBoundLocationOffsetFromCmd;
    uint32_t dwSize;

    MOS_HW_COMMAND HwCommandType;
    uint32_t dwSharedMocsOffset;
    uint32_t bIsWritable;

    // If the patching location does not start at bit 0 then the value to be patched needs to be shifted
    uint32_t shiftAmount;
    uint32_t shiftDirection;
    MOS_PATCH_TYPE patchType;
    MOS_MOCS_PARAMS mocsParams;
} MOS_RESOURCE_PARAMS, *PMOS_RESOURCE_PARAMS;

/**
 * @brief Mock implementation of MOS_SPECIFIC_RESOURCE
 */
struct _MOS_SPECIFIC_RESOURCE
{
    void *pData;                    // Pointer to resource data
    uint32_t size;                  // Size of resource
    uint32_t iWidth;                // Width
    uint32_t iHeight;               // Height
    uint32_t iPitch;                // Pitch
    MOS_FORMAT format;              // Format
    MOS_TILE_TYPE TileType;         // Tile type
    bool bMapped;                   // Whether resource is mapped
    void *pSystemAddress;           // System virtual address
    uint64_t iGfxAddress;           // Graphics virtual address
};

/**
 * @brief Buffer structure
 */
struct MOS_BUFFER
{
    MOS_RESOURCE OsResource;        //!< Buffer resource
    uint32_t size;                  //!< Buffer size
    const char* name;               //!< Buffer name
    bool initOnAllocate;            //!< Flag to indicate whether initialize when allocate
    uint8_t initValue;              //!< Initialize value when initOnAllocate is set
    bool bPersistent;               //!< Persistent flag
};
typedef MOS_BUFFER *PMOS_BUFFER;

/**
 * @brief Surface structure
 */
struct MOS_SURFACE
{
    MOS_RESOURCE OsResource;        // Surface Resource

    uint32_t dwArraySlice;          // [in]
    uint32_t dwMipSlice;            // [in]
    MOS_S3D_CHANNEL S3dChannel;     // [in]

    MOS_GFXRES_TYPE Type;           // [out] Basic resource geometry
    int32_t bOverlay;
    int32_t bFlipChain;

    union
    {
        struct
        {
            uint32_t dwFirstArraySlice; // [out] D3D11/D3D12. For arrayed surfaces, this is the current array slice specified by DDI at BLT time to use.
            uint32_t dwFirstMipSlice;   // [out] D3D11/D3D12. For mipped surfaces, this is the current mip map specified by DDI at BLT time to use.
        };
        uint32_t dwSubResourceIndex;    // [out] D3D9 only. D3D Sub resource index.
    };

    uint32_t dwWidth;               // [out] Type == 2D || VOLUME, width in pixels.
    uint32_t dwHeight;              // [out] Type == 2D || VOLUME, height in rows. Type == BUFFER, n/a
    uint32_t dwSize;                // [out] Type == 2D || VOLUME, the size of surface
    uint32_t dwDepth;               // [out] 0: Implies 2D resource. >=1: volume resource
    uint32_t dwArraySize;           // [out] 0,1: 1 element. >1: N elements
    uint32_t dwLockPitch;           // [out] pitch in bytes used for locking
    uint32_t dwPitch;               // [out] < RenderPitch > pitch in bytes used for programming HW
    uint32_t dwSlicePitch;          // [out] Type == VOLUME, byte offset to next slice. Type != VOLUME, n/a
    uint32_t dwQPitch;              // [out] QPitch - distance in rows between R-Planes used for programming HW
    MOS_TILE_TYPE TileType;         // [out] Defines the layout of a physical page. Optimal choice depends on usage model.
    MOS_TILE_MODE_GMM TileModeGMM;  // [out] Transparent GMM Tiletype specifying in hwcmd finally
    int32_t bGMMTileEnabled;        // [out] GMM defined tile mode flag
    MOS_FORMAT Format;              // [out] Pixel format
    int32_t bArraySpacing;          // [out] Array spacing
    int32_t bCompressible;          // [out] Memory compression
uint32_t dwOffset;              // Surface Offset (Y/Base)
    MOS_PLANE_OFFSET YPlaneOffset;  // Y surface plane offset
    MOS_PLANE_OFFSET UPlaneOffset;  // U surface plane offset
    MOS_PLANE_OFFSET VPlaneOffset;  // V surface plane offset
    uint32_t dwYPitch;              // Y surface plane pitch
    uint32_t dwUPitch;              // U surface plane pitch
    uint32_t dwVPitch;              // V surface plane pitch

    union
    {
        struct
        {
            MOS_RESOURCE_OFFSETS Y;
            MOS_RESOURCE_OFFSETS U;
            MOS_RESOURCE_OFFSETS V;
        } YUV;                      // [out] Valid for YUV & planar RGB formats. Invalid for RGB formats.

        MOS_RESOURCE_OFFSETS RGB;   // [out] Valid non planar RGB formats. Invalid for YUV and planar RGB formats.
    } RenderOffset;                 // [out] Offsets request by input parameters. Used to program HW.

    union
    {
        struct
        {
            uint32_t Y;
            uint32_t U;
            uint32_t V;
        } YUV;                      // [out] Valid for YUV & planar RGB formats. Invalid for RGB formats.

        uint32_t RGB;               // [out] Valid non planar RGB formats. Invalid for YUV and planar RGB formats.
    } LockOffset;                   // [out] Offset in bytes used for locking

    // Surface compression mode, enable flags
    int32_t bIsCompressed;          // [out] Memory compression flag
    MOS_RESOURCE_MMC_MODE CompressionMode; // [out] Memory compression mode
    uint32_t CompressionFormat;     // [out] Memory compression format
    MOS_MEMCOMP_STATE MmcState;     // Memory compression state
    uint32_t YoffsetForUplane;      // [out] Y offset from U plane to Y plane.
    uint32_t YoffsetForVplane;      // [out] Y offset from V plane to Y plane.

    // Surface cache Usage
    uint32_t CacheSetting;
#if (_DEBUG || _RELEASE_INTERNAL)
    uint32_t oldCacheSetting;
#endif
};
typedef MOS_SURFACE *PMOS_SURFACE;

/**
 * @brief Virtual engine initialization parameters
 */
typedef struct _MOS_VIRTUALENGINE_INIT_PARAMS
{
    bool bScalabilitySupported;

    // below only valid when scalability is supported
    bool bFESeparateSubmit;         //!< for decode only
    uint8_t ucMaxNumOfSdryCmdBufInOneFrame;
    uint8_t ucMaxNumPipesInUse;
    uint8_t ucNumOfSdryCmdBufSets;
} MOS_VIRTUALENGINE_INIT_PARAMS, *PMOS_VIRTUALENGINE_INIT_PARAMS;

/**
 * @brief Virtual engine hint parameters
 */
typedef struct _MOS_SPECIFIC_VE_HINT_PARAMS
{
    union
    {
        struct
        {
            // in VE2.0, that is ctx based scheduling, only FrontEndBackEndPresent is used, others are ignored.
            uint32_t UsingSFC : 1;              // Use SFC or not
            uint32_t UsingFrameSplit : 1;       // Frame split
            uint32_t NeedSyncWithPrevious : 1;  // Need to wait until previous submission from the same context is done
            uint32_t NoReRunAllowed : 1;        // Can't tolerate rerun
            uint32_t SameEngineAsLastSubmission : 1; // Submit on the same engine as previous, hint only, not hard requirement
            uint32_t HWRestrictedEngine : 1;    // HW restriction to specific engine
            uint32_t FrontEndBackEndPresent : 1; // Frame split decode
#if (_DEBUG || _RELEASE_INTERNAL)
            uint32_t Reserved : 24;
            uint32_t DebugOverride : 1;         // Debug & validation usage
#else
            uint32_t Reserved : 25;
#endif
        };

        uint32_t Flags;
    };

    // Number of batch buffers in frame split case (flag UsingFrameSplit is set), not used in all other cases
    uint32_t BatchBufferCount;

    // Batch buffer addresses in frame split case (flag UsingFrameSplit is set), not used in all other cases
    MOS_RESOURCE resScalableBatchBufs[MOS_MAX_ENGINE_INSTANCE_PER_CLASS];

    // Logical engine instances to submit workload on; valid only if flag DebugOverride is set.
    // WA here to use MAX_ENGINE_INSTANCE_PER_CLASS since the macro value is not changed in KMD api header
    uint8_t EngineInstance[MAX_ENGINE_INSTANCE_PER_CLASS];
} MOS_VIRTUALENGINE_HINT_PARAMS, *PMOS_VIRTUALENGINE_HINT_PARAMS;

/**
 * @brief GPU context creation options
 */
typedef struct _MOS_GPUCTX_CREATOPTIONS
{
    uint32_t CmdBufferNumScale;
    uint32_t RAMode;                // default using 0
    uint32_t ProtectMode;           // default using 0
    uint32_t gpuNode;

    uint8_t isRealTimePriority;     // 1 if context is created from real time priority command queue (run GT at higher frequency)
} MOS_GPUCTX_CREATOPTIONS, *PMOS_GPUCTX_CREATOPTIONS;

/**
 * @brief Enhanced GPU context creation options
 */
typedef struct _MOS_GPUCTX_CREATOPTIONS_ENHANCED : public _MOS_GPUCTX_CREATOPTIONS
{
    union
    {
        struct
        {
            uint32_t UsingSFC : 1;  // default using false
            uint32_t Reserved1 : 1; // remove HWRestrictedEngine
#if (_DEBUG || _RELEASE_INTERNAL)
            uint32_t Reserved : 29;
            uint32_t DebugOverride : 1; // Debug & validation usage only
#else
            uint32_t Reserved : 30;
#endif
        };
        uint32_t Flags;
    };

    uint32_t LRCACount;             // default using 1

#if (_DEBUG || _RELEASE_INTERNAL)
    // Logical engine instances used by this context; valid only if flag DebugOverride is set.
    uint8_t EngineInstance[MOS_MAX_ENGINE_INSTANCE_PER_CLASS];
#endif 
} MOS_GPUCTX_CREATOPTIONS_ENHANCED, *PMOS_GPUCTX_CREATOPTIONS_ENHANCED;

/**
 * @brief Command buffer attribute for virtual engine
 */
typedef struct _MOS_CMD_BUF_ATTRI_VE
{
    int32_t bUseVirtualEngineHint;
    MOS_VIRTUALENGINE_HINT_PARAMS VEngineHintParams;
    int32_t bTEEparamspresent;
    MOS_TEE_INPUT_OUTPUT_BUFFER_PARAMS TEEInputOutPutParams;
} MOS_CMD_BUF_ATTRI_VE, *PMOS_CMD_BUF_ATTRI_VE;

/**
 * @brief Command buffer attributes
 */
typedef struct _MOS_COMMAND_BUFFER_ATTRIBUTES
{
    int32_t bTurboMode;
    int32_t bIsMdfLoad;
    int32_t bMediaPreemptionEnabled;
    uint32_t dwNumRequestedEUSlices;
    uint32_t dwNumRequestedSubSlices;
    uint32_t dwNumRequestedEUs;
    int32_t bValidPowerGatingRequest;
    int32_t bEnableMediaFrameTracking;
    uint32_t dwMediaFrameTrackingTag;
    uint32_t dwMediaFrameTrackingAddrOffset;
    PMOS_RESOURCE resMediaFrameTrackingSurface;
    int32_t bUmdSSEUEnable;
    int32_t bFrequencyBoost;
    void* pAttriVe;
} MOS_COMMAND_BUFFER_ATTRIBUTES, *PMOS_COMMAND_BUFFER_ATTRIBUTES;

/**
 * @brief Command buffer structure
 */
struct _MOS_COMMAND_BUFFER
{
    MOS_RESOURCE OsResource;        //!< OS Resource
    PMHW_BATCH_BUFFER syncMhwBatchBuffer; //!< Pointer to sync mhw batch buffer

    // Common fields
    uint32_t *pCmdBase;             //!< Base address (CPU)
    uint32_t *pCmdPtr;              //!< Current address (CPU)
    int32_t iOffset;                //!< Current offset in bytes
    int32_t iRemaining;             //!< Remaining size
    int32_t iTokenOffsetInCmdBuf;   //!< Pointer to (Un)Secure token's next field Offset
    int32_t iCmdIndex;              //!< command buffer's index
    MOS_VDBOX_NODE_IND iVdboxNodeIndex; //!< Which VDBOX buffer is binded to
    MOS_VEBOX_NODE_IND iVeboxNodeIndex; //!< Which VEBOX buffer is binded to
    int32_t iSubmissionType;
    bool is1stLvlBB;                //!< indicate it's a first level BB or not
    struct _MOS_COMMAND_BUFFER *cmdBuf1stLvl; //!< Pointer to 1st level command buffer.
    MOS_COMMAND_BUFFER_ATTRIBUTES Attributes; //!< Attributes for the command buffer to be provided to KMD at submission
};

/**
 * @brief Mock implementation of MosSpecificCommandBufferHandle
 */
struct MosSpecificCommandBufferHandle
{
    MOS_COMMAND_BUFFER cmdBuffer;   // Command buffer
};

/**
 * @brief Virtual engine set parameters
 */
typedef struct _MOS_VIRTUALENGINE_SET_PARAMS
{
    bool bSameEngineAsLastSubmission; //deprecated
    bool bNeedSyncWithPrevious;       //deprecated
    bool bSFCInUse;                   //deprecated

    //below only valid when scalability is supported when hw has multi vdbox.
    bool bScalableMode;
    bool bHaveFrontEndCmds;
    uint8_t ucScalablePipeNum;
    MOS_RESOURCE veBatchBuffer[MOS_MAX_ENGINE_INSTANCE_PER_CLASS];
} MOS_VIRTUALENGINE_SET_PARAMS, *PMOS_VIRTUALENGINE_SET_PARAMS;

/**
 * @brief Stream state structure
 */
struct MosStreamState
{
    bool supportVirtualEngine = false; //!< Flag to indicate using virtual engine interface
    MosVeInterface *virtualEngineInterface = nullptr; //!< Interface to virtual engine state
    bool useHwSemaForResSyncInVe = false; //!< Flag to indicate if UMD need to send HW sema cmd under this OS when there is a resource sync need with Virtual Engine interface
    bool veEnable = false; //!< Flag to indicate virtual engine enabled (Can enable VE without using virtual engine interface)
    bool phasedSubmission = false; //!< Flag to indicate if secondary command buffers are submitted together or separately due to different OS
    bool frameSplit = true; //!< Flag to indicate if frame split is enabled (only active when phasedSubmission is true)
    int32_t hcpDecScalabilityMode = 0; //!< Hcp scalability mode
    int32_t veboxScalabilityMode = 0; //!< Vebox scalability mode

    bool ctxBasedScheduling = false; //!< Indicate if context based scheduling is enabled in this stream
    bool multiNodeScaling = false; //!< Flag to indicate if multi-node scaling is enabled for virtual engine (only active when ctxBasedScheduling is true)
};

/**
 * @brief Mock implementation of MHW_BATCH_BUFFER
 */
struct _MHW_BATCH_BUFFER
{
    MOS_RESOURCE OsResource;        // OS Resource
    uint32_t dwOffset;              // Offset to the beginning of the buffer
    bool bSecondLevel;              // Flag to indicate if this is a second level batch buffer
};

//==============================================================================
// MOS Interface Structure and Function Pointers
//==============================================================================

/**
 * @brief MOS interface structure
 */
struct _MOS_INTERFACE
{
    uint32_t CurrentGpuContextHandle;
    PMOS_VIRTUALENGINE_INTERFACE pVEInterf;
    uint32_t osStreamState = MOS_INVALID_HANDLE; // For APO path

    // Virtual Engine Functions
    MOS_STATUS (*pfnVirtualEngineInit)(
        PMOS_INTERFACE pOsInterface,
        PMOS_VIRTUALENGINE_HINT_PARAMS* veHitParams,
        MOS_VIRTUALENGINE_INIT_PARAMS& veInParams);

    MOS_STATUS (*pfnDestroyVeInterface)(
        PMOS_VIRTUALENGINE_INTERFACE *veInterface);

    // GPU Context Functions
    MOS_STATUS (*pfnSetGpuContextHandle)(
        PMOS_INTERFACE pOsInterface,
        GPU_CONTEXT_HANDLE gpuContextHandle,
        MOS_GPU_CONTEXT GpuContext);

    MOS_STATUS (*pfnCreateGpuContext)(
        PMOS_INTERFACE pOsInterface,
        MOS_GPU_CONTEXT GpuContext,
        MOS_GPU_NODE GpuNode,
        PMOS_GPUCTX_CREATOPTIONS createOption);

    MOS_STATUS (*pfnSetGpuContext)(
        PMOS_INTERFACE pOsInterface,
        MOS_GPU_CONTEXT GpuContext);

    void (*pfnResetOsStates)(
        PMOS_INTERFACE pOsInterface);

    MOS_STATUS (*pfnRegisterBBCompleteNotifyEvent)(
        PMOS_INTERFACE pOsInterface,
        MOS_GPU_CONTEXT GpuContext);

    MOS_STATUS (*pfnDestroyGpuContextByHandle)(
        PMOS_INTERFACE pOsInterface,
        GPU_CONTEXT_HANDLE gpuContextHandle);

    void (*pfnSetLatestVirtualNode)(
        PMOS_INTERFACE pOsInterface,
        MOS_GPU_NODE node);

    MOS_STATUS (*pfnCreateVideoNodeAssociation)(
        PMOS_INTERFACE pOsInterface,
        int32_t bSetVideoNode,
        MOS_GPU_NODE *pVideoNodeOrdinal);

    void (*pfnSetDecoderVirtualNodePerStream)(
        PMOS_INTERFACE pOsInterface,
        MOS_GPU_NODE node);

    MOS_STATUS (*pfnDestroyVideoNodeAssociation)(
        PMOS_INTERFACE pOsInterface,
        MOS_GPU_NODE VideoNodeOrdinal);

    // Command Buffer Functions
    MOS_STATUS (*pfnVerifyPatchListSize)(
        PMOS_INTERFACE pOsInterface,
        uint32_t dwRequestedSize);

    MOS_STATUS (*pfnVerifyCommandBufferSize)(
        PMOS_INTERFACE pOsInterface,
        uint32_t dwRequestedSize,
        uint32_t dwFlags);

    MOS_STATUS (*pfnResizeCommandBufferAndPatchList)(
        PMOS_INTERFACE pOsInterface,
        uint32_t dwRequestedCommandBufferSize,
        uint32_t dwRequestedPatchListSize,
        uint32_t dwFlags);

    MOS_STATUS (*pfnGetCommandBuffer)(
        PMOS_INTERFACE pOsInterface,
        PMOS_COMMAND_BUFFER pCmdBuffer,
        uint32_t dwFlags);

    void (*pfnReturnCommandBuffer)(
        PMOS_INTERFACE pOsInterface,
        PMOS_COMMAND_BUFFER pCmdBuffer,
        uint32_t dwFlags);

    MOS_STATUS (*pfnSetHintParams)(
        PMOS_INTERFACE pOsInterface,
        PMOS_VIRTUALENGINE_SET_PARAMS veParams);

    MOS_CMD_BUF_ATTRI_VE* (*pfnGetAttributeVeBuffer)(
        COMMAND_BUFFER_HANDLE cmdBuffer);

    MOS_STATUS (*pfnSubmitCommandBuffer)(
        PMOS_INTERFACE pOsInterface,
        PMOS_COMMAND_BUFFER pCmdBuffer,
        int32_t bNullRendering);

    // Resource Functions
    MOS_STATUS (*pfnAllocateResource)(
        PMOS_INTERFACE pOsInterface,
        PMOS_ALLOC_GFXRES_PARAMS pParams,
        PMOS_RESOURCE pOsResource);

    MOS_STATUS (*pfnFillResource)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pResource,
        uint32_t dwSize,
        uint8_t iValue);

    MOS_STATUS (*pfnGetResourceInfo)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pOsResource,
        PMOS_SURFACE pDetails);

    void (*pfnFreeResource)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pResource);

    void (*pfnFreeResourceWithFlag)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pResource,
        uint32_t uiFlag);

    void *(*pfnLockResource)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pResource,
        PMOS_LOCK_PARAMS pFlags);

    MOS_STATUS (*pfnUnlockResource)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pResource);

    MOS_STATUS (*pfnSkipResourceSync)(
        PMOS_RESOURCE pOsResource);

    void (*pfnSyncOnResource)(
        PMOS_INTERFACE pOsInterface,
        PMOS_RESOURCE pOsResource,
        MOS_GPU_CONTEXT requestorGPUCtx,
        int32_t bWriteOperation);

    MOS_STATUS (*pfnUpdateResourceUsageType)(
        PMOS_RESOURCE pOsResource,
        MOS_HW_RESOURCE_DEF resUsageType);

    // GFX Address Functions
    MOS_STATUS (*pfnInitMocsParams)(
        MOS_RESOURCE_PARAMS& resourceParam,
        uint32_t* addr,
        uint8_t bitFieldLow,
        uint8_t bitFieldHigh);

    MOS_STATUS (*pfnAddResourceToCmd)(
        PMOS_INTERFACE pOsInterface,
        PMOS_COMMAND_BUFFER pCmdBuffer,
        PMOS_RESOURCE_PARAMS pParams);

    MOS_STATUS (*pfnAddCommand)(
        PMOS_COMMAND_BUFFER pCmdBuffer,
        const void *pCmd,
        uint32_t dwCmdSize);

    // Other properties
    bool bSupportVirtualEngine;
    bool multiNodeScaling;
};

//==============================================================================
// Utility Macros
//==============================================================================

#define Mos_ResourceIsNull(resource) ((resource) == nullptr || (resource)->pData == nullptr)

#define MOS_OS_CHK_STATUS(status) \
    if (status != MOS_STATUS_SUCCESS) { \
        goto finish; \
    }

#define MOS_OS_CHK_STATUS_RETURN(status) \
    if (status != MOS_STATUS_SUCCESS) { \
        return status; \
    }

#define MOS_OS_CHK_NULL(pointer) \
    if (pointer == nullptr) { \
        return MOS_STATUS_NULL_POINTER; \
    }

#define MOS_OS_CHK_NULL_RETURN(pointer) \
    if (pointer == nullptr) { \
        return MOS_STATUS_NULL_POINTER; \
    }

#define MOS_OS_NORMALMESSAGE(_message, ...) \
    printf(_message "\n", ##__VA_ARGS__)

#define MOS_OS_ASSERTMESSAGE(_message, ...) \
    printf(_message "\n", ##__VA_ARGS__)

#define MOS_VE_SUPPORTED(pOsInterface) \
    (pOsInterface ? pOsInterface->bSupportVirtualEngine : false)

#define MOS_VE_MULTINODESCALING_SUPPORTED(pOsInterface) \
    (pOsInterface ? pOsInterface->multiNodeScaling : false)

#define MOS_New(classType, ...) new classType(__VA_ARGS__)
#define MOS_Delete(ptr) delete ptr 

#define MOS_SecureMemcpy(pDestination, dstLength, pSource, srcLength) memcpy(pDestination, pSource, srcLength)
#define MOS_ALIGN_CEIL(_a, _alignment)      (((_a) + ((_alignment)-1)) & (~((_alignment)-1)))

#define MOS_OS_FUNCTION_ENTER 

#define MOS_ZeroMemory(pDestination, stLength) memset(pDestination, 0, stLength)

//==============================================================================
// Mock Implementation Functions
//==============================================================================

/**
 * @brief Mock implementation of VirtualEngineInit
 */
static MOS_STATUS MockVirtualEngineInit(
    PMOS_INTERFACE pOsInterface,
    PMOS_VIRTUALENGINE_HINT_PARAMS* veHitParams,
    MOS_VIRTUALENGINE_INIT_PARAMS& veInParams)
{
    if (pOsInterface == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Allocate hint params if requested
    if (veHitParams != nullptr && *veHitParams == nullptr)
    {
        *veHitParams = (PMOS_VIRTUALENGINE_HINT_PARAMS)malloc(sizeof(MOS_VIRTUALENGINE_HINT_PARAMS));
        if (*veHitParams == nullptr)
        {
            return MOS_STATUS_NO_SPACE;
        }
        memset(*veHitParams, 0, sizeof(MOS_VIRTUALENGINE_HINT_PARAMS));
    }

    // Create VE interface if not already created
    if (pOsInterface->pVEInterf == nullptr)
    {
        pOsInterface->pVEInterf = (PMOS_VIRTUALENGINE_INTERFACE)malloc(sizeof(MOS_VIRTUALENGINE_INTERFACE));
        if (pOsInterface->pVEInterf == nullptr)
        {
            return MOS_STATUS_NO_SPACE;
        }
        memset(pOsInterface->pVEInterf, 0, sizeof(MOS_VIRTUALENGINE_INTERFACE));
    }

    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of DestroyVeInterface
 */
static MOS_STATUS MockDestroyVeInterface(
    PMOS_VIRTUALENGINE_INTERFACE *veInterface)
{
    if (veInterface == nullptr || *veInterface == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    free(*veInterface);
    *veInterface = nullptr;
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of SetGpuContextHandle
 */
static MOS_STATUS MockSetGpuContextHandle(
    PMOS_INTERFACE pOsInterface,
    GPU_CONTEXT_HANDLE gpuContextHandle,
    MOS_GPU_CONTEXT GpuContext)
{
    if (pOsInterface == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    pOsInterface->CurrentGpuContextHandle = gpuContextHandle;
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of CreateGpuContext
 */
static MOS_STATUS MockCreateGpuContext(
    PMOS_INTERFACE pOsInterface,
    MOS_GPU_CONTEXT GpuContext,
    MOS_GPU_NODE GpuNode,
    PMOS_GPUCTX_CREATOPTIONS createOption)
{
    if (pOsInterface == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Simulate creating a GPU context by assigning a handle
    pOsInterface->CurrentGpuContextHandle = (GPU_CONTEXT_HANDLE)GpuContext;
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of SetGpuContext
 */
static MOS_STATUS MockSetGpuContext(
    PMOS_INTERFACE pOsInterface,
    MOS_GPU_CONTEXT GpuContext)
{
    if (pOsInterface == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    pOsInterface->CurrentGpuContextHandle = (GPU_CONTEXT_HANDLE)GpuContext;
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of ResetOsStates
 */
static void MockResetOsStates(
    PMOS_INTERFACE pOsInterface)
{
    // Nothing to do in mock implementation
}

/**
 * @brief Mock implementation of RegisterBBCompleteNotifyEvent
 */
static MOS_STATUS MockRegisterBBCompleteNotifyEvent(
    PMOS_INTERFACE pOsInterface,
    MOS_GPU_CONTEXT GpuContext)
{
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of DestroyGpuContextByHandle
 */
static MOS_STATUS MockDestroyGpuContextByHandle(
    PMOS_INTERFACE pOsInterface,
    GPU_CONTEXT_HANDLE gpuContextHandle)
{
    if (pOsInterface == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    if (pOsInterface->CurrentGpuContextHandle == gpuContextHandle)
    {
        pOsInterface->CurrentGpuContextHandle = 0;
    }
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of SetLatestVirtualNode
 */
static void MockSetLatestVirtualNode(
    PMOS_INTERFACE pOsInterface,
    MOS_GPU_NODE node)
{
    // Nothing to do in mock implementation
}

/**
 * @brief Mock implementation of CreateVideoNodeAssociation
 */
static MOS_STATUS MockCreateVideoNodeAssociation(
    PMOS_INTERFACE pOsInterface,
    int32_t bSetVideoNode,
    MOS_GPU_NODE *pVideoNodeOrdinal)
{
    if (pOsInterface == nullptr || pVideoNodeOrdinal == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Set default video node if requested
    if (bSetVideoNode)
    {
        *pVideoNodeOrdinal = MOS_GPU_NODE_VIDEO;
    }
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of SetDecoderVirtualNodePerStream
 */
static void MockSetDecoderVirtualNodePerStream(
    PMOS_INTERFACE pOsInterface,
    MOS_GPU_NODE node)
{
    // Nothing to do in mock implementation
}

/**
 * @brief Mock implementation of DestroyVideoNodeAssociation
 */
static MOS_STATUS MockDestroyVideoNodeAssociation(
    PMOS_INTERFACE pOsInterface,
    MOS_GPU_NODE VideoNodeOrdinal)
{
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of VerifyPatchListSize
 */
static MOS_STATUS MockVerifyPatchListSize(
    PMOS_INTERFACE pOsInterface,
    uint32_t dwRequestedSize)
{
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of VerifyCommandBufferSize
 */
static MOS_STATUS MockVerifyCommandBufferSize(
    PMOS_INTERFACE pOsInterface,
    uint32_t dwRequestedSize,
    uint32_t dwFlags)
{
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of ResizeCommandBufferAndPatchList
 */
static MOS_STATUS MockResizeCommandBufferAndPatchList(
    PMOS_INTERFACE pOsInterface,
    uint32_t dwRequestedCommandBufferSize,
    uint32_t dwRequestedPatchListSize,
    uint32_t dwFlags)
{
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of GetCommandBuffer
 */
static MOS_STATUS MockGetCommandBuffer(
    PMOS_INTERFACE pOsInterface,
    PMOS_COMMAND_BUFFER pCmdBuffer,
    uint32_t dwFlags)
{
    if (pOsInterface == nullptr || pCmdBuffer == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Allocate a simple command buffer
    const uint32_t cmdBufSize = 4096;
    pCmdBuffer->pCmdBase = (uint32_t*)malloc(cmdBufSize);
    if (pCmdBuffer->pCmdBase == nullptr)
    {
        return MOS_STATUS_NO_SPACE;
    }

    memset(pCmdBuffer->pCmdBase, 0, cmdBufSize);
    pCmdBuffer->pCmdPtr = pCmdBuffer->pCmdBase;
    pCmdBuffer->iOffset = 0;
    pCmdBuffer->iRemaining = cmdBufSize;
    pCmdBuffer->iCmdIndex = 0;
    pCmdBuffer->is1stLvlBB = true;
    pCmdBuffer->iVdboxNodeIndex = MOS_VDBOX_NODE_1;
    pCmdBuffer->iVeboxNodeIndex = MOS_VEBOX_NODE_1;

    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of ReturnCommandBuffer
 */
static void MockReturnCommandBuffer(
    PMOS_INTERFACE pOsInterface,
    PMOS_COMMAND_BUFFER pCmdBuffer,
    uint32_t dwFlags)
{
    if (pOsInterface == nullptr || pCmdBuffer == nullptr)
    {
        return;
    }

    if (pCmdBuffer->pCmdBase != nullptr)
    {
        free(pCmdBuffer->pCmdBase);
        pCmdBuffer->pCmdBase = nullptr;
        pCmdBuffer->pCmdPtr = nullptr;
    }
}

/**
 *
* @brief Mock implementation of SetHintParams
 */
static MOS_STATUS MockSetHintParams(
    PMOS_INTERFACE pOsInterface,
    PMOS_VIRTUALENGINE_SET_PARAMS veParams)
{
    if (pOsInterface == nullptr || veParams == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of GetAttributeVeBuffer
 */
static MOS_CMD_BUF_ATTRI_VE* MockGetAttributeVeBuffer(
    COMMAND_BUFFER_HANDLE cmdBuffer)
{
    if (cmdBuffer == nullptr)
    {
        return nullptr;
    }

    // Create attribute buffer if needed
    if (cmdBuffer->cmdBuffer.Attributes.pAttriVe == nullptr)
    {
        cmdBuffer->cmdBuffer.Attributes.pAttriVe = malloc(sizeof(MOS_CMD_BUF_ATTRI_VE));
        if (cmdBuffer->cmdBuffer.Attributes.pAttriVe == nullptr)
        {
            return nullptr;
        }
        memset(cmdBuffer->cmdBuffer.Attributes.pAttriVe, 0, sizeof(MOS_CMD_BUF_ATTRI_VE));
    }

    return (MOS_CMD_BUF_ATTRI_VE*)cmdBuffer->cmdBuffer.Attributes.pAttriVe;
}

/**
 * @brief Mock implementation of SubmitCommandBuffer
 */
static MOS_STATUS MockSubmitCommandBuffer(
    PMOS_INTERFACE pOsInterface,
    PMOS_COMMAND_BUFFER pCmdBuffer,
    int32_t bNullRendering)
{
    if (pOsInterface == nullptr || pCmdBuffer == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // In a real implementation, this would submit the command buffer to the hardware
    // For mock, we just return success
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of AllocateResource
 */
static MOS_STATUS MockAllocateResource(
    PMOS_INTERFACE pOsInterface,
    PMOS_ALLOC_GFXRES_PARAMS pParams,
    PMOS_RESOURCE pOsResource)
{
    if (pOsInterface == nullptr || pParams == nullptr || pOsResource == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Determine size based on resource type
    uint32_t size = 0;
    if (pParams->Type == MOS_GFXRES_BUFFER)
    {
        size = pParams->dwBytes;
    }
    else if (pParams->Type == MOS_GFXRES_2D)
    {
        size = pParams->dwWidth * pParams->dwHeight;
        if (pParams->Format == MOS_FORMAT_NV12 || 
            pParams->Format == MOS_FORMAT_P010 || 
            pParams->Format == MOS_FORMAT_P016)
        {
            size = size * 3 / 2; // Account for Y + UV planes
        }
        else if (pParams->Format == MOS_FORMAT_YUY2 || 
                 pParams->Format == MOS_FORMAT_YUYV || 
                 pParams->Format == MOS_FORMAT_UYVY)
        {
            size = size * 2; // 16 bits per pixel
        }
        else if (pParams->Format == MOS_FORMAT_RGBA || 
                 pParams->Format == MOS_FORMAT_BGRA || 
                 pParams->Format == MOS_FORMAT_R8G8B8A8)
        {
            size = size * 4; // 32 bits per pixel
        }
    }
    else if (pParams->Type == MOS_GFXRES_VOLUME)
    {
        size = pParams->dwWidth * pParams->dwHeight * pParams->dwDepth;
    }

    // Allocate memory for the resource
    pOsResource->pData = malloc(size);
    if (pOsResource->pData == nullptr)
    {
        return MOS_STATUS_NO_SPACE;
    }

    // Initialize the resource
    memset(pOsResource->pData, 0, size);
    pOsResource->size = size;
    pOsResource->iWidth = pParams->dwWidth;
    pOsResource->iHeight = pParams->dwHeight;
    pOsResource->iPitch = pParams->dwWidth;
    pOsResource->format = pParams->Format;
    pOsResource->TileType = pParams->TileType;
    pOsResource->bMapped = false;
    pOsResource->pSystemAddress = nullptr;
    pOsResource->iGfxAddress = 0x10000000 + (uint64_t)((uintptr_t)pOsResource->pData); // Fake GPU address

    // Initialize with provided system memory if available
    if (pParams->pSystemMemory != nullptr)
    {
        memcpy(pOsResource->pData, pParams->pSystemMemory, size);
    }

    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of FillResource
 */
static MOS_STATUS MockFillResource(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pResource,
    uint32_t dwSize,
    uint8_t iValue)
{
    if (pOsInterface == nullptr || pResource == nullptr || pResource->pData == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Fill the resource with the specified value
    memset(pResource->pData, iValue, dwSize);
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of GetResourceInfo
 */
static MOS_STATUS MockGetResourceInfo(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pOsResource,
    PMOS_SURFACE pDetails)
{
    if (pOsInterface == nullptr || pOsResource == nullptr || pDetails == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Copy resource information to surface details
    pDetails->OsResource = *pOsResource;
    pDetails->dwWidth = pOsResource->iWidth;
    pDetails->dwHeight = pOsResource->iHeight;
    pDetails->dwPitch = pOsResource->iPitch;
    pDetails->Format = pOsResource->format;
    pDetails->TileType = pOsResource->TileType;

    // Set up plane offsets for YUV formats
    if (pOsResource->format == MOS_FORMAT_NV12 || 
        pOsResource->format == MOS_FORMAT_P010 || 
        pOsResource->format == MOS_FORMAT_P016)
    {
        pDetails->YPlaneOffset.iSurfaceOffset = 0;
        pDetails->UPlaneOffset.iSurfaceOffset = pOsResource->iWidth * pOsResource->iHeight;
        pDetails->VPlaneOffset.iSurfaceOffset = pOsResource->iWidth * pOsResource->iHeight;
    }

    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of FreeResource
 */
static void MockFreeResource(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pResource)
{
    if (pOsInterface == nullptr || pResource == nullptr)
    {
        return;
    }

    if (pResource->pData != nullptr)
    {
        free(pResource->pData);
        pResource->pData = nullptr;
    }

    pResource->size = 0;
    pResource->iWidth = 0;
    pResource->iHeight = 0;
    pResource->iPitch = 0;
    pResource->bMapped = false;
    pResource->pSystemAddress = nullptr;
    pResource->iGfxAddress = 0;
}

/**
 * @brief Mock implementation of FreeResourceWithFlag
 */
static void MockFreeResourceWithFlag(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pResource,
    uint32_t uiFlag)
{
    // For mock implementation, just call the regular free resource function
    MockFreeResource(pOsInterface, pResource);
}

/**
 * @brief Mock implementation of LockResource
 */
static void* MockLockResource(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pResource,
    PMOS_LOCK_PARAMS pFlags)
{
    if (pOsInterface == nullptr || pResource == nullptr || pResource->pData == nullptr)
    {
        return nullptr;
    }

    // Mark the resource as mapped and return the data pointer
    pResource->bMapped = true;
    pResource->pSystemAddress = pResource->pData;
    return pResource->pData;
}

/**
 * @brief Mock implementation of UnlockResource
 */
static MOS_STATUS MockUnlockResource(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pResource)
{
    if (pOsInterface == nullptr || pResource == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Mark the resource as unmapped
    pResource->bMapped = false;
    pResource->pSystemAddress = nullptr;
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of SkipResourceSync
 */
static MOS_STATUS MockSkipResourceSync(
    PMOS_RESOURCE pOsResource)
{
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of SyncOnResource
 */
static void MockSyncOnResource(
    PMOS_INTERFACE pOsInterface,
    PMOS_RESOURCE pOsResource,
    MOS_GPU_CONTEXT requestorGPUCtx,
    int32_t bWriteOperation)
{
    // Nothing to do in mock implementation
}

/**
 * @brief Mock implementation of UpdateResourceUsageType
 */
static MOS_STATUS MockUpdateResourceUsageType(
    PMOS_RESOURCE pOsResource,
    MOS_HW_RESOURCE_DEF resUsageType)
{
    if (pOsResource == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of InitMocsParams
 */
static MOS_STATUS MockInitMocsParams(
    MOS_RESOURCE_PARAMS& resourceParam,
    uint32_t* addr,
    uint8_t bitFieldLow,
    uint8_t bitFieldHigh)
{
    if (addr == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Set default MOCS parameters
    resourceParam.mocsParams.index = 0;
    resourceParam.mocsParams.value = 0;
    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of AddResourceToCmd
 */
static MOS_STATUS MockAddResourceToCmd(
    PMOS_INTERFACE pOsInterface,
    PMOS_COMMAND_BUFFER pCmdBuffer,
    PMOS_RESOURCE_PARAMS pParams)
{
    if (pOsInterface == nullptr || pCmdBuffer == nullptr || pParams == nullptr || pParams->presResource == nullptr)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // In a real implementation, this would patch the command buffer with the resource address
    // For mock, we just simulate patching by writing a fake address to the command location
    if (pParams->pdwCmd != nullptr)
    {
        uint64_t fakeAddress = pParams->presResource->iGfxAddress + pParams->dwOffset;
        uint32_t lowPart = (uint32_t)(fakeAddress & 0xFFFFFFFF);
        
        // Apply the address to the command
        *pParams->pdwCmd = lowPart;
    }

    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Mock implementation of AddCommand
 */
static MOS_STATUS MockAddCommand(
    PMOS_COMMAND_BUFFER pCmdBuffer,
    const void *pCmd,
    uint32_t dwCmdSize)
{
    if (pCmdBuffer == nullptr || pCmd == nullptr || dwCmdSize == 0)
    {
        return MOS_STATUS_NULL_POINTER;
    }

    // Check if there's enough space in the command buffer
    if (pCmdBuffer->iRemaining < (int32_t)dwCmdSize)
    {
        return MOS_STATUS_NO_SPACE;
    }

    // Copy the command into the command buffer
    memcpy(pCmdBuffer->pCmdPtr, pCmd, dwCmdSize);
    
    // Update command buffer pointers and remaining size
    pCmdBuffer->pCmdPtr = (uint32_t*)((uint8_t*)pCmdBuffer->pCmdPtr + dwCmdSize);
    pCmdBuffer->iOffset += dwCmdSize;
    pCmdBuffer->iRemaining -= dwCmdSize;

    return MOS_STATUS_SUCCESS;
}

/**
 * @brief Creates and initializes a MOS interface
 * 
 * @return Pointer to initialized MOS_INTERFACE structure
 */
inline PMOS_INTERFACE CreateMosInterface()
{
    PMOS_INTERFACE pOsInterface = (PMOS_INTERFACE)malloc(sizeof(MOS_INTERFACE));
    if (pOsInterface == nullptr)
    {
        return nullptr;
    }

    // Initialize the interface with default values
    memset(pOsInterface, 0, sizeof(MOS_INTERFACE));
    
    // Set up function pointers
    pOsInterface->pfnVirtualEngineInit = MockVirtualEngineInit;
    pOsInterface->pfnDestroyVeInterface = MockDestroyVeInterface;
    pOsInterface->pfnSetGpuContextHandle = MockSetGpuContextHandle;
    pOsInterface->pfnCreateGpuContext = MockCreateGpuContext;
    pOsInterface->pfnSetGpuContext = MockSetGpuContext;
    pOsInterface->pfnResetOsStates = MockResetOsStates;
    pOsInterface->pfnRegisterBBCompleteNotifyEvent = MockRegisterBBCompleteNotifyEvent;
    pOsInterface->pfnDestroyGpuContextByHandle = MockDestroyGpuContextByHandle;
    pOsInterface->pfnSetLatestVirtualNode = MockSetLatestVirtualNode;
    pOsInterface->pfnCreateVideoNodeAssociation = MockCreateVideoNodeAssociation;
    pOsInterface->pfnSetDecoderVirtualNodePerStream = MockSetDecoderVirtualNodePerStream;
    pOsInterface->pfnDestroyVideoNodeAssociation = MockDestroyVideoNodeAssociation;
    pOsInterface->pfnVerifyPatchListSize = MockVerifyPatchListSize;
    pOsInterface->pfnVerifyCommandBufferSize = MockVerifyCommandBufferSize;
    pOsInterface->pfnResizeCommandBufferAndPatchList = MockResizeCommandBufferAndPatchList;
    pOsInterface->pfnGetCommandBuffer = MockGetCommandBuffer;
    pOsInterface->pfnReturnCommandBuffer = MockReturnCommandBuffer;
    pOsInterface->pfnSetHintParams = MockSetHintParams;
    pOsInterface->pfnGetAttributeVeBuffer = MockGetAttributeVeBuffer;
    pOsInterface->pfnSubmitCommandBuffer = MockSubmitCommandBuffer;
    pOsInterface->pfnAllocateResource = MockAllocateResource;
    pOsInterface->pfnFillResource = MockFillResource;
    pOsInterface->pfnGetResourceInfo = MockGetResourceInfo;
    pOsInterface->pfnFreeResource = MockFreeResource;
    pOsInterface->pfnFreeResourceWithFlag = MockFreeResourceWithFlag;
    pOsInterface->pfnLockResource = MockLockResource;
    pOsInterface->pfnUnlockResource = MockUnlockResource;
    pOsInterface->pfnSkipResourceSync = MockSkipResourceSync;
    pOsInterface->pfnSyncOnResource = MockSyncOnResource;
    pOsInterface->pfnUpdateResourceUsageType = MockUpdateResourceUsageType;
    pOsInterface->pfnInitMocsParams = MockInitMocsParams;
    pOsInterface->pfnAddResourceToCmd = MockAddResourceToCmd;
    pOsInterface->pfnAddCommand = MockAddCommand;

    // Set up properties
    pOsInterface->bSupportVirtualEngine = true;
    pOsInterface->multiNodeScaling = true;
    pOsInterface->CurrentGpuContextHandle = 0;
    pOsInterface->pVEInterf = nullptr;
    pOsInterface->osStreamState = MOS_INVALID_HANDLE;

    return pOsInterface;
}

/**
 * @brief Destroys a MOS interface
 * 
 * @param pOsInterface Pointer to MOS_INTERFACE to destroy
 */
inline void DestroyMosInterface(PMOS_INTERFACE pOsInterface)
{
    if (pOsInterface == nullptr)
    {
        return;
    }

    // Clean up VE interface if it exists
    if (pOsInterface->pVEInterf != nullptr)
    {
        free(pOsInterface->pVEInterf);
        pOsInterface->pVEInterf = nullptr;
    }

    // Free the interface itself
    free(pOsInterface);
}

#ifdef __cplusplus
}
#endif

#endif // __MOS_MOCK_DEF_H__
