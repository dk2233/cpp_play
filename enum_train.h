#ifndef ENUM_TRAIN_H
#define ENUM_TRAIN_H

#include <cstdint>

enum class Status_e : uint8_t {
    STATUS_IDLE = 0,
    STATUS_INIT = 1,
    STATUS_RESTART = 2,
    STATUS_RUN = 4,
    STATUS_ERROR = 9,
};

enum Status_unscoped {
    STAT_IDLE, STAT_INIT, STAT_RESTART, STAT_RUN, STAT_ERROR };


enum struct Colors_e {
    YELLOW,
    GREEN,
    BLUE,
    RED,
    BLACK,
    WHITE,
};

void enum_sandbox();

#endif
