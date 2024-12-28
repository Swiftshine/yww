#pragma once

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAXEQ(x, y) ((x) >= (y) ? (x) : y)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MINEQ(x, y) ((x) <= (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define ROUND_UP(x, align) (((x) + (align)-1) & (-(align)))
#define ROUND_UP_PTR(x, align) ((void *)((((u32)(x)) + (align)-1) & (~((align)-1))))
#define ARRAY_LENGTH(x) (sizeof((x)) / sizeof((x)[0]))

#define ENUM_CLASS(name, ...)              \
    class name {virtual void This_error_means_you_forgot_to_write___type___in_an_object_instantiation()=0;public: \
        enum __type__ { __VA_ARGS__ };     \
    }
