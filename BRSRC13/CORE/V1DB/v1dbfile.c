#include "v1dbfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_file_struct_member(* hookvar_br_vertex_FM )[3] = (void*)0x00523fd0;
br_file_struct * hookvar_br_vertex_F  = (void*)0x00524000;
br_file_struct_member(* hookvar_br_vertex_uv_FM )[2] = (void*)0x00524010;
br_file_struct * hookvar_br_vertex_uv_F  = (void*)0x00524030;
br_file_struct_member(* hookvar_br_old_vertex_uv_FM )[5] = (void*)0x00524040;
br_file_struct * hookvar_br_old_vertex_uv_F  = (void*)0x00524090;
br_file_struct_member(* hookvar_br_face_FM )[5] = (void*)0x005240a0;
br_file_struct * hookvar_br_face_F  = (void*)0x005240f0;
br_file_struct_member(* hookvar_br_old_face_1_FM )[5] = (void*)0x00524100;
br_file_struct * hookvar_br_old_face_1_F  = (void*)0x00524150;
br_file_struct_member(* hookvar_br_old_face_FM )[5] = (void*)0x00524160;
br_file_struct * hookvar_br_old_face_F  = (void*)0x005241b0;
br_file_struct_member(* hookvar_br_model_FM )[2] = (void*)0x005241c0;
br_file_struct * hookvar_br_model_F  = (void*)0x005241e0;
br_file_struct_member(* hookvar_br_old_model_1_FM )[1] = (void*)0x005241f0;
br_file_struct * hookvar_br_old_model_1_F  = (void*)0x00524200;
br_file_struct_member(* hookvar_br_pivot_FM )[3] = (void*)0x00524210;
br_file_struct * hookvar_br_pivot_F  = (void*)0x00524240;
br_file_struct_member(* hookvar_br_material_old_FM )[13] = (void*)0x00524250;
br_file_struct * hookvar_br_material_old_F  = (void*)0x00524320;
br_file_struct_member(* hookvar_br_material_FM )[17] = (void*)0x00524330;
br_file_struct * hookvar_br_material_F  = (void*)0x00524440;
struct {		// size: 0xc
    br_uint_32 id;		// @0x0
    size_t offset;		// @0x4
    int table;		// @0x8
}(* hookvar_MaterialMaps )[5] = (void*)0x00524450;
br_file_enum_member(* hookvar_actor_type_FM )[8] = (void*)0x00524490;
br_file_enum * hookvar_actor_type_F  = (void*)0x005244d0;
br_file_enum_member(* hookvar_render_style_FM )[8] = (void*)0x005244d8;
br_file_enum * hookvar_render_style_F  = (void*)0x00524518;
br_file_struct_member(* hookvar_br_actor_FM )[3] = (void*)0x00524520;
br_file_struct * hookvar_br_actor_F  = (void*)0x00524550;
br_file_struct_member(* hookvar_br_transform_matrix34_FM )[4] = (void*)0x00524560;
br_file_struct * hookvar_br_transform_matrix34_F  = (void*)0x005245a0;
br_file_struct_member(* hookvar_br_transform_quat_FM )[5] = (void*)0x005245b0;
br_file_struct * hookvar_br_transform_quat_F  = (void*)0x00524600;
br_file_enum_member(* hookvar_angle_order_FM )[24] = (void*)0x00524610;
br_file_enum * hookvar_angle_order_F  = (void*)0x005246d0;
br_file_struct_member(* hookvar_br_transform_euler_FM )[5] = (void*)0x005246d8;
br_file_struct * hookvar_br_transform_euler_F  = (void*)0x00524728;
br_file_struct_member(* hookvar_br_transform_look_up_FM )[3] = (void*)0x00524738;
br_file_struct * hookvar_br_transform_look_up_F  = (void*)0x00524768;
br_file_struct_member(* hookvar_br_transform_translation_FM )[1] = (void*)0x00524778;
br_file_struct * hookvar_br_transform_translation_F  = (void*)0x00524788;
struct transform_type(* hookvar_TransformTypes )[7] = (void*)0x00524798;
br_file_struct_member(* hookvar_br_bounds3_FM )[2] = (void*)0x005247d0;
br_file_struct * hookvar_br_bounds3_F  = (void*)0x005247f0;
br_file_struct_member(* hookvar_br_plane_FM )[1] = (void*)0x00524800;
br_file_struct * hookvar_br_plane_F  = (void*)0x00524810;
br_file_enum_member(* hookvar_light_type_FM )[6] = (void*)0x00524820;
#if 0
br_file_enum * hookvar_light_type_F ;
#endif
br_file_struct_member(* hookvar_br_light_FM )[8] = (void*)0x00524858;
br_file_struct * hookvar_br_light_F  = (void*)0x005248d8;
br_file_enum_member(* hookvar_camera_type_FM )[2] = (void*)0x005248e8;
br_file_enum * hookvar_camera_type_F  = (void*)0x005248f8;
br_file_struct_member(* hookvar_br_camera_FM )[6] = (void*)0x00524900;
br_file_struct * hookvar_br_camera_F  = (void*)0x00524960;
br_chunks_table_entry(* hookvar_ModelLoadEntries )[15] = (void*)0x00524970;
br_chunks_table * hookvar_ModelLoadTable  = (void*)0x00524a28;
br_chunks_table_entry(* hookvar_ActorLoadEntries )[21] = (void*)0x00524a30;
br_chunks_table * hookvar_ActorLoadTable  = (void*)0x00524b30;
br_chunks_table_entry(* hookvar_MaterialLoadEntries )[8] = (void*)0x00524b38;
br_chunks_table * hookvar_MaterialLoadTable  = (void*)0x00524b98;

