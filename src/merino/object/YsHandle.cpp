#include "object/YsHandle.h"
#include "object/YsHandleList.h"

void YsHandleList::Set(uint index, YsHandleObj* object) {
    // not decompiled
}

void YsHandleList::Add(YsHandleObj* object) {
    // not decompiled
}

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

YsHandleList::YsHandleList() {
    // not decompiled
}

void YsHandleList::InitInstance() {
    sInstance = new (1) YsHandleObj();
}

YsHandleList::~YsHandleList() { }

void YsHandleList::DestroyInstance() {
    delete sInstance;
    sInstance = nullptr;
}
