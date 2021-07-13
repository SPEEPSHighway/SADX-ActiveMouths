#pragma once
#include "SADXModLoader.h"

FunctionPointer(void, PFaceCancel, (unsigned __int8 pno), 0x440770);
FunctionPointer(void, KillHimP, (unsigned __int8 pno), 0x440CD0);
FunctionPointer(int, rand, (), 0x6443BF);
FunctionPointer(void, PConvertVector_G2N, (taskwk* twp, NJS_POINT3* vp), 0x43EC90);
FunctionPointer(void, EV_SetFace, (ObjectMaster* tp, const char* str), 0x4310D0);
FunctionPointer(void, BreathCounterP, (task* tp), 0x446B10);
FunctionPointer(void, PlayerLookingAtDestructor, (unsigned __int8 pno), 0x441080);
FunctionPointer(bool, EV_CheckCansel, (), 0x42FB00);
ObjectFunc(EV_ClrFace, 0x4310F0);