int FopWrite_VERTICES(br_datafile *df, br_vertex *vertices, int nvertices) {
    LOG_TRACE("(%p, %p, %d)", df, vertices, nvertices);

    (void)df;
    (void)vertices;
    (void)nvertices;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_VERTICES)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004dad10;
CARM95_HOOK_FUNCTION(original_FopRead_VERTICES, FopRead_VERTICES)
int FopRead_VERTICES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_model *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_VERTICES(df, id, length, count);
}

static int(*original_FopRead_OLD_VERTICES)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004dad60;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_VERTICES, FopRead_OLD_VERTICES)
int FopRead_OLD_VERTICES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    void *ptr;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)ptr;

    return original_FopRead_OLD_VERTICES(df, id, length, count);
}

int FopWrite_VERTEX_UV(br_datafile *df, br_vertex *vertices, int nvertices) {
    LOG_TRACE("(%p, %p, %d)", df, vertices, nvertices);

    (void)df;
    (void)vertices;
    (void)nvertices;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_VERTEX_UV)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004dadc0;
CARM95_HOOK_FUNCTION(original_FopRead_VERTEX_UV, FopRead_VERTEX_UV)
int FopRead_VERTEX_UV(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_model *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_VERTEX_UV(df, id, length, count);
}

static int(*original_FopRead_OLD_VERTICES_UV)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004dae10;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_VERTICES_UV, FopRead_OLD_VERTICES_UV)
int FopRead_OLD_VERTICES_UV(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    void *ptr;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)ptr;

    return original_FopRead_OLD_VERTICES_UV(df, id, length, count);
}

static int(*original_FopRead_MATERIAL_INDEX)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004dae70;
CARM95_HOOK_FUNCTION(original_FopRead_MATERIAL_INDEX, FopRead_MATERIAL_INDEX)
int FopRead_MATERIAL_INDEX(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    char name[256];
    br_material **mip;
    br_uint_32 i;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)name;
    (void)mip;
    (void)i;

    return original_FopRead_MATERIAL_INDEX(df, id, length, count);
}

int FopWrite_MATERIAL_INDEX(br_datafile *df, br_material **materials, int nmaterials) {
    int i;
    int s;
    LOG_TRACE("(%p, %p, %d)", df, materials, nmaterials);

    (void)df;
    (void)materials;
    (void)nmaterials;
    (void)i;
    (void)s;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_OLD_MATERIAL_INDEX)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004daf00;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_MATERIAL_INDEX, FopRead_OLD_MATERIAL_INDEX)
int FopRead_OLD_MATERIAL_INDEX(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    char *mblock;
    char *cp;
    int i;
    int num_materials;
    br_material **mip;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mblock;
    (void)cp;
    (void)i;
    (void)num_materials;
    (void)mip;

    return original_FopRead_OLD_MATERIAL_INDEX(df, id, length, count);
}

static int(*original_FopRead_FACES)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004dafd0;
CARM95_HOOK_FUNCTION(original_FopRead_FACES, FopRead_FACES)
int FopRead_FACES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    struct br_model *mp;
    int i;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;
    (void)i;

    return original_FopRead_FACES(df, id, length, count);
}

