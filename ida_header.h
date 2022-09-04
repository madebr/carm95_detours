
/*
 typedef int FILE;
 typedef unsigned int size_t;

 typedef struct br_exception_handler br_exception_handler;
 typedef struct br_exception_handler
 {
     br_exception_handler *prev;
     //jmp_buf context;
 } br_exception_handler;
*/

typedef int br_int_32;
typedef unsigned int br_uint_32;
typedef short br_int_16;
typedef unsigned short br_uint_16;
typedef signed char br_int_8;
typedef unsigned char br_uint_8;
typedef unsigned int br_size_t;
typedef int br_boolean;
typedef float br_float;
typedef br_uint_32 br_error;
typedef int br_fixed_ls;
typedef short br_fixed_lsf;
typedef unsigned int br_fixed_lu;
typedef unsigned short br_fixed_luf;
typedef short br_fixed_ss;
typedef char br_fixed_ssf;
typedef unsigned short br_fixed_su;
typedef unsigned char br_fixed_suf;
typedef float br_scalar;
typedef float br_fraction;
typedef float br_ufraction;
typedef br_fixed_ls br_scalar_x;
typedef br_fixed_lsf br_fraction_x;
typedef br_fixed_luf br_ufraction_x;
typedef float br_scalar_f;
typedef float br_fraction_f;
typedef float br_ufraction_f;
typedef unsigned int br_colour;
typedef struct br_bounds3 br_bounds;
typedef struct br_bounds2_i br_bounds2i;
typedef struct br_bounds3_i br_bounds3i;
typedef struct br_bounds4_i br_bounds4i;
typedef br_fixed_luf br_angle;
typedef struct br_value_tag br_value;
typedef struct br_associative_array_tag br_associative_array;
typedef struct br_tri_strip br_tri_fan;
typedef struct br_tri_strip br_quad_strip;

typedef struct br_renderer_dispatch br_renderer_dispatch;
typedef struct br_renderer
{
    br_renderer_dispatch* dispatch; // @0
} br_renderer;

typedef enum br_filesystem_attributes
{
    BR_FS_ATTR_READABLE = 1,
    BR_FS_ATTR_WRITEABLE = 2,
    BR_FS_ATTR_HAS_TEXT = 4,
    BR_FS_ATTR_HAS_BINARY = 8,
    BR_FS_ATTR_HAS_ADVANCE = 16
} br_filesystem_attributes;

typedef enum br_filesystem_identify
{
    BR_FS_MODE_BINARY = 0,
    BR_FS_MODE_TEXT = 1,
    BR_FS_MODE_UNKNOWN = 2
} br_filesystem_identify;

typedef enum br_memory_classes
{
    BR_MEMORY_SCRATCH = 1,
    BR_MEMORY_PIXELMAP = 2,
    BR_MEMORY_PIXELS = 3,
    BR_MEMORY_VERTICES = 4,
    BR_MEMORY_FACES = 5,
    BR_MEMORY_GROUPS = 6,
    BR_MEMORY_MODEL = 7,
    BR_MEMORY_MATERIAL = 8,
    BR_MEMORY_MATERIAL_INDEX = 9,
    BR_MEMORY_ACTOR = 10,
    BR_MEMORY_PREPARED_VERTICES = 11,
    BR_MEMORY_PREPARED_FACES = 12,
    BR_MEMORY_LIGHT = 13,
    BR_MEMORY_CAMERA = 14,
    BR_MEMORY_BOUNDS = 15,
    BR_MEMORY_CLIP_PLANE = 16,
    BR_MEMORY_STRING = 17,
    BR_MEMORY_REGISTRY = 18,
    BR_MEMORY_TRANSFORM = 19,
    BR_MEMORY_RESOURCE_CLASS = 20,
    BR_MEMORY_FILE = 21,
    BR_MEMORY_ANCHOR = 22,
    BR_MEMORY_POOL = 23,
    BR_MEMORY_RENDER_MATERIAL = 24,
    BR_MEMORY_DATAFILE = 25,
    BR_MEMORY_IMAGE = 26,
    BR_MEMORY_IMAGE_ARENA = 27,
    BR_MEMORY_IMAGE_SECTIONS = 28,
    BR_MEMORY_IMAGE_NAMES = 29,
    BR_MEMORY_EXCEPTION_HANDLER = 30,
    BR_MEMORY_RENDER_DATA = 31,
    BR_MEMORY_TOKEN = 32,
    BR_MEMORY_TOKEN_MAP = 33,
    BR_MEMORY_OBJECT = 34,
    BR_MEMORY_OBJECT_DATA = 35,
    BR_MEMORY_DRIVER = 36,
    BR_MEMORY_LEXER = 37,
    BR_MEMORY_OBJECT_LIST = 38,
    BR_MEMORY_OBJECT_LIST_ENTRY = 39,
    BR_MEMORY_ENABLED_ACTORS = 40,
    BR_MEMORY_FMT_RESULTS = 41,
    BR_MEMORY_PREPARED_MODEL = 42,
    BR_MEMORY_ORDER_TABLE = 43,
    BR_MEMORY_TOKEN_VALUE = 44,
    BR_MEMORY_TOKEN_TEMPLATE = 45,
    BR_MEMORY_FREE = 127,
    BR_MEMORY_APPLICATION = 128,
    BR_MEMORY_MAX = 256
} br_memory_classes;

typedef enum br_pixelmap_allocate_flags
{
    BR_PMAF_NORMAL = 0,
    BR_PMAF_INVERTED = 1,
    BR_PMAF_NO_PIXELS = 2
} br_pixelmap_allocate_flags;

typedef enum br_pixelmap_channel_mask
{
    BR_PMCHAN_INDEX = 1,
    BR_PMCHAN_RGB = 2,
    BR_PMCHAN_DEPTH = 4,
    BR_PMCHAN_ALPHA = 8,
    BR_PMCHAN_YUV = 16,
    BR_PMCHAN_VECTOR = 32
} br_pixelmap_channel_mask;

typedef enum br_pmmatch_type
{
    BR_PMMATCH_OFFSCREEN = 0,
    BR_PMMATCH_DEPTH_16 = 1,
    BR_PMMATCH_DEPTH = 2,
    BR_PMMATCH_HIDDEN = 3,
    BR_PMMATCH_HIDDEN_BUFFER = 4,
    BR_PMMATCH_NO_RENDER = 5,
    BR_PMMATCH_DEPTH_8 = 6,
    BR_PMMATCH_DEPTH_32 = 7,
    BR_PMMATCH_DEPTH_15 = 8,
    BR_PMMATCH_DEPTH_31 = 9,
    BR_PMMATCH_DEPTH_FP15 = 10,
    BR_PMMATCH_DEPTH_FP16 = 11,
    BR_PMMATCH_MAX = 12
} br_pmmatch_type;

typedef enum br_pixelmap_copy_function
{
    BR_PMCOPY_NORMAL = 0,
    BR_PMCOPY_SRC_KEYED = 1,
    BR_PMCOPY_DST_KEYED = 2
} br_pixelmap_copy_function;

typedef enum br_clip_result
{
    BR_CLIP_REJECT = 0,
    BR_CLIP_PARTIAL = 1,
    BR_CLIP_ACCEPT = 2
} br_clip_result;

typedef enum br_token
{
    BRT_ABGR_1_5_5_5 = 319,
    BRT_ABGR_4_4_4_4 = 335,
    BRT_ABGR_8_8_8_8 = 331,
    BRT_ACCEPT = 276,
    BRT_AINDEX_4_4 = 345,
    BRT_AINDEX_8_8 = 344,
    BRT_ALPHA = 85,
    BRT_ALWAYS = 163,
    BRT_AMBIENT_F = 193,
    BRT_AMBIENT_X = 192,
    BRT_ANGLE = 13,
    BRT_ANTIALIASING_T = 298,
    BRT_ANTIALIASING_TL = 299,
    BRT_ARGB_1_5_5_5 = 318,
    BRT_ARGB_4_4_4_4 = 334,
    BRT_ARGB_8_8_8_8 = 330,
    BRT_ATTENUATION_C_F = 222,
    BRT_ATTENUATION_C_X = 221,
    BRT_ATTENUATION_L_F = 220,
    BRT_ATTENUATION_L_X = 219,
    BRT_ATTENUATION_Q_F = 224,
    BRT_ATTENUATION_Q_X = 223,
    BRT_A_4 = 450,
    BRT_A_8 = 341,
    BRT_BEST_QUALITY = 380,
    BRT_BEST_SPEED = 291,
    BRT_BGRA_4_4_4_4 = 336,
    BRT_BGRA_8_8_8_8 = 332,
    BRT_BGRX_8_8_8_8 = 328,
    BRT_BGR_2_3_2 = 323,
    BRT_BGR_5_6_5 = 321,
    BRT_BGR_8_8_8 = 325,
    BRT_BLENDER_PROGRAM_P = 458,
    BRT_BLEND_B = 133,
    BRT_BLEND_CONSTANT = 445,
    BRT_BLEND_DIMMED = 444,
    BRT_BLEND_MODE_T = 440,
    BRT_BLEND_MODE_TL = 441,
    BRT_BLEND_STANDARD = 442,
    BRT_BLEND_SUMMED = 443,
    BRT_BLUE = 83,
    BRT_BOOLEAN = 2,
    BRT_BOTTOM_TOP = 67,
    BRT_BOUNDS = 122,
    BRT_BOUNDS_B = 255,
    BRT_BRENDER_DEVICES_STR = 422,
    BRT_BRENDER_DRIVERS_STR = 420,
    BRT_BRENDER_PATH_STR = 419,
    BRT_BRENDER_VERSION_U32 = 356,
    BRT_BUCKET_SORT = 257,
    BRT_BUFFER_STORED = 45,
    BRT_BUMP_O = 170,
    BRT_BUMP_TVL = 401,
    BRT_CACHED_B = 286,
    BRT_CACHED_SIZE_U32 = 287,
    BRT_CACHED_TOTAL_U32 = 288,
    BRT_CAN_SHARE_B = 110,
    BRT_CLAMP = 308,
    BRT_CLIP = 121,
    BRT_CLIPPING_B = 254,
    BRT_CLIP_MAX_I32 = 105,
    BRT_CLONE = 102,
    BRT_CLUT_MAX_I32 = 90,
    BRT_CLUT_O = 68,
    BRT_COLOUR_B = 135,
    BRT_COLOUR_BUFFER_O = 249,
    BRT_COLOUR_I32 = 189,
    BRT_COLOUR_MAP_O = 165,
    BRT_COLOUR_MAP_TVL = 396,
    BRT_COLOUR_RGB = 14,
    BRT_COLOUR_SOURCE_T = 180,
    BRT_COLOUR_T = 136,
    BRT_COLOUR_TL = 297,
    BRT_COLOUR_WRITE_B = 132,
    BRT_CONSTANT_STRING = 32,
    BRT_COPY_BITS_F = 371,
    BRT_COPY_BITS_X = 370,
    BRT_COPY_DESTINATION_TVL = 361,
    BRT_COPY_F = 363,
    BRT_COPY_SOURCE_TVL = 360,
    BRT_COPY_X = 362,
    BRT_CREATOR_CSTR = 56,
    BRT_CULL = 116,
    BRT_CULL_B = 251,
    BRT_DDI_VERSION_U32 = 357,
    BRT_DECAL_B = 128,
    BRT_DEFAULT = 138,
    BRT_DEFAULT_BASE_I32 = 282,
    BRT_DEFAULT_DEVICE_STR = 421,
    BRT_DEFAULT_RANGE_I32 = 283,
    BRT_DEPTH = 84,
    BRT_DEPTH_BUFFER_O = 250,
    BRT_DEPTH_TEST_T = 155,
    BRT_DEPTH_TEST_TL = 304,
    BRT_DEPTH_WRITE_B = 131,
    BRT_DESTINATION_O = 114,
    BRT_DEVICE = 37,
    BRT_DEVICE_CLUT = 41,
    BRT_DEVICE_PIXELMAP = 40,
    BRT_DIBSECTION = 410,
    BRT_DIFFUSE_F = 195,
    BRT_DIFFUSE_X = 194,
    BRT_DIRECT = 208,
    BRT_DIRECT3D_HAL = 416,
    BRT_DIRECT3D_RAMP = 414,
    BRT_DIRECT3D_RENDER_METHOD_T = 413,
    BRT_DIRECT3D_RGB = 415,
    BRT_DIRECTDRAW = 411,
    BRT_DIRECTDRAW_DEVICENAME_CSTR = 412,
    BRT_DIRECTION_V3_F = 213,
    BRT_DIRECTION_V3_X = 214,
    BRT_DIRECT_F = 378,
    BRT_DIRECT_X = 377,
    BRT_DITHER = 431,
    BRT_DITHER_B = 457,
    BRT_DITHER_COLOUR_B = 129,
    BRT_DITHER_COLOUR_T = 293,
    BRT_DITHER_COLOUR_TL = 294,
    BRT_DITHER_MAP_B = 130,
    BRT_DITHER_MAP_T = 295,
    BRT_DITHER_MAP_TL = 296,
    BRT_DONT_CARE = 246,
    BRT_D_15 = 446,
    BRT_D_16 = 338,
    BRT_D_24 = 339,
    BRT_D_31 = 447,
    BRT_D_32 = 340,
    BRT_D_FP15 = 448,
    BRT_D_FP16 = 449,
    BRT_ENABLE = 119,
    BRT_ENVIRONMENT_INFINITE = 184,
    BRT_ENVIRONMENT_LOCAL = 183,
    BRT_EQUAL = 158,
    BRT_EVEN_ODD = 63,
    BRT_FACILITY = 38,
    BRT_FACILITY_O = 281,
    BRT_FIXED = 11,
    BRT_FLOAT = 12,
    BRT_FOG_MAX_F = 153,
    BRT_FOG_MAX_X = 154,
    BRT_FOG_MIN_F = 151,
    BRT_FOG_MIN_X = 152,
    BRT_FOG_RGB = 150,
    BRT_FOG_T = 149,
    BRT_FOG_TL = 303,
    BRT_FONT_NORMAL_O = 98,
    BRT_FONT_NORMAL_P = 97,
    BRT_FORCE_FRONT_B = 179,
    BRT_FORMAT_T = 113,
    BRT_GEOMETRY = 46,
    BRT_GEOMETRY_LIGHTING = 51,
    BRT_GEOMETRY_MAP = 185,
    BRT_GEOMETRY_PRIMITIVES = 48,
    BRT_GEOMETRY_STORED = 47,
    BRT_GEOMETRY_V1_BUCKETS = 50,
    BRT_GEOMETRY_V1_MODEL = 49,
    BRT_GEOMETRY_X = 186,
    BRT_GEOMETRY_Y = 187,
    BRT_GEOMETRY_Z = 188,
    BRT_GREATER = 156,
    BRT_GREATER_OR_EQUAL = 157,
    BRT_GREEN = 82,
    BRT_HANDLE = 354,
    BRT_HEIGHT_I32 = 72,
    BRT_HEIGHT_MAX_I32 = 74,
    BRT_HEIGHT_MIN_I32 = 73,
    BRT_HEIGHT_OPTIMUM_I32 = 392,
    BRT_HEIGHT_T = 389,
    BRT_HEIGHT_TL = 390,
    BRT_HIDDEN = 100,
    BRT_HIDDEN_BUFFER = 278,
    BRT_HIDDEN_SURFACE = 123,
    BRT_HOST_MEMORY_U32 = 93,
    BRT_IDENTIFIER_CSTR = 54,
    BRT_INDEX = 80,
    BRT_INDEXA_4_4 = 343,
    BRT_INDEXA_8_8 = 342,
    BRT_INDEXED_B = 86,
    BRT_INDEX_1 = 312,
    BRT_INDEX_2 = 313,
    BRT_INDEX_4 = 314,
    BRT_INDEX_8 = 315,
    BRT_INDEX_BASE_I32 = 139,
    BRT_INDEX_BLEND_O = 167,
    BRT_INDEX_BLEND_TVL = 398,
    BRT_INDEX_FOG_O = 394,
    BRT_INDEX_FOG_TVL = 402,
    BRT_INDEX_LIGHT_O = 169,
    BRT_INDEX_LIGHT_TVL = 400,
    BRT_INDEX_RANGE_I32 = 140,
    BRT_INDEX_SHADE_O = 166,
    BRT_INDEX_SHADE_TVL = 397,
    BRT_INI_STR = 418,
    BRT_INTEL = 423,
    BRT_INTEL_386 = 427,
    BRT_INTEL_486 = 428,
    BRT_INTEL_PENTIUM = 429,
    BRT_INTEL_PENTIUM_PRO = 430,
    BRT_INTERLACE_B = 456,
    BRT_INT_16 = 7,
    BRT_INT_32 = 9,
    BRT_INT_8 = 5,
    BRT_KEY_IS_TRANSPARENT = 353,
    BRT_LEFT_RIGHT = 64,
    BRT_LENGTH_PRESERVING = 237,
    BRT_LESS = 161,
    BRT_LESS_OR_EQUAL = 160,
    BRT_LIGHT = 120,
    BRT_LIGHTING_B = 178,
    BRT_LIGHT_MAX_I32 = 104,
    BRT_LIGHT_VERTICES = 273,
    BRT_LINE = 266,
    BRT_LINEAR = 147,
    BRT_LPDIRECTDRAWSURFACE_P = 432,
    BRT_MAPPING_SOURCE_T = 182,
    BRT_MAP_ANTIALIASING_T = 141,
    BRT_MAP_ANTIALIASING_TL = 300,
    BRT_MAP_HEIGHT_LIMIT_T = 310,
    BRT_MAP_HEIGHT_LIMIT_TL = 311,
    BRT_MAP_INTERPOLATION_MAG_T = 383,
    BRT_MAP_INTERPOLATION_MAG_TL = 384,
    BRT_MAP_INTERPOLATION_MIN_T = 385,
    BRT_MAP_INTERPOLATION_MIN_TL = 386,
    BRT_MAP_INTERPOLATION_T = 145,
    BRT_MAP_INTERPOLATION_TL = 301,
    BRT_MAP_MATRIX_M23_F = 200,
    BRT_MAP_MATRIX_M23_X = 201,
    BRT_MAP_WIDTH_LIMIT_T = 305,
    BRT_MAP_WIDTH_LIMIT_TL = 306,
    BRT_MATCH_TVL = 359,
    BRT_MATRIX = 118,
    BRT_MATRIX23_FIXED = 25,
    BRT_MATRIX23_FLOAT = 28,
    BRT_MATRIX34_FIXED = 26,
    BRT_MATRIX34_FLOAT = 29,
    BRT_MATRIX4_FIXED = 27,
    BRT_MATRIX4_FLOAT = 30,
    BRT_MAX_V2_F = 233,
    BRT_MAX_V2_I = 231,
    BRT_MAX_V2_X = 232,
    BRT_MEMORY_MAPPED_B = 87,
    BRT_MIN_V2_F = 230,
    BRT_MIN_V2_I = 228,
    BRT_MIN_V2_X = 229,
    BRT_MIP = 142,
    BRT_MIPS = 425,
    BRT_MIP_INTERPOLATION_T = 148,
    BRT_MIP_INTERPOLATION_TL = 302,
    BRT_MIP_PER_PIXEL = 143,
    BRT_MIP_PER_PRIMITIVE = 144,
    BRT_MIRROR = 309,
    BRT_MODEL = 177,
    BRT_MODEL_TO_SCREEN_M4_F = 247,
    BRT_MODEL_TO_SCREEN_M4_X = 248,
    BRT_MODEL_TO_VIEW_HINT_T = 236,
    BRT_MODEL_TO_VIEW_M34_F = 234,
    BRT_MODEL_TO_VIEW_M34_X = 235,
    BRT_MODE_U32 = 94,
    BRT_MODULATE_B = 134,
    BRT_MOTOROLA = 426,
    BRT_NEAREST = 146,
    BRT_NEVER = 162,
    BRT_NONE = 1,
    BRT_NOT_EQUAL = 159,
    BRT_NO_RENDER = 379,
    BRT_OBJECT = 15,
    BRT_OBJECT_CONTAINER = 36,
    BRT_OBJECT_LIST = 33,
    BRT_ODD_EVEN = 62,
    BRT_OFFSCREEN = 101,
    BRT_ONE_SIDED = 173,
    BRT_OPACITY_F = 191,
    BRT_OPACITY_SOURCE_T = 181,
    BRT_OPACITY_X = 190,
    BRT_ORIGIN_V2_I = 96,
    BRT_OUTPUT = 125,
    BRT_OUTPUT_FACILITY = 39,
    BRT_OUTPUT_FACILITY_O = 95,
    BRT_PARALLEL = 242,
    BRT_PARTIAL = 275,
    BRT_PARTS_TL = 107,
    BRT_PARTS_U32 = 112,
    BRT_PERSPECTIVE = 241,
    BRT_PERSPECTIVE_B = 127,
    BRT_PERSPECTIVE_T = 289,
    BRT_PERSPECTIVE_TL = 290,
    BRT_PIXELMAP_MAX_I32 = 89,
    BRT_PIXEL_BITS_I32 = 76,
    BRT_PIXEL_CHANNELS_I32 = 78,
    BRT_PIXEL_CHANNELS_TL = 79,
    BRT_PIXEL_GET_F = 374,
    BRT_PIXEL_GET_X = 373,
    BRT_PIXEL_SET_F = 376,
    BRT_PIXEL_SET_X = 375,
    BRT_PIXEL_TYPE_U8 = 75,
    BRT_PLANE = 225,
    BRT_PLANE_V4_F = 226,
    BRT_PLANE_V4_X = 227,
    BRT_POINT = 209,
    BRT_POINTER = 3,
    BRT_POINTER_LIST = 35,
    BRT_POSITION_V3_F = 211,
    BRT_POSITION_V3_X = 212,
    BRT_POWERPC = 424,
    BRT_POWER_OF_2 = 351,
    BRT_PREFER_SHARE_B = 111,
    BRT_PRIMITIVE = 124,
    BRT_PRIMITIVES = 270,
    BRT_PRIMITIVE_BLOCK_P = 393,
    BRT_PRIMITIVE_CUSTOM_P = 206,
    BRT_PRIMITIVE_FILTER_P = 207,
    BRT_PRIMITIVE_LIBRARY = 52,
    BRT_PRIMITIVE_LIBRARY_O = 88,
    BRT_PRIMITIVE_LIBRARY_P = 115,
    BRT_PRIMITIVE_STATE = 53,
    BRT_PRIVATE = 349,
    BRT_PRODUCT_CSTR = 57,
    BRT_PRODUCT_VERSION_CSTR = 58,
    BRT_QUAD = 268,
    BRT_QUAD_STRIP = 455,
    BRT_RED = 81,
    BRT_REGISTRY_STR = 417,
    BRT_REJECT = 277,
    BRT_RENDERER = 43,
    BRT_RENDERER_FACILITY = 42,
    BRT_RENDERER_FACILITY_O = 108,
    BRT_RENDERER_MAX_I32 = 106,
    BRT_RENDERER_O = 103,
    BRT_RENDERER_STATE_STORED = 44,
    BRT_RENDER_B = 256,
    BRT_RGB = 137,
    BRT_RGBA_4_4_4_4 = 337,
    BRT_RGBA_8_8_8_8 = 333,
    BRT_RGBX_8_8_8_8 = 329,
    BRT_RGB_2_3_2 = 322,
    BRT_RGB_5_6_5 = 320,
    BRT_RGB_8_8_8 = 324,
    BRT_RIGHT_LEFT = 65,
    BRT_SCREEN_DOOR_O = 168,
    BRT_SCREEN_DOOR_TVL = 399,
    BRT_SHARED_B = 109,
    BRT_SMOOTH_B = 126,
    BRT_SPACE_T = 175,
    BRT_SPECULAR_F = 197,
    BRT_SPECULAR_POWER_F = 199,
    BRT_SPECULAR_POWER_X = 198,
    BRT_SPECULAR_X = 196,
    BRT_SPOT = 210,
    BRT_SPOT_INNER_F = 218,
    BRT_SPOT_INNER_X = 217,
    BRT_SPOT_OUTER_F = 216,
    BRT_SPOT_OUTER_X = 215,
    BRT_SPRITE = 265,
    BRT_SQUARE = 350,
    BRT_STATE_RESTORE = 269,
    BRT_STEREO_B = 59,
    BRT_STEREO_T = 60,
    BRT_STEREO_TL = 61,
    BRT_STORED_STATE_O = 264,
    BRT_STRETCHDIBITS = 409,
    BRT_STRETCH_COPY_DESTINATION_TVL = 365,
    BRT_STRETCH_COPY_F = 369,
    BRT_STRETCH_COPY_SOURCE_TVL = 364,
    BRT_STRETCH_COPY_T = 366,
    BRT_STRETCH_COPY_TL = 367,
    BRT_STRETCH_COPY_X = 368,
    BRT_STRING = 31,
    BRT_SUBDIVIDE = 381,
    BRT_SUBDIVIDE_TOLERANCE_I32 = 382,
    BRT_SURFACE = 117,
    BRT_SURFACE_B = 253,
    BRT_SURFACE_C_CUSTOM_P = 202,
    BRT_SURFACE_C_FILTER_P = 203,
    BRT_SURFACE_V_CUSTOM_P = 204,
    BRT_SURFACE_V_FILTER_P = 205,
    BRT_SYCHRONISE_I32 = 372,
    BRT_TEXTURE_MEMORY_U32 = 92,
    BRT_TEXTURE_O = 164,
    BRT_TEXTURE_TVL = 395,
    BRT_TITLE_CSTR = 358,
    BRT_TOKEN = 4,
    BRT_TOKEN_LIST = 34,
    BRT_TOKEN_VALUE_LIST = 355,
    BRT_TOP_BOTTOM = 66,
    BRT_TRANSFORM_B = 252,
    BRT_TRIANGLE = 267,
    BRT_TRI_FAN = 454,
    BRT_TRI_STRIP = 453,
    BRT_TWO_SIDED = 174,
    BRT_TYPE_T = 172,
    BRT_UINT_16 = 8,
    BRT_UINT_32 = 10,
    BRT_UINT_8 = 6,
    BRT_UNKNOWN = 171,
    BRT_USE_NO_3D_B = 279,
    BRT_USE_NO_DEPTH_B = 280,
    BRT_USE_T = 99,
    BRT_V1BUCKETS = 272,
    BRT_V1INSERT_ARG1_P = 261,
    BRT_V1INSERT_ARG2_P = 262,
    BRT_V1INSERT_ARG3_P = 263,
    BRT_V1INSERT_FUNCTION_P = 260,
    BRT_V1MODEL = 271,
    BRT_V1ORDER_TABLE_P = 258,
    BRT_V1PRIMITIVE_HEAP_P = 259,
    BRT_VECTOR2_FIXED = 19,
    BRT_VECTOR2_FLOAT = 22,
    BRT_VECTOR2_INTEGER = 16,
    BRT_VECTOR3_FIXED = 20,
    BRT_VECTOR3_FLOAT = 23,
    BRT_VECTOR3_INTEGER = 17,
    BRT_VECTOR4_FIXED = 21,
    BRT_VECTOR4_FLOAT = 24,
    BRT_VECTOR4_INTEGER = 18,
    BRT_VERSION_U32 = 55,
    BRT_VERTEX_DBL = 452,
    BRT_VERTEX_SGL = 451,
    BRT_VERTICAL_BLANK = 274,
    BRT_VIDEO_MEMORY_U32 = 91,
    BRT_VIEW = 176,
    BRT_VIEW_TO_ENVIRONMENT_HINT_T = 245,
    BRT_VIEW_TO_ENVIRONMENT_M34_F = 243,
    BRT_VIEW_TO_ENVIRONMENT_M34_X = 244,
    BRT_VIEW_TO_SCREEN_HINT_T = 240,
    BRT_VIEW_TO_SCREEN_M4_F = 238,
    BRT_VIEW_TO_SCREEN_M4_X = 239,
    BRT_WIDTH_I32 = 69,
    BRT_WIDTH_MAX_I32 = 71,
    BRT_WIDTH_MIN_I32 = 70,
    BRT_WIDTH_OPTIMUM_I32 = 391,
    BRT_WIDTH_T = 387,
    BRT_WIDTH_TL = 388,
    BRT_WINDOW_BUFFER_METHOD_T = 407,
    BRT_WINDOW_FULLSCREEN_B = 406,
    BRT_WINDOW_HANDLE_H = 405,
    BRT_WINDOW_NAME_CSTR = 403,
    BRT_WINDOW_PROCEDURE_P = 404,
    BRT_WING = 408,
    BRT_WORD_BYTES_I32 = 77,
    BRT_WRAP = 307,
    BRT_WRITABLE_BASE_I32 = 284,
    BRT_WRITABLE_RANGE_I32 = 285,
    BRT_XBGR_1_5_5_5 = 317,
    BRT_XBGR_8_8_8_8 = 327,
    BRT_XRGB_1_5_5_5 = 316,
    BRT_XRGB_8_8_8_8 = 326,
    BRT_XYZ_16_16_16 = 347,
    BRT_XYZ_8_8_8 = 346,
    BRT_YUV_16 = 348,
    BRT_ZERO_IS_TRANSPARENT = 352,
    BRT_ZTRANSPARENCY_B = 439,
    BRT_Z_WRITE_ALWAYS = 436,
    BRT_Z_WRITE_CONDITIONAL = 438,
    BRT_Z_WRITE_CONDITIONAL_NO_Z = 437,
    BRT_Z_WRITE_NEVER = 435,
    BRT_Z_WRITE_T = 433,
    BRT_Z_WRITE_TL = 434,
    _BRT_MAX = 134217727
} br_token;

