#ifndef _V1DBFILE_H_
#define _V1DBFILE_H_

#include "br_types.h"

extern br_file_enum_member(* hookvar_actor_type_FM )[8]; // addr: 00524490
extern br_file_enum * hookvar_actor_type_F ; // addr: 005244D0
extern br_file_enum_member(* hookvar_render_style_FM )[8]; // addr: 005244D8
extern br_file_enum * hookvar_render_style_F ; // addr: 00524518
extern br_file_enum_member(* hookvar_angle_order_FM )[24]; // addr: 00524610
extern br_file_enum * hookvar_angle_order_F ; // addr: 005246D0
extern br_file_enum_member(* hookvar_light_type_FM )[6]; // addr: 00524820
// extern br_file_enum * hookvar_light_type_F ;
extern br_file_enum_member(* hookvar_camera_type_FM )[2]; // addr: 005248E8
extern br_file_enum * hookvar_camera_type_F ; // addr: 005248F8
extern br_chunks_table_entry(* hookvar_ModelLoadEntries )[15]; // addr: 00524970
extern br_chunks_table * hookvar_ModelLoadTable ; // addr: 00524A28
extern br_chunks_table_entry(* hookvar_ActorLoadEntries )[21]; // addr: 00524A30
extern br_chunks_table * hookvar_ActorLoadTable ; // addr: 00524B30
extern br_chunks_table_entry(* hookvar_MaterialLoadEntries )[8]; // addr: 00524B38
extern br_chunks_table * hookvar_MaterialLoadTable ; // addr: 00524B98

int FopWrite_VERTICES(br_datafile *df, br_vertex *vertices, int nvertices);

int __stdcall FopRead_VERTICES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __cdecl FopRead_OLD_VERTICES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_VERTEX_UV(br_datafile *df, br_vertex *vertices, int nvertices);

int __stdcall FopRead_VERTEX_UV(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_OLD_VERTICES_UV(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_MATERIAL_INDEX(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_MATERIAL_INDEX(br_datafile *df, br_material **materials, int nmaterials);

int __stdcall FopRead_OLD_MATERIAL_INDEX(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_FACES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_FACES(br_datafile *df, br_face *faces, int nfaces);

int __stdcall FopRead_OLD_FACES_1(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_OLD_FACES(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_FACE_MATERIAL(br_datafile *df, br_face *faces, int nfaces, br_material **mindex, int nmaterials);

int __stdcall FopRead_FACE_MATERIAL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_MODEL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_MODEL(br_datafile *df, br_model *mp);

int __stdcall FopRead_OLD_MODEL_1(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_OLD_MODEL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_PIVOT(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_MATERIAL_OLD(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopRead_MATERIAL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_MATERIAL(br_datafile *df, br_material *mp);

int __stdcall FopRead_PIXELMAP_REF(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_PIXELMAP_REF(br_datafile *df, int id, br_pixelmap *pixelmap);

int FopWrite_ACTOR(br_datafile *df, br_actor *ap);

int __stdcall FopRead_ACTOR(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_MODEL(br_datafile *df, br_model *model);

int __stdcall FopRead_ACTOR_MODEL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_MATERIAL(br_datafile *df, br_material *material);

int __stdcall FopRead_ACTOR_MATERIAL(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_TRANSFORM(br_datafile *df);

int __stdcall FopRead_ACTOR_TRANSFORM(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_LIGHT(br_datafile *df);

int __stdcall FopRead_ACTOR_LIGHT(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_CAMERA(br_datafile *df);

int __stdcall FopRead_ACTOR_CAMERA(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_BOUNDS(br_datafile *df);

int __stdcall FopRead_ACTOR_BOUNDS(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_CLIP_PLANE(br_datafile *df);

int __stdcall FopRead_ACTOR_CLIP_PLANE(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ACTOR_ADD_CHILD(br_datafile *df);

int __stdcall FopRead_ACTOR_ADD_CHILD(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_TRANSFORM(br_datafile *df, br_transform *t);

int __stdcall FopRead_TRANSFORM(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_BOUNDS(br_datafile *df, br_bounds *bp);

int __stdcall FopRead_BOUNDS(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_PLANE(br_datafile *df, br_vector4 *pp);

int __stdcall FopRead_PLANE(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_LIGHT(br_datafile *df, br_light *lp);

int __stdcall FopRead_LIGHT(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_CAMERA(br_datafile *df, br_camera *cp);

int __stdcall FopRead_CAMERA(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

br_uint_32 __cdecl BrModelLoadMany(char *filename, br_model **models, br_uint_16 num);

int __cdecl PtrCompare(void *a, void *b);

br_uint_32 __cdecl WriteModel(br_model *mp, br_datafile *df);

br_uint_32 __cdecl BrModelSaveMany(char *filename, br_model **models, br_uint_16 num);

br_uint_32 __cdecl BrActorLoadMany(char *filename, br_actor **actors, br_uint_16 num);

int __stdcall WriteActor(br_actor *a, br_datafile *df);

br_uint_32 __cdecl BrActorSaveMany(char *filename, br_actor **actors, br_uint_16 num);

br_uint_32 __cdecl BrMaterialLoadMany(char *filename, br_material **materials, br_uint_16 num);

br_uint_32 __cdecl WriteMaterial(br_material *mp, br_datafile *df);

br_uint_32 __cdecl BrMaterialSaveMany(char *filename, br_material **materials, br_uint_16 num);

br_model* __cdecl BrModelLoad(char *filename);

br_uint_32 __cdecl BrModelSave(char *filename, br_model *ptr);

br_material* __cdecl BrMaterialLoad(char *filename);

br_uint_32 __cdecl BrMaterialSave(char *filename, br_material *ptr);

br_actor* __cdecl BrActorLoad(char *filename);

br_uint_32 __cdecl BrActorSave(char *filename, br_actor *ptr);

br_error __cdecl BrModelFileCount(char *filename, br_uint_16 *num);

br_error __cdecl BrActorFileCount(char *filename, br_uint_16 *num);

br_error __cdecl BrMaterialFileCount(char *filename, br_uint_16 *num);

#endif