int FopWrite_FACES(br_datafile *df, br_face *faces, int nfaces) {
    LOG_TRACE("(%p, %p, %d)", df, faces, nfaces);

    (void)df;
    (void)faces;
    (void)nfaces;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_OLD_FACES_1)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db050;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_FACES_1, FopRead_OLD_FACES_1)
int FopRead_OLD_FACES_1(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    struct br_model *mp;
    int i;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;
    (void)i;

    return original_FopRead_OLD_FACES_1(df, id, length, count);
}

static int(*original_FopRead_OLD_FACES)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db100;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_FACES, FopRead_OLD_FACES)
int FopRead_OLD_FACES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    struct br_face *fp;
    br_material **mip;
    int mi_count;
    unsigned int i;
    void *ptr;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)fp;
    (void)mip;
    (void)mi_count;
    (void)i;
    (void)ptr;

    return original_FopRead_OLD_FACES(df, id, length, count);
}

int FopWrite_FACE_MATERIAL(br_datafile *df, br_face *faces, int nfaces, br_material **mindex, int nmaterials) {
    br_uint_16 *block;
    br_uint_16 *ip;
    br_face *fp;
    int i;
    int j;
    LOG_TRACE("(%p, %p, %d, %p, %d)", df, faces, nfaces, mindex, nmaterials);

    (void)df;
    (void)faces;
    (void)nfaces;
    (void)mindex;
    (void)nmaterials;
    (void)block;
    (void)ip;
    (void)fp;
    (void)i;
    (void)j;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_FACE_MATERIAL)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db1e0;
CARM95_HOOK_FUNCTION(original_FopRead_FACE_MATERIAL, FopRead_FACE_MATERIAL)
int FopRead_FACE_MATERIAL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_material **mindex;
    int nmaterials;
    br_model *mp;
    br_face *fp;
    br_uint_16 *block;
    br_uint_16 *ip;
    int block_count;
    int i;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mindex;
    (void)nmaterials;
    (void)mp;
    (void)fp;
    (void)block;
    (void)ip;
    (void)block_count;
    (void)i;

    return original_FopRead_FACE_MATERIAL(df, id, length, count);
}

static int(*original_FopRead_MODEL)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db2b0;
CARM95_HOOK_FUNCTION(original_FopRead_MODEL, FopRead_MODEL)
int FopRead_MODEL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_model *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_MODEL(df, id, length, count);
}

int FopWrite_MODEL(br_datafile *df, br_model *mp) {
    br_model temp_model;
    LOG_TRACE("(%p, %p)", df, mp);

    (void)df;
    (void)mp;
    (void)temp_model;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_OLD_MODEL_1)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db300;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_MODEL_1, FopRead_OLD_MODEL_1)
int FopRead_OLD_MODEL_1(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_model *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_OLD_MODEL_1(df, id, length, count);
}

static int(*original_FopRead_OLD_MODEL)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db340;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_MODEL, FopRead_OLD_MODEL)
int FopRead_OLD_MODEL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_model *mp;
    int i;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;
    (void)i;

    return original_FopRead_OLD_MODEL(df, id, length, count);
}

static int(*original_FopRead_PIVOT)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db3e0;
CARM95_HOOK_FUNCTION(original_FopRead_PIVOT, FopRead_PIVOT)
int FopRead_PIVOT(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_model *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_PIVOT(df, id, length, count);
}

static int(*original_FopRead_MATERIAL_OLD)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db420;
CARM95_HOOK_FUNCTION(original_FopRead_MATERIAL_OLD, FopRead_MATERIAL_OLD)
int FopRead_MATERIAL_OLD(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_material *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_MATERIAL_OLD(df, id, length, count);
}

static int(*original_FopRead_MATERIAL)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db460;
CARM95_HOOK_FUNCTION(original_FopRead_MATERIAL, FopRead_MATERIAL)
int FopRead_MATERIAL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_material *mp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)mp;

    return original_FopRead_MATERIAL(df, id, length, count);
}

int FopWrite_MATERIAL(br_datafile *df, br_material *mp) {
    LOG_TRACE("(%p, %p)", df, mp);

    (void)df;
    (void)mp;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_PIXELMAP_REF)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db4a0;