typedef enum br_apply_map_types
{
    BR_APPLYMAP_PLANE = 0,
    BR_APPLYMAP_SPHERE = 1,
    BR_APPLYMAP_CYLINDER = 2,
    BR_APPLYMAP_DISC = 3,
    BR_APPLYMAP_NONE = 4
} br_apply_map_types;

typedef enum br_fitmap_axis
{
    BR_FITMAP_PLUS_X = 0,
    BR_FITMAP_PLUS_Y = 1,
    BR_FITMAP_PLUS_Z = 2,
    BR_FITMAP_MINUS_X = 3,
    BR_FITMAP_MINUS_Y = 4,
    BR_FITMAP_MINUS_Z = 5
} br_fitmap_axis;
typedef void br_putline_cbfn(char*, void*);
typedef int br_mode_test_cbfn(br_uint_8*, br_size_t);
typedef br_uint_32 brfile_attributes_cbfn();
typedef void* brfile_open_read_cbfn(char*, br_size_t, br_mode_test_cbfn*, int*);
typedef void* brfile_open_write_cbfn(char*, int);
typedef void brfile_close_cbfn(void*);
typedef int brfile_eof_cbfn(void*);
typedef int brfile_getchr_cbfn(void*);
typedef void brfile_putchr_cbfn(int, void*);
typedef br_size_t brfile_read_cbfn(void*, br_size_t, unsigned int, void*);
typedef br_size_t brfile_write_cbfn(void*, br_size_t, unsigned int, void*);
typedef br_size_t brfile_getline_cbfn(char*, br_size_t, void*);
typedef void brfile_putline_cbfn(char*, void*);
typedef void brfile_advance_cbfn(br_size_t, void*);
typedef void* brmem_allocate_cbfn(br_size_t, br_uint_8);
typedef void brmem_free_cbfn(void*);
typedef br_size_t brmem_inquire_cbfn(br_uint_8);
typedef br_uint_32 brmem_align_cbfn(br_uint_8);
typedef void br_resourcefree_cbfn(void*, br_uint_8, br_size_t);
typedef void br_diag_warning_cbfn(char*);
typedef void br_diag_failure_cbfn(char*);
typedef struct br_resource_class br_resource_class;
typedef br_resource_class* br_resclass_find_cbfn(char*);
typedef br_uint_32 br_resclass_enum_cbfn(br_resource_class*, void*);
typedef int br_qsort_cbfn(void*, void*);
typedef br_uint_32 br_resenum_cbfn(void*, void*);
typedef struct br_device br_device;
typedef br_device* br_device_begin_fn(char*);
typedef br_boolean br_device_enum_cbfn(char*, br_uint_32, char*, char*, char*, char*, void*);
typedef struct br_outfcty_desc br_outfcty_desc;
typedef br_boolean br_outfcty_enum_cbfn(char*, br_outfcty_desc*, void*);
typedef struct br_actor br_actor;
typedef struct br_model br_model;
typedef struct br_material br_material;
typedef void br_model_custom_cbfn(br_actor*, br_model*, br_material*, void*, br_uint_8, int);
typedef int br_fmt_report_cbfn(char*);
typedef struct br_matrix4 br_matrix4;
typedef void br_renderbounds_cbfn(br_actor*, br_model*, br_material*, void*, br_uint_8, br_matrix4*, br_int_32*);
typedef struct br_primitive br_primitive;
typedef struct br_order_table br_order_table;
typedef void br_primitive_cbfn(br_primitive*, br_actor*, br_model*, br_material*, br_order_table*, br_scalar*);
typedef br_material* br_material_find_cbfn(char*);
typedef br_uint_32 br_material_enum_cbfn(br_material*, void*);
typedef br_model* br_model_find_cbfn(char*);
typedef br_uint_32 br_model_enum_cbfn(br_model*, void*);
typedef struct br_pixelmap br_pixelmap;
typedef br_pixelmap* br_map_find_cbfn(char*);
typedef br_uint_32 br_map_enum_cbfn(br_pixelmap*, void*);
typedef br_pixelmap* br_table_find_cbfn(char*);
typedef br_uint_32 br_table_enum_cbfn(br_pixelmap*, void*);
typedef br_uint_32 br_actor_enum_cbfn(br_actor*, void*);
typedef struct br_vector3 br_vector3;
typedef int br_pick2d_cbfn(br_actor*, br_model*, br_material*, br_vector3*, br_vector3*, br_scalar, br_scalar, void*);
typedef struct br_matrix34 br_matrix34;
typedef int br_pick3d_cbfn(br_actor*, br_model*, br_material*, br_matrix34*, br_bounds*, void*);
typedef struct br_vector2 br_vector2;
typedef int br_modelpick2d_cbfn(br_model*, br_material*, br_vector3*, br_vector3*, br_scalar, int, int, int, br_vector3*, br_vector2*, void*);

typedef enum view_to_screen_type
{
    BR_VTOS_PARALLEL = 0,
    BR_VTOS_PERSPECTIVE = 1,
    BR_VTOS_4X4 = 2
} view_to_screen_type;

typedef void dev_fill_cbfn(br_device*, br_pixelmap*, br_uint_32);
typedef void dev_rectangle_copy_cbfn(br_device*, br_pixelmap*, br_uint_16, br_uint_16, br_pixelmap*, br_uint_16, br_uint_16, br_uint_16, br_uint_16);
typedef void dev_rectangle_fill_cbfn(br_device*, br_pixelmap*, br_uint_16, br_uint_16, br_uint_16, br_uint_16, br_uint_32);
typedef void dev_dirty_rectangle_copy_cbfn(br_device*, br_pixelmap*, br_pixelmap*, br_uint_16, br_uint_16, br_uint_16, br_uint_16);
typedef void dev_dirty_rectangle_fill_cbfn(br_device*, br_pixelmap*, br_uint_16, br_uint_16, br_uint_16, br_uint_16, br_uint_32);
typedef void dev_plot_cbfn(br_device*, br_pixelmap*, br_uint_16, br_uint_16, br_uint_32);
typedef void dev_copy_cbfn(br_device*, br_pixelmap*, br_pixelmap*);
typedef void dev_line_cbfn(br_device*, br_pixelmap*, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32);
typedef void dev_copy_bits_cbfn(br_device*, br_pixelmap*, br_int_16, br_int_16, br_uint_8*, br_uint_16, br_uint_16, br_uint_16, br_uint_16, br_uint_32);
typedef br_pixelmap* dev_double_buffer_cbfn(br_device*, br_pixelmap*, br_pixelmap*);
typedef br_pixelmap* dev_match_cbfn(br_device*, br_pixelmap*, br_uint_8);
typedef br_pixelmap* dev_clone_cbfn(br_device*, br_pixelmap*);
typedef void dev_free_cbfn(br_device*, br_pixelmap*);

typedef struct br_resource_class
{
    br_uint_32 reserved;
    char* identifier;
    br_uint_8 res_class;
    br_resourcefree_cbfn* free_cb;
    br_uint_32 alignment;
} br_resource_class;

typedef struct br_filesystem
{
    char* identifier;
    brfile_attributes_cbfn* attributes;
    brfile_open_read_cbfn* open_read;
    brfile_open_write_cbfn* open_write;
    brfile_close_cbfn* close;
    brfile_eof_cbfn* eof;
    brfile_getchr_cbfn* getchr;
    brfile_putchr_cbfn* putchr;
    brfile_read_cbfn* read;
    brfile_write_cbfn* write;
    brfile_getline_cbfn* getline;
    brfile_putline_cbfn* putline;
    brfile_advance_cbfn* advance;
} br_filesystem;

typedef struct br_allocator
{
    char* identifier;
    brmem_allocate_cbfn* allocate;
    brmem_free_cbfn* free;
    brmem_inquire_cbfn* inquire;
    brmem_align_cbfn* align;
} br_allocator;

typedef struct br_diaghandler
{
    char* identifier;
    br_diag_warning_cbfn* warning;
    br_diag_failure_cbfn* failure;
} br_diaghandler;

typedef struct br_errorhandler
{
    char* identifier;
    br_diag_warning_cbfn* message;
    br_diag_failure_cbfn* error;
} br_errorhandler;

typedef struct br_colour_range
{
    br_colour low;
    br_colour high;
} br_colour_range;

typedef struct br_matrix23
{
    br_scalar m[3][2];
} br_matrix23;

typedef struct br_matrix23_f
{
    br_float m[3][2];
} br_matrix23_f;

typedef struct br_matrix23_x
{
    br_fixed_ls m[3][2];
} br_matrix23_x;

typedef struct br_matrix34
{
    br_scalar m[4][3];
} br_matrix34;

typedef struct br_matrix34_f
{
    br_float m[4][3];
} br_matrix34_f;

typedef struct br_matrix34_x
{
    br_fixed_ls m[4][3];
} br_matrix34_x;

typedef struct br_matrix4
{
    br_scalar m[4][4];
} br_matrix4;

typedef struct br_matrix4_f
{
    br_float m[4][4];
} br_matrix4_f;

typedef struct br_matrix4_x
{
    br_fixed_ls m[4][4];
} br_matrix4_x;

typedef struct br_vector2
{
    br_scalar v[2];
} br_vector2;

typedef struct br_vector3
{
    br_scalar v[3];
} br_vector3;

typedef struct br_vector4
{
    br_scalar v[4];
} br_vector4;

typedef struct br_vector2_x
{
    br_fixed_ls v[2];
} br_vector2_x;

typedef struct br_vector3_x
{
    br_fixed_ls v[3];
} br_vector3_x;

typedef struct br_vector4_x
{
    br_fixed_ls v[4];
} br_vector4_x;

typedef struct br_vector2_f
{
    br_float v[2];
} br_vector2_f;

typedef struct br_vector3_f
{
    br_float v[3];
} br_vector3_f;

typedef struct br_vector4_f
{
    br_float v[4];
} br_vector4_f;

typedef struct br_vector2_i
{
    br_int_32 v[2];
} br_vector2_i;

typedef struct br_vector3_i
{
    br_int_32 v[3];
} br_vector3_i;

typedef struct br_vector4_i
{
    br_int_32 v[4];
} br_vector4_i;

typedef struct br_fvector2
{
    br_fraction v[2];
} br_fvector2;

typedef struct br_fvector3
{
    br_fraction v[3];
} br_fvector3;

typedef struct br_fvector4
{
    br_fraction v[4];
} br_fvector4;

typedef struct br_fvector2_f
{
    br_fraction_f v[2];
} br_fvector2_f;

typedef struct br_fvector3_f
{
    br_fraction_f v[3];
} br_fvector3_f;

typedef struct br_fvector4_f
{
    br_fraction v[4];
} br_fvector4_f;

typedef struct br_fvector2_x
{
    br_fraction_x v[2];
} br_fvector2_x;

typedef struct br_fvector3_x
{
    br_fraction_x v[3];
} br_fvector3_x;

typedef struct br_fvector4_x
{
    br_fraction_x v[4];
} br_fvector4_x;

typedef struct br_bounds2
{
    br_vector2 min;
    br_vector2 max;
} br_bounds2;

typedef struct br_bounds3
{
    br_vector3 min;
    br_vector3 max;
} br_bounds3;

typedef struct br_bounds4
{
    br_vector4 min;
    br_vector4 max;
} br_bounds4;

typedef struct br_bounds2_f
{
    br_vector2_f min;
    br_vector2_f max;
} br_bounds2_f;

typedef struct br_bounds3_f
{
    br_vector3_f min;
    br_vector3_f max;
} br_bounds3_f;

typedef struct br_bounds4_f
{
    br_vector4_f min;
    br_vector4_f max;
} br_bounds4_f;

typedef struct br_bounds2_x
{
    br_vector2_x min;
    br_vector2_x max;
} br_bounds2_x;

typedef struct br_bounds3_x
{
    br_vector3_x min;
    br_vector3_x max;
} br_bounds3_x;

typedef struct br_bounds4_x
{
    br_vector4_x min;
    br_vector4_x max;
} br_bounds4_x;

typedef struct br_bounds2_i
{
    br_vector2_i min;
    br_vector2_i max;
} br_bounds2_i;

typedef struct br_bounds3_i
{
    br_vector3_i min;
    br_vector3_i max;
} br_bounds3_i;

typedef struct br_bounds4_i
{
    br_vector4_i min;
    br_vector4_i max;
} br_bounds4_i;

typedef struct br_euler
{
    br_angle a;
    br_angle b;
    br_angle c;
    br_uint_8 order;
} br_euler;

typedef struct br_quat
{
    br_scalar x;
    br_scalar y;
    br_scalar z;
    br_scalar w;
} br_quat;

typedef struct br_transform
{                        // size: 0x34
    br_uint_16 type;     // @0x0
    union {              // size: 0x30
        br_matrix34 mat; // @0x0
        struct
        {                      // size: 0x30
            br_euler e;        // @0x0
            br_scalar _pad[7]; // @0x8
            br_vector3 t;      // @0x24
        } euler;               // @0x0
        struct
        {                      // size: 0x30
            br_quat q;         // @0x0
            br_scalar _pad[5]; // @0x10
            br_vector3 t;      // @0x24
        } quat;                // @0x0
        struct
        {                      // size: 0x30
            br_vector3 look;   // @0x0
            br_vector3 up;     // @0xc
            br_scalar _pad[3]; // @0x18
            br_vector3 t;      // @0x24
        } look_up;             // @0x0
        struct
        {                      // size: 0x30
            br_scalar _pad[9]; // @0x0
            br_vector3 t;      // @0x24
        } translate;           // @0x0
    } t;                       // @0x4
} br_transform;

typedef struct br_pixelmap
{
    br_uint_32 _reserved;
    char* identifier;
    void* pixels;
    br_uint_32 pixels_qualifier;
    br_pixelmap* map;
    br_colour_range src_key;
    br_colour_range dst_key;
    br_uint_32 key;
    br_int_16 row_bytes;
    br_int_16 mip_offset;
    br_uint_8 type;
    br_uint_8 flags;
    br_uint_16 copy_function;
    br_uint_16 base_x;
    br_uint_16 base_y;
    br_uint_16 width;
    br_uint_16 height;
    br_int_16 origin_x;
    br_int_16 origin_y;
    void* user;
    void* stored;
} br_pixelmap;

typedef struct br_point
{
    br_int_32 x;
    br_int_32 y;
} br_point;

typedef struct br_rectangle
{
    br_int_32 x;
    br_int_32 y;
    br_int_32 w;
    br_int_32 h;
} br_rectangle;

typedef struct br_font
{
    br_uint_32 flags;
    br_uint_16 glyph_x;
    br_uint_16 glyph_y;
    br_int_16 spacing_x;
    br_int_16 spacing_y;
    br_int_8* width;
    br_uint_16* encoding;
    br_uint_8* glyphs;
} br_font;

typedef struct br_object
{
    int a;
} br_object;

typedef union br_token_value br_token_value;
typedef union br_value_tag {
    br_uint_32 u32;
    br_boolean b;
    void* p;
    br_token t;
    br_int_8 i8;
    br_uint_8 u8;
    br_int_16 i16;
    br_uint_16 u16;
    br_int_32 i32;
    br_fixed_ls x;
    br_float f;
    br_scalar s;
    br_angle a;
    br_colour rgb;
    br_object* o;
    br_vector2_i* v2_i;
    br_vector3_i* v3_i;
    br_vector4_i* v4_i;
    br_vector2_x* v2_x;
    br_vector3_x* v3_x;
    br_vector4_x* v4_x;
    br_vector2_f* v2_f;
    br_vector3_f* v3_f;
    br_vector4_f* v4_f;
    br_matrix23_x* m23_x;
    br_matrix34_x* m34_x;
    br_matrix4_x* m4_x;
    br_matrix23_f* m23_f;
    br_matrix34_f* m34_f;
    br_matrix4_f* m4_f;
    char* str;
    char* cstr;
    br_object** hl;
    br_token* tl;
    void** pl;
    br_token_value* tvl;
} br_value;

typedef struct br_token_value
{
    br_token t;
    br_value v;
} br_token_value;

typedef struct br_pool_block br_pool_block;
typedef struct br_pool_block
{
    br_pool_block* next;
} br_pool_block;

typedef struct br_pool
{
    br_pool_block* free;
    br_uint_32 block_size;
    br_uint_32 chunk_size;
    int mem_type;
} br_pool;

typedef struct br_primitive
{
    br_primitive* next;
    br_uint_32 type;
    void* stored;
    void* v[3];
} br_primitive;

typedef struct br_order_table
{
    br_primitive** table;
    br_uint_16 size;
    br_order_table* next;
    br_scalar min_z;
    br_scalar max_z;
    br_scalar sort_z;
    br_scalar scale;
    br_uint_32 flags;
    br_uint_16 type;
    br_uint_16 visits;
} br_order_table;

typedef struct br_primitive_heap
{
    br_uint_8* base;
    br_size_t size;
    br_uint_8* current;
} br_primitive_heap;

typedef struct br_associative_array_tag
{
    br_token_value* tv;
    br_uint_16 num_elements;
    br_uint_16 max_elements;
} br_associative_array;

typedef struct br_device
{
    br_uint_32 magic;
    char* identifier;
    br_font* default_font;
    br_uint_32 qualifier;
    dev_fill_cbfn* fill;
    dev_rectangle_copy_cbfn* rectangle_copy;
    dev_rectangle_fill_cbfn* rectangle_fill;
    dev_dirty_rectangle_copy_cbfn* dirty_rectangle_copy;
    dev_dirty_rectangle_fill_cbfn* dirty_rectangle_fill;
    dev_plot_cbfn* plot;
    dev_copy_cbfn* copy;
    dev_line_cbfn* line;
    dev_copy_bits_cbfn* copy_bits;
    dev_double_buffer_cbfn* double_buffer;
    dev_match_cbfn* match;
    dev_clone_cbfn* clone;
    dev_free_cbfn* free;
} br_device;

typedef struct br_outfcty_desc
{
    br_int_32 width;
    br_int_32 width_min;
    br_int_32 width_max;
    br_int_32 height;
    br_int_32 height_min;
    br_int_32 height_max;
    br_uint_8 pmtype;
    br_int_32 pmbits;
    br_boolean indexed;
    br_boolean fullscreen;
} br_outfcty_desc;

typedef struct br_material
{
    br_uint_32 _reserved;
    char* identifier;
    br_colour colour;
    br_uint_8 opacity;
    br_ufraction ka;
    br_ufraction kd;
    br_ufraction ks;
    br_scalar power;
    br_uint_32 flags;
    br_matrix23 map_transform;
    br_uint_8 index_base;
    br_uint_8 index_range;
    br_pixelmap* colour_map;
    br_pixelmap* screendoor;
    br_pixelmap* index_shade;
    br_pixelmap* index_blend;
    br_pixelmap* index_fog;
    br_token_value* extra_surf;
    br_token_value* extra_prim;
    br_scalar fog_min;
    br_scalar fog_max;
    br_colour fog_colour;
    br_uint_32 flags_ext;
    br_pixelmap* colour_map_1;
    br_matrix23 map_transform_1;
    br_int_8 mip_modifier;
    br_uint_8 min_mip;
    br_uint_8 max_mip;
    br_uint_8 alpha_mode;
    br_uint_8 zbuffer_mode;
    br_uint_8 zbuffer_compare;
    br_int_32 subdivide_tolerance;
    void* user;
    void* stored;
} br_material;

typedef struct br_vertex
{
    br_vector3 p;
    br_vector2 map;
    br_uint_8 index;
    br_uint_8 red;
    br_uint_8 grn;
    br_uint_8 blu;
    br_uint_16 _pad0;
    br_fvector3 n;
} br_vertex;

typedef struct br_face
{
    br_uint_16 vertices[3];
    br_uint_16 smoothing;
    br_material* material;
    br_uint_8 index;
    br_uint_8 red;
    br_uint_8 grn;
    br_uint_8 blu;
    br_uint_8 flags;
    br_uint_8 _pad0;
    br_uint_32 _pad1;
    br_fvector3 n;
    br_scalar d;
} br_face;

typedef struct br_primitive_list br_primitive_list;
typedef struct br_primitive_list
{
    br_primitive_list* next;
    br_uint_32 prim_type;
    br_uint_16 nprims;
    br_uint_16 nspares;
    void* prim;
    void* spare;
} br_primitive_list;

typedef struct br_vertex_single
{
    br_vector3 p;
    br_vector2 map;
    br_uint_8 alpha;
    br_uint_8 red;
    br_uint_8 grn;
    br_uint_8 blu;
    br_uint_16 _pad0;
    br_fvector3 n;
} br_vertex_single;

typedef struct br_vertex_double
{
    br_vector3 p;
    br_vector2 map0;
    br_uint_8 alpha0;
    br_uint_8 red0;
    br_uint_8 grn0;
    br_uint_8 blu0;
    br_vector2 map1;
    br_uint_8 alpha1;
    br_uint_8 red1;
    br_uint_8 grn1;
    br_uint_8 blu1;
    br_fvector3 n;
} br_vertex_double;

typedef struct br_point_prim
{
    br_uint_16 vertices[1];
    br_material* material;
} br_point_prim;

typedef struct br_line
{
    br_uint_16 vertices[2];
    br_material* material;
    br_uint_8 alpha0;
    br_uint_8 red0;
    br_uint_8 grn0;
    br_uint_8 blu0;
    br_uint_8 alpha1;
    br_uint_8 red1;
    br_uint_8 grn1;
    br_uint_8 blu1;
} br_line;

typedef struct br_triangle
{
    br_uint_16 vertices[3];
    br_uint_16 smoothing;
    br_material* material;
    br_uint_8 alpha0;
    br_uint_8 red0;
    br_uint_8 grn0;
    br_uint_8 blu0;
    br_uint_8 alpha1;
    br_uint_8 red1;
    br_uint_8 grn1;
    br_uint_8 blu1;
    br_uint_8 flags;
    br_fvector3 n;
    br_scalar d;
} br_triangle;

typedef struct br_quad
{
    br_uint_16 vertices[4];
    br_uint_16 smoothing;
    br_material* material;
    br_uint_8 alpha0;
    br_uint_8 red0;
    br_uint_8 grn0;
    br_uint_8 blu0;
    br_uint_8 alpha1;
    br_uint_8 red1;
    br_uint_8 grn1;
    br_uint_8 blu1;
    br_uint_8 flags;
    br_fvector3 n;
    br_scalar d;
} br_quad;

typedef struct br_strip_face_data
{
    br_uint_16 smoothing;
    br_uint_8 alpha0;
    br_uint_8 red0;
    br_uint_8 grn0;
    br_uint_8 blu0;
    br_uint_8 alpha1;
    br_uint_8 red1;
    br_uint_8 grn1;
    br_uint_8 blu1;
    br_uint_8 flags;
    br_fvector3 n;
    br_scalar d;
} br_strip_face_data;

typedef struct br_tri_strip
{
    br_uint_16 nvertices;
    br_uint_16* vertices;
    br_material* material;
    br_strip_face_data* face_data;
} br_tri_strip;

typedef struct br_actor
{
    br_actor* next;
    br_actor** prev;
    br_actor* children;
    br_actor* parent;
    br_uint_16 depth;
    br_uint_8 type;
    char* identifier;
    br_model* model;
    br_material* material;
    br_uint_8 render_style;
    void* render_data;
    br_transform t;
    void* type_data;
    void* user;
} br_actor;

typedef struct br_model
{
    br_uint_32 _reserved;
    char* identifier;
    br_vertex* vertices;
    br_face* faces;
    br_uint_16 nvertices;
    br_uint_16 nfaces;
    br_vector3 pivot;
    br_uint_16 flags;
    br_model_custom_cbfn* custom;
    void* user;
    br_angle crease_angle;
    br_scalar radius;
    br_bounds bounds;
    void* prepared;
    void* stored;
    br_uint_16 nprimitive_lists;
    br_primitive_list* primitive_list;
} br_model;

typedef struct br_camera
{
    char* identifier;
    br_uint_8 type;
    br_angle field_of_view;
    br_scalar hither_z;
    br_scalar yon_z;
    br_scalar aspect;
    br_scalar width;
    br_scalar height;
    br_scalar distance;
    void* user;
} br_camera;

typedef struct br_light
{
    char* identifier;
    br_uint_8 type;
    br_colour colour;
    br_scalar attenuation_c;
    br_scalar attenuation_l;
    br_scalar attenuation_q;
    br_angle cone_outer;
    br_angle cone_inner;
    void* user;
} br_light;

typedef struct br_fmt_results
{
    br_actor** actors;
    br_model** models;
    br_light** lights;
    br_camera** cameras;
    br_vector4** clip_planes;
    br_bounds3** bounds;
    br_bounds3** bounds_correct;
    br_material** materials;
    br_pixelmap** pixelmaps;
    br_uint_32 nactors;
    br_uint_32 nmodels;
    br_uint_32 nlights;
    br_uint_32 ncameras;
    br_uint_32 nclip_planes;
    br_uint_32 nbounds;
    br_uint_32 nbounds_correct;
    br_uint_32 nmaterials;
    br_uint_32 npixelmaps;
} br_fmt_results;

typedef struct br_fmt_options
{
    br_uint_32 convert_flags;
} br_fmt_options;

typedef struct br_3ds_options
{
    br_uint_32 flags;
    br_scalar hither;
    br_scalar yon;
    br_scalar scale;
    br_fmt_report_cbfn* report;
} br_3ds_options;

typedef struct br_registery br_registry;
typedef void* br_find_failed_cbfn(char*);
typedef br_uint_32 br_enum_cbfn(void*, void*);
typedef void br_surface_fn(br_vertex*, br_fvector3*, br_scalar*);
typedef br_uint_32 br_face_surface_fn(br_vertex*, br_face*, int);
typedef struct br_active_light br_active_light;
typedef void br_light_sub_fn(br_vector3*, br_fvector3*, br_active_light*, br_scalar*);
typedef void br_model_update_cbfn(br_model*, br_uint_16);
typedef void br_material_update_cbfn(br_material*, br_uint_16);
typedef void br_table_update_cbfn(br_pixelmap*, br_uint_16);
typedef void br_map_update_cbfn(br_pixelmap*, br_uint_16);
typedef struct br_node br_node;
typedef struct br_node
{
    br_node* next;
    br_node* prev;
} br_node;

typedef struct br_list
{
    br_node* head;
    br_node* _null;
    br_node* tail;
} br_list;

typedef struct br_simple_node br_simple_node;
typedef struct br_simple_node
{
    br_simple_node* next;
    br_simple_node** prev;
} br_simple_node;

typedef struct br_simple_list
{
    br_simple_node* head;
} br_simple_list;

typedef struct br_registry_entry
{
    br_node node;
    char** item;
} br_registry_entry;

typedef struct br_registery
{
    br_list list;
    int count;
    br_find_failed_cbfn* find_failed_hook;
} br_registry;

