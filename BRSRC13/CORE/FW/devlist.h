#ifndef _DEVLIST_H_
#define _DEVLIST_H_

#include "br_types.h"


br_error AddRequestedDrivers();

br_error __stdcall devAdd(br_device **pdev, br_device_begin_fn *dev_begin, char *args, br_image *image);

br_error __cdecl BrDevAdd(br_device **pdev, char *image, char *args);

br_error __cdecl BrDevAddStatic(br_device **pdev, br_device_begin_fn *dev_begin, char *args);

br_error __cdecl BrDevCheckAdd(br_device **pdev, char *name, char *args);

br_error BrDevAddConfig(char *config);

br_error __cdecl BrDevRemove(br_device *dev);

br_error __stdcall BrDevFind(struct br_device **pdev, char *pattern);

br_error __stdcall BrDevFindMany(struct br_device **devices, br_int_32 *ndevices, br_int_32 max_devices, char *pattern);

br_error __stdcall BrDevCount(br_int_32 *ndevices, char *pattern);

br_error __cdecl BrDevContainedFind(struct br_object **ph, br_token type, char *pattern, br_token_value *tv);

br_error __cdecl BrDevContainedFindMany(struct br_object **objects, br_int_32 max_objects, br_int_32 *pnum_objects, br_token type, char *pattern, br_token_value *tv);

br_error __cdecl BrDevContainedCount(br_int_32 *pcount, br_token type, char *pattern, br_token_value *tv);

#endif