CARM95_HOOK_FUNCTION(original_FopRead_PIXELMAP_REF, FopRead_PIXELMAP_REF)
int FopRead_PIXELMAP_REF(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_pixelmap *pm;
    char name[256];
    char *mp;
    int i;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)pm;
    (void)name;
    (void)mp;
    (void)i;

    return original_FopRead_PIXELMAP_REF(df, id, length, count);
}

int FopWrite_PIXELMAP_REF(br_datafile *df, int id, br_pixelmap *pixelmap) {
    LOG_TRACE("(%p, %d, %p)", df, id, pixelmap);

    (void)df;
    (void)id;
    (void)pixelmap;

    NOT_IMPLEMENTED();
}

int FopWrite_ACTOR(br_datafile *df, br_actor *ap) {
    LOG_TRACE("(%p, %p)", df, ap);

    (void)df;
    (void)ap;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db530;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR, FopRead_ACTOR)
int FopRead_ACTOR(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *ap;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)ap;

    return original_FopRead_ACTOR(df, id, length, count);
}

int FopWrite_ACTOR_MODEL(br_datafile *df, br_model *model) {
    LOG_TRACE("(%p, %p)", df, model);

    (void)df;
    (void)model;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_MODEL)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db580;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_MODEL, FopRead_ACTOR_MODEL)
int FopRead_ACTOR_MODEL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    char name[256];
    br_actor *a;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)name;
    (void)a;

    return original_FopRead_ACTOR_MODEL(df, id, length, count);
}

int FopWrite_ACTOR_MATERIAL(br_datafile *df, br_material *material) {
    LOG_TRACE("(%p, %p)", df, material);

    (void)df;
    (void)material;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_MATERIAL)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db5c0;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_MATERIAL, FopRead_ACTOR_MATERIAL)
int FopRead_ACTOR_MATERIAL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    char name[256];
    br_actor *a;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)name;
    (void)a;

    return original_FopRead_ACTOR_MATERIAL(df, id, length, count);
}

int FopWrite_ACTOR_TRANSFORM(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_TRANSFORM)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db600;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_TRANSFORM, FopRead_ACTOR_TRANSFORM)
int FopRead_ACTOR_TRANSFORM(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *a;
    br_transform *tp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)a;
    (void)tp;

    return original_FopRead_ACTOR_TRANSFORM(df, id, length, count);
}

int FopWrite_ACTOR_LIGHT(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_LIGHT)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db640;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_LIGHT, FopRead_ACTOR_LIGHT)
int FopRead_ACTOR_LIGHT(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *a;
    br_light *lp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)a;
    (void)lp;

    return original_FopRead_ACTOR_LIGHT(df, id, length, count);
}

int FopWrite_ACTOR_CAMERA(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_CAMERA)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db660;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_CAMERA, FopRead_ACTOR_CAMERA)
int FopRead_ACTOR_CAMERA(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *a;
    br_light *cp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)a;
    (void)cp;

    return original_FopRead_ACTOR_CAMERA(df, id, length, count);
}

int FopWrite_ACTOR_BOUNDS(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_BOUNDS)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db680;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_BOUNDS, FopRead_ACTOR_BOUNDS)
int FopRead_ACTOR_BOUNDS(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *a;
    br_bounds *bp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)a;
    (void)bp;

    return original_FopRead_ACTOR_BOUNDS(df, id, length, count);
}

int FopWrite_ACTOR_CLIP_PLANE(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_CLIP_PLANE)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db6a0;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_CLIP_PLANE, FopRead_ACTOR_CLIP_PLANE)
int FopRead_ACTOR_CLIP_PLANE(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *a;
    br_vector4 *vp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)a;
    (void)vp;

    return original_FopRead_ACTOR_CLIP_PLANE(df, id, length, count);
}

int FopWrite_ACTOR_ADD_CHILD(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_ACTOR_ADD_CHILD)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db6c0;
CARM95_HOOK_FUNCTION(original_FopRead_ACTOR_ADD_CHILD, FopRead_ACTOR_ADD_CHILD)
int FopRead_ACTOR_ADD_CHILD(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_actor *a;
    br_actor *p;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)a;
    (void)p;

    return original_FopRead_ACTOR_ADD_CHILD(df, id, length, count);
}

int FopWrite_TRANSFORM(br_datafile *df, br_transform *t) {
    struct transform_type *tt;
    LOG_TRACE("(%p, %p)", df, t);

    (void)df;
    (void)t;
    (void)tt;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_TRANSFORM)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db6f0;