typedef struct br_active_light
{
    br_scalar intensity;
    br_vector3 view_position;
    br_vector3 view_direction;
    br_vector3 position;
    br_vector3 direction;
    br_vector3 half;
    br_scalar spot_cosine_outer;
    br_scalar spot_cosine_inner;
    void (*light_sub_function)(br_vector3*, br_fvector3*, br_active_light*, br_scalar*);
    int type;
    br_light* light;
} br_active_light;

typedef struct br_active_clip_plane
{
    br_vector4 screen_plane;
} br_active_clip_plane;

typedef struct fw_fn_table
{
    br_surface_fn* light;
    br_surface_fn* light_material;
    br_surface_fn* light_vertex;
    br_surface_fn* light_texture;
    br_face_surface_fn* face_light;
    br_light_sub_fn* direct;
    br_light_sub_fn* point;
    br_light_sub_fn* point_attn;
    br_light_sub_fn* spot;
    br_light_sub_fn* spot_attn;
} fw_fn_table;

typedef struct br_image_section
{
    char* name;
    void* base;
    br_size_t mem_offset;
    br_size_t mem_size;
    br_uint_32 data_offset;
    br_uint_32 data_size;
} br_image_section;

typedef struct br_image br_image;
typedef struct br_image
{
    br_node node;
    char* identifier;
    br_int_32 type;
    br_int_32 ref_count;
    br_uint_32 ordinal_base;
    br_uint_32 n_functions;
    void** functions;
    br_uint_32 n_names;
    char** names;
    br_uint_16* name_ordinals;
    br_uint_16 n_imports;
    br_image** imports;
    br_uint_16 n_sections;
    br_image_section* sections;
    void* type_pointer;
} br_image;

typedef struct br_open_device
{
    br_device* dev;
    br_image* image;
} br_open_device;

typedef struct br_framework_state
{
    br_boolean active;
    br_registry reg_resource_classes;
    br_resource_class* resource_class_index[256];
    br_list tokens;
    br_token next_free_token;
    br_filesystem* fsys;
    br_allocator* mem;
    br_diaghandler* diag;
    int open_mode;
    void* res;
    void* scratch_ptr;
    br_size_t scratch_size;
    br_size_t scratch_last;
    int scratch_inuse;
    br_error last_error_type;
    void** last_error_value;
    br_list images;
    br_open_device* dev_slots;
    br_int_32 ndev_slots;
    br_associative_array* sys_config;
    br_boolean bAlreadyLoadedDrivers;
} br_framework_state;

// br_framework_state defined by "C:\DETHRACE\source\common\finteray.c" module
typedef struct br_framework_state_2
{
    br_surface_fn* surface_fn;
    br_surface_fn* surface_fn_after_map;
    br_surface_fn* surface_fn_after_copy;
    br_face_surface_fn* face_surface_fn;
    br_matrix23 map_transform;
    br_scalar index_base;
    br_scalar index_range;
    br_matrix4 model_to_screen;
    br_matrix4 view_to_screen;
    br_matrix34 model_to_view;
    br_matrix34 view_to_model;
    br_matrix34 model_to_environment;
    struct
    {
        br_matrix34 m;
        br_actor* a;
    } camera_path[16];
    int vtos_type;
    br_vector3 eye_m;
    br_vector3 eye_m_normalised;
    br_material* material;
    br_active_light active_lights_model[16];
    br_active_light active_lights_view[16];
    br_uint_16 nactive_lights_model;
    br_uint_16 nactive_lights_view;
    int light_is_1md;
    br_vector3 eye_l;
    br_active_clip_plane active_clip_planes[6];
    br_uint_16 nactive_clip_planes;
    br_actor* enabled_lights[16];
    br_actor* enabled_clip_planes[6];
    br_actor* enabled_environment;
    br_pixelmap* output;
    br_scalar vp_width;
    br_scalar vp_height;
    br_scalar vp_ox;
    br_scalar vp_oy;
    int rendering;
    br_registry reg_models;
    br_registry reg_materials;
    br_registry reg_textures;
    br_registry reg_tables;
    br_registry reg_resource_classes;
    br_resource_class* resource_class_index[256];
    br_model_update_cbfn* model_update;
    br_material_update_cbfn* material_update;
    br_table_update_cbfn* table_update;
    br_map_update_cbfn* map_update;
    br_filesystem* fsys;
    br_allocator* mem;
    br_errorhandler* err;
    int open_mode;
    void* res;
    br_model* default_model;
    br_material* default_material;
    fw_fn_table fn_table;
    void* scratch_ptr;
    br_size_t scratch_size;
    br_size_t scratch_last;
    int scratch_inuse;
} br_framework_state_2;

typedef br_error br_exception;
typedef void br_resident_fn();
typedef struct br_tv_template_entry
{
    br_token token;
    char* name;
    br_int_32 offset;
    br_int_16 flags;
    br_int_16 conv;
    br_int_32 conv_arg;
    br_int_32 mask;
} br_tv_template_entry;

typedef struct br_tv_template
{
    int n_entries;
    br_tv_template_entry* entries;
    br_int_32 map_base;
    br_int_32 n_map_entries;
    br_tv_template_entry** map_query_entry;
    br_tv_template_entry** map_set_entry;
    br_boolean names_resolved;
    void* res;
} br_tv_template;

typedef struct br_object_container_dispatch br_object_container_dispatch;
typedef struct br_object_container
{
    br_object_container_dispatch* dispatch;
} br_object_container;

typedef struct br_object_container_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    void* (*_listQuery)(br_object_container*);
    void* (*_tokensMatchBegin)(br_object_container*, br_token, br_token_value*);
    br_boolean(*_tokensMatch)(br_object_container*, br_object*, void*);
    void (*_tokensMatchEnd)(br_object_container*, void*);
    br_error(*_addFront)(br_object_container*, br_object*);
    br_error(*_removeFront)(br_object_container*, br_object**);
    br_error(*_remove)(br_object_container*, br_object*);
    br_error(*_find)(br_object_container*, br_object**, br_token, char*, br_token_value*);
    br_error(*_findMany)(br_object_container*, br_object**, br_int_32, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_count)(br_object_container*, br_int_32*, br_token, char*, br_token_value*);
} br_object_container_dispatch;

typedef struct br_device_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    void* (*_listQuery)(br_object_container*);
    void* (*_tokensMatchBegin)(br_object_container*, br_token, br_token_value*);
    br_boolean(*_tokensMatch)(br_object_container*, br_object*, void*);
    void (*_tokensMatchEnd)(br_object_container*, void*);
    br_error(*_addFront)(br_object_container*, br_object*);
    br_error(*_removeFront)(br_object_container*, br_object**);
    br_error(*_remove)(br_object_container*, br_object*);
    br_error(*_find)(br_object_container*, br_object**, br_token, char*, br_token_value*);
    br_error(*_findMany)(br_object_container*, br_object**, br_int_32, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_count)(br_object_container*, br_int_32*, br_token, char*, br_token_value*);
} br_device_dispatch;

// br_device. Not sure when this is used
typedef struct br_device_2
{
    br_device_dispatch* dispatch;
} br_device_2;

typedef struct br_object_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
} br_object_dispatch;

typedef struct br_geometry_stored_dispatch br_geometry_stored_dispatch;
typedef struct br_geometry_stored
{
    br_geometry_stored_dispatch* dispatch;
} br_geometry_stored;

typedef struct br_renderer_state_stored_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
} br_renderer_state_stored_dispatch;

typedef struct br_renderer_state_stored
{
    br_renderer_state_stored_dispatch* dispatch;
} br_renderer_state_stored;

typedef struct br_buffer_stored_dispatch br_buffer_stored_dispatch;
typedef struct br_buffer_stored
{
    br_buffer_stored_dispatch* dispatch;
} br_buffer_stored;

typedef struct br_device_pixelmap_dispatch br_device_pixelmap_dispatch;
typedef struct br_device_pixelmap
{                                          // size: 68
    br_device_pixelmap_dispatch* dispatch; // @0
    char* pm_identifier;                   // @4
    void* pm_pixels;                       // @8
    br_uint_32 pm_pixels_qualifier;        // @12
    br_pixelmap* pm_map;                   // @16
    br_colour_range pm_src_key;            // @20
    br_colour_range pm_dst_key;            // @28
    br_uint_32 pm_key;                     // @36
    br_int_16 pm_row_bytes;                // @40
    br_int_16 pm_mip_offset;               // @42
    br_uint_8 pm_type;                     // @44
    br_uint_8 pm_flags;                    // @45
    br_uint_16 pm_copy_function;           // @46
    br_uint_16 pm_base_x;                  // @48
    br_uint_16 pm_base_y;                  // @50
    br_uint_16 pm_width;                   // @52
    br_uint_16 pm_height;                  // @54
    br_int_16 pm_origin_x;                 // @56
    br_int_16 pm_origin_y;                 // @58
    void* pm_user;                         // @60
    void* pm_stored;                       // @64
} br_device_pixelmap;

typedef struct br_device_pixelmap_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    br_error(*_validSource)(br_device_pixelmap*, br_boolean*, br_object*);
    br_error(*_resize)(br_device_pixelmap*, br_int_32, br_int_32);
    br_error(*_match)(br_device_pixelmap*, br_device_pixelmap**, br_token_value*);
    br_error(*_allocateSub)(br_device_pixelmap*, br_device_pixelmap**, br_rectangle*);
    br_error(*_copy)(br_device_pixelmap*, br_device_pixelmap*);
    br_error(*_copyTo)(br_device_pixelmap*, br_device_pixelmap*);
    br_error(*_copyFrom)(br_device_pixelmap*, br_device_pixelmap*);
    br_error(*_fill)(br_device_pixelmap*, br_uint_32);
    br_error(*_doubleBuffer)(br_device_pixelmap*, br_device_pixelmap*);
    br_error(*_copyDirty)(br_device_pixelmap*, br_device_pixelmap*, br_rectangle*, br_int_32);
    br_error(*_copyToDirty)(br_device_pixelmap*, br_device_pixelmap*, br_rectangle*, br_int_32);
    br_error(*_copyFromDirty)(br_device_pixelmap*, br_device_pixelmap*, br_rectangle*, br_int_32);
    br_error(*_fillDirty)(br_device_pixelmap*, br_uint_32, br_rectangle*, br_int_32);
    br_error(*_doubleBufferDirty)(br_device_pixelmap*, br_device_pixelmap*, br_rectangle*, br_int_32);
    br_error(*_rectangle)(br_device_pixelmap*, br_rectangle*, br_uint_32);
    br_error(*_rectangle2)(br_device_pixelmap*, br_rectangle*, br_uint_32, br_uint_32);
    br_error(*_rectangleCopy)(br_device_pixelmap*, br_point*, br_device_pixelmap*, br_rectangle*);
    br_error(*_rectangleCopyTo)(br_device_pixelmap*, br_point*, br_device_pixelmap*, br_rectangle*);
    br_error(*_rectangleCopyFrom)(br_device_pixelmap*, br_point*, br_device_pixelmap*, br_rectangle*);
    br_error(*_rectangleStretchCopy)(br_device_pixelmap*, br_rectangle*, br_device_pixelmap*, br_rectangle*);
    br_error(*_rectangleStretchCopyTo)(br_device_pixelmap*, br_rectangle*, br_device_pixelmap*, br_rectangle*);
    br_error(*_rectangleStretchCopyFrom)(br_device_pixelmap*, br_rectangle*, br_device_pixelmap*, br_rectangle*);
    br_error(*_rectangleFill)(br_device_pixelmap*, br_rectangle*, br_uint_32);
    br_error(*_pixelSet)(br_device_pixelmap*, br_point*, br_uint_32);
    br_error(*_line)(br_device_pixelmap*, br_point*, br_point*, br_uint_32);
    br_error(*_copyBits)(br_device_pixelmap*, br_point*, br_uint_8*, br_uint_16, br_rectangle*, br_uint_32);
    br_error(*_text)(br_device_pixelmap*, br_point*, br_font*, char*, br_uint_32);
    br_error(*_textBounds)(br_device_pixelmap*, br_rectangle*, br_font*, char*);
    br_error(*_rowSize)(br_device_pixelmap*, br_size_t*);
    br_error(*_rowSet)(br_device_pixelmap*, void*, br_size_t, br_uint_32);
    br_error(*_rowQuery)(br_device_pixelmap*, void*, br_size_t, br_uint_32);
    br_error(*_pixelQuery)(br_device_pixelmap*, br_uint_32*, br_point*);
    br_error(*_pixelAddressQuery)(br_device_pixelmap*, void**, br_uint_32*, br_point*);
    br_error(*_pixelAddressSet)(br_device_pixelmap*, void*, br_uint_32*);
    br_error(*_originSet)(br_device_pixelmap*, br_point*);
    br_error(*_flush)(br_device_pixelmap*);
    br_error(*_synchronise)(br_device_pixelmap*, br_token, br_boolean);
    br_error(*_directLock)(br_device_pixelmap*, br_boolean);
    br_error(*_directUnlock)(br_device_pixelmap*);
} br_device_pixelmap_dispatch;

typedef struct br_buffer_stored_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    br_error(*_update)(br_buffer_stored*, br_device_pixelmap*, br_token_value*);
} br_buffer_stored_dispatch;

typedef struct brp_vertex
{
} brp_vertex;

typedef struct br_renderer_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    void* (*_listQuery)(br_object_container*);
    void* (*_tokensMatchBegin)(br_object_container*, br_token, br_token_value*);
    br_boolean(*_tokensMatch)(br_object_container*, br_object*, void*);
    void (*_tokensMatchEnd)(br_object_container*, void*);
    br_error(*_addFront)(br_object_container*, br_object*);
    br_error(*_removeFront)(br_object_container*, br_object**);
    br_error(*_remove)(br_object_container*, br_object*);
    br_error(*_find)(br_object_container*, br_object**, br_token, char*, br_token_value*);
    br_error(*_findMany)(br_object_container*, br_object**, br_int_32, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_count)(br_object_container*, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_validDestination)(br_renderer*, br_boolean*, br_object*);
    br_error(*_stateStoredNew)(br_renderer*, br_renderer_state_stored**, br_uint_32, br_token_value*);
    br_error(*_stateStoredAvail)(br_renderer*, br_int_32*, br_uint_32, br_token_value*);
    br_error(*_bufferStoredNew)(br_renderer*, br_buffer_stored**, br_token, br_device_pixelmap*, br_token_value*);
    br_error(*_bufferStoredAvail)(br_renderer*, br_int_32*, br_token, br_token_value*);
    br_error(*_partSet)(br_renderer*, br_token, br_int_32, br_token, br_uint_32);
    br_error(*_partSetMany)(br_renderer*, br_token, br_int_32, br_token_value*, br_int_32*);
    br_error(*_partQuery)(br_renderer*, br_token, br_int_32, br_uint_32*, br_token);
    br_error(*_partQueryBuffer)(br_renderer*, br_token, br_int_32, br_uint_32*, br_uint_32*, br_size_t, br_token);
    br_error(*_partQueryMany)(br_renderer*, br_token, br_int_32, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_partQueryManySize)(br_renderer*, br_token, br_int_32, br_size_t*, br_token_value*);
    br_error(*_partQueryAll)(br_renderer*, br_token, br_int_32, br_token_value*, br_size_t);
    br_error(*_partQueryAllSize)(br_renderer*, br_token, br_int_32, br_size_t*);
    br_error(*_partIndexQuery)(br_renderer*, br_token, br_int_32*);
    br_error(*_modelMulF)(br_renderer*, br_matrix34_f*);
    br_error(*_modelMulX)(br_renderer*, br_matrix34_x*);
    br_error(*_modelPopPushMulF)(br_renderer*, br_matrix34_f*);
    br_error(*_modelPopPushMulX)(br_renderer*, br_matrix34_x*);
    br_error(*_modelInvert)(br_renderer*);
    br_error(*_statePush)(br_renderer*, br_uint_32);
    br_error(*_statePop)(br_renderer*, br_uint_32);
    br_error(*_stateSave)(br_renderer*, br_renderer_state_stored*, br_uint_32);
    br_error(*_stateRestore)(br_renderer*, br_renderer_state_stored*, br_uint_32);
    br_error(*_stateMask)(br_renderer*, br_uint_32*, br_token*, int);
    br_error(*_stateDefault)(br_renderer*, br_uint_32);
    br_error(*_boundsTestF)(br_renderer*, br_token*, br_bounds3_f*);
    br_error(*_boundsTestX)(br_renderer*, br_token*, br_bounds3_x*);
    br_error(*_coverageTestF)(br_renderer*, br_float*, br_bounds3_f*);
    br_error(*_coverageTestX)(br_renderer*, br_fixed_ls*, br_bounds3_x*);
    br_error(*_viewDistanceF)(br_renderer*, br_float*);
    br_error(*_viewDistanceX)(br_renderer*, br_fixed_ls*);
    br_error(*_commandModeSet)(br_renderer*, br_token);
    br_error(*_commandModeQuery)(br_renderer*, br_token*);
    br_error(*_commandModeDefault)(br_renderer*);
    br_error(*_commandModePush)(br_renderer*);
    br_error(*_commandModePop)(br_renderer*);
    br_error(*_flush)(br_renderer*, br_boolean);
    br_error(*_synchronise)(br_renderer*, br_token, br_boolean);
    br_error(*_testRender)(br_renderer*, br_token, brp_vertex*, brp_vertex*, brp_vertex*);
    br_error(*_partQueryCapability)(br_renderer*, br_token, br_int_32, br_token_value*, br_size_t);
    br_error(*_stateQueryPerformance)(br_renderer*, br_fixed_lu*);
} br_renderer_dispatch;

typedef struct br_geometry_stored_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    br_error(*_render)(br_geometry_stored*, br_renderer*);
    br_error(*_renderOnScreen)(br_geometry_stored*, br_renderer*);
} br_geometry_stored_dispatch;

typedef struct br_datafile br_datafile;
typedef struct br_file_struct_member
{
    br_uint_16 type;
    br_uint_32 offset;
    char* name;
    void* extra;
} br_file_struct_member;

typedef struct br_file_struct
{
    char* name;
    br_uint_32 nmembers;
    br_file_struct_member* members;
    int mem_size;
} br_file_struct;

typedef struct br_file_primitives
{
    char* identifier;
    int (*skip)(br_datafile*, br_uint_32);
    int (*chunk_write)(br_datafile*, br_uint_32, br_uint_32);
    int (*chunk_read)(br_datafile*, br_uint_32*);
    void (*count_write)(br_datafile*, br_uint_32);
    br_uint_32(*count_read)(br_datafile*);
    int (*count_size)(br_datafile*);
    br_uint_32(*struct_write)(br_datafile*, br_file_struct*, void*);
    br_uint_32(*struct_read)(br_datafile*, br_file_struct*, void*);
    int (*struct_size)(br_datafile*, br_file_struct*, void*);
    int (*block_write)(br_datafile*, void*, int, int, int, int);
    void* (*block_read)(br_datafile*, void*, int*, int, int);
    int (*block_size)(br_datafile*, void*, int, int, int, int);
    int (*name_write)(br_datafile*, char*);
    char* (*name_read)(br_datafile*, char*);
    int (*name_size)(br_datafile*, char*);
} br_file_primitives;

typedef struct br_chunks_table_entry
{
    br_uint_32 id;
    br_uint_8 has_count;
    int (*handler)(br_datafile*, br_uint_32, br_uint_32, br_uint_32);
} br_chunks_table_entry;

typedef struct br_chunks_table
{
    int nentries;
    br_chunks_table_entry* entries;
} br_chunks_table;

typedef struct br_file_enum_member
{
    int value;
    char* name;
} br_file_enum_member;

typedef struct br_file_enum
{
    br_uint_32 nmembers;
    br_file_enum_member* members;
} br_file_enum;

typedef struct br_device_clut_dispatch br_device_clut_dispatch;
typedef struct br_device_clut
{
    br_device_clut_dispatch* dispatch;
} br_device_clut;

typedef struct br_device_clut_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    br_error(*_entrySet)(br_device_clut*, br_int_32, br_colour);
    br_error(*_entryQuery)(br_device_clut*, br_colour*, br_int_32);
    br_error(*_entrySetMany)(br_device_clut*, br_int_32, br_int_32, br_colour*);
    br_error(*_entryQueryMany)(br_device_clut*, br_colour*, br_int_32, br_int_32);
} br_device_clut_dispatch;

typedef struct br_geometry_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
} br_geometry_dispatch;

typedef struct br_geometry_lighting_dispatch br_geometry_lighting_dispatch;
typedef struct br_geometry_lighting
{
    br_geometry_lighting_dispatch* dispatch;
} br_geometry_lighting;

typedef struct br_geometry_lighting_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    br_error(*_renderF)(br_geometry_lighting*, br_renderer*, br_vector3_f*, br_vector3_f*, br_colour*, br_colour*, br_uint_16*, int, int, int, int, int);
    br_error(*_renderX)(br_geometry_lighting*, br_renderer*, br_vector3_x*, br_vector3_x*, br_colour*, br_colour*, br_uint_16*, int, int, int, int, int);
} br_geometry_lighting_dispatch;

typedef struct br_v1db_enable
{
    br_int_32 max;
    br_int_32 count;
    br_int_32 type;
    char* name;
    br_actor** enabled;
} br_v1db_enable;

typedef struct br_geometry br_geometry;

typedef struct br_v1db_state
{
    br_boolean active;
    br_boolean zs_active;
    br_boolean zb_active;
    br_int_32 rendering;
    br_renderer* renderer;
    br_renderer* query_renderer;
    br_geometry* format_model;
    br_geometry* format_buckets;
    br_geometry_lighting* format_lighting;
    br_matrix4 model_to_screen;
    br_matrix34 model_to_view;
    br_boolean model_to_screen_valid;
    br_uint_32 ttype;
    br_actor* render_root;
    struct
    {
        br_matrix34 m;
        br_actor* a;
        br_uint_8 transform_type;
    } camera_path[16];
    br_v1db_enable enabled_lights;
    br_v1db_enable enabled_clip_planes;
    br_v1db_enable enabled_horizon_planes;
    br_int_32 max_light;
    br_int_32 max_clip;
    br_actor* enabled_environment;
    br_registry reg_models;
    br_registry reg_materials;
    br_registry reg_textures;
    br_registry reg_tables;
    void* res;
    br_model* default_model;
    br_material* default_material;
    void* default_render_data;
    br_order_table* default_order_table;
    br_order_table* primary_order_table;
    br_order_table* order_table_list;
    br_primitive_heap heap;
    br_primitive_cbfn* primitive_call;
    br_renderbounds_cbfn* bounds_call;
    br_vector2 origin;
    br_scalar vp_ox;
    br_scalar vp_oy;
    br_scalar vp_width;
    br_scalar vp_height;
    br_pixelmap* colour_buffer;
} br_v1db_state;

typedef struct br_renderer_facility br_renderer_facility;

typedef struct br_renderer_facility_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    void* (*_listQuery)(br_object_container*);
    void* (*_tokensMatchBegin)(br_object_container*, br_token, br_token_value*);
    br_boolean(*_tokensMatch)(br_object_container*, br_object*, void*);
    void (*_tokensMatchEnd)(br_object_container*, void*);
    br_error(*_addFront)(br_object_container*, br_object*);
    br_error(*_removeFront)(br_object_container*, br_object**);
    br_error(*_remove)(br_object_container*, br_object*);
    br_error(*_find)(br_object_container*, br_object**, br_token, char*, br_token_value*);
    br_error(*_findMany)(br_object_container*, br_object**, br_int_32, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_count)(br_object_container*, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_validDestination)(br_renderer_facility*, br_boolean*, br_object*);
    br_error(*_rendererNew)(br_renderer_facility*, br_renderer**, br_token_value*);
} br_renderer_facility_dispatch;

typedef struct br_output_facility_dispatch br_output_facility_dispatch;
typedef struct br_output_facility
{
    br_output_facility_dispatch* dispatch;
} br_output_facility;

typedef struct br_output_facility_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    void* (*_listQuery)(br_object_container*);
    void* (*_tokensMatchBegin)(br_object_container*, br_token, br_token_value*);
    br_boolean(*_tokensMatch)(br_object_container*, br_object*, void*);
    void (*_tokensMatchEnd)(br_object_container*, void*);
    br_error(*_addFront)(br_object_container*, br_object*);
    br_error(*_removeFront)(br_object_container*, br_object**);
    br_error(*_remove)(br_object_container*, br_object*);
    br_error(*_find)(br_object_container*, br_object**, br_token, char*, br_token_value*);
    br_error(*_findMany)(br_object_container*, br_object**, br_int_32, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_count)(br_object_container*, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_validSource)(br_output_facility*, br_boolean*, br_object*);
    br_error(*_pixelmapNew)(br_output_facility*, br_device_pixelmap**, br_token_value*);
    br_error(*_clutNew)(br_output_facility*, br_device_clut**, br_token_value*);
    br_error(*_queryCapability)(br_output_facility*, br_token_value*, br_token_value*, br_size_t);
} br_output_facility_dispatch;

typedef struct br_primitive_state_dispatch br_primitive_state_dispatch;
typedef struct br_primitive_state
{
    br_primitive_state_dispatch* dispatch;
} br_primitive_state;

typedef struct brp_block
{
} brp_block;

typedef struct br_primitive_state_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    br_error(*_partSet)(br_primitive_state*, br_token, br_int_32, br_token, br_uint_32);
    br_error(*_partSetMany)(br_primitive_state*, br_token, br_int_32, br_token_value*, br_int_32*);
    br_error(*_partQuery)(br_primitive_state*, br_token, br_int_32, br_uint_32*, br_token);
    br_error(*_partQueryBuffer)(br_primitive_state*, br_token, br_int_32, br_uint_32*, br_uint_32*, br_size_t, br_token);
    br_error(*_partQueryMany)(br_primitive_state*, br_token, br_int_32, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_partQueryManySize)(br_primitive_state*, br_token, br_int_32, br_size_t*, br_token_value*);
    br_error(*_partQueryAll)(br_primitive_state*, br_token, br_int_32, br_token_value*, br_size_t);
    br_error(*_partQueryAllSize)(br_primitive_state*, br_token, br_int_32, br_size_t*);
    br_error(*_partIndexQuery)(br_primitive_state*, br_token, br_int_32*);
    br_error(*_stateDefault)(br_primitive_state*, br_uint_32);
    br_error(*_stateCopy)(br_primitive_state*, br_primitive_state*, br_uint_32);
    br_error(*_renderBegin)(br_primitive_state*, brp_block**, br_boolean*, br_boolean*, br_boolean, br_int_32);
    br_error(*_renderEnd)(br_primitive_state*, brp_block*);
    br_error(*_rangesQueryF)(br_primitive_state*, br_float*, br_float*, br_int_32);
    br_error(*_rangesQueryX)(br_primitive_state*, br_fixed_ls*, br_fixed_ls*, br_int_32);
    br_error(*_partQueryCapability)(br_primitive_state*, br_token, br_int_32, br_token_value*, br_size_t);
    br_error(*_stateQueryPerformance)(br_primitive_state*, br_fixed_lu*);
} br_primitive_state_dispatch;

typedef struct br_primitive_library br_primitive_library;
typedef struct br_primitive_library_dispatch
{
    void (*__reserved0)(br_object*);
    void (*__reserved1)(br_object*);
    void (*__reserved2)(br_object*);
    void (*__reserved3)(br_object*);
    void (*_free)(br_object*);
    char* (*_identifier)(br_object*);
    br_token(*_type)(br_object*);
    br_boolean(*_isType)(br_object*, br_token);
    br_device* (*_device)(br_object*);
    br_int_32(*_space)(br_object*);
    br_tv_template* (*_templateQuery)(br_object*);
    br_error(*_query)(br_object*, br_uint_32*, br_token);
    br_error(*_queryBuffer)(br_object*, br_uint_32*, void*, br_size_t, br_token);
    br_error(*_queryMany)(br_object*, br_token_value*, void*, br_size_t, br_int_32*);
    br_error(*_queryManySize)(br_object*, br_size_t*, br_token_value*);
    br_error(*_queryAll)(br_object*, br_token_value*, br_size_t);
    br_error(*_queryAllSize)(br_object*, br_size_t*);
    void* (*_listQuery)(br_object_container*);
    void* (*_tokensMatchBegin)(br_object_container*, br_token, br_token_value*);
    br_boolean(*_tokensMatch)(br_object_container*, br_object*, void*);
    void (*_tokensMatchEnd)(br_object_container*, void*);
    br_error(*_addFront)(br_object_container*, br_object*);
    br_error(*_removeFront)(br_object_container*, br_object**);
    br_error(*_remove)(br_object_container*, br_object*);
    br_error(*_find)(br_object_container*, br_object**, br_token, char*, br_token_value*);
    br_error(*_findMany)(br_object_container*, br_object**, br_int_32, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_count)(br_object_container*, br_int_32*, br_token, char*, br_token_value*);
    br_error(*_stateNew)(br_primitive_library*, br_primitive_state**);
    br_error(*_bufferStoredNew)(br_primitive_library*, br_buffer_stored**, br_token, br_device_pixelmap*, br_token_value*);
    br_error(*_bufferStoredAvail)(br_primitive_library*, br_int_32*, br_token, br_token_value*);
    br_error(*_flush)(br_primitive_library*, br_boolean);
    br_error(*_synchronise)(br_primitive_library*, br_token, br_boolean);
    br_error(*_mask)(br_primitive_library*, br_uint_32*, br_token*, int);
} br_primitive_library_dispatch;

