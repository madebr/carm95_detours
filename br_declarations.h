typedef void(__cdecl* tBrMatrix34Identity)(br_matrix34* mat);
static tBrMatrix34Identity BrMatrix34Identity = (tBrMatrix34Identity)0x4d0d90;
typedef void(__cdecl* tBrMatrix34RotateY)(br_matrix34* mat, br_angle ry);
static tBrMatrix34RotateY BrMatrix34RotateY = (tBrMatrix34RotateY)0x4d0e20;
typedef void(__cdecl* tBrMatrix34ApplyV)(br_vector3* A, br_vector3* B, br_matrix34* C);
static tBrMatrix34ApplyV BrMatrix34ApplyV = (tBrMatrix34ApplyV)0x4d1a70;
typedef void(__cdecl* tBrMatrix34PreRotateY)(br_matrix34* mat, br_angle ry);
static tBrMatrix34PreRotateY BrMatrix34PreRotateY = (tBrMatrix34PreRotateY)0x4d1db0;