CARM95_HOOK_FUNCTION(original_FopRead_TRANSFORM, FopRead_TRANSFORM)
int FopRead_TRANSFORM(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    int t;
    br_transform *tp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)t;
    (void)tp;

    return original_FopRead_TRANSFORM(df, id, length, count);
}

int FopWrite_BOUNDS(br_datafile *df, br_bounds *bp) {
    LOG_TRACE("(%p, %p)", df, bp);

    (void)df;
    (void)bp;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_BOUNDS)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db760;
CARM95_HOOK_FUNCTION(original_FopRead_BOUNDS, FopRead_BOUNDS)
int FopRead_BOUNDS(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_bounds3 *bp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)bp;

    return original_FopRead_BOUNDS(df, id, length, count);
}

int FopWrite_PLANE(br_datafile *df, br_vector4 *pp) {
    LOG_TRACE("(%p, %p)", df, pp);

    (void)df;
    (void)pp;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_PLANE)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db7b0;
CARM95_HOOK_FUNCTION(original_FopRead_PLANE, FopRead_PLANE)
int FopRead_PLANE(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_vector4 *pp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)pp;

    return original_FopRead_PLANE(df, id, length, count);
}

int FopWrite_LIGHT(br_datafile *df, br_light *lp) {
    LOG_TRACE("(%p, %p)", df, lp);

    (void)df;
    (void)lp;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_LIGHT)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db800;
CARM95_HOOK_FUNCTION(original_FopRead_LIGHT, FopRead_LIGHT)
int FopRead_LIGHT(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_light *lp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)lp;

    return original_FopRead_LIGHT(df, id, length, count);
}

int FopWrite_CAMERA(br_datafile *df, br_camera *cp) {
    LOG_TRACE("(%p, %p)", df, cp);

    (void)df;
    (void)cp;

    NOT_IMPLEMENTED();
}

static int(*original_FopRead_CAMERA)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...) = (int(*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32, ...))0x004db850;
CARM95_HOOK_FUNCTION(original_FopRead_CAMERA, FopRead_CAMERA)
int FopRead_CAMERA(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_camera *cp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)cp;

    return original_FopRead_CAMERA(df, id, length, count);
}

static br_uint_32(*original_BrModelLoadMany)(char *, br_model **, br_uint_16, ...) = (br_uint_32(*)(char *, br_model **, br_uint_16, ...))0x004db8a0;
CARM95_HOOK_FUNCTION(original_BrModelLoadMany, BrModelLoadMany)
br_uint_32 BrModelLoadMany(char *filename, br_model **models, br_uint_16 num) {
    int count;
    int r;
    br_datafile *df;
    LOG_TRACE("(\"%s\", %p, %u)", filename, models, num);

    (void)filename;
    (void)models;
    (void)num;
    (void)count;
    (void)r;
    (void)df;

    return original_BrModelLoadMany(filename, models, num);
}

static int(*original_PtrCompare)(void *, void *, ...) = (int(*)(void *, void *, ...))0x004dbdd0;
CARM95_HOOK_FUNCTION(original_PtrCompare, PtrCompare)
int PtrCompare(void *a, void *b) {
    LOG_TRACE("(%p, %p)", a, b);

    (void)a;
    (void)b;

    return original_PtrCompare(a, b);
}

static br_uint_32(*original_WriteModel)(br_model *, br_datafile *, ...) = (br_uint_32(*)(br_model *, br_datafile *, ...))0x004db9b0;
CARM95_HOOK_FUNCTION(original_WriteModel, WriteModel)
br_uint_32 WriteModel(br_model *mp, br_datafile *df) {
    br_material **mindex;
    br_vertex *vp;
    int nmaterials;
    int i;
    int has_uv;
    LOG_TRACE("(%p, %p)", mp, df);

    (void)mp;
    (void)df;
    (void)mindex;
    (void)vp;
    (void)nmaterials;
    (void)i;
    (void)has_uv;

    return original_WriteModel(mp, df);
}

