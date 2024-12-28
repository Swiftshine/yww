#pragma once
#define YS_HANDLE_LIST_MAX_HANDLES 2000

#include "common.h"

class YsHandleObj;

// size: 0x1F48
class YsHandleList {
private:
    // 0x102BECC0
    static YsHandleList* sInstance;
public:
    static inline YsHandleList* Instance() {
        return sInstance;
    }

    // 0x02AB0098
    YsHandleList();

    // 0x02AB0130
    ~YsHandleList();

    // 0x02AB00F4
    static void InitInstance();

    // 0x02AB0144
    static void DestroyInstance();

    // 0x02AAFF50
    void Add(YsHandleObj* object);

    // 0x02AB0034
    void Remove(YsHandleObj* object);

    // 0x02AAFF20
    void Set(uint index, YsHandleObj* object);
private:
    YsHandleObj* mObjects[YS_HANDLE_LIST_MAX_HANDLES];
    uint mHandleCount;
    uint mLastHandleID;
};