typedef struct br_file
{
    void* raw_file;
    br_boolean writing;
    int mode;
    char name[1];
} br_file;

typedef enum br_lexer_token_id
{
    T_EOF = 0,
    T_ERROR = 1,
    T_IDENT = 2,
    T_STRING = 3,
    T_INTEGER = 4,
    T_REAL = 5,
    T_EXCLAM = 33,
    T_DQUOTE = 34,
    T_HASH = 35,
    T_DOLLAR = 36,
    T_PERCENT = 37,
    T_AMPERSAND = 38,
    T_RQUOTE = 39,
    T_LPAREN = 40,
    T_RPAREN = 41,
    T_ASTERISK = 42,
    T_PLUS = 43,
    T_COMMA = 44,
    T_DASH = 45,
    T_PERIOD = 46,
    T_SLASH = 47,
    T_COLON = 58,
    T_SEMICOLON = 59,
    T_LANGLE = 60,
    T_EQUAL = 61,
    T_RANGLE = 62,
    T_QUERY = 63,
    T_COMAT = 64,
    T_LSQUARE = 91,
    T_BSLASH = 92,
    T_RSQUARE = 93,
    T_CARET = 94,
    T_UNDERBAR = 95,
    T_LQUOTE = 96,
    T_LBRACE = 123,
    T_VBAR = 124,
    T_RBRACE = 125,
    T_TILDE = 126,
    T_KEYWORD = 128
} br_lexer_token_id;
typedef struct br_lexer_source br_lexer_source;
typedef void br_lexer_getchar_cbfn(br_lexer_source*);
typedef struct br_lexer br_lexer;
typedef void br_lexer_error_cbfn(br_lexer*, char*);
typedef struct br_lexer_source
{
    br_lexer_source* prev;
    char* name;
    br_int_32 line;
    br_int_32 next;
    br_lexer_getchar_cbfn* getchar;
    void* ptr;
} br_lexer_source;

typedef struct br_lexer_token
{
    br_lexer_token_id id;
    struct
    {
        br_int_32 integer;
        float real;
        char* string;
    };
} br_lexer_token;

typedef struct br_lexer_keyword
{
    char* name;
    br_int_32 id;
} br_lexer_keyword;

typedef struct br_lexer
{
    br_lexer_source* source;
    br_lexer_token current;
    br_lexer_keyword* keywords;
    br_int_32 nkeywords;
    char eol_comment;
    void (*advance)(br_lexer*);
    br_putline_cbfn* putline;
    void* putline_arg;
    char* string_buffer;
    br_int_32 string_buffer_size;
    br_lexer_error_cbfn* error;
} br_lexer;

typedef br_error br_tv_custom_query_cbfn(br_uint_32*, void**, br_size_t*, void*, br_tv_template_entry*);
typedef br_error br_tv_custom_set_cbfn(void*, br_uint_32*, br_tv_template_entry*);
typedef br_size_t br_tv_custom_extra_size_cbfn(void*, br_tv_template_entry*);
typedef struct br_tv_custom
{
    br_tv_custom_query_cbfn* query;
    br_tv_custom_set_cbfn* set;
    br_tv_custom_extra_size_cbfn* extra_size;
} br_tv_custom;

typedef struct br_token_entry
{
    br_node node;
    char* identifier;
    br_int_32 type;
    br_token token;
    br_int_32 base_length;
} br_token_entry;



typedef struct br_pixelmap_state
{
    void* res;
    br_tv_template* device_pixelmap_template;
    br_tv_template* pixelmap_match_template;
} br_pixelmap_state;

typedef struct pm_type_info
{
    br_uint_16 bits;
    br_uint_16 file_size;
    br_uint_16 align;
    br_uint_16 channels;
} pm_type_info;

typedef struct match_tokens
{
    br_token use;
    br_uint_8 pixel_type;
    br_int_32 pixel_bits;
    br_int_32 width;
    br_int_32 height;
    br_object* renderer;
} match_tokens;

typedef struct host_info
{
    br_uint_32 size;
    char identifier[40];
    br_uint_32 capabilities;
    br_token processor_family;
    br_token processor_type;
} host_info;

typedef struct host_interrupt_hook
{
    br_uint_8 vector;
    br_boolean active;
    br_uint_32 old_offset;
    br_uint_16 old_sel;
} host_interrupt_hook;

typedef struct host_exception_hook
{
    br_uint_8 exception;
    br_boolean active;
    br_uint_32 old_offset;
    br_uint_16 old_sel;
    br_uint_8 scratch[256];
} host_exception_hook;

typedef struct host_regs
{
    struct
    {
        br_uint_32 edi;
        br_uint_32 esi;
        br_uint_32 ebp;
        br_uint_32 _res;
        br_uint_32 ebx;
        br_uint_32 edx;
        br_uint_32 ecx;
        br_uint_32 eax;
        br_uint_16 flags;
        br_uint_16 es;
        br_uint_16 ds;
        br_uint_16 fs;
        br_uint_16 gs;
        br_uint_16 ip;
        br_uint_16 cs;
        br_uint_16 sp;
        br_uint_16 ss;
    } a;
    struct
    {
        br_uint_16 di;
        br_uint_16 _pad0;
        br_uint_16 si;
        br_uint_16 _pad1;
        br_uint_16 bp;
        br_uint_16 _pad2;
        br_uint_16 _res;
        br_uint_16 _pad3;
        br_uint_16 bx;
        br_uint_16 _pad4;
        br_uint_16 dx;
        br_uint_16 _pad5;
        br_uint_16 cx;
        br_uint_16 _pad6;
        br_uint_16 ax;
        br_uint_16 _pad7;
        br_uint_16 flags;
        br_uint_16 es;
        br_uint_16 ds;
        br_uint_16 fs;
        br_uint_16 gs;
        br_uint_16 ip;
        br_uint_16 cs;
        br_uint_16 sp;
        br_uint_16 ss;
    } b;
    struct
    {
        br_uint_32 _pad0[4];
        br_uint_8 bl;
        br_uint_8 bh;
        br_uint_8 _pad1;
        br_uint_8 _pad2;
        br_uint_8 dl;
        br_uint_8 dh;
        br_uint_8 _pad3;
        br_uint_8 _pad4;
        br_uint_8 cl;
        br_uint_8 ch;
        br_uint_8 _pad5;
        br_uint_8 _pad6;
        br_uint_8 al;
        br_uint_8 ah;
        br_uint_8 _pad7;
        br_uint_8 _pad8;
    } c;
} host_regs;

typedef struct ldt
{
    unsigned long limit_0 : 10;
    unsigned long base_0 : 10;
    unsigned long base_1 : 8;
    unsigned long type : 4;
    unsigned long application : 1;
    unsigned long dpl : 2;
    unsigned long present : 1;
    unsigned long limit_1 : 4;
    unsigned long system : 1;
    unsigned long reserved : 1;
    unsigned long use32 : 1;
    unsigned long granularity : 1;
    unsigned long base_2 : 8;
} ldt;

typedef struct msdos_header
{
    br_uint_16 magic;
    br_uint_16 last_page_bytes;
    br_uint_16 pages;
    br_uint_16 n_relocations;
    br_uint_16 header_size;
    br_uint_16 minalloc;
    br_uint_16 maxalloc;
    br_uint_16 start_ss;
    br_uint_16 start_sp;
    br_uint_16 checksum;
    br_uint_16 start_ip;
    br_uint_16 start_cs;
    br_uint_16 reloc_offset;
    br_uint_16 overlay_number;
    br_uint_16 _reserved0[4];
    br_uint_16 oem_id;
    br_uint_16 oem_info;
    br_uint_16 _reserved1[10];
    br_uint_32 new_header_offset;
} msdos_header;

typedef struct coff_header
{
    br_uint_16 machine;
    br_uint_16 n_sections;
    br_uint_32 time_date;
    br_uint_32 symbols_offset;
    br_uint_32 n_symbols;
    br_uint_16 opt_header_size;
    br_uint_16 flags;
} coff_header;

typedef struct nt_optional_header
{
    br_uint_16 magic;
    br_uint_8 l_major;
    br_uint_8 l_minor;
    br_uint_32 code_size;
    br_uint_32 data_size;
    br_uint_32 bss_size;
    br_uint_32 entry_point;
    br_uint_32 code_base;
    br_uint_32 data_base;
    br_uint_32 image_base;
    br_uint_32 section_alignment;
    br_uint_32 file_alignment;
    br_uint_16 os_major;
    br_uint_16 os_minor;
    br_uint_16 user_major;
    br_uint_16 user_minor;
    br_uint_16 subsys_major;
    br_uint_16 subsys_minor;
    br_uint_32 _reserved;
    br_uint_32 image_size;
    br_uint_32 header_size;
    br_uint_32 file_checksum;
    br_uint_16 subsystem;
    br_uint_16 dll_flags;
    br_uint_32 stack_reserve_size;
    br_uint_32 stack_commit_size;
    br_uint_32 heap_reserve_size;
    br_uint_32 heap_commit_size;
    br_uint_32 loader_flags;
    br_uint_32 n_data_directories;
    struct
    {
        br_uint_32 rva;
        br_uint_32 size;
    };
} nt_optional_header;

typedef struct section_header
{
    br_uint_8 section_name[8];
    br_uint_32 virtual_size;
    br_uint_32 rva;
    br_uint_32 data_size;
    br_uint_32 data_offset;
    br_uint_32 relocs_offset;
    br_uint_32 linenums_offset;
    br_uint_16 n_relocs;
    br_uint_16 n_linenums;
    br_uint_32 flags;
} section_header;

typedef struct resource_header
{
    br_simple_node node;
    br_simple_list children;
    br_uint_8 size_l;
    br_uint_8 size_m;
    br_uint_8 size_h;
    br_uint_8 res_class;
    void* magic_ptr;
    int magic_num;
} resource_header;

typedef struct host_real_memory
{
    br_uint_32 pm_off;
    br_uint_16 pm_seg;
    br_uint_16 _reserved;
    br_uint_16 rm_off;
    br_uint_16 rm_seg;
} host_real_memory;

typedef struct file_info
{
    br_uint_32 type;
    br_uint_32 version;
} file_info;

typedef struct object_list
{
    br_simple_list l;
} object_list;

typedef struct object_list_entry
{
    br_simple_node n;
    br_object* h;
} object_list_entry;

typedef struct token_match
{
    br_token_value* original;
    br_token_value* query;
    br_int_32 n;
    void* extra;
    br_size_t extra_size;
} token_match;

typedef struct token_type
{
    char* identifier;
    br_token type;
    int length;
} token_type;

typedef struct export_directory
{
    br_uint_32 flags;
    br_uint_32 timestamp;
    br_uint_16 major_version;
    br_uint_16 minor_version;
    br_uint_32 name;
    br_uint_32 ordinal_base;
    br_uint_32 n_entries;
    br_uint_32 n_names;
    br_uint_32 export_table;
    br_uint_32 name_table;
    br_uint_32 ordinal_table;
} export_directory;

typedef struct import_directory
{
    br_uint_32 lookup_table;
    br_uint_32 timestamp;
    br_uint_32 forwarder;
    br_uint_32 name;
    br_uint_32 address_table;
} import_directory;

typedef struct basereloc_header
{
    br_uint_32 rva;
    br_uint_32 size;
} basereloc_header;

typedef struct order_info
{
    br_uint_8 a0;
    br_uint_8 a1;
    br_uint_8 a2;
    br_uint_8 _pad[1];
} order_info;

typedef struct transform_type
{
    br_uint_32 id;
    br_file_struct* fs;
} transform_type;

typedef enum dosio_event_type
{
    DOSIO_EVENT_KEY_DOWN = 0,
    DOSIO_EVENT_KEY_UP = 1,
    DOSIO_EVENT_POINTER1_DOWN = 2,
    DOSIO_EVENT_POINTER1_UP = 3,
    DOSIO_EVENT_POINTER2_DOWN = 4,
    DOSIO_EVENT_POINTER2_UP = 5,
    DOSIO_EVENT_POINTER3_DOWN = 6,
    DOSIO_EVENT_POINTER3_UP = 7,
    DOSIO_EVENT_POINTER_MOVE = 8,
    DOSIO_EVENT_MAX = 9
} dosio_event_type;

typedef enum dosio_event_qual
{
    DOSIO_QUAL_SHIFT = 1,
    DOSIO_QUAL_CONTROL = 2,
    DOSIO_QUAL_ALT = 4
} dosio_event_qual;

typedef struct dosio_event
{
    br_uint_16 type;
    br_uint_16 qualifiers;
    br_uint_32 value_1;
    br_uint_32 value_2;
} dosio_event;

typedef struct dosio_event_queue
{
    br_uint_16 total;
    br_uint_16 count;
    br_uint_16 head;
    br_uint_16 tail;
    dosio_event slots[1];
} dosio_event_queue;

typedef struct pm_temp_edge
{
    struct pm_temp_edge* next;
    br_uint_16 first;
    br_uint_16 last;
    char other;
} pm_temp_edge;

typedef struct prep_vertex
{
    br_vector3 n;
    br_uint_16 v;
    br_uint_16 f;
} prep_vertex;

typedef struct fmt_vertex
{
    br_vector3 p;
    br_vector2 map;
    br_vector3 n;
} DR_VERTEX, fmt_vertex;

typedef struct v11face
{
    br_uint_16 vertices[3];
    br_uint_16 edges[3];
    br_vector4 eqn;
} DR_FACE, v11face;

typedef struct v11group
{
    void* stored;
    DR_FACE* faces;
    br_colour* face_colours;
    br_uint_16* face_user;
    DR_VERTEX* vertices;
    br_colour* vertex_colours;
    br_uint_16* vertex_user;
    br_uint_16 nfaces;
    br_uint_16 nvertices;
    br_uint_16 nedges;
} v11group;

typedef struct v11model
{
    br_size_t size;
    br_uint_32 flags;
    br_uint_16 ngroups;
    br_vector3 pivot;
    v11group* groups;
} v11model;

typedef short SHORT;
typedef unsigned short USHORT;
typedef int INT;
typedef int BOOL;
typedef unsigned int UINT;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int W32;
typedef unsigned short W16;
typedef long LONG;
typedef unsigned long DWORD;
typedef BYTE* PBYTE;
typedef char* PSTR;
typedef WORD* PWORD;
typedef unsigned short* PSHORT;
typedef LONG* PLONG;
typedef void* PVOID;
typedef BYTE* LPBYTE;
typedef BYTE* LPSTR;
typedef WORD* LPWORD;
typedef W32* LPW32;
typedef LONG* LPLONG;
typedef void* LPVOID;
typedef BYTE* HPBYTE;
typedef BYTE* HPSTR;
typedef LONG* HPLONG;
typedef void* HPVOID;
typedef unsigned int HANDLE;
typedef struct _tagRMI_REGS _RMI_REGS;
typedef struct _tagBREGS _HMI_BREGS;
typedef struct _tagWREGS _HMI_WREGS;
typedef struct _tagDREGS _HMI_DREGS;
typedef struct _tagSREGS _HMI_SREGS;
typedef struct _tagIPX_HEADER _IPX_HEADER;
typedef struct _tagIPX_ECB _IPX_ECB;
typedef struct _tagIPX_INTERNET_ADDR _IPX_INTERNET_ADDR;
typedef struct _tagIPX_NETWORK_ADDR _IPX_NETWORK_ADDR;
typedef struct _tagIPX_LOCAL_TARGET _IPX_LOCAL_TARGET;
typedef struct _tagIPX_ELEMENT _IPX_ELEMENT;
typedef struct _tag_NETBIOS_NCB _NETBIOS_NCB;
typedef struct _tagNETBIOS_ADAPTER_STATUS _NETBIOS_ADAPTER_STATUS;
typedef struct _tagNETBIOS_ELEMENT _NETBIOS_ELEMENT;
typedef struct _tagNETBIOS_LOCAL_TARGET _NETBIOS_LOCAL_TARGET;
typedef struct _tagXFER_BLOCK_HEADER _XFER_BLOCK_HEADER;
typedef unsigned char tU8;
typedef signed char tS8;
typedef unsigned short tU16;
typedef short tS16;
typedef unsigned long tU32;
typedef int tS32;
typedef float tF32;
typedef double tF64;
typedef short tX88;
typedef int tX1616;
typedef tU8 tNet_message_type;
typedef char* tS3_sound_source_ptr;
typedef int tS3_sound_tag;
typedef struct tCar_spec_struct tCar_spec;
typedef struct tPath_node_struct tPath_node;
typedef struct tPath_section_struct tPath_section;
typedef tU32 tPlayer_ID;
typedef int tS3_sound_id;
typedef int tS3_type;
typedef int tS3_repeats;
typedef int tS3_volume;
typedef int tS3_effect_tag;
typedef long tS3_priority;
typedef long tS3_pitch;
typedef long tS3_speed;
typedef char* tS3_outlet_ptr;
typedef void* tPipe_reset_proc();
typedef struct tPowerup tPowerup;
typedef int* tGot_proc(tPowerup*, tCar_spec*);
typedef void* tLose_proc(tPowerup*, tCar_spec*);
typedef void* tPeriodic_proc(tPowerup*, tU32);
typedef char tPath_name[256];
typedef struct tFlic_descriptor* tFlic_descriptor_ptr;
typedef struct exception_struct* tException_list;
typedef struct exception_struct tException_node;
typedef int tKey_array[123];
typedef tS32 tJoy_array[8];
typedef void* tPMFM2CB(br_material*);
typedef struct v11face DR_FACE;
typedef struct fmt_vertex DR_VERTEX;

typedef enum tDriver
{
    eDriver_non_car_unused_slot = 0,
    eDriver_non_car = 1,
    eDriver_oppo = 2,
    eDriver_net_human = 3,
    eDriver_local_human = 4
} tDriver;

typedef enum tBounds_type
{
    eUndefined = 0,
    eBounds_ws = 1,
    eBounds_cs = 2
} tBounds_type;

typedef enum tImpact_location
{
    eImpact_top = 0,
    eImpact_bottom = 1,
    eImpact_left = 2,
    eImpact_right = 3,
    eImpact_front = 4,
    eImpact_back = 5,
    eImpact_location_count = 6,
    eImpact_unknown = 7
} tImpact_location;

typedef enum tAxis_comp
{
    eAxis_x = 0,
    eAxis_y = 1,
    eAxis_z = 2
} tAxis_comp;

typedef enum tCondition_operator
{
    eCondition_less_than = 0,
    eCondition_greater_than = 1
} tCondition_operator;

typedef enum tDamage_type
{
    eDamage_engine = 0,
    eDamage_transmission = 1,
    eDamage_driver = 2,
    eDamage_steering = 3,
    eDamage_lf_brake = 4,
    eDamage_rf_brake = 5,
    eDamage_lr_brake = 6,
    eDamage_rr_brake = 7,
    eDamage_lf_wheel = 8,
    eDamage_rf_wheel = 9,
    eDamage_lr_wheel = 10,
    eDamage_rr_wheel = 11,
    eDamage_type_count = 12
} tDamage_type;

typedef enum tJustification
{
    eJust_left = 0,
    eJust_right = 1,
    eJust_centre = 2
} tJustification;

typedef enum tOpponent_objective_type
{
    eOOT_none = 0,
    eOOT_complete_race = 1,
    eOOT_pursue_and_twat = 2,
    eOOT_run_away = 3,
    eOOT_get_near_player = 4,
    eOOT_levitate = 5,
    eOOT_knackered_and_freewheeling = 6,
    eOOT_frozen = 7,
    eOOT_wait_for_some_hapless_sod = 8,
    eOOT_rematerialise = 9,
    eOOT_return_to_start = 10
} tOpponent_objective_type;

typedef enum tFollow_path_result
{
    eFPR_OK = 0,
    eFPR_end_of_path = 1,
    eFPR_given_up = 2
} tFollow_path_result;

typedef enum tPath_section_type_enum
{
    ePST_normal = 0,
    ePST_race_path = 1,
    ePST_cheat_only = 2,
    ePST_count = 3
} tPath_section_type_enum;

typedef enum tPursue_car_state
{
    ePCS_what_now = 0,
    ePCS_following_trail = 1,
    ePCS_following_line_of_sight = 2,
    ePCS_backing_up = 3
} tPursue_car_state;

typedef enum tProcess_objective_command
{
    ePOC_start = 0,
    ePOC_run = 1,
    ePOC_die = 2
} tProcess_objective_command;

typedef enum tParts_category
{
    eParts_armour = 0,
    eParts_power = 1,
    eParts_offensive = 2,
    eParts_count = 3
} tParts_category;

typedef enum tRace_over_reason
{
    eRace_not_over_yet = 255,
    eRace_over_laps = 0,
    eRace_over_peds = 1,
    eRace_over_opponents = 2,
    eRace_over_abandoned = 3,
    eRace_over_out_of_time = 4,
    eRace_over_demo = 5,
    eRace_over_network_victory = 6,
    eRace_over_network_loss = 7,
    eRace_over_count = 8
} tRace_over_reason;

typedef enum tNet_mode
{
    eNet_mode_none = 0,
    eNet_mode_thinking_about_it = 1,
    eNet_mode_host = 2,
    eNet_mode_client = 3
} tNet_mode;

typedef enum tPlayer_status
{
    ePlayer_status_unknown = 0,
    ePlayer_status_ready = 1,
    ePlayer_status_loading = 2,
    ePlayer_status_wrecks_gallery = 3,
    ePlayer_status_summary = 4,
    ePlayer_status_not_responding = 5,
    ePlayer_status_racing = 6,
    ePlayer_status_main_menu = 7,
    ePlayer_status_recovering = 8,
    ePlayer_status_action_replay = 9
} tPlayer_status;

typedef enum tNet_game_type
{
    eNet_game_type_fight_to_death = 0,
    eNet_game_type_car_crusher = 1,
    eNet_game_type_carnage = 2,
    eNet_game_type_checkpoint = 3,
    eNet_game_type_sudden_death = 4,
    eNet_game_type_tag = 5,
    eNet_game_type_foxy = 6,
    eNet_game_type_count = 7
} tNet_game_type;

typedef enum tNet_game_stage
{
    eNet_game_starting = 0,
    eNet_game_ready = 1,
    eNet_game_playing = 2,
    eNet_game_status_count = 3
} tNet_game_stage;

typedef enum tCar_choice
{
    eNet_car_frankie = 0,
    eNet_car_annie = 1,
    eNet_car_both = 2,
    eNet_car_all = 3
} tCar_choice;

typedef enum tNet_sequence_type
{
    eNet_sequence_sequential = 0,
    eNet_sequence_random = 1
} tNet_sequence_type;

typedef enum tPowerup_event
{
    ePowerup_gained = 0,
    ePowerup_ongoing = 1,
    ePowerup_lost = 2
} tPowerup_event;

typedef enum tNet_gameplay_mess
{
    eNet_gameplay_checkpoint = 0,
    eNet_gameplay_wrong_checkpoint = 1,
    eNet_gameplay_suddenly_death = 2,
    eNet_gameplay_suicide = 3,
    eNet_gameplay_go_for_it = 4,
    eNet_gameplay_host_paused = 5,
    eNet_gameplay_host_unpaused = 6,
    eNet_gameplay_earn_credits = 7
} tNet_gameplay_mess;

typedef enum tCar_detail_ownership
{
    eCar_owner_none = 0,
    eCar_owner_someone = 1,
    eCar_owner_self = 2,
    eCar_owner_not_allowed = 3
} tCar_detail_ownership;

typedef enum tS3_error_codes
{
    eS3_error_none = 0,
    eS3_error_digi_init = 1,
    eS3_error_midi_init = 2,
    eS3_error_memory = 3,
    eS3_error_readfile = 4,
    eS3_error_soundbank = 5,
    eS3_error_bad_id = 6,
    eS3_error_bad_stag = 7,
    eS3_error_load_sound = 8,
    eS3_error_start_sound = 9,
    eS3_error_channel_alloc = 10,
    eS3_error_not_spatial = 11,
    eS3_error_function_failed = 12,
    eS3_error_load_song = 13,
    eS3_error_song_not_loaded = 14,
    eS3_error_start_song = 15,
    eS3_error_start_cda = 16,
    eS3_error_cda_not_init = 17,
    eS3_error_already_started_cda = 18,
    eS3_error_nonexistant_source = 19
} tS3_error_codes;

typedef enum tS3_termination_reason
{
    eS3_tr_natural = 0,
    eS3_tr_stopped = 1,
    eS3_tr_overridden = 2
} tS3_termination_reason;

typedef enum tS3_filter_type
{
    eS3_filter_none = 0,
    eS3_filter_reversed = 1,
    eS3_filter_echo = 2
} tS3_filter_type;

typedef enum tPowerup_type
{
    ePowerup_dummy = 0,
    ePowerup_instantaneous = 1,
    ePowerup_timed = 2,
    ePowerup_whole_race = 3
} tPowerup_type;

typedef enum tNet_powerup_type
{
    eNet_powerup_local = 0,
    eNet_powerup_global = 1,
    eNet_powerup_inappropriate = 2
} tNet_powerup_type;

typedef enum tVehicle_type
{
    eVehicle_self = 0,
    eVehicle_net_player = 1,
    eVehicle_opponent = 2,
    eVehicle_rozzer = 3,
    eVehicle_drone = 4,
    eVehicle_not_really = 5
} tVehicle_type;

typedef enum tDepth_effect_type
{
    eDepth_effect_none = 255,
    eDepth_effect_darkness = 0,
    eDepth_effect_fog = 1
} tDepth_effect_type;

typedef enum tPlane_type
{
    ePlane_pos_x = 0,
    ePlane_neg_x = 1,
    ePlane_pos_y = 2,
    ePlane_neg_y = 3,
    ePlane_pos_z = 4,
    ePlane_neg_z = 5,
    ePlane_general = 6
} tPlane_type;

typedef enum tNet_avail
{
    eNet_avail_never = 0,
    eNet_avail_eagle = 1,
    eNet_avail_hawk = 2,
    eNet_avail_all = 3
} tNet_avail;

typedef enum tProg_status
{
    eProg_intro = 0,
    eProg_opening = 1,
    eProg_idling = 2,
    eProg_demo = 3,
    eProg_game_starting = 4,
    eProg_game_ongoing = 5,
    eProg_quit = 6
} tProg_status;

typedef enum tMM_result
{
    eMM_none = 0,
    eMM_continue = 1,
    eMM_end_game = 2,
    eMM_1_start = 3,
    eMM_n_start = 4,
    eMM_loaded = 5,
    eMM_save = 6,
    eMM_options = 7,
    eMM_quit = 8,
    eMM_timeout = 9,
    eMM_recover = 10,
    eMM_abort_race = 11
} tMM_result;

typedef enum tSO_result
{
    eSO_main_menu_invoked = 0,
    eSO_game_over = 1,
    eSO_game_completed = 2,
    eSO_continue = 3
} tSO_result;

typedef enum tRace_result
{
    eRace_game_abandonned = 0,
    eRace_aborted = 1,
    eRace_timed_out = 2,
    eRace_completed = 3
} tRace_result;

typedef enum tFrank_anne
{
    eFrankie = 0,
    eAnnie = 1
} tFrank_anne;

typedef enum tRace_sel_view_type
{
    eVT_Scene = 0,
    eVT_Info = 1,
    eVT_Opponents = 2
} tRace_sel_view_type;