static br_uint_32(*original_BrModelSaveMany)(char *, br_model **, br_uint_16, ...) = (br_uint_32(*)(char *, br_model **, br_uint_16, ...))0x004db920;
CARM95_HOOK_FUNCTION(original_BrModelSaveMany, BrModelSaveMany)
br_uint_32 BrModelSaveMany(char *filename, br_model **models, br_uint_16 num) {
    br_datafile *df;
    int i;
    int m;
    LOG_TRACE("(\"%s\", %p, %u)", filename, models, num);

    (void)filename;
    (void)models;
    (void)num;
    (void)df;
    (void)i;
    (void)m;

    return original_BrModelSaveMany(filename, models, num);
}

static br_uint_32(*original_BrActorLoadMany)(char *, br_actor **, br_uint_16, ...) = (br_uint_32(*)(char *, br_actor **, br_uint_16, ...))0x004dbdf0;
CARM95_HOOK_FUNCTION(original_BrActorLoadMany, BrActorLoadMany)
br_uint_32 BrActorLoadMany(char *filename, br_actor **actors, br_uint_16 num) {
    br_datafile *df;
    int count;
    int r;
    LOG_TRACE("(\"%s\", %p, %u)", filename, actors, num);

    (void)filename;
    (void)actors;
    (void)num;
    (void)df;
    (void)count;
    (void)r;

    return original_BrActorLoadMany(filename, actors, num);
}

static int(*original_WriteActor)(br_actor *, br_datafile *, ...) = (int(*)(br_actor *, br_datafile *, ...))0x004dbee0;
CARM95_HOOK_FUNCTION(original_WriteActor, WriteActor)
int WriteActor(br_actor *a, br_datafile *df) {
    br_actor *ap;
    br_actor *last_ap;
    LOG_TRACE("(%p, %p)", a, df);

    (void)a;
    (void)df;
    (void)ap;
    (void)last_ap;

    return original_WriteActor(a, df);
}

static br_uint_32(*original_BrActorSaveMany)(char *, br_actor **, br_uint_16, ...) = (br_uint_32(*)(char *, br_actor **, br_uint_16, ...))0x004dbe6b;
CARM95_HOOK_FUNCTION(original_BrActorSaveMany, BrActorSaveMany)
br_uint_32 BrActorSaveMany(char *filename, br_actor **actors, br_uint_16 num) {
    br_datafile *df;
    int i;
    LOG_TRACE("(\"%s\", %p, %u)", filename, actors, num);

    (void)filename;
    (void)actors;
    (void)num;
    (void)df;
    (void)i;

    return original_BrActorSaveMany(filename, actors, num);
}

static br_uint_32(*original_BrMaterialLoadMany)(char *, br_material **, br_uint_16, ...) = (br_uint_32(*)(char *, br_material **, br_uint_16, ...))0x004dc0e0;
CARM95_HOOK_FUNCTION(original_BrMaterialLoadMany, BrMaterialLoadMany)
br_uint_32 BrMaterialLoadMany(char *filename, br_material **materials, br_uint_16 num) {
    br_datafile *df;
    int count;
    int r;
    LOG_TRACE("(\"%s\", %p, %u)", filename, materials, num);

    (void)filename;
    (void)materials;
    (void)num;
    (void)df;
    (void)count;
    (void)r;

    return original_BrMaterialLoadMany(filename, materials, num);
}

static br_uint_32(*original_WriteMaterial)(br_material *, br_datafile *, ...) = (br_uint_32(*)(br_material *, br_datafile *, ...))0x004dc2e0;
CARM95_HOOK_FUNCTION(original_WriteMaterial, WriteMaterial)
br_uint_32 WriteMaterial(br_material *mp, br_datafile *df) {
    LOG_TRACE("(%p, %p)", mp, df);

    (void)mp;
    (void)df;

    return original_WriteMaterial(mp, df);
}

static br_uint_32(*original_BrMaterialSaveMany)(char *, br_material **, br_uint_16, ...) = (br_uint_32(*)(char *, br_material **, br_uint_16, ...))0x004dc160;
CARM95_HOOK_FUNCTION(original_BrMaterialSaveMany, BrMaterialSaveMany)
br_uint_32 BrMaterialSaveMany(char *filename, br_material **materials, br_uint_16 num) {
    br_datafile *df;
    int i;
    int count;
    LOG_TRACE("(\"%s\", %p, %u)", filename, materials, num);

    (void)filename;
    (void)materials;
    (void)num;
    (void)df;
    (void)i;
    (void)count;

    return original_BrMaterialSaveMany(filename, materials, num);
}

