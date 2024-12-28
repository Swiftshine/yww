#pragma once

#include "common.h"

class YsHandleObj;

// size: 0x8
class YsHandle {
public:
    inline YsHandle()
        : mObject(nullptr)
        , mHandleID(0)
    { }

    inline void SetID(uint id) {
        mHandleID = id;
    }

    inline void SetObject(YsHandleObj** obj) {
        mObject = obj;
    }

    inline uint GetID() {
        return mHandleID;
    }

    inline YsHandleObj** GetObject() {
        return mObject;
    }

    inline void ClearObject() {
        *mObject = nullptr;
    }

    inline void operator=(const YsHandle& other) {
        mObject = other.mObject;
        mHandleID = other.mHandleID;
    }

private:
    YsHandleObj** mObject;
    uint mHandleID;
};

// size: 0xC
class YsHandleObj {
public:
    // 0x02AAFFCC
    YsHandleObj();

    // 0x02AB0044
    virtual ~YsHandleObj();

    inline void SetHandleID(uint id) {
        mHandle.SetID(id);
    }

    inline void SetHandleObject(YsHandleObj** obj) {
        mHandle.SetObject(obj);
    }

    inline uint GetHandleID() {
        return mHandle.GetID();
    }

    inline YsHandleObj** GetHandleObject() {
        return mHandle.GetObject();
    }

    inline void ClearHandleObject() {
        mHandle.ClearObject();
    }
private:
    YsHandle mHandle;
};