typedef enum tAuto_parts_reply
{
    eAP_auto = 0,
    eAP_manual = 1,
    eAP_piss_off = 2
} tAuto_parts_reply;

typedef enum tWhich_view
{
    eView_undefined = 0,
    eView_left = 1,
    eView_forward = 2,
    eView_right = 3
} tWhich_view;

typedef enum tRolling_type
{
    eRT_alpha = 0,
    eRT_numeric = 1,
    eRT_looping_random = 2,
    eRT_looping_single = 3
} tRolling_type;

typedef enum tCar_texturing_level
{
    eCTL_none = 0,
    eCTL_transparent = 1,
    eCTL_full = 2,
    eCTL_count = 3
} tCar_texturing_level;

typedef enum tRoad_texturing_level
{
    eRTL_none = 0,
    eRTL_full = 1,
    eRTL_count = 2
} tRoad_texturing_level;

typedef enum tWall_texturing_level
{
    eWTL_none = 0,
    eWTL_linear = 1,
    eWTL_full = 2,
    eWTL_count = 3
} tWall_texturing_level;

typedef enum tAdd_to_storage_result
{
    eStorage_not_enough_room = 0,
    eStorage_duplicate = 1,
    eStorage_allocated = 2
} tAdd_to_storage_result;

typedef enum tLollipop_mode
{
    eLollipop_none = 255,
    eLollipop_x_match = 0,
    eLollipop_y_match = 1,
    eLollipop_z_match = 2
} tLollipop_mode;

typedef enum tSmear_type
{
    eSmear_oil = 0,
    eSmear_blood = 1,
    eSmear_count = 2
} tSmear_type;
typedef struct ot_vertex ot_vertex;
typedef void zs_order_table_traversal_cbfn(int, ot_vertex*, ot_vertex*, ot_vertex*);
typedef void tS3_outlet_callback(tS3_outlet_ptr, tS3_sound_tag, tS3_termination_reason);
typedef void tS3_sample_filter(tS3_effect_tag, tS3_sound_tag);

// Make gcc happy
typedef struct exception_
{
    int type;
    char* name;
    double arg1;
    double arg2;
    double retval;
} exception_;

typedef struct ot_vertex
{
    br_scalar screenX;
    br_scalar screenY;
    br_scalar distanceZ;
} ot_vertex;

typedef struct _tagRMI_REGS
{
    long EDI;
    long ESI;
    long EBP;
    long reserved_by_system;
    long EBX;
    long EDX;
    long ECX;
    long EAX;
    short flags;
    short ES;
    short DS;
    short FS;
    short GS;
    short IP;
    short CS;
    short SP;
    short SS;
} _RMI_REGS;

typedef struct _tagBREGS
{
    char al;
    char ah;
    unsigned short _1;
    char bl;
    char bh;
    unsigned short _2;
    char cl;
    char ch;
    unsigned short _3;
    char dl;
    char dh;
    unsigned short _4;
} _HMI_BREGS;

typedef struct _tagWREGS
{
    unsigned short ax;
    unsigned short _1;
    unsigned short bx;
    unsigned short _2;
    unsigned short cx;
    unsigned short _3;
    unsigned short dx;
    unsigned short _4;
    unsigned short si;
    unsigned short _5;
    unsigned short di;
    unsigned short _6;
} _HMI_WREGS;

typedef struct _tagDREGS
{
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int esi;
    unsigned int edi;
    unsigned int cflags;
} _HMI_DREGS;

typedef struct _tagSREGS
{
    unsigned short es;
    unsigned short cs;
    unsigned short ss;
    unsigned short ds;
    unsigned short fs;
    unsigned short gs;
} _HMI_SREGS;

typedef struct _HMI_REGS
{
    _HMI_DREGS x;
    _HMI_WREGS w;
    _HMI_BREGS h;
} _HMI_REGS;

typedef struct _tagIPX_HEADER
{
    USHORT wChecksum;
    USHORT wLength;
    BYTE bTransportControl;
    BYTE bPacketType;
    BYTE bDestNetworkNumber[4];
    BYTE bDestNetworkNode[6];
    USHORT wDestNetworkSocket;
    BYTE bSourceNetworkNumber[4];
    BYTE bSourceNetworkNode[6];
    USHORT wSourceNetworkSocket;
} _IPX_HEADER;

typedef struct _PACKET
{
    PSTR pData;
    USHORT wLength;
} _PACKET;

typedef struct _REAL_PACKET
{
    SHORT wOffset;
    SHORT wSegment;
    USHORT wLength;
} _REAL_PACKET;

typedef struct _ECB_PACKET
{
    _PACKET sPacket;
    _REAL_PACKET sRealPacket;
} _ECB_PACKET;

typedef struct _tagIPX_ECB
{
    PSTR pLinkAddress;
    PSTR pESRRoutine;
    BYTE bInUse;
    BYTE bCompletionCode;
    USHORT wSocket;
    USHORT wConnectionID;
    USHORT wWorkSpace;
    BYTE bDriverWorkSpace[12];
    BYTE bImmediateAddress[6];
    USHORT wPacketCount;
    _ECB_PACKET sPacket[2];
} _IPX_ECB;

typedef struct _tagIPX_INTERNET_ADDR
{
    BYTE bNetwork[4];
    BYTE bNode[6];
} _IPX_INTERNET_ADDR;

typedef struct _tagIPX_NETWORK_ADDR
{
    _IPX_INTERNET_ADDR sInternetAddr;
    BYTE bSocket[2];
} _IPX_NETWORK_ADDR;

typedef struct _tagIPX_LOCAL_TARGET
{
    _IPX_INTERNET_ADDR sInternetAddr;
    BYTE bImmediate[6];
} _IPX_LOCAL_TARGET;

typedef struct _tagIPX_ELEMENT
{
    USHORT wFlags;
    USHORT wOffset;
    _IPX_HEADER sHeader;
    _IPX_ECB sECB;
    _IPX_ECB* pECB;
    _IPX_HEADER* pIPXHeader;
    PSTR pHeader;
    USHORT wHSize;
} _IPX_ELEMENT;

typedef struct _PROT_PTR
{
    PSTR pData;
} _PROT_PTR;

typedef struct _REAL_PTR
{
    SHORT wOffset;
    SHORT wSegment;
} _REAL_PTR;

typedef struct _PTR
{
    _PROT_PTR sPointer;
    _REAL_PTR sRealPtr;
} _PTR;

typedef struct _tag_NETBIOS_NCB
{
    BYTE bCommand;
    BYTE bReturnCode;
    BYTE bLocalSession;
    BYTE bNetworkNameNumber;
    _PTR sPtr;
    USHORT wLength;
    BYTE bCallName[16];
    BYTE bName[16];
    BYTE bReceiveTimeOut;
    BYTE bSendTimeOut;
    PSTR pPostFunction;
    BYTE bAdapter;
    BYTE bCompletionCode;
    BYTE bReserve[14];
} _NETBIOS_NCB;

typedef struct _tagNETBIOS_ADAPTER_STATUS
{
    BYTE bCardID[6];
    BYTE bReleaseLevel;
    BYTE bReserved1;
    BYTE bTypeOfAdapter;
    BYTE bOldOrNewParameters;
    USHORT wReportingPeriodMinutes;
    USHORT wFrameRejectReceivedCount;
    USHORT wFrameRejectSentCount;
    USHORT wReceivedDataFrameErrors;
    USHORT wUnsuccessfulTransmissions;
    LONG dwGoodTransmissions;
    LONG dwGoodReceptions;
    USHORT wRetransmissions;
    USHORT wExhaustedResourceCount;
    USHORT wT1TimerExpiredCount;
    USHORT wTITimerExpiredCount;
    BYTE bReserved2[4];
    USHORT wAvailableNCBS;
    USHORT wMaxNCBSConfigured;
    USHORT wMaxNCBSPossible;
    USHORT wBufferOrStationBusyCount;
    USHORT wMaxDatagramSize;
    USHORT wPendingSessions;
    USHORT wMaxSessionsConfigured;
    USHORT wMaxSessionsPossible;
    USHORT wMaxFrameSize;
    USHORT wNameCount;
    struct
    {
        BYTE bName[16];
        BYTE bNameNumber;
        BYTE bNameStatus;
    };
} _NETBIOS_ADAPTER_STATUS;

typedef struct _tagNETBIOS_ELEMENT
{
    USHORT wFlags;
    USHORT wOffset;
    _NETBIOS_NCB sNCB;
    _NETBIOS_NCB* pNCB;
    PSTR pHeader;
    USHORT wHSize;
} _NETBIOS_ELEMENT;

typedef struct _tagNETBIOS_LOCAL_TARGET
{
    BYTE bNode[16];
} _NETBIOS_LOCAL_TARGET;

typedef struct _tagXFER_BLOCK_HEADER
{
    W32 wSequence;
    W32 wType;
    W32 wID;
    W32 wLength;
    W32 wNode;
    W32 wUser1;
} _XFER_BLOCK_HEADER;

typedef struct _NETNOW_NODE_ADDR
{
    _IPX_LOCAL_TARGET sIPX;
    _NETBIOS_LOCAL_TARGET sNETBIOS;
} _NETNOW_NODE_ADDR;

typedef struct tPD_net_player_info
{
    _IPX_LOCAL_TARGET addr_ipx;
} tPD_net_player_info;

typedef struct tTrack_spec
{
    tU8 ncolumns_x;
    tU8 ncolumns_z;
    br_scalar column_size_x;
    br_scalar column_size_z;
    br_scalar origin_x;
    br_scalar origin_z;
    br_actor* the_actor;
    br_actor*** columns;
    br_actor*** lollipops;
    br_actor*** blends;
    int ampersand_digits;
    br_actor** non_car_list;
} tTrack_spec;

typedef struct tCrush_neighbour
{
    br_uint_8 vertex_index;
    br_uint_8 factor;
} tCrush_neighbour;

typedef struct tCrush_point_spec
{
    br_uint_16 vertex_index;
    br_uint_16 number_of_neighbours;
    br_vector3 limits_neg;
    br_vector3 limits_pos;
    br_vector3 softness_neg;
    br_vector3 softness_pos;
    tCrush_neighbour* neighbours;
} tCrush_point_spec;

typedef struct tCrush_data
{
    int number_of_crush_points;
    float softness_factor;
    float min_fold_factor;
    float max_fold_factor;
    float wibble_factor;
    float limit_deviant;
    float split_chance;
    br_scalar min_y_fold_down;
    tCrush_point_spec* crush_points;
} tCrush_data;

typedef struct tSpecial_volume
{
    br_matrix34 mat;
    br_matrix34 inv_mat;
    br_bounds bounds;
    br_scalar gravity_multiplier;
    br_scalar viscosity_multiplier;
    float car_damage_per_ms;
    float ped_damage_per_ms;
    int no_mat;
    int camera_special_effect_index;
    int sky_col;
    int entry_noise;
    int exit_noise;
    int engine_noise_index;
    br_material* screen_material;
    int material_modifier_index;
} tSpecial_volume;

typedef struct tReduced_matrix
{
    br_vector3 row1;
    br_vector3 row2;
    br_vector3 translation;
} tReduced_matrix;

typedef struct tCar_controls
{
    int joystick_acc : 8;
    int joystick_dec : 8;
    unsigned int left : 1;
    unsigned int right : 1;
    unsigned int acc : 1;
    unsigned int dec : 1;
    unsigned int brake : 1;
    unsigned int up : 1;
    unsigned int down : 1;
    unsigned int holdw : 1;
    unsigned int backwards : 1;
    unsigned int change_up : 1;
    unsigned int change_down : 1;
    unsigned int horn : 1;
} tCar_controls;

typedef struct tNet_message_mechanics_info
{
    tU8 contents_size;
    tNet_message_type type;
    tU32 ID;
    tU32 time;
    tReduced_matrix mat;
    br_vector3 v;
    br_vector3 omega;
    tU8 d[4];
    tCar_controls keys;
    tU32 cc_coll_time;
    tS16 curvature;
    tU16 revs;
    br_scalar front;
    br_scalar back;
    tU32 repair_time;
    tU8 damage[12];
    tU16 powerups;
    br_scalar wheel_dam_offset[4];
} tNet_message_mechanics_info;

typedef struct tDamage_unit
{
    int x_coord;
    int y_coord;
    int damage_level;
    int last_level;
    int smoke_last_level;
    int periods[5];
    br_pixelmap* images;
} tDamage_unit;

typedef struct tDamage_condition
{
    tAxis_comp axis_comp;
    tCondition_operator condition_operator;
    float comparitor;
} tDamage_condition;

typedef struct tDamage_effect
{
    tDamage_type type;
    float weakness_factor;
} tDamage_effect;

typedef struct tDamage_clause
{
    tDamage_condition conditions[2];
    int effect_count;
    int condition_count;
    tDamage_effect effects[4];
} tDamage_clause;

typedef struct tDamage_program
{
    int clause_count;
    tDamage_clause* clauses;
} tDamage_program;

typedef struct tHeadup_slot
{
    int x;
    int y;
    int colour;
    int cockpit_anchored;
    int dimmed_background;
    int dim_left;
    int dim_top;
    int dim_right;
    int dim_bottom;
    tJustification justification;
} tHeadup_slot;

typedef struct tPart_info
{
    char part_name[14];
    tU8* data_ptr;
    tU32 data_length;
    int rank_required;
    int prices[3];
} tPart_info;

typedef struct tParts_spec
{
    int number_of_parts;
    tPart_info info[6];
} tParts_spec;

typedef struct tCar_actor
{
    br_actor* actor;
    br_scalar min_distance_squared;
    tCrush_data crush_data;
    br_vertex* undamaged_vertices;
} tCar_actor;

typedef struct tJoystick
{
    tS32 left;
    tS32 right;
    tS32 acc;
    tS32 dec;
} tJoystick;

typedef struct tPursuee_trail
{
    br_vector3 trail_nodes[25];
    br_vector3 base_heading;
    tU32 time_of_next_recording;
    tU32 end_of_deviation;
    tU8 number_of_nodes;
    tU8 has_deviated_recently;
    tU8 nodes_shifted_this_frame;
} tPursuee_trail;

typedef struct tCar_spec_struct
{
    int index;
    int disabled;
    tDriver driver;
    br_actor* car_master_actor;
    br_scalar min_torque_squared;
    br_scalar break_off_radians_squared;
    br_vector3 v;
    br_vector3 old_v;
    br_vector3 velocity_car_space;
    br_matrix34 oldmat;
    br_matrix34 old_frame_mat;
    br_vector3 pos;
    br_vector3 omega;
    br_vector3 oldomega;
    br_scalar M;
    int infinite_mass;
    br_vector3 I;
    br_vector3 cmpos;
    int extra_point_num;
    br_bounds bounds[3];
    br_bounds max_bounds[2];
    br_vector3 extra_points[6];
    br_scalar original_extra_points_z[6];
    br_vector3 old_point;
    br_vector3 old_norm;
    int box_face_start;
    int box_face_end;
    int box_face_ref;
    br_matrix34 last_box_inv_mat;
    br_bounds last_box;
    int doing_nothing_flag;
    tSpecial_volume* last_special_volume;
    tSpecial_volume* auto_special_volume;
    int frame_collision_flag;
    int collision_flag;
    int max_shrapnel_material;
    br_vector3 direction;
    float speed;
    tU16 car_ID;
    br_material* shrapnel_material[3];
    br_bounds bounds_world_space;
    tBounds_type bounds_ws_type;
    tU16 fire_vertex[12];
    tU16 num_smoke_columns;
    br_vector3 water_normal;
    br_scalar water_d;
    br_scalar water_depth_factor;
    tNet_message_mechanics_info message;
    tU32 last_car_car_collision;
    br_scalar dt;
    struct tCar_spec_struct* who_last_hit_me;
    char name[32];
    char driver_name[32];
    char grid_icon_names[3][14];
    tS8* cockpit_images[3];
    br_pixelmap* prat_cam_left;
    br_pixelmap* prat_cam_top;
    br_pixelmap* prat_cam_right;
    br_pixelmap* prat_cam_bottom;
    br_pixelmap* prat_cam_dummy;
    br_pixelmap* speedo_image[2];
    br_pixelmap* tacho_image[2];
    br_pixelmap* damage_background;
    br_pixelmap* lhands_images[7];
    br_pixelmap* rhands_images[7];
    br_pixelmap* grid_icon_image;
    br_pixelmap* gears_image;
    int fg_index;
    int underwater_ability;
    int invulnerable;
    int wall_climber_mode;
    int can_be_stolen;
    int has_been_stolen;
    int active;
    int knackered;
    int pre_car_col_knackered;
    int render_left[3];
    int render_top[3];
    int render_right[3];
    int render_bottom[3];
    int mirror_left;
    int mirror_top;
    int mirror_right;
    int mirror_bottom;
    int prat_left;
    int prat_top;
    int prat_right;
    int prat_bottom;
    int speedo_x[2];
    int speedo_y[2];
    int speedo_centre_x[2];
    int speedo_centre_y[2];
    int speedo_x_pitch[2];
    int speedo_y_pitch[2];
    int speedo_radius_1[2];
    int speedo_radius_2[2];
    int speedo_start_angle[2];
    int speedo_end_angle[2];
    int speedo_needle_colour[2];
    int tacho_x[2];
    int tacho_y[2];
    int tacho_centre_x[2];
    int tacho_centre_y[2];
    int tacho_x_pitch[2];
    int tacho_y_pitch[2];
    int tacho_radius_1[2];
    int tacho_radius_2[2];
    int tacho_start_angle[2];
    int tacho_end_angle[2];
    int tacho_needle_colour[2];
    int gear_x[2];
    int gear_y[2];
    int red_line;
    int lhands_x[7];
    int lhands_y[7];
    int rhands_x[7];
    int rhands_y[7];
    int number_of_hands_images;
    int max_speed;
    int damage_x_offset;
    int damage_y_offset;
    int damage_background_x;
    int damage_background_y;
    int dim_count[2];
    int dim_left[2][4];
    int dim_top[2][4];
    int dim_right[2][4];
    int dim_bottom[2][4];
    int car_actor_count;
    int current_car_actor;
    int principal_car_actor;
    int car_model_variable;
    int number_of_steerable_wheels;
    int steering_ref[6];
    int lf_sus_ref[4];
    int rf_sus_ref[4];
    int lr_sus_ref[2];
    int rr_sus_ref[2];
    int driven_wheels_spin_ref_1;
    int driven_wheels_spin_ref_2;
    int driven_wheels_spin_ref_3;
    int driven_wheels_spin_ref_4;
    int non_driven_wheels_spin_ref_1;
    int non_driven_wheels_spin_ref_2;
    int non_driven_wheels_spin_ref_3;
    int non_driven_wheels_spin_ref_4;
    int engine_noises[3];
    float driver_x_offset;
    float driver_y_offset;
    float driver_z_offset;
    float mirror_x_offset;
    float mirror_y_offset;
    float mirror_z_offset;
    float rearview_camera_angle;
    float head_left_angle;
    float head_right_angle;
    float steering_angle;
    float speedo_speed;
    float lf_sus_position;
    float rf_sus_position;
    float lr_sus_position;
    float rr_sus_position;
    float driven_wheels_circum;
    float non_driven_wheels_circum;
    float bounce_rate;
    float bounce_amount;
    float collision_mass_multiplier;
    float damage_multiplier;
    float grip_multiplier;
    float engine_power_multiplier;
    tDamage_unit damage_units[12];
    tU8 frame_start_damage[12];
    tImpact_location last_impact_location;
    tDamage_program damage_programs[6];
    tHeadup_slot headup_slots[2][20];
    tParts_spec power_ups[3];
    int car_actor_pipe_ref;
    tCar_actor car_model_actors[5];
    br_material* screen_material;
    br_material* screen_material_source;
    br_matrix34 last_safe_positions[5];
    int wheel_slip;
    br_scalar damping;
    br_scalar sk[2];
    br_scalar sb[2];
    br_scalar susp_give[2];
    br_scalar susp_height[2];
    br_scalar ride_height;
    br_vector3 wpos[4];
    br_scalar curvature;
    br_scalar maxcurve;
    br_scalar turn_speed;
    br_scalar oldd[4];
    int material_index[4];
    int dust_time[4];
    br_scalar mu[3];
    br_scalar friction_elipticity;
    br_scalar down_force_speed;
    int down_force_flag;
    br_scalar initial_brake;
    br_scalar brake_increase;
    br_scalar freduction;
    br_scalar acc_force;
    br_scalar torque;
    br_scalar brake_force;
    int traction_control;
    br_scalar rolling_r_front;
    br_scalar rolling_r_back;
    tCar_controls keys;
    tJoystick joystick;
    int pedals_xy;
    int number_of_wheels_on_ground;
    br_actor* wheel_actors[6];
    float wheel_rot_pos[4];
    br_scalar wheel_dam_offset[4];
    br_scalar damage_magnitude_accumulator;
    br_scalar revs;
    br_scalar target_revs;
    br_vector3 road_normal;
    br_scalar max_force_front;
    br_scalar max_force_rear;
    int gear;
    int just_changed_gear;
    int max_gear;
    br_scalar speed_revs_ratio;
    br_scalar force_torque_ratio;
    tS3_sound_source_ptr sound_source;
    br_matrix34 pre_car_col_mat;
    br_scalar pre_car_col_speed;
    br_vector3 pre_car_col_direction;
    br_vector3 pre_car_col_velocity;
    br_vector3 pre_car_col_velocity_car_space;
    br_vector3 velocity_bu_per_sec;
    float last_col_prop_x;
    float last_col_prop_y;
    float last_col_prop_z;
    tU32 time_last_hit;
    tU32 time_last_victim;
    struct tCar_spec_struct* last_hit_by;
    struct tCar_spec_struct* last_culprit;
    int no_of_processes_recording_my_trail;
    tPursuee_trail my_trail;

    unsigned int grudge_bang_scary_bang;
    tU32 last_collision_time;
    tU32 last_time_we_touched_a_player;
    tU32 end_steering_damage_effect;
    tU32 end_trans_damage_effect;
    int false_key_left;
    int false_key_right;
    struct tCar_spec_struct* last_person_to_hit_us;
    struct tCar_spec_struct* last_person_we_hit;
    br_vector3 engine_pos;
    br_model* last_wheel_models[4];
    int last_wheel_faces[4];
    tU32 shadow_intersection_flags;
    tU32 last_bounce;
    unsigned int new_skidding;
    unsigned int old_skidding;
    tU16 old_skid[4];
    br_vector3 prev_skid_pos[4];
    br_vector3 skid_line_start[4];
    br_vector3 skid_line_end[4];
    br_vector3 nor[4];
    br_vector3 prev_nor[4];
    br_vector3 special_start[4];
    br_scalar oil_remaining[4];
    br_scalar blood_remaining[4];
    br_scalar total_length[4];
    float proxy_ray_distance;
    tS32 powerups[64];
    tU32 time_to_recover;
    tU32 repair_time;
    int power_up_levels[3];
    tS3_sound_tag horn_sound_tag;
} tCar_spec;

typedef struct tOppo_psyche
{
    tU8 grudge_against_player;
} tOppo_psyche;

typedef struct tComplete_race_data
{
    tU8 finished_calcing_race_route;
    tU8 found_race_section;
} tComplete_race_data;

typedef struct tReturn_to_start_data
{
    br_vector3 nearest_path_point;
    tS16 section_no;
    tU8 waiting_near_start;
} tReturn_to_start_data;

typedef struct tPath_node_struct
{
    br_vector3 p;
    tS16 sections[8];
    tU8 number_of_sections;
} tPath_node;

typedef struct tPath_section_struct
{
    tS16 node_indices[2];
    tU8 min_speed[2];
    tU8 max_speed[2];
    br_scalar width;
    br_scalar length;
    tU8 type;
    tU8 one_way;
} tPath_section;

typedef struct tPursue_car_data
{
    tCar_spec* pursuee;
    tU32 time_of_next_visibility_check;
    tU32 start_backup_time;
    tU32 time_last_twatted_em;
    tU32 time_pursuee_last_visible;
    tU32 time_last_away_from_pursuee;
    tPath_node direct_line_nodes[2];
    tPath_section direct_line_section;
    tU8 state;
} tPursue_car_data;

typedef struct tFollow_path_data
{
    tU32 struggle_time;
    tU32 last_finished_struggle_time;
    tU32 toggle_time;
    tU32 borrowed_time_start;
    br_scalar prev_acc;
    br_scalar prev_acc_error;
    br_scalar desired_speed;
    br_scalar last_distance;
    br_vector3 cheaty_intersect;
    tS16 section_no;
    tS16 first_section_no;
    tS16 last_struggle_section;
    unsigned int number_of_struggles : 8;
    unsigned int has_moved_during_this_task : 1;
    unsigned int made_it : 1;
    unsigned int cheating : 1;
    unsigned int cornering : 1;
    unsigned int left_not_right : 1;
    unsigned int off_path_toggle;
    unsigned int moving_to_intersect;
    br_vector2 turning_cent;
    br_scalar turning_radius;
    br_scalar corner_size;
    br_scalar corner_width;
    int section_after;
} tFollow_path_data;

typedef struct tLevitate_data
{
    br_scalar initial_y;
    tU32 time_started;
    unsigned int waiting_to_levitate : 1;
} tLevitate_data;

typedef struct tRun_away_data
{
    tU32 time_to_stop;
} tRun_away_data;

typedef struct tRoute_section
{
    tS16 section_no;
    tU8 direction;
} tRoute_section;

typedef struct tOpponent_spec
{
    int index;
    tOpponent_objective_type current_objective;
    tCar_spec* car_spec;
    float nastiness;
    br_scalar distance_to_camera;
    br_scalar distance_from_home;
    br_scalar player_to_oppo_d;
    br_vector3 start_pos;
    br_vector3 start_direction;
    br_vector3 pos_last_frame;
    br_vector3 player_to_oppo_v;
    tU32 next_out_of_world_check;
    tU32 stun_time_ends;
    tU32 next_player_visibility_check;
    tU32 last_moved_ok;
    tU32 last_in_view;
    tU32 time_last_processed;
    tU32 time_this_objective_started;
    tU32 time_for_this_objective_to_finish;
    tU32 cunting_buttfuck_timer;
    tS16 players_section_when_last_calced_full_path;
    int nnext_sections;
    tRoute_section next_sections[10];
    unsigned int new_objective_required : 1;
    unsigned int finished_for_this_race : 1;
    unsigned int knackeredness_detected : 1;
    unsigned int physics_me : 1;
    unsigned int pursue_from_start : 1;
    unsigned int cheating : 1;
    unsigned int last_cheating_value : 1;
    unsigned int pursuing_player_before_freeze : 1;
    unsigned int has_moved_at_some_point : 1;
    unsigned int player_in_view_now : 1;
    unsigned int acknowledged_piv : 1;
    unsigned int murder_reported : 1;
    tComplete_race_data complete_race_data;
    tFollow_path_data follow_path_data;
    tPursue_car_data pursue_car_data;
    tLevitate_data levitate_data;
    tRun_away_data run_away_data;
    tReturn_to_start_data return_to_start_data;
} tOpponent_spec;

typedef struct tIntelligent_vehicles
{
    int number_of_opponents;
    int number_of_cops;
    int number_of_path_nodes;
    int number_of_path_sections;
    br_vector3 cop_start_points[10];
    br_vector3 cop_start_vectors[10];
    tOpponent_spec opponents[5];
    tOpponent_spec cops[10];
    tPath_node* path_nodes;
    tPath_section* path_sections;
} tIntelligent_vehicles;

typedef struct tBounds
{
    br_matrix34* mat;
    br_bounds original_bounds;
    br_vector3 box_centre;
    br_scalar radius;
    br_bounds real_bounds;
} tBounds;

typedef struct tFace_ref
{
    br_material* material;
    br_vector3 v[3];
    br_vector2* map[3];
    br_vector3 normal;
    int flags;
    br_scalar d;
} tFace_ref;

typedef struct tNet_game_player_info
{
    tPD_net_player_info pd_net_info;
    tU32 this_players_time_stamp;
    tU32 last_heard_from_him;
    tU32 reposition_time;
    tU32 last_waste_message;
    int host;
    tPlayer_ID ID;
    char player_name[32];
    tPlayer_status player_status;
    int car_index;
    int grid_index;
    int grid_position_set;
    int opponent_list_index;
    int awaiting_confirmation;
    int score;
    int credits;
    int wasted;
    int wasteage_attributed;
    int name_not_clipped;
    int race_stuff_initialised;
    int played;
    int won;
    int next_car_index;
    int games_score;
    int last_score_index;
    br_matrix34 initial_position;
    tCar_spec* car;
} tNet_game_player_info;

