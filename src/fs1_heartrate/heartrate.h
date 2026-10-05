#ifndef HEARTRATE_H
#define HEARTRATE_H

#include "../state.hpp"

void heartrate_init(void);

void heartrate_update(
    CoreState *state,
    u16 rawSample,
    u32 timestampMs
);

#endif