static br_model *(*original_BrModelLoad)(char *, ...) = (br_model *(*)(char *, ...))0x004dc3d0;
CARM95_HOOK_FUNCTION(original_BrModelLoad, BrModelLoad)
br_model* BrModelLoad(char *filename) {
    br_model *ptr;
    LOG_TRACE("(\"%s\")", filename);

    (void)filename;
    (void)ptr;

    return original_BrModelLoad(filename);
}

static br_uint_32(*original_BrModelSave)(char *, br_model *, ...) = (br_uint_32(*)(char *, br_model *, ...))0x004dc445;
CARM95_HOOK_FUNCTION(original_BrModelSave, BrModelSave)
br_uint_32 BrModelSave(char *filename, br_model *ptr) {
    LOG_TRACE("(\"%s\", %p)", filename, ptr);

    (void)filename;
    (void)ptr;

    return original_BrModelSave(filename, ptr);
}

static br_material *(*original_BrMaterialLoad)(char *, ...) = (br_material *(*)(char *, ...))0x004dc4a0;
CARM95_HOOK_FUNCTION(original_BrMaterialLoad, BrMaterialLoad)
br_material* BrMaterialLoad(char *filename) {
    br_material *ptr;
    LOG_TRACE("(\"%s\")", filename);

    (void)filename;
    (void)ptr;

    return original_BrMaterialLoad(filename);
}

static br_uint_32(*original_BrMaterialSave)(char *, br_material *, ...) = (br_uint_32(*)(char *, br_material *, ...))0x004dc515;
CARM95_HOOK_FUNCTION(original_BrMaterialSave, BrMaterialSave)
br_uint_32 BrMaterialSave(char *filename, br_material *ptr) {
    LOG_TRACE("(\"%s\", %p)", filename, ptr);

    (void)filename;
    (void)ptr;

    return original_BrMaterialSave(filename, ptr);
}

static br_actor *(*original_BrActorLoad)(char *, ...) = (br_actor *(*)(char *, ...))0x004dc660;
CARM95_HOOK_FUNCTION(original_BrActorLoad, BrActorLoad)
br_actor* BrActorLoad(char *filename) {
    br_actor *ptr;
    LOG_TRACE("(\"%s\")", filename);

    (void)filename;
    (void)ptr;

    return original_BrActorLoad(filename);
}

static br_uint_32(*original_BrActorSave)(char *, br_actor *, ...) = (br_uint_32(*)(char *, br_actor *, ...))0x004dc6e0;
CARM95_HOOK_FUNCTION(original_BrActorSave, BrActorSave)
br_uint_32 BrActorSave(char *filename, br_actor *ptr) {
    LOG_TRACE("(\"%s\", %p)", filename, ptr);

    (void)filename;
    (void)ptr;

    return original_BrActorSave(filename, ptr);
}

static br_error(*original_BrModelFileCount)(char *, br_uint_16 *, ...) = (br_error(*)(char *, br_uint_16 *, ...))0x004dc730;
CARM95_HOOK_FUNCTION(original_BrModelFileCount, BrModelFileCount)
br_error BrModelFileCount(char *filename, br_uint_16 *num) {
    br_datafile *df;
    LOG_TRACE("(\"%s\", %p)", filename, num);

    (void)filename;
    (void)num;
    (void)df;

    return original_BrModelFileCount(filename, num);
}

static br_error(*original_BrActorFileCount)(char *, br_uint_16 *, ...) = (br_error(*)(char *, br_uint_16 *, ...))0x004dc7b0;
CARM95_HOOK_FUNCTION(original_BrActorFileCount, BrActorFileCount)
br_error BrActorFileCount(char *filename, br_uint_16 *num) {
    br_datafile *df;
    LOG_TRACE("(\"%s\", %p)", filename, num);

    (void)filename;
    (void)num;
    (void)df;

    return original_BrActorFileCount(filename, num);
}

static br_error(*original_BrMaterialFileCount)(char *, br_uint_16 *, ...) = (br_error(*)(char *, br_uint_16 *, ...))0x004dc830;
CARM95_HOOK_FUNCTION(original_BrMaterialFileCount, BrMaterialFileCount)
br_error BrMaterialFileCount(char *filename, br_uint_16 *num) {
    br_datafile *df;
    LOG_TRACE("(\"%s\", %p)", filename, num);

    (void)filename;
    (void)num;
    (void)df;

    return original_BrMaterialFileCount(filename, num);
}