typedef struct tNet_game_options
{
    int show_players_on_map;
    int show_peds_on_map;
    int enable_text_messages;
    int show_powerups_on_map;
    int powerup_respawn;
    int open_game;
    int starting_money_index;
    int grid_start;
    int race_end_target;
    int random_car_choice;
    tNet_sequence_type race_sequence_type;
    tCar_choice car_choice;
} tNet_game_options;

typedef struct tNet_game_status
{
    tNet_game_stage stage;
} tNet_game_status;

typedef struct tNet_game_details
{
    tPD_net_player_info pd_net_info;
    char host_name[32];
    tPlayer_ID host_ID;
    int num_players;
    int start_race;
    int no_races_yet;
    tNet_game_status status;
    tNet_game_options options;
    tNet_game_type type;
} tNet_game_details;

typedef struct tNet_message_send_me_details
{
    tU8 contents_size;
    tNet_message_type type;
} tNet_message_send_me_details;

typedef struct tNet_message_my_details
{
    tU8 contents_size;
    tNet_message_type type;
    tNet_game_details details;
} tNet_message_my_details;

typedef struct tNet_message_join
{
    tU8 contents_size;
    tNet_message_type type;
    tNet_game_player_info player_info;
} tNet_message_join;

typedef struct tNet_message_leave
{
    tU8 contents_size;
    tNet_message_type type;
} tNet_message_leave;

typedef struct tNet_message_host_pissing_off
{
    tU8 contents_size;
    tNet_message_type type;
} tNet_message_host_pissing_off;

typedef struct tNet_message_new_player_list
{
    tU8 contents_size;
    tNet_message_type type;
    int number_of_players;
    int this_index;
    int batch_number;
    tNet_game_player_info player;
} tNet_message_new_player_list;

typedef struct tNet_message_race_over
{
    tU8 contents_size;
    tNet_message_type type;
    tRace_over_reason reason;
} tNet_message_race_over;

typedef struct tNet_message_status_report
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_status status;
} tNet_message_status_report;

typedef struct tGrid_spec
{
    int index;
    int next_car_index;
    br_matrix34 mat;
} tGrid_spec;

typedef struct tNet_message_start_race
{
    tU8 contents_size;
    tNet_message_type type;
    int car_count;
    int racing;
    int next_race;
    tGrid_spec car_list[6];
} tNet_message_start_race;

typedef struct tNet_message_guarantee_reply
{
    tU8 contents_size;
    tNet_message_type type;
    tU32 guarantee_number;
} tNet_message_guarantee_reply;

typedef struct tNet_message_headup
{
    tU8 contents_size;
    tNet_message_type type;
    char text[128];
} tNet_message_headup;

typedef struct tNet_message_host_query
{
    tU8 contents_size;
    tNet_message_type type;
} tNet_message_host_query;

typedef struct tNet_message_host_reply
{
    tU8 contents_size;
    tNet_message_type type;
    int race_has_started;
    int race_index;
    int pending_race;
} tNet_message_host_reply;

typedef struct tNet_message_cop_info
{
    tU8 contents_size;
    tNet_message_type type;
    tU32 ID;
    tU32 time;
    tReduced_matrix mat;
    br_vector3 v;
    br_vector3 omega;
    br_scalar curvature;
    br_scalar d[4];
    tU8 damage[12];
} tNet_message_cop_info;

typedef struct tNet_message_non_car_info
{
    tU8 contents_size;
    tNet_message_type type;
    tU32 ID;
    tU32 time;
    tReduced_matrix mat;
    br_vector3 v;
    br_vector3 omega;
    tU32 cc_coll_time;
    tU16 flags;
} tNet_message_non_car_info;

typedef struct tNet_message_non_car_position
{
    tU8 contents_size;
    tNet_message_type type;
    tU32 ID;
    br_matrix34 mat;
    tU16 flags;
} tNet_message_non_car_position;

typedef struct tNet_message_time_sync
{
    tU8 contents_size;
    tNet_message_type type;
    int race_start_time;
} tNet_message_time_sync;

typedef struct tNet_message_players_confirm
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID player;
} tNet_message_players_confirm;

typedef struct tNet_message_disable_car
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID player;
} tNet_message_disable_car;

typedef struct tNet_message_enable_car
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID player;
} tNet_message_enable_car;

typedef struct tNet_message_powerup
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID player;
    int powerup_index;
    tU32 time_left;
    tPowerup_event event;
} tNet_message_powerup;

typedef struct tNet_message_recover
{
    tU8 contents_size;
    tNet_message_type type;
    tU32 ID;
    int time_to_recover;
} tNet_message_recover;

typedef struct tNet_message_scores
{
    tU8 contents_size;
    tNet_message_type type;
    int general_score;
    int scores[6];
} tNet_message_scores;

typedef struct tNet_message_wasted
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID victim;
    tPlayer_ID culprit;
} tNet_message_wasted;

typedef struct tNet_message_gameplay
{
    tU8 contents_size;
    tNet_message_type type;
    tNet_gameplay_mess mess;
    tU32 param_1;
    tU32 param_2;
    tU32 param_3;
    tU32 param_4;
} tNet_message_gameplay;

typedef struct tNet_message_pedestrian
{
    tU8 contents_size;
    tNet_message_type type;
    tS8 action_instruction;
    tS8 flags;
    tS16 index;
    br_vector3 pos;
    br_scalar speed;
    br_vector3 to_pos;
    br_vector3 offset;
    tPlayer_ID murderer;
    tU32 respawn_time_or_spin_period;
    tS8 frame;
} tNet_message_pedestrian;

typedef struct tNet_message_car_details_req
{
    tU8 contents_size;
    tNet_message_type type;
} tNet_message_car_details_req;

typedef struct tCar_details
{
    int car_index;
    char owner[16];
} tCar_details;

typedef struct tNet_message_car_details
{
    tU8 contents_size;
    tNet_message_type type;
    int count;
    tCar_details details[6];
} tNet_message_car_details;

typedef struct tGame_scores
{
    int played;
    int won;
    int score;
} tGame_scores;

typedef struct tNet_message_game_scores
{
    tU8 contents_size;
    tNet_message_type type;
    tGame_scores scores[6];
} tNet_message_game_scores;

typedef struct tNet_message_oil_spill
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID player;
    br_scalar full_size;
    br_scalar grow_rate;
    br_scalar current_size;
} tNet_message_oil_spill;

typedef struct tNet_message_crush_point
{
    tU8 contents_size;
    tNet_message_type type;
    tPlayer_ID id;
    tU16 vertex;
    br_vector3 energy_vector;
} tNet_message_crush_point;

typedef union tNet_contents { // size: 0x160
    struct
    {                                                   // size: 0x2
        tU8 contents_size;                              // @0x0
        tNet_message_type type;                         // @0x1
    } header;                                           // @0x0
    union {                                             // size: 0x160
        tNet_message_send_me_details send_details;      // @0x0
        tNet_message_my_details details;                // @0x0
        tNet_message_join join;                         // @0x0
        tNet_message_leave leave;                       // @0x0
        tNet_message_host_pissing_off hosticide;        // @0x0
        tNet_message_new_player_list player_list;       // @0x0
        tNet_message_race_over race_over;               // @0x0
        tNet_message_status_report report;              // @0x0
        tNet_message_start_race start_race;             // @0x0
        tNet_message_guarantee_reply reply;             // @0x0
        tNet_message_headup headup;                     // @0x0
        tNet_message_host_query where_we_at;            // @0x0
        tNet_message_host_reply heres_where_we_at;      // @0x0
        tNet_message_mechanics_info mech;               // @0x0
        tNet_message_non_car_info non_car;              // @0x0
        tNet_message_time_sync time_sync;               // @0x0
        tNet_message_players_confirm confirm;           // @0x0
        tNet_message_disable_car disable_car;           // @0x0
        tNet_message_enable_car enabled_car;            // @0x0
        tNet_message_powerup powerup;                   // @0x0
        tNet_message_recover recover;                   // @0x0
        tNet_message_scores scores;                     // @0x0
        tNet_message_wasted wasted;                     // @0x0
        tNet_message_pedestrian pedestrian;             // @0x0
        tNet_message_gameplay gameplay;                 // @0x0
        tNet_message_non_car_position non_car_position; // @0x0
        tNet_message_cop_info cop_info;                 // @0x0
        tNet_message_car_details_req car_details_req;   // @0x0
        tNet_message_car_details car_details;           // @0x0
        tNet_message_game_scores game_scores;           // @0x0
        tNet_message_oil_spill oil_spill;               // @0x0
        tNet_message_crush_point crush;                 // @0x0
    } data;                                             // @0x0
} tNet_contents;

typedef struct tNet_message
{
    tU32 pd_stuff_so_DO_NOT_USE;
    tU32 magic_number;
    tU32 guarantee_number;
    tPlayer_ID sender;
    int version;
    tU32 senders_time_stamp;
    tU16 num_contents;
    tU16 overall_size;
    tNet_contents contents;
} tNet_message;

typedef struct tCar_detail_info
{
    tCar_detail_ownership ownership;
    char name[16];
} tCar_detail_info;

typedef struct tS3_vector3
{
    tF32 x;
    tF32 y;
    tF32 z;
} tS3_vector3;

typedef struct tWav_header
{
    char quote_RIFF[4];
    tU32 format_length;
    tU8 wave[4];
    tU8 fmt[4];
    tU32 wave_format_length;
    tU16 format_tag;
    tU16 channels;
    tU32 samples_per_sec;
    tU32 avg_bytes_per_sec;
    tU16 block_align;
    tU16 bits_per_sample;
    tU8 data[4];
    tU32 data_length;
} tWav_header;

typedef struct tPowerup
{
    tPowerup_type type;
    tU32 got_time;
    tU32 duration;
    tU32 lose_time;
    tU16 group_inclusion;
    br_pixelmap* icon;
    int fizzle_type;
    int number_of_float_params;
    int number_of_integer_params;
    int* integer_params;
    int current_value;
    int prat_cam_event;
    tNet_powerup_type net_type;
    tGot_proc* got_proc;
    tLose_proc* lose_proc;
    tPeriodic_proc* periodic_proc;
    float* float_params;
    tCar_spec* car;
    char message[64];
} tPowerup;

typedef struct tDepth_effect
{
    tDepth_effect_type type;
    int start;
    int end;
    br_pixelmap* sky_texture;
} tDepth_effect;

typedef struct tPlane_spec
{
    tPlane_type plane_type;
    br_fvector3 n;
    br_scalar d;
} tPlane_spec;

typedef struct tMaterial_modifiers
{
    br_scalar car_wall_friction;
    br_scalar tyre_road_friction;
    br_scalar down_force;
    br_scalar bumpiness;
    int tyre_noise_index;
    int crash_noise_index;
    int scrape_noise_index;
    br_scalar sparkiness;
    int smoke_type;
    br_material* skid_mark_material;
} tMaterial_modifiers;

typedef struct tSpecial_screen
{
    br_material* material;
    br_scalar min_x;
    br_scalar min_z;
    br_scalar max_x;
    br_scalar max_z;
} tSpecial_screen;

typedef struct tRace_list_spec
{
    char name[32];
    int rank_required;
    int best_rank;
    int suggested_rank;
    int been_there_done_that;
} tRace_list_spec;

typedef struct tRace_save_info
{
    tU32 been_there_done_that;
} tRace_save_info;

typedef struct tGraf_spec
{
    int depth_bits;
    int depth_bytes;
    int doubled;
    int total_width;
    int total_height;
    long black_value;
    int colour_index;
    char* data_dir_name;
    char* gfx_init_string;
    int row_bytes;
    int phys_width;
    int phys_height;
    void* base_addr;
} tGraf_spec;

typedef struct tCollision_info
{
    int index;
    int disabled;
    tDriver driver;
    br_actor* car_master_actor;
    br_scalar min_torque_squared;
    br_scalar break_off_radians_squared;
    br_vector3 v;
    br_vector3 old_v;
    br_vector3 velocity_car_space;
    br_matrix34 oldmat;
    br_matrix34 old_frame_mat;
    br_vector3 pos;
    br_vector3 omega;
    br_vector3 oldomega;
    br_scalar M;
    int infinite_mass;
    br_vector3 I;
    br_vector3 cmpos;
    int extra_point_num;
    br_bounds bounds[3];
    br_bounds max_bounds[2];
    br_vector3 extra_points[6];
    br_scalar original_extra_points_z[6];
    br_vector3 old_point;
    br_vector3 old_norm;
    int box_face_start;
    int box_face_end;
    int box_face_ref;
    br_matrix34 last_box_inv_mat;
    br_bounds last_box;
    int doing_nothing_flag;
    tSpecial_volume* last_special_volume;
    tSpecial_volume* auto_special_volume;
    int frame_collision_flag;
    int collision_flag;
    int max_shrapnel_material;
    br_vector3 direction;
    float speed;
    tU16 car_ID;
    br_material* shrapnel_material[3];
    br_bounds bounds_world_space;
    tBounds_type bounds_ws_type;
    tU16 fire_vertex[12];
    tU16 num_smoke_columns;
    br_vector3 water_normal;
    br_scalar water_d;
    br_scalar water_depth_factor;
    tNet_message_mechanics_info message;
    tU32 last_car_car_collision;
    br_scalar dt;
    tCar_spec* who_last_hit_me;
} tCollision_info;

typedef struct tNon_car_spec
{
    tCollision_info collision_info;
    br_scalar free_mass;
    br_scalar attached_mass;
    br_vector3 free_cmpos;
    br_vector3 attached_cmpos;
    br_scalar min_torque_squared;
    br_scalar snap_off_cosine;
    br_vector3 I_over_M;
} tNon_car_spec;

typedef struct tOpp_spec
{
    int index;
    int ranking;
    int net_player_index;
    tCar_spec* car_spec;
} tOpp_spec;

typedef struct tCheckpoint
{
    int time_value[3];
    int quad_count;
    br_vector3 vertices[4][4];
    br_vector3 normal[4];
    int map_left[2];
    int map_top[2];
    int map_right[2];
    int map_bottom[2];
} tCheckpoint;

typedef struct tNet_starts
{
    br_vector3 pos;
    br_scalar yaw;
} tNet_starts;

typedef struct tText_chunk
{
    int frame_cue;
    int frame_end;
    int x_coord;
    int y_coord;
    int line_count;
    char* text[8];
} tText_chunk;

typedef struct tRace_info
{
    char name[32];
    char track_file_name[14];
    int rank_required;
    int best_rank;
    int suggested_rank;
    int total_laps;
    int check_point_count;
    int initial_timer[3];
    int bonus_score[8][3];
    int number_of_racers;
    int number_of_net_start_points;
    int text_chunk_count;
    tNet_starts net_starts[24];
    tCheckpoint checkpoints[10];
    tOpp_spec opponent_list[30];
    tU8* scene_image_data;
    tU8* map_image_data;
    tU8* info_image_data;
    tU32 scene_image_data_length;
    tU32 map_image_data_length;
    tU32 info_image_data_length;
    br_vector3 initial_position;
    br_scalar initial_yaw;
    br_pixelmap* map_image;
    br_matrix34 map_transformation;
    tText_chunk* text_chunks;
    tMaterial_modifiers material_modifiers[11];
} tRace_info;

typedef struct tOpponent_save_info
{
    tU32 dead;
} tOpponent_save_info;

typedef struct tOpponent
{
    char name[24];
    char abbrev_name[24];
    char mug_shot_name[14];
    char car_file_name[14];
    char stolen_car_flic_name[14];
    tU8* mug_shot_image_data;
    tU8* stolen_car_image_data;
    tU32 mug_shot_image_data_length;
    tU32 stolen_car_image_data_length;
    int car_number;
    int strength_rating;
    int picked;
    int dead;
    int text_chunk_count;
    tNet_avail network_availability;
    br_pixelmap* grid_icon_image;
    tOppo_psyche psyche;
    tText_chunk* text_chunks;
} tOpponent;

typedef struct tProgram_state
{
    tS32 credits;
    tS32 credits_earned;
    tS32 credits_lost;
    tU32 view_change_start;
    tU32 pratcam_move_start;
    int peds_killed;
    int sausage_eater_mode;
    int rank;
    int loaded;
    int last_slot;
    int skill_level;
    int parts_shop_visited;
    int racing;
    int cut_scene;
    int saving;
    int loading;
    int dont_save_or_load;
    int dont_load;
    int mirror_on;
    int prat_cam_on;
    int cockpit_on;
    int cockpit_image_index;
    int current_render_left;
    int current_render_top;
    int current_render_right;
    int current_render_bottom;
    int frame_rate_headup;
    int revs;
    int music_volume;
    int effects_volume;
    int current_race_index;
    int redo_race_index;
    int credits_per_rank;
    int game_completed;
    int number_of_cars;
    int current_car_index;
    tWhich_view which_view;
    tWhich_view new_view;
    tWhich_view pending_view;
    tWhich_view old_view;
    tRace_sel_view_type view_type;
    tProg_status prog_status;
    tFrank_anne frank_or_anniness;
    tAuto_parts_reply auto_parts_reply;
    tCar_spec current_car;
    char player_name[2][14];
    char track_file_name[14];
    char car_name[14];
    int cars_available[60];
    br_vector3 initial_position;
    br_scalar initial_yaw;
    tTrack_spec track_spec;
    tDepth_effect default_depth_effect;
    tDepth_effect current_depth_effect;
    int special_volume_count;
    tSpecial_volume* special_volumes;
    br_material* standard_screen;
    br_material* standard_screen_dark;
    br_material* standard_screen_fog;
    int special_screens_count;
    tSpecial_screen* special_screens;
    tIntelligent_vehicles AI_vehicles;
    tNon_car_spec* non_cars;
    int num_non_car_spaces;
} tProgram_state;

typedef struct tDR_font
{
    br_pixelmap* images;
    int file_read_once;
    int height;
    int width;
    int spacing;
    int offset;
    int num_entries;
    int width_table[224];
} tDR_font;

typedef struct tGraf_data
{
    int width;
    int height;
    int rolling_letter_y_pitch;
    int save_slot_y_offset;
    int rolling_letter_x_pitch;
    int save_slot_x_offset;
    int save_slot_rank_x_offset;
    int save_slot_credits_x_offset;
    int save_slot_height;
    int save_slot_letter_height;
    int save_slot_table[41];
    int player_name_y;
    int player_name_x[2];
    int enter_name_x[2];
    int enter_name_y;
    int frank_panel_left;
    int frank_panel_top;
    int frank_panel_right;
    int frank_panel_bottom;
    int anne_panel_left;
    int anne_panel_top;
    int anne_panel_right;
    int anne_panel_bottom;
    int cock_margin_x;
    int cock_margin_y;
    int total_cock_width;
    int total_cock_height;
    int dial__x[2];
    int dial__y[2];
    int dial__x_centre;
    int dial__y_centre;
    int start_race_panel_left;
    int start_race_panel_top;
    int start_race_panel_right;
    int start_race_panel_bottom;
    int start_race_panel_top_clip;
    int start_race_panel_bottom_clip;
    int choose_race_rank_right;
    int choose_race_name_left;
    int choose_race_bullet_left;
    int choose_race_left;
    int choose_race_right;
    int choose_race_y_top;
    int choose_race_y_bottom;
    int choose_race_y_pitch;
    int choose_race_curr_y;
    int choose_race_box_left;
    int choose_race_box_top;
    int choose_race_line_y;
    int choose_race_current_text_x;
    int choose_race_current_text_y;
    int choose_race_current_num_x;
    int grid_x_pitch;
    int grid_y_pitch;
    int grid_x_stagger;
    int grid_left_x;
    int grid_top_y;
    int grid_left_clip;
    int grid_top_clip;
    int grid_right_clip;
    int grid_bottom_clip;
    int grid_numbers_left;
    int grid_numbers_top;
    int grid_numbers_right;
    int grid_marker_margin;
    int grid_marker_x_len;
    int dare_mugshot_left;
    int dare_mugshot_top;
    int dare_mugshot_width;
    int dare_mugshot_height;
    int dare_text_left;
    int dare_text_width;
    int dare_mug_left_margin;
    int dare_mug_top_margin;
    int dare_y_adjust;
    int parts_image_x;
    int parts_image_y;
    int parts_image_width;
    int parts_image_height;
    int parts_cost_x;
    int parts_cost_y;
    int parts_total_x;
    int parts_total_y;
    int parts_net_x;
    int parts_net_y;
    int parts_numbers_x;
    int parts_top_clip;
    int parts_bottom_clip;
    int parts_label_x;
    int parts_label_y;
    int summ1_credits_box_left;
    int summ1_credits_left;
    int summ1_credits_right;
    int summ1_earned_top;
    int summ1_earned_bottom;
    int summ1_lost_top;
    int summ1_lost_bottom;
    int summ1_total_top;
    int summ1_total_bottom;
    int summ1_rank_x_pitch;
    int summ1_rank_inc_l;
    int summ1_rank_inc_c;
    int summ1_rank_total_l;
    int summ1_rank_total_c;
    int summ1_rank_inc_left;
    int summ1_rank_inc_right;
    int summ1_rank_total_left;
    int summ1_rank_total_right;
    int summ1_rank_top;
    int summ1_rank_bot;
    int summ1_rank_y;
    int wreck_name_left;
    int wreck_name_right;
    int wreck_name_top;
    int wreck_name_bottom;
    int wreck_name_base_line;
    int wreck_render_x;
    int wreck_render_y;
    int wreck_render_w;
    int wreck_render_h;
    int power_up_icon_x;
    int power_up_icon_countdown_x;
    int power_up_icon_y;
    int power_up_icon_y_pitch;
    int power_up_icon_countdown_y_offset;
    int change_car_text_y;
    int change_car_line_left;
    int change_car_line_y;
    int change_car_line_right;
    int change_car_panel_left;
    int change_car_panel_top;
    int change_car_panel_right;
    int change_car_panel_bottom;
    int change_car_panel_top_clip;
    int change_car_panel_bottom_clip;
    int map_timer_text_x;
    int map_timer_text_y;
    int map_timer_border_x;
    int map_timer_border_y;
    int action_replay_R_x;
    int action_replay_R_y;
    int action_replay_controls_x;
    int action_replay_controls_y;
    int action_replay_hilite_y;
    int action_replay_rew_start_x;
    int action_replay_rew_x;
    int action_replay_rev_play_x;
    int action_replay_pause_x;
    int action_replay_play_x;
    int action_replay_ffwd_x;
    int action_replay_fwd_end_x;
    int action_replay_camera_x;
    int action_replay_cam_text_x;
    int action_replay_cam_text_y;
    int joinable_games_x_1;
    int joinable_games_x_2;
    int joinable_games_x_3;
    int joinable_games_x_4;
    int joinable_games_x_r;
    int joinable_games_y;
    int joinable_games_y_pitch;
    int joinable_games_sel_left;
    int joinable_games_sel_right;
    int joinable_games_sel_top_marg;
    int joinable_games_sel_bot_marg;
    int net_player_name_x;
    int net_player_name_y;
    int error_box_left;
    int error_box_top;
    int error_box_right;
    int error_box_bottom;
    int start_synch_x_0;
    int start_synch_x_1;
    int start_synch_x_2;
    int start_synch_x_r;
    int start_synch_top;
    int start_synch_y_pitch;
    int start_synch_start_x;
    int start_synch_start_y;
    int key_assign_col_1;
    int key_assign_col_1_a;
    int key_assign_col_2;
    int key_assign_col_2_a;
    int key_assign_y_pitch;
    int key_assign_y;
    int key_assign_key_map_y;
    int key_assign_flic_x;
    int key_assign_flic_y;
    int map_render_x_marg;
    int map_render_y_marg;
    int net_head_box_x;
    int net_head_box_pitch;
    int net_head_box_width;
    int net_head_box_top;
    int net_head_box_bot;
    int net_head_name_x_marg;
    int net_head_name_y;
    int net_head_num_x;
    int net_head_num_y;
    int net_head_num_height;
    int net_head_icon_x;
    int net_head_icon_y;
    int net_head_icon_height;
    int net_head_score_x;
    int net_head_score_y;
    int armour_headup_y[2];
    int power_headup_y[2];
    int offense_headup_y[2];
    int ps_dim_left;
    int ps_dim_right;
    int ps_dim_height;
    int ps_name_left;
    int ps_name_top_border;
    int ps_bars_per_level;
    int ps_x_pitch;
    int ps_bar_top_border;
    int ps_bar_left;
    int ps_bar_height;
    int net_choose_race_x;
    int net_choose_race_y;
    int net_descr_race_l;
    int net_descr_race_r;
    int net_descr_race_top;
    int net_descr_race_bot;
    int net_sum_x_1;
    int net_sum_x_2;
    int net_sum_x_3;
    int net_sum_x_4;
    int net_sum_x_5;
    int net_sum_headings_y;
    int net_sum_y_pitch;
    int graph_opt_disable_x;
    int graph_opt_disable_y;
    int sound_opt_disable_x;
    int sound_opt_disable_y;
    int net_message_enter_x;
    int net_message_enter_y;
    int eval_x;
    int eval_y;
} tGraf_data;

typedef struct tRolling_letter
{
    int letters[9];
    int x_coord;
    int y_coord;
    int number_of_letters;
    tRolling_type rolling_type;
    float current_offset;
} tRolling_letter;

typedef struct tFlic_descriptor
{
    char* data;
    char* data_start;
    char file_name[32];
    tU8* first_pixel;
    tU32 bytes_remaining;
    tU32 frame_period;
    tU32 last_frame;
    br_pixelmap* the_pixelmap;
    int x_offset;
    int y_offset;
    int width;
    int height;
    int frames_left;
    int current_frame;
    int the_index;
    int new_format;
    int must_finish;
    int bytes_still_to_be_read;
    int bytes_in_buffer;
    FILE* f;
    tFlic_descriptor_ptr next;
} tFlic_descriptor;

typedef struct tBrender_storage
{
    int models_count;
    int materials_count;
    int shade_tables_count;
    int pixelmaps_count;
    int max_pixelmaps;
    int max_shade_tables;
    int max_materials;
    int max_models;
    br_model** models;
    br_pixelmap** pixelmaps;
    br_pixelmap** shade_tables;
    br_material** materials;
    br_pixelmap** saved_colour_maps;
} tBrender_storage;

typedef struct tSave_game
{
    char slot_name[16];
    char car_name[16];
    char player_name[2][14];
    tRace_save_info race_info[100];
    tOpponent_save_info opponent_info[48];
    tU32 credits;
    tU32 rank;
    tU32 skill_level;
    tU32 game_completed;
    tU32 number_of_cars;
    tU32 cars_available[60];
    tU32 current_car_index;
    tU32 current_race_index;
    tU32 redo_race_index;
    tU32 frank_or_annitude;
    tU32 power_up_levels[3];
    tU32 version;
    tU32 checksum;
} tSave_game;

typedef struct tPed_subs
{
    int orig;
    int subs;
} tPed_subs;

typedef struct tRadio_bastards
{
    int count;
    int top;
    int current_value;
    int left[5];
} tRadio_bastards;

typedef struct exception_struct
{
    tException_list next;
    char* name;
    int flags;
} tException_node;

typedef struct tPixelmap_user_data
{
    tU16 orig_width;
    tU16 orig_height;
} tPixelmap_user_data;

typedef struct tMatrix_and_actor
{
    br_matrix34* m;
    br_actor* a;
} tMatrix_and_actor;

typedef tU16 tChunk_subject_index;

typedef enum tShadow_level
{
    eShadow_none = 0,
    eShadow_us_only = 1,
    eShadow_us_and_opponents = 2,
    eShadow_everyone = 3
} tShadow_level;

