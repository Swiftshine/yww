#include "object/YsHandle.h"
#include "object/YsHandleList.h"
#include "gfl/gflMemoryUtil.h"

// functions not defined in this TU

extern "C" {
    void fn_02BB6EE4();
}

void YsHandleList::Set(uint index, YsHandleObj* object) {
   mObjects[index] = object;
   object->SetHandleID(mLastHandleID);
   object->SetHandleObject(&mObjects[index]);
   mHandleCount = index + 1;
   mLastHandleID++;
}

// void YsHandleList::Add(YsHandleObj* object) {
//     // uint curCount = mHandleCount;
//     // YsHandleObj** lastHandleObj = &mObjects[mHandleCount];
    
//     // while (curCount < YS_HANDLE_LIST_MAX_HANDLES) {
//     //     if (*lastHandleObj == nullptr) {
//     //         Set(curCount, object);
//     //         return;
//     //     }

//     //     lastHandleObj++;
//     //     curCount++;
//     // }



// }

YsHandleObj::YsHandleObj() {
    mHandle.SetObject(nullptr);
    mHandle.SetID(0);
    YsHandleList::Instance()->Add(this);
}

void YsHandleList::Remove(YsHandleObj* object) {
    object->ClearHandleObject();
}

YsHandleObj::~YsHandleObj() {
    YsHandleList::Instance()->Remove(this);
}

YsHandleList::YsHandleList()
    : mHandleCount(0)
    , mLastHandleID(1)
{
    gfl::Memset(mObjects, 0, 0x1F40);
}

void YsHandleList::InitInstance() {
    sInstance = new (1) YsHandleList;
}

YsHandleList::~YsHandleList() { }

void YsHandleList::DestroyInstance() {
    delete sInstance;
    sInstance = nullptr;
}