typedef enum tPipe_chunk_type
{
    ePipe_chunk_actor_rstyle = 0,
    ePipe_chunk_actor_translate = 1,
    ePipe_chunk_actor_transform = 2,
    ePipe_chunk_actor_create = 3,
    ePipe_chunk_actor_destroy = 4,
    ePipe_chunk_actor_relink = 5,
    ePipe_chunk_actor_material = 6,
    ePipe_chunk_face_material = 7,
    ePipe_chunk_material_trans = 8,
    ePipe_chunk_material_pixelmap = 9,
    ePipe_chunk_model_geometry = 10,
    ePipe_chunk_pedestrian = 11,
    ePipe_chunk_frame_boundary = 12,
    ePipe_chunk_car = 13,
    ePipe_chunk_sound = 14,
    ePipe_chunk_damage = 15,
    ePipe_chunk_special = 16,
    ePipe_chunk_ped_gib = 17,
    ePipe_chunk_incident = 18,
    ePipe_chunk_spark = 19,
    ePipe_chunk_shrapnel = 20,
    ePipe_chunk_screen_shake = 21,
    ePipe_chunk_groove_stop = 22,
    ePipe_chunk_non_car = 23,
    ePipe_chunk_smoke = 24,
    ePipe_chunk_oil_spill = 25,
    ePipe_chunk_smoke_column = 26,
    ePipe_chunk_flame = 27,
    ePipe_chunk_smudge = 28,
    ePipe_chunk_splash = 29,
    ePipe_chunk_prox_ray = 30,
    ePipe_chunk_skid_adjustment = 31,
    ePipe_chunk_enum_count = 32
} tPipe_chunk_type;

typedef enum tSpecial_type
{
    ePipe_special_fade = 0,
    ePipe_special_giant_ped_on = 1,
    ePipe_special_giant_ped_off = 2,
    ePipe_special_min_ped_on = 3,
    ePipe_special_min_ped_off = 4
} tSpecial_type;

typedef enum tIncident_type
{
    eIncident_ped = 0,
    eIncident_car = 1,
    eIncident_wall = 2,
    eNo_incident = 3
} tIncident_type;

typedef enum tAction_replay_camera_type
{
    eAction_replay_standard = 0,
    eAction_replay_tv = 1,
    eAction_replay_action = 2
} tAction_replay_camera_type;

typedef enum tKey_down_result
{
    tKey_down_no = 0,
    tKey_down_yes = 1,
    tKey_down_still = 2,
    tKey_down_repeat = 3
} tKey_down_result;
typedef int dr_pick2d_cbfn(br_actor*, br_model*, br_material*, br_vector3*, br_vector3*, br_scalar, br_scalar, void*);
typedef struct tReduced_pos
{
    tS16 v[3];
} tReduced_pos;

typedef union tIncident_info { // size: 0x10
    struct
    {                            // size: 0x10
        tCar_spec* car;          // @0x0
        br_vector3 impact_point; // @0x4
    } car_info;                  // @0x0
    struct
    {                             // size: 0x8
        br_actor* ped_actor;      // @0x0
        br_actor* murderer_actor; // @0x4
    } ped_info;                   // @0x0
    struct
    {                   // size: 0xc
        br_vector3 pos; // @0x0
    } wall_info;        // @0x0
} tIncident_info;

typedef struct tChanged_vertex
{
    tU16 vertex_index;
    br_vector3 delta_coordinates;
} tChanged_vertex;

typedef struct tPipe_actor_rstyle_data
{
    tU8 new_rstyle;
} tPipe_actor_rstyle_data;

typedef struct tPipe_actor_translate_data
{
    br_vector3 new_translation;
} tPipe_actor_translate_data;

typedef struct tPipe_actor_transform_data
{
    br_matrix34 new_transformation;
} tPipe_actor_transform_data;

typedef struct tPipe_actor_create_data
{
    tU8 dummy;
} tPipe_actor_create_data;

typedef struct tPipe_actor_destroy_data
{
    tU8 dummy;
} tPipe_actor_destroy_data;

typedef struct tPipe_actor_relink_data
{
    tChunk_subject_index new_parent;
} tPipe_actor_relink_data;

typedef struct tPipe_actor_material_data
{
    tChunk_subject_index new_material;
} tPipe_actor_material_data;

typedef struct tPipe_face_material_data
{
    tU16 face_index;
    tChunk_subject_index new_material;
} tPipe_face_material_data;

typedef struct tPipe_material_trans_data
{
    br_matrix23 new_transformation;
} tPipe_material_trans_data;

typedef struct tPipe_material_pixelmap_data
{
    tChunk_subject_index new_pixelmap;
} tPipe_material_pixelmap_data;

typedef struct tPipe_model_geometry_data
{
    tU16 vertex_count;
    int model_index;
    tChanged_vertex vertex_changes[1];
} tPipe_model_geometry_data;

typedef struct tSmudged_vertex
{
    tU16 vertex_index;
    tU16 light_index;
} tSmudged_vertex;

typedef struct tPipe_smudge_data
{
    tU16 vertex_count;
    int model_index;
    tSmudged_vertex vertex_changes[1];
} tPipe_smudge_data;

typedef struct tPipe_pedestrian_data
{
    tU8 action_and_frame_index;
    tS8 hit_points;
    tU16 parent;
    br_vector3 new_translation;
    float spin_period;
    br_actor* parent_actor;
    br_vector3 offset;
    br_scalar jump_magnitude;
} tPipe_pedestrian_data;

typedef struct tPipe_frame_boundary_data
{
    tU32 time;
} tPipe_frame_boundary_data;

typedef struct tPipe_car_data
{
    br_matrix34 transformation;
    br_vector3 velocity;
    tS16 speedo_speed;
    tS16 steering_angle;
    tU16 revs_and_gear;
    tS8 lf_sus_position;
    tS8 rf_sus_position;
    tS8 lr_sus_position;
    tS8 rr_sus_position;
} tPipe_car_data;

typedef struct tPipe_sound_data
{
    tS3_pitch pitch;
    br_vector3 position;
    tU16 outlet_index;
    tU16 volume;
} tPipe_sound_data;

typedef struct tPipe_damage_data
{
    tS8 damage_delta[12];
} tPipe_damage_data;

typedef struct tPipe_special_data
{
    tU8 dummy;
    tS8 padding;
} tPipe_special_data;

typedef struct tPipe_ped_gib_data
{
    tU16 ped_parent_index;
    tU8 size;
    tU8 gib_index;
    br_matrix34 transform;
} tPipe_ped_gib_data;

typedef struct tPipe_incident_data
{                   // size: 0x14
    float severity; // @0x0
    union {         // size: 0x10
        struct
        {                            // size: 0x10
            tU16 car_ID;             // @0x0
            br_vector3 impact_point; // @0x4
        } car_info;                  // @0x0
        struct
        {                    // size: 0x8
            tU16 ped_index;  // @0x0
            br_actor* actor; // @0x4
        } ped_info;          // @0x0
        struct
        {                   // size: 0xc
            br_vector3 pos; // @0x0
        } wall_info;        // @0x0
    } info;                 // @0x4
} tPipe_incident_data;

typedef struct tPipe_spark_data
{
    br_vector3 pos;
    br_vector3 v;
} tPipe_spark_data;

typedef struct tPipe_shrapnel_data
{
    br_vector3 pos;
    tU16 age;
    br_material* material;
} tPipe_shrapnel_data;

typedef struct tPipe_screen_shake_data
{
    tS8 wobble_x;
    tS8 wobble_y;
} tPipe_screen_shake_data;

typedef struct tPipe_non_car_data
{
    br_actor* actor;
    br_matrix34 mat;
} tPipe_non_car_data;

typedef struct tPipe_smoke_data
{
    tReduced_pos pos;
    tU16 radius;
    tU8 strength;
    tU8 type;
} tPipe_smoke_data;

typedef struct tPipe_smoke_column_data
{
    int car_ID;
    tU16 vertex;
} tPipe_smoke_column_data;

typedef struct tPipe_flame_data
{
    tS16 frame_count;
    br_scalar scale_x;
    br_scalar scale_y;
    br_scalar offset_x;
    br_scalar offset_z;
} tPipe_flame_data;

typedef struct tPipe_splash_data
{
    br_scalar d;
    br_vector3 normal;
} tPipe_splash_data;

typedef struct tPipe_prox_ray_data
{
    tU16 ped_index;
    tU16 car_ID;
    tU32 time;
} tPipe_prox_ray_data;

typedef struct tPipe_oil_spill_data
{
    br_matrix34 mat;
    br_scalar full_size;
    br_scalar grow_rate;
    tU32 spill_time;
    tU32 previous_stop_time;
    tCar_spec* car;
    br_vector3 original_pos;
    br_pixelmap* pixelmap;
} tPipe_oil_spill_data;

typedef struct tPipe_groove_stop_data
{
    int path_interrupt;
    int object_interrupt;
    float path_resumption;
    float object_resumption;
    br_matrix34 matrix;
} tPipe_groove_stop_data;

typedef struct tPipe_skid_adjustment
{
    br_matrix34 matrix;
    int material_index;
} tPipe_skid_adjustment;

typedef struct tPipe_chunk
{                                                            // size: 0x58
    tChunk_subject_index subject_index;                      // @0x0
    union {                                                  // size: 0x54
        tPipe_actor_rstyle_data actor_rstyle_data;           // @0x0
        tPipe_actor_translate_data actor_translate_data;     // @0x0
        tPipe_actor_transform_data actor_transform_data;     // @0x0
        tPipe_actor_create_data actor_create_data;           // @0x0
        tPipe_actor_destroy_data actor_destroy_data;         // @0x0
        tPipe_actor_relink_data actor_relink_data;           // @0x0
        tPipe_actor_material_data actor_material_data;       // @0x0
        tPipe_face_material_data face_material_data;         // @0x0
        tPipe_material_trans_data material_trans_data;       // @0x0
        tPipe_material_pixelmap_data material_pixelmap_data; // @0x0
        tPipe_model_geometry_data model_geometry_data;       // @0x0
        tPipe_pedestrian_data pedestrian_data;               // @0x0
        tPipe_frame_boundary_data frame_boundary_data;       // @0x0
        tPipe_car_data car_data;                             // @0x0
        tPipe_sound_data sound_data;                         // @0x0
        tPipe_damage_data damage_data;                       // @0x0
        tPipe_special_data special_data;                     // @0x0
        tPipe_ped_gib_data ped_gib_data;                     // @0x0
        tPipe_incident_data incident_data;                   // @0x0
        tPipe_spark_data spark_data;                         // @0x0
        tPipe_shrapnel_data shrapnel_data;                   // @0x0
        tPipe_screen_shake_data screen_shake_data;           // @0x0
        tPipe_groove_stop_data groove_stop_data;             // @0x0
        tPipe_non_car_data non_car_data;                     // @0x0
        tPipe_smoke_data smoke_data;                         // @0x0
        tPipe_oil_spill_data oil_data;                       // @0x0
        tPipe_smoke_column_data smoke_column_data;           // @0x0
        tPipe_flame_data flame_data;                         // @0x0
        tPipe_smudge_data smudge_data;                       // @0x0
        tPipe_splash_data splash_data;                       // @0x0
        tPipe_prox_ray_data prox_ray_data;                   // @0x0
        tPipe_skid_adjustment skid_adjustment;               // @0x0
    } chunk_data;                                            // @0x4
} tPipe_chunk;

typedef struct tPipe_session
{
    tPipe_chunk_type chunk_type;
    tU8 number_of_chunks;
    tPipe_chunk chunks;
} tPipe_session;

typedef struct tCollison_data
{
    int ref;
    tCollision_info* car;
} tCollison_data;

typedef struct tSave_camera
{
    int saved;
    br_scalar zoom;
    br_angle yaw;
} tSave_camera;

typedef void* tEdit_func();

typedef enum tEdit_mode
{
    eEdit_mode_cheat = 0,
    eEdit_mode_acc = 1,
    eEdit_mode_spec_vol = 2,
    eEdit_mode_ped = 3,
    eEdit_mode_opp = 4,
    eEdit_mode_pratcam = 5,
    eEdit_mode_depth = 6,
    eEdit_mode_damage = 7,
    eEdit_mode_bonnet = 8,
    eEdit_mode_options = 9,
    eEdit_mode_count = 10
} tEdit_mode;
typedef struct tToggle_element
{
    int key1;
    int key2;
    int in_game_only;
    int exact_modifiers;
    int on_last_time;
    void (*action_proc)();
} tToggle_element;

typedef struct tCheat
{
    tU32 code;
    tU32 code2;
    void (*action_proc)(int);
    int num;
} tCheat;

typedef struct _tag_sos_evds_struct _SOS_EVDS_STRUCT;
typedef struct _tag_sos_vds_struct _SOS_VDS_STRUCT;
typedef struct _tag_sos_sample _SOS_SAMPLE;
typedef _SOS_SAMPLE* PSOSSAMPLE;
typedef struct _tagCAPABILITIES _SOS_CAPABILITIES;
typedef _SOS_CAPABILITIES* PSOSCAPABILITIES;
typedef struct _SOS_HARDWARE* PSOSHARDWARE;
typedef struct _tag_sos_driver _SOS_DIGI_DRIVER;
typedef _SOS_DIGI_DRIVER* PSOSDIGIDRIVER;
typedef struct _SOS_DRV_FILEHEADER* PSOSDRVFILEHEADER;
typedef struct _SOS_DRV_DRIVERHEADER* PSOSDRVDRIVERHEADER;
typedef struct _tag_sos_system _SOS_SYSTEM;
typedef _SOS_SYSTEM* PSOSSYSTEM;
typedef struct _tag_sos_det_system _SOS_DET_SYSTEM;
typedef _SOS_DET_SYSTEM* PSOSDETSYSTEM;
typedef struct _tag_sos_timer_system _SOS_TIMER_SYSTEM;
typedef _SOS_TIMER_SYSTEM* PSOSTIMERSYSTEM;
typedef struct SmackTag Smack;
typedef struct SmackSumTag SmackSum;
typedef void* SmackTimerSetupType();
typedef unsigned long* SmackTimerReadType();
typedef void* SmackTimerDoneType();
typedef struct _heapinfo _HEAPINFO;
typedef struct _tag_sos_evds_struct
{
    unsigned int region_size;
    unsigned int offset;
    unsigned int segment;
    unsigned short number_available;
    unsigned short number_used;
    unsigned int page0;
} _SOS_EVDS_STRUCT;

typedef struct _tag_sos_vds_struct
{
    unsigned int region_size;
    unsigned int offset;
    unsigned short segment;
    unsigned short ID;
    unsigned int physical;
} _SOS_VDS_STRUCT;

typedef struct _tag_sos_sample
{
    PSTR pSample;
    PSTR pSampleCurrent;
    PSTR pSampleLoop;
    DWORD wLength;
    DWORD wLoopLength;
    DWORD wLoopEndLength;
    DWORD wLoopStage;
    DWORD wID;
    DWORD wFlags;
    DWORD wPriority;
    DWORD hSample;
    DWORD wVolume;
    DWORD wLoopCount;
    DWORD wRate;
    DWORD wBitsPerSample;
    DWORD wChannels;
    DWORD wFormat;
    DWORD wPanPosition;
    DWORD wPanSpeed;
    DWORD wPanStart;
    DWORD wPanEnd;
    DWORD wPanMode;
    DWORD wTotalBytesProcessed;
    void (*pfnSampleProcessed)(PSOSSAMPLE*);
    void (*pfnSampleDone)(PSOSSAMPLE*);
    void (*pfnSampleLoop)(PSOSSAMPLE*);
    DWORD wSystem[16];
    DWORD wUser[16];
    PSOSSAMPLE* pLink;
    PSOSSAMPLE* pNext;
} _SOS_SAMPLE;

typedef struct _tagCAPABILITIES
{
    BYTE szDeviceName[32];
    W32 wDeviceVersion;
    W32 wBitsPerSample;
    W32 wChannels;
    W32 wMinRate;
    W32 wMaxRate;
    W32 wMixerOnBoard;
    W32 wMixerFlags;
    W32 wFlags;
    short* lpPortList;
    short* lpDMAList;
    short* lpIRQList;
    short* lpRateList;
    W32 fBackground;
    W32 wID;
    W32 wTimerID;
} _SOS_CAPABILITIES;

typedef struct _SOS_HARDWARE
{
    W32 wPort;
    W32 wIRQ;
    W32 wDMA;
    W32 wParam;
} _SOS_HARDWARE;

typedef struct _tag_sos_driver
{
    W32 wFlags;
    DWORD wDriverRate;
    DWORD wDriverChannels;
    DWORD wDriverBitsPerSample;
    DWORD wDriverFormat;
    DWORD wMixerChannels;
    DWORD wDMACountRegister;
    DWORD wDMAPosition;
    DWORD wDMALastPosition;
    DWORD wDMADistance;
    PSTR pXFERPosition;
    DWORD wXFERJumpAhead;
    _SOS_SAMPLE* pSampleList;
    void (*pfnPseudoDMAFunction)();
    PSTR pDMABuffer;
    PSTR pDMABufferEnd;
    DWORD wDMABufferSize;
    PSTR pMixingBuffer;
    PSTR pMixingBufferEnd;
    DWORD wMixingBufferSize;
    DWORD wActiveChannels;
    _SOS_SAMPLE* pSamples;
    _SOS_HARDWARE sHardware;
    _SOS_CAPABILITIES sCaps;
    LPSTR lpDriverDS;
    LPSTR lpDriverCS;
    W32 wSize;
    DWORD dwLinear;
    DWORD dwDMAPhysical;
    LPSTR lpDMABuffer;
    W32 hMemory;
    W32 wDMARealSeg;
    W32 wID;
    void (*pfnMixFunction)();
} _SOS_DIGI_DRIVER;

typedef struct _SOS_DRV_FILEHEADER
{
    BYTE szName[32];
    W32 wDrivers;
    W32 lOffset;
    W32 lFileSize;
} _SOS_DRV_FILEHEADER;

typedef struct _SOS_DRV_DRIVERHEADER
{
    BYTE szName[32];
    W32 lNextDriver;
    W32 wSize;
    W32 wDeviceID;
    W32 wExtenderType;
} _SOS_DRV_DRIVERHEADER;

typedef struct _tag_sos_system
{
    W32 wFlags;
    BYTE szDriverPath[128];
    BYTE szTempDriverPath[128];
    PSOSDIGIDRIVER pDriver[5];
    _SOS_VDS_STRUCT sVDS;
    _SOS_DRV_FILEHEADER sFileHeader;
    _SOS_DRV_DRIVERHEADER sDriverHeader;
    PSTR(*pMemAllocFunction)
        (DWORD);
    void (*pMemFreeFunction)(PSTR, W32);
} _SOS_SYSTEM;

typedef struct _tag_sos_det_system
{
    W32 wFlags;
    BYTE szDriverPath[128];
    BYTE szTempDriverPath[128];
    _SOS_DRV_FILEHEADER sFileHeader;
    _SOS_DRV_DRIVERHEADER sDriverHeader;
    _SOS_CAPABILITIES sCaps;
    PSOSCAPABILITIES pCaps;
    LPSTR lpBufferDS;
    LPSTR lpBufferCS;
    W32 hFile;
    DWORD dwDriverIndex;
    W32 wDriverIndexCur;
    W32 hMemory;
    DWORD dwLinear;
} _SOS_DET_SYSTEM;

typedef struct _tag_sos_timer_system
{
    W32 wFlags;
    W32 wChipDivisor;
    void (*pfnEvent[16])();
    W32 wEventRate[16];
    DWORD dwAdditiveFraction[16];
    DWORD dwCurrentSummation[16];
    W32 wMIDIEventSongHandle[16];
    W32 wMIDIActiveSongHandle;
} _SOS_TIMER_SYSTEM;

typedef struct SmackTag
{
    unsigned long Version;
    unsigned long Width;
    unsigned long Height;
    unsigned long Frames;
    unsigned long MSPerFrame;
    unsigned long SmackerType;
    unsigned long LargestInTrack[7];
    unsigned long tablesize;
    unsigned long codesize;
    unsigned long absize;
    unsigned long detailsize;
    unsigned long typesize;
    unsigned long TrackType[7];
    unsigned long extra;
    unsigned long NewPalette;
    unsigned char Palette[772];
    unsigned long PalType;
    unsigned long FrameNum;
    unsigned long FrameSize;
    unsigned long SndSize;
    unsigned long LastRectx;
    unsigned long LastRecty;
    unsigned long LastRectw;
    unsigned long LastRecth;
    unsigned long OpenFlags;
    unsigned long LeftOfs;
    unsigned long TopOfs;
    unsigned long ReadError;
    unsigned long addr32;
} Smack;

typedef struct SmackSumTag
{
    unsigned long TotalTime;
    unsigned long MS100PerFrame;
    unsigned long TotalOpenTime;
    unsigned long TotalFrames;
    unsigned long SkippedFrames;
    unsigned long SoundSkips;
    unsigned long TotalBlitTime;
    unsigned long TotalReadTime;
    unsigned long TotalDecompTime;
    unsigned long TotalBackReadTime;
    unsigned long TotalReadSpeed;
    unsigned long SlowestFrameTime;
    unsigned long Slowest2FrameTime;
    unsigned long SlowestFrameNum;
    unsigned long Slowest2FrameNum;
    unsigned long AverageFrameSize;
    unsigned long Highest1SecRate;
    unsigned long Highest1SecFrame;
    unsigned long HighestMemAmount;
    unsigned long TotalExtraMemory;
    unsigned long HighestExtraUsed;
} SmackSum;

typedef struct _heapinfo
{
    void* _pentry;
    size_t _size;
    int _useflag;
} _HEAPINFO;

typedef enum tSpec_vol_depth_effect
{
    eSpec_dep_acid = 0,
    eSpec_dep_water = 1,
    eSpec_dep_slight_fog = 2,
    eSpec_dep_med_fog = 3,
    eSpec_dep_thick_fog = 4
} tSpec_vol_depth_effect;

typedef enum tSpec_vol_cam_effect
{
    eSpec_cam_wobble = 0
} tSpec_vol_cam_effect;

typedef enum tHeadup_type
{
    eHeadup_unused = 0,
    eHeadup_text = 1,
    eHeadup_coloured_text = 2,
    eHeadup_image = 3,
    eHeadup_fancy = 4,
    eHeadup_box_text = 5
} tHeadup_type;

typedef enum tFancy_stage
{
    eFancy_stage_incoming = 0,
    eFancy_stage_halting = 1,
    eFancy_stage_waiting = 2,
    eFancy_stage_readying = 3,
    eFancy_stage_leaving = 4
} tFancy_stage;

typedef struct tHeadup
{                                 // size: 0x14c
    tHeadup_type type;            // @0x0
    int x;                        // @0x4
    int y;                        // @0x8
    int original_x;               // @0xc
    int right_edge;               // @0x10
    int flash_period;             // @0x14
    int slot_index;               // @0x18
    int dimmed_background;        // @0x1c
    int dim_left;                 // @0x20
    int dim_top;                  // @0x24
    int dim_right;                // @0x28
    int dim_bottom;               // @0x2c
    int clever;                   // @0x30
    int cockpit_anchored;         // @0x34
    int flash_state;              // @0x38
    tJustification justification; // @0x3c
    tU32 end_time;                // @0x40
    tU32 last_flash;              // @0x44
    union {                       // size: 0x104
        struct
        {                   // size: 0x104
            char text[250]; // @0x0
            int colour;     // @0xfc
            br_font* font;  // @0x100
        } text_info;        // @0x0
        struct
        {                            // size: 0x100
            char text[250];          // @0x0
            tDR_font* coloured_font; // @0xfc
        } coloured_text_info;        // @0x0
        struct
        {                       // size: 0x4
            br_pixelmap* image; // @0x0
        } image_info;           // @0x0
        struct
        {                             // size: 0x18
            br_pixelmap* image;       // @0x0
            int offset;               // @0x4
            int shear_amount;         // @0x8
            int end_offset;           // @0xc
            tFancy_stage fancy_stage; // @0x10
            tU32 start_time;          // @0x14
        } fancy_info;                 // @0x0
    } data;                           // @0x48
} tHeadup;

typedef struct tQueued_headup
{
    int flash_rate;
    int lifetime;
    int font_index;
    char text[256];
} tQueued_headup;

//typedef unsigned long time_t;
//typedef unsigned long clock_t;
typedef struct tFlicette
{
    int flic_index;
    int x[2];
    int y[2];
} tFlicette;

typedef struct tMouse_area
{
    int left[2];
    int top[2];
    int right[2];
    int bottom[2];
    int new_choice;
    int new_mode;
    int available_when_typing;
    int (*mouse_click)(int*, int*, int, int);
} tMouse_area;

typedef struct tRectile
{
    int left[2];
    int top[2];
    int right[2];
    int bottom[2];
} tRectile;

typedef struct tInterface_spec
{
    int initial_imode;
    int first_opening_flic;
    int second_opening_flic;
    int end_flic_go_ahead;
    int end_flic_escaped;
    int end_flic_otherwise;
    int flic_bunch_to_load;
    int move_left_new_mode[2];
    int move_left_delta[2];
    int move_left_min[2];
    int move_left_max[2];
    int (*move_left_proc[2])(int*, int*);
    int move_right_new_mode[2];
    int move_right_delta[2];
    int move_right_min[2];
    int move_right_max[2];
    int (*move_right_proc[2])(int*, int*);
    int move_up_new_mode[2];
    int move_up_delta[2];
    int move_up_min[2];
    int move_up_max[2];
    int (*move_up_proc[2])(int*, int*);
    int move_down_new_mode[2];
    int move_down_delta[2];
    int move_down_min[2];
    int move_down_max[2];
    int (*move_down_proc[2])(int*, int*);
    int go_ahead_allowed[2];
    int (*go_ahead_proc[2])(int*, int*);
    int escape_allowed[2];
    int (*escape_proc[2])(int*, int*);
    int (*exit_proc)(int*, int*);
    void (*draw_proc)(int, int);
    tU32 time_out;
    void (*start_proc1)();
    void (*start_proc2)();
    int (*done_proc)(int, int, int, int, int);
    int font_needed;
    int typeable[2];
    void (*get_original_string)(int, int, char*, int*);
    int escape_code;
    int dont_save_or_load;
    int number_of_button_flics;
    tFlicette* flicker_on_flics;
    tFlicette* flicker_off_flics;
    tFlicette* pushed_flics;
    int number_of_mouse_areas;
    tMouse_area* mouse_areas;
    int number_of_recopy_areas;
    tRectile* recopy_areas;
} tInterface_spec;

typedef int dr_modelpick2d_cbfn(br_model*, br_material*, br_vector3*, br_vector3*, br_scalar, int, int, int, br_vector3*, br_vector2*, void*);
typedef int dr_pick3d_cbfn(br_actor*, br_model*, br_material*, br_matrix34*, br_bounds*, void*);

typedef struct tFlic_spec
{
    char* file_name;
    int interruptable;
    int queued;
    int frame_rate;
    int repeat;
    int x_offset;
    int y_offset;
    tS8* data_ptr;
    tU32 the_size;
} tFlic_spec;

typedef struct tFlic_bunch
{
    char count;
    int* indexes;
} tFlic_bunch;

typedef struct tTranslation_record
{
    int flic_index;
    int x;
    int y;
    int font_index;
    int global;
    int every_frame;
    tJustification justification;
    char* text;
} tTranslation_record;

/* Changed due to conflict with tVehicle_type enum */
typedef enum tVehicle_category
{
    eVehiclecat_self = 0,
    eVehiclecat_opponent = 1,
    eVehiclecat_rozzer = 2,
    eVehiclecat_drone = 3
} tVehicle_category;

typedef struct tTransient_bm
{
    br_pixelmap* pixmap;
    int in_use;
    int x_coord;
    int y_coord;
    int order_number;
    int user_data;
} tTransient_bm;

typedef struct tCursor_giblet
{
    int current_giblet;
    int sequence_index;
    int landed;
    int transient_index;
    float x_speed;
    float y_speed;
    float x_coord;
    float y_coord;
    float the_speed;
    tU32 last_giblet_change;
    tU32 giblet_change_period;
    tU32 e_t_a;
} tCursor_giblet;

typedef struct tWobble_spec
{
    float amplitude_x;
    float amplitude_y;
    float period;
    int time_started;
} tWobble_spec;

typedef struct tConcussion
{
    int concussed;
    br_matrix34 amplitudes;
    br_matrix34 periods;
    tU32 time_started;
} tConcussion;

typedef struct tSaved_table
{
    br_pixelmap* original;
    br_pixelmap* copy;
} tSaved_table;

typedef struct tClip_details
{
    br_actor* clip;
    br_scalar length;
} tClip_details;

typedef enum tS3_sound_type
{
    eS3_ST_sample = 0,
    eS3_ST_midi = 1,
    eS3_ST_cda = 2
} tS3_sound_type;

typedef struct tS3_outlet tS3_outlet;
typedef struct tS3_descriptor tS3_descriptor;
typedef struct tS3_channel tS3_channel;
typedef struct tS3_sound_source tS3_sound_source;
typedef struct tS3_channel
{
    int active;
    int termination_reason;
    int needs_service;
    int repetitions;
    int rate;
    int spatial_sound;
    unsigned int song_handle;
    tS3_sound_tag tag;
    tS3_type type;
    tS3_volume left_volume;
    tS3_volume right_volume;
    float volume_multiplier;
    tS3_vector3 position;
    tS3_vector3 velocity;
    tS3_vector3 lastpos;
    tS3_volume initial_volume;
    tS3_pitch initial_pitch;
    float pMax_distance_squared;
    tS3_outlet* owner_outlet;
    tS3_descriptor* descriptor;
    tS3_channel* next;
    char* type_struct_sample;
    char* type_struct_midi;
    char* type_struct_cda;
    tS3_sound_source* sound_source_ptr;
} tS3_channel;

typedef struct tS3_outlet
{
    int id;
    int max_channels;
    int independent_pitch;
    tS3_channel* channel_list;
    tS3_outlet* prev;
    tS3_outlet* next;
    tS3_outlet_callback* callback;
} tS3_outlet;

typedef struct tS3_descriptor
{
    tS3_sound_id id;
    tS3_type type;
    tS3_priority priority;
    tS3_repeats repeats;
    tS3_volume min_volume;
    tS3_volume max_volume;
    tS3_pitch min_pitch;
    tS3_pitch max_pitch;
    tS3_speed min_speed;
    tS3_speed max_speed;
    tS3_descriptor* prev;
    tS3_descriptor* next;
    int flags;
    int midi_song_handle;
    int special_fx;
    int memory_proxy;
    char* sound_data;
    char* filename;
} tS3_descriptor;

typedef struct tS3_sound_source
{
    tS3_channel* channel;
    int brender_vector;
    void* position_ptr;
    void* velocity_ptr;
    tS3_outlet* bound_outlet;
    tS3_sound_source* prev;
    tS3_sound_source* next;
    int ambient;
    tS3_repeats ambient_repeats;
    int time_since_last_played;
    tS3_sound_id sound_id;
    float max_distance_sq;
    int period;
    tS3_volume volume;
    tS3_pitch pitch;
    tS3_speed speed;
    tS3_sound_tag tag;
} tS3_sound_source;

typedef struct tS3_sample
{
    int size;
    int rate;
    int resolution;
    int channels;
    char* dataptr;
    void* freeptr;
} tS3_sample;

typedef struct tS3_hardware_info
{
    int device_installed;
    int timer_installed;
    int num_channels;
    int max_resolution;
    int stereo_flag;
    int max_sample_rate;
    int min_sample_rate;
    int independent_pitch;
} tS3_hardware_info;

typedef enum tNet_head_avail
{
    eNet_or_otherwise = 0,
    eNet_only = 1,
    eNot_net = 2,
    eNot_ever_ever_ever = 3
} tNet_head_avail;
typedef struct tModel_pool
{
    br_model** model_array;
    int model_count;
} tModel_pool;

typedef struct tHeadup_info
{
    char* name;
    tNet_head_avail avail;
} tHeadup_info;

typedef enum tTime_bonus_state
{
    eTime_bonus_none = 0,
    eTime_bonus_initial_pause = 1,
    eTime_bonus_race_bonus = 2,
    eTime_bonus_tb_up = 3,
    eTime_bonus_tb_pause = 4,
    eTime_bonus_tb_down = 5,
    eTime_bonus_end_pause = 6
} tTime_bonus_state;

typedef enum tInfo_mode
{
    eInfo_regular = 0,
    eInfo_pcam_car = 1,
    eInfo_nearby_mat = 2,
    eInfo_count = 3
} tInfo_mode;
typedef struct tHeadup_pair
{
    int player_index;
    int score;
    int out_of_game;
} tHeadup_pair;

typedef struct tMax_message
{
    char buffer[516];
} tMax_message;

typedef struct tMid_message
{
    char buffer[132];
} tMid_message;

typedef struct tMin_message
{
    char buffer[36];
} tMin_message;

typedef struct tGuaranteed_message
{
    tNet_message* message;
    tU32 send_time;
    tU32 next_resend_time;
    tU32 resend_period;
    int recieved;
    tPD_net_player_info pd_address;
    int (*NotifyFail)(tU32, tNet_message*);
    tU32 guarantee_number;
} tGuaranteed_message;

typedef enum tJoin_or_host_result
{
    eJoin_or_host_cancel = 0,
    eJoin_or_host_join = 1,
    eJoin_or_host_host = 2
} tJoin_or_host_result;
typedef struct tJoinable_game
{
    tNet_game_details* game;
    tU32 time;
} tJoinable_game;

typedef struct tOil_spill_info
{
    br_actor* actor;
    tCar_spec* car;
    tU32 spill_time;
    tU32 stop_time;
    br_scalar full_size;
    br_scalar current_size;
    br_scalar grow_rate;
    br_vector3 original_pos;
    br_vector3 pos;
} tOil_spill_info;

typedef enum tJoy_calib_stage
{
    eJoy_calib_tl_1 = 0,
    eJoy_calib_br_1 = 1,
    eJoy_calib_cn_1 = 2,
    eJoy_calib_tl_2 = 3,
    eJoy_calib_br_2 = 4,
    eJoy_calib_cn_2 = 5
} tJoy_calib_stage;

typedef enum tPed_instruc_type
{
    ePed_instruc_point = 0,
    ePed_instruc_xpoint = 1,
    ePed_instruc_bchoice = 2,
    ePed_instruc_fchoice = 3,
    ePed_instruc_dead = 4,
    ePed_instruc_bmarker = 5,
    ePed_instruc_fmarker = 6,
    ePed_instruc_baction = 7,
    ePed_instruc_faction = 8,
    ePed_instruc_reverse = 9
} tPed_instruc_type;

typedef enum tPed_frame_rate_type
{
    ePed_frame_fixed = 0,
    ePed_frame_speed = 1,
    ePed_frame_variable = 2
} tPed_frame_rate_type;

typedef enum tPed_collide_type
{
    ePed_collide_none = 255,
    ePed_collide_on = 0
} tPed_collide_type;

typedef enum tPed_hit_position
{
    ePed_hit_unknown = 0,
    ePed_hit_front = 1,
    ePed_hit_back = 2,
    ePed_hit_rside = 3,
    ePed_hit_lside = 4
} tPed_hit_position;
typedef struct tPed_choice
{
    tU16 danger_level;
    tU8 percentage_chance;
    tU8 marker_ref;
} tPed_choice;

typedef struct tPedestrian_instruction
{                           // size: 0x14
    tPed_instruc_type type; // @0x0
    union {                 // size: 0x10
        struct
        {                        // size: 0x10
            br_vector3 position; // @0x0
            int irreversable;    // @0xc
        } point_data;            // @0x0
        struct
        {                           // size: 0xc
            int number_of_choices;  // @0x0
            tPed_choice choices[2]; // @0x4
        } choice_data;              // @0x0
        struct
        {                       // size: 0x4
            int death_sequence; // @0x0
        } death_data;           // @0x0
        struct
        {                   // size: 0x4
            int marker_ref; // @0x0
        } marker_data;      // @0x0
        struct
        {                     // size: 0x4
            int action_index; // @0x0
        } action_data;        // @0x0
    } data;                   // @0x4
} tPedestrian_instruction;

typedef struct tBearing_sequence
{
    int sequence_index;
    float max_bearing;
} tBearing_sequence;

typedef struct tPedestrian_action
{
    float danger_level;
    float percentage_chance;
    int number_of_bearings;
    int number_of_sounds;
    int sounds[3];
    tBearing_sequence sequences[7];
    float initial_speed;
    float looping_speed;
    tU32 reaction_time;
} tPedestrian_action;

typedef struct tPed_frame_info
{
    br_vector2 offset;
    int flipped;
    br_pixelmap* pixelmap;
} tPed_frame_info;

typedef struct tPedestrian_sequence
{
    tPed_frame_rate_type frame_rate_type;
    float frame_rate_factor1;
    float frame_rate_factor2;
    int number_of_frames;
    int looping_frame_start;
    tPed_frame_info frames[10];
} tPedestrian_sequence;

typedef struct tPedestrian_data
{
    int magic_number;
    br_scalar height;
    br_scalar jump_magnitude;
    br_scalar car_to_ped;
    br_scalar min_x;
    br_scalar max_x;
    int credits_value;
    int hit_points;
    int number_of_exploding_sounds;
    int exploding_sounds[3];
    int falling_sound;
    int last_sound_action;
    tU16 killers_ID;
    br_scalar width;
    br_scalar height2;
    tCar_spec* fate;
    br_actor* actor;
    tPlayer_ID murderer;
    tPedestrian_instruction* instruction_list;
    tPedestrian_action* action_list;
    tU8 ref_number;
    tU8 active;
    tU8 munged;
    tU8 collided_last_time;
    tU8 flipped;
    tU8 reverse_frames;
    tU8 sent_dead_message;
    tS8 image_index;
    tS8 number_of_actions;
    tS8 number_of_instructions;
    tS8 first_instruction;
    tS8 current_instruction;
    tS8 fatal_car_impact_action;
    tS8 non_fatal_car_impact_action;
    tS8 after_impact_action;
    tS8 fatal_ground_impact_action;
    tS8 non_fatal_ground_impact_action;
    tS8 giblets_action;
    tS8 current_sequence;
    tS8 current_action;
    tS8 current_action_mode;
    tS8 current_frame;
    tS8 number_of_sequences;
    tS8 done_initial;
    tS8 giblets_being_sat_upon;
    tS8 mid_air;
    tS8 instruction_direction;
    tS8 irreversable;
    tS8 frightened_of_us;
    tS8 cloned;
    float current_speed;
    float acceleration;
    float spin_period;
    tU32 last_frame;
    tU32 last_action_change;
    tU32 last_sound_make;
    tS32 respawn_time;
    br_vector3 pos;
    br_vector3 direction;
    br_vector3 from_pos;
    br_vector3 to_pos;
    br_vector3 offset;
    float falling_speed;
    tSpecial_volume* last_special_volume;
    tPedestrian_sequence* sequences;
    tS3_sound_tag last_sound;
    br_pixelmap* colour_map;
} tPedestrian_data;

typedef struct tPed_gib
{
    br_actor* actor;
    br_scalar x_speed;
    br_scalar y_speed;
    int size;
    int last_frame;
    int gib_index;
    int parent_index;
    tU32 start_time;
    tU32 end_time;
    tU32 flip_period;
} tPed_gib;

typedef struct tPed_gib_materials
{
    int count;
    br_material* materials[5];
} tPed_gib_materials;

typedef struct tProximity_ray
{
    tCar_spec* car;
    tPedestrian_data* ped;
    tU32 start_time;
} tProximity_ray;

typedef struct tPiped_registration_snapshot
{
    int piped_actors_count;
    int piped_models_count;
    int piped_materials_count;
    int piped_pixelmaps_count;
} tPiped_registration_snapshot;

typedef struct tHeadup_icon
{
    tPowerup* powerup;
    int fizzle_stage;
    int fizzle_direction;
    tU32 fizzle_start;
} tHeadup_icon;

typedef struct tPrat_flic_spec
{
    char* data;
    tU32 data_length;
} tPrat_flic_spec;

typedef struct tPrat_alternative
{
    int ref;
    int chance;
    int number_of_sounds;
    int sound_ids[8];
    int sound_chance;
} tPrat_alternative;

typedef struct tPrat_flic_chunk
{
    int number_of_alternatives;
    tPrat_alternative alternatives[6];
} tPrat_flic_chunk;

typedef struct tPrat_sequence
{
    int number_of_chunks;
    int precedence;
    int repeat_chunk;
    tPrat_flic_chunk chunks[6];
} tPrat_sequence;

typedef enum tGrid_draw
{
    eGrid_draw_none = 0,
    eGrid_draw_icons_only = 1,
    eGrid_draw_all = 2
} tGrid_draw;

typedef enum tNet_synch_mode
{
    eNet_synch_host_first = 0,
    eNet_synch_host_subsequent = 1,
    eNet_synch_client = 2
} tNet_synch_mode;
typedef struct tWreck_info
{
    br_actor* actor;
    br_matrix34 rotation;
    br_matrix34 original_matrix;
    int customised;
    int car_index;
    float pos_x;
    float pos_y;
    tVehicle_type car_type;
    br_scalar scaling_factor;
} tWreck_info;

typedef struct tRectangle
{
    int left;
    int top;
    int right;
    int bottom;
} tRectangle;

typedef struct tSkid
{
    br_actor* actor;
    br_vector3 normal;
    br_vector3 pos;
} tSkid;

typedef struct tSpark
{
    int count;
    br_vector3 pos;
    br_vector3 v;
    br_vector3 length;
    br_vector3 normal;
    tU32 time_sync;
    tCar_spec* car;
    tU8 colour;
} tSpark;

typedef struct tShrapnel
{
    br_actor* actor;
    br_vector3 v;
    tU32 time_sync;
    tU32 age;
    br_scalar shear1;
    br_scalar shear2;
    br_vector3 axis;
} tShrapnel;

typedef struct tSmoke
{
    tU32 time_sync;
    br_vector3 pos;
    br_vector3 v;
    br_scalar radius;
    br_scalar strength;
    br_scalar decay_factor;
    tU8 type;
    tU8 pipe_me;
} tSmoke;

typedef struct tSmoke_column
{
    tCar_spec* car;
    tU32 time;
    tU32 lifetime;
    tU32 count;
    int colour;
    int whiter;
    br_actor* flame_actor;
    int frame_count[3];
    br_vector3 pos;
    br_scalar scale_x[3];
    br_scalar scale_y[3];
    br_scalar offset_x[3];
    br_scalar offset_z[3];
    tU32 smudge_timer;
    int vertex_index;
    int upright;
} tSmoke_column;

typedef struct tSplash
{
    br_actor* actor;
    br_vector3 v;
    int just_done;
    br_scalar size;
    br_scalar scale_x;
} tSplash;

typedef struct tBRender_smoke
{
    br_vector3 pos;
    br_scalar r;
    br_scalar strength;
    br_colour col;
    br_scalar aspect;
} tBRender_smoke;

typedef struct tRGB_colour
{
    int red;
    int green;
    int blue;
} tRGB_colour;

typedef br_material** tPMFMCB(br_model*, tU16);

typedef enum tMatrix_mod_type
{
    eMatrix_mod_none = 255,
    eMatrix_mod_spin = 0,
    eMatrix_mod_rock = 1,
    eMatrix_mod_throb = 2,
    eMatrix_mod_slither = 3,
    eMatrix_mod_roll = 4
} tMatrix_mod_type;

typedef enum tTexture_animation_type
{
    eTexture_animation_none = 255,
    eTexture_animation_frames = 0,
    eTexture_animation_flic = 1
} tTexture_animation_type;

typedef enum tMove_mode
{
    eMove_none = 255,
    eMove_linear = 0,
    eMove_harmonic = 1,
    eMove_flash = 2,
    eMove_controlled = 3,
    eMove_absolute = 4,
    eMove_continuous = 5
} tMove_mode;

typedef enum tFunk_trigger_mode
{
    eFunk_mode_constant = 0,
    eFunk_mode_distance = 1,
    eFunk_mode_last_lap_only = 2,
    eFunk_mode_all_laps_but_last = 3
} tFunk_trigger_mode;

typedef enum tGroove_trigger_mode
{
    eGroove_mode_constant = 0,
    eGroove_mode_distance = 1
} tGroove_trigger_mode;

typedef enum tGroove_path_mode
{
    eGroove_path_none = 255,
    eGroove_path_straight = 0,
    eGroove_path_circular = 1
} tGroove_path_mode;

typedef enum tGroove_object_mode
{
    eGroove_object_none = 255,
    eGroove_object_spin = 0,
    eGroove_object_rock = 1,
    eGroove_object_throb = 2,
    eGroove_object_shear = 3
} tGroove_object_mode;

typedef enum tGroove_axis_mode
{
    eGroove_axis_x = 0,
    eGroove_axis_y = 1,
    eGroove_axis_z = 2
} tGroove_axis_mode;

typedef enum tAnimation_time_mode
{
    eTime_mode_approximate = 0,
    eTime_mode_accurate = 1
} tAnimation_time_mode;

typedef enum tInterrupt_status
{
    eInterrupt_none = 0,
    eInterrupt_less_than = 1,
    eInterrupt_greater_than = 2
} tInterrupt_status;

typedef enum tRotate_mode
{
    eRotate_mode_x = 0,
    eRotate_mode_y = 1,
    eRotate_mode_z = 2
} tRotate_mode;

typedef enum tScale_mode
{
    eScale_mode_all = 0,
    eScale_mode_x = 1,
    eScale_mode_y = 2,
    eScale_mode_z = 3
} tScale_mode;

typedef struct tFunkotronic_spec
{                                     // size: 0xd8
    int owner;                        // @0x0
    br_material* material;            // @0x4
    tFunk_trigger_mode mode;          // @0x8
    tMatrix_mod_type matrix_mod_type; // @0xc
    tMove_mode matrix_mode;           // @0x10
    union {                           // size: 0x18
        struct
        {                 // size: 0x4
            float period; // @0x0
        } spin_info;      // @0x0
        struct
        {                       // size: 0x10
            float period;       // @0x0
            br_scalar x_centre; // @0x4
            br_scalar y_centre; // @0x8
            float rock_angle;   // @0xc
        } rock_info;            // @0x0
        struct
        {                       // size: 0x18
            float x_period;     // @0x0
            float y_period;     // @0x4
            br_scalar x_centre; // @0x8
            br_scalar y_centre; // @0xc
            float x_magnitude;  // @0x10
            float y_magnitude;  // @0x14
        } throb_info;           // @0x0
        struct
        {                      // size: 0x10
            float x_period;    // @0x0
            float y_period;    // @0x4
            float x_magnitude; // @0x8
            float y_magnitude; // @0xc
        } slither_info;        // @0x0
        struct
        {                                           // size: 0x8
            float x_period;                         // @0x0
            float y_period;                         // @0x4
        } roll_info;                                // @0x0
    } matrix_mod_data;                              // @0x14
    tMove_mode lighting_animation_type;             // @0x2c
    float lighting_animation_period;                // @0x30
    float ambient_base;                             // @0x34
    float ambient_delta;                            // @0x38
    float direct_base;                              // @0x3c
    float direct_delta;                             // @0x40
    float specular_base;                            // @0x44
    float specular_delta;                           // @0x48
    tTexture_animation_type texture_animation_type; // @0x4c
    tAnimation_time_mode time_mode;                 // @0x50
    float last_frame;                               // @0x54
    union {                                         // size: 0x78
        struct
        {                             // size: 0x30
            tMove_mode mode;          // @0x0
            float period;             // @0x4
            int texture_count;        // @0x8
            int current_frame;        // @0xc
            br_pixelmap* textures[8]; // @0x10
        } frames_info;                // @0x0
        struct
        {                                     // size: 0x78
            tU8* flic_data;                   // @0x0
            tU32 flic_data_length;            // @0x4
            tFlic_descriptor flic_descriptor; // @0x8
        } flic_info;                          // @0x0
    } texture_animation_data;                 // @0x58
    int proximity_count;                      // @0xd0
    br_vector3* proximity_array;              // @0xd4
} tFunkotronic_spec;

typedef struct tGroovidelic_spec
{                                            // size: 0x80
    int owner;                               // @0x0
    int done_this_frame;                     // @0x4
    br_actor* actor;                         // @0x8
    tLollipop_mode lollipop_mode;            // @0xc
    tGroove_trigger_mode mode;               // @0x10
    tGroove_path_mode path_type;             // @0x14
    tMove_mode path_mode;                    // @0x18
    tInterrupt_status path_interrupt_status; // @0x1c
    float path_resumption_value;             // @0x20
    union {                                  // size: 0x1c
        struct
        {                      // size: 0x1c
            float period;      // @0x0
            float x_delta;     // @0x4
            float y_delta;     // @0x8
            float z_delta;     // @0xc
            br_vector3 centre; // @0x10
        } straight_info;       // @0x0
        struct
        {                                      // size: 0x18
            float period;                      // @0x0
            float radius;                      // @0x4
            br_vector3 centre;                 // @0x8
            tGroove_axis_mode axis;            // @0x14
        } circular_info;                       // @0x0
    } path_data;                               // @0x24
    br_vector3 object_centre;                  // @0x40
    br_vector3 object_position;                // @0x4c
    tGroove_object_mode object_type;           // @0x58
    tMove_mode object_mode;                    // @0x5c
    tInterrupt_status object_interrupt_status; // @0x60
    float object_resumption_value;             // @0x64
    union {                                    // size: 0x18
        struct
        {                           // size: 0x8
            float period;           // @0x0
            tGroove_axis_mode axis; // @0x4
        } spin_info;                // @0x0
        struct
        {                           // size: 0x10
            float period;           // @0x0
            float max_angle;        // @0x4
            float current_angle;    // @0x8
            tGroove_axis_mode axis; // @0xc
        } rock_info;                // @0x0
        struct
        {                      // size: 0x18
            float x_period;    // @0x0
            float y_period;    // @0x4
            float z_period;    // @0x8
            float x_magnitude; // @0xc
            float y_magnitude; // @0x10
            float z_magnitude; // @0x14
        } throb_info;          // @0x0
        struct
        {                      // size: 0x18
            float x_period;    // @0x0
            float y_period;    // @0x4
            float z_period;    // @0x8
            float x_magnitude; // @0xc
            float y_magnitude; // @0x10
            float z_magnitude; // @0x14
        } shear_info;          // @0x0
    } object_data;             // @0x68
} tGroovidelic_spec;

typedef struct DWORDREGS
{
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int esi;
    unsigned int edi;
    unsigned int cflag;
} DWORDREGS;

typedef struct WORDREGS
{
    unsigned short ax;
    unsigned short _1;
    unsigned short bx;
    unsigned short _2;
    unsigned short cx;
    unsigned short _3;
    unsigned short dx;
    unsigned short _4;
    unsigned short si;
    unsigned short _5;
    unsigned short di;
    unsigned short _6;
    unsigned int cflag;
} WORDREGS;

typedef struct BYTEREGS
{
    unsigned char al;
    unsigned char ah;
    unsigned short _1;
    unsigned char bl;
    unsigned char bh;
    unsigned short _2;
    unsigned char cl;
    unsigned char ch;
    unsigned short _3;
    unsigned char dl;
    unsigned char dh;
    unsigned short _4;
} BYTEREGS;

typedef struct REGS
{
    DWORDREGS x;
    WORDREGS w;
    BYTEREGS h;
} REGS;

typedef struct SREGS
{
    unsigned short es;
    unsigned short cs;
    unsigned short ss;
    unsigned short ds;
    unsigned short fs;
    unsigned short gs;
} SREGS;

typedef struct REGPACKB
{
    unsigned char al;
    unsigned char ah;
    unsigned short _1;
    unsigned char bl;
    unsigned char bh;
    unsigned short _2;
    unsigned char cl;
    unsigned char ch;
    unsigned short _3;
    unsigned char dl;
    unsigned char dh;
    unsigned short _4;
} REGPACKB;

typedef struct REGPACKW
{
    unsigned short ax;
    unsigned short _1;
    unsigned short bx;
    unsigned short _2;
    unsigned short cx;
    unsigned short _3;
    unsigned short dx;
    unsigned short _4;
    unsigned short bp;
    unsigned short _5;
    unsigned short si;
    unsigned short _6;
    unsigned short di;
    unsigned short _7;
    unsigned short ds;
    unsigned short es;
    unsigned short fs;
    unsigned short gs;
    unsigned int flags;
} REGPACKW;

typedef struct REGPACKX
{
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int ebp;
    unsigned int esi;
    unsigned int edi;
    unsigned short ds;
    unsigned short es;
    unsigned short fs;
    unsigned short gs;
    unsigned int flags;
} REGPACKX;

typedef struct REGPACK
{
    REGPACKB h;
    REGPACKW w;
    REGPACKX x;
} REGPACK;

typedef struct INTPACKX
{
    unsigned int gs;
    unsigned int fs;
    unsigned int es;
    unsigned int ds;
    unsigned int edi;
    unsigned int esi;
    unsigned int ebp;
    unsigned int esp;
    unsigned int ebx;
    unsigned int edx;
    unsigned int ecx;
    unsigned int eax;
    unsigned int eip;
    unsigned int cs;
    unsigned int flags;
} INTPACKX;

typedef struct INTPACKW
{
    unsigned short gs;
    unsigned short _1;
    unsigned short fs;
    unsigned short _2;
    unsigned short es;
    unsigned short _3;
    unsigned short ds;
    unsigned short _4;
    unsigned short di;
    unsigned short _5;
    unsigned short si;
    unsigned short _6;
    unsigned short bp;
    unsigned short _7;
    unsigned short sp;
    unsigned short _8;
    unsigned short bx;
    unsigned short _9;
    unsigned short dx;
    unsigned short _a;
    unsigned short cx;
    unsigned short _b;
    unsigned short ax;
    unsigned short _c;
    unsigned short ip;
    unsigned short _d;
    unsigned short cs;
    unsigned short _e;
    unsigned int flags;
} INTPACKW;

typedef struct INTPACKB
{
    unsigned char bl;
    unsigned char bh;
    unsigned short _1;
    unsigned char dl;
    unsigned char dh;
    unsigned short _2;
    unsigned char cl;
    unsigned char ch;
    unsigned short _3;
    unsigned char al;
    unsigned char ah;
    unsigned short _4;
} INTPACKB;

typedef struct INTPACK
{
    INTPACKB h;
    INTPACKW w;
    INTPACKX x;
} INTPACK;

typedef struct _DOSERROR
{
    int exterror;
    char errclass;
    char action;
    char locus;
} _DOSERROR;

typedef struct DOSERROR
{
    int exterror;
    char class_;
    char action;
    char locus;
} DOSERROR;

typedef struct dosdate_t
{
    unsigned char day;
    unsigned char month;
    unsigned short year;
    unsigned char dayofweek;
} dosdate_t;

typedef struct dostime_t
{
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
    unsigned char hsecond;
} dostime_t;

typedef struct find_t
{
    char reserved[21];
    char attrib;
    unsigned short wr_time;
    unsigned short wr_date;
    unsigned long size;
    char name[13];
} find_t;

typedef struct _diskfree_t
{
    unsigned short total_clusters;
    unsigned short avail_clusters;
    unsigned short sectors_per_cluster;
    unsigned short bytes_per_sector;
} _diskfree_t;

typedef struct tPD_net_game_info
{
    _IPX_LOCAL_TARGET addr_ipx;
    tU32 last_response;
} tPD_net_game_info;

typedef struct tIPX_netnum
{
    BYTE bNetwork[4];
} tIPX_netnum;

typedef struct tRM_info
{
    unsigned long EDI;
    unsigned long ESI;
    unsigned long EBP;
    unsigned long reserved;
    unsigned long EBX;
    unsigned long EDX;
    unsigned long ECX;
    unsigned long EAX;
    unsigned short flags;
    unsigned short ES;
    unsigned short DS;
    unsigned short FS;
    unsigned short GS;
    unsigned short IP;
    unsigned short CS;
    unsigned short SP;
    unsigned short SS;
} tRM_info;

typedef struct tMem_info
{
    unsigned int largest_block_avail;
    unsigned int max_unlocked_page;
    unsigned int largest_lockable_page;
    unsigned int lin_addr_space;
    unsigned int num_free_pages_avail;
    unsigned int num_physical_pages_free;
    unsigned int total_physical_pages;
    unsigned int free_lin_addr_space;
    unsigned int size_of_page_file;
    unsigned int reserved[3];
} tMem_info;

typedef struct br_datafile
{                              // size: 0x10
    void* h;                   // @0x0
    br_file_primitives* prims; // @0x4
    br_token scalar_type;      // @0x8
    void* res;                 // @0xc
} br_datafile;

typedef struct DatafileStackType
{                // size: 0xc
    int type;    // @0x0
    void* value; // @0x4
    int count;   // @0x8
} DatafileStackType;
