#include "music.h"

MusicCommand PS1_LevelMusicTable[7][22][4] = 
{
    {
        {
            {.cmd_and_flags = 0x01, .param = 0x06},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x07},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x05},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x02},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x2f},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x04},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x01},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x30},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x1d},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x1d},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x01, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    },
    {
        {
            {.cmd_and_flags = 0x35, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x08},
            {.cmd_and_flags = 0xe1, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x09},
            {.cmd_and_flags = 0xe1, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x08},
            {.cmd_and_flags = 0x81, .param = 0x09},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x01, .param = 0x0a},
            {.cmd_and_flags = 0x03, .param = 0x02}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0b},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x01, .param = 0x0c},
            {.cmd_and_flags = 0x03, .param = 0x02}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x81, .param = 0x2e},
            {.cmd_and_flags = 0x03, .param = 0x02}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x09},
            {.cmd_and_flags = 0x81, .param = 0x08},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x09},
            {.cmd_and_flags = 0x81, .param = 0x0b},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x08},
            {.cmd_and_flags = 0xa1, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x01},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0b},
            {.cmd_and_flags = 0xa1, .param = 0x23},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x31},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    },
    {
        {
            {.cmd_and_flags = 0x35, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0e},
            {.cmd_and_flags = 0xa1, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0f},
            {.cmd_and_flags = 0xa1, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x10},
            {.cmd_and_flags = 0xa1, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x25},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0f},
            {.cmd_and_flags = 0x81, .param = 0x10},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x32},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0e},
            {.cmd_and_flags = 0xe1, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x14},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x00},
            {.cmd_and_flags = 0xe1, .param = 0x24},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x11},
            {.cmd_and_flags = 0x81, .param = 0x12},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x01},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0e},
            {.cmd_and_flags = 0x81, .param = 0x14},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x33},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x33},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    },
    {
        {
            {.cmd_and_flags = 0x35, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x81, .param = 0x17},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x15},
            {.cmd_and_flags = 0x81, .param = 0x16},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x16},
            {.cmd_and_flags = 0xe1, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x01},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0xc1, .param = 0x26},
            {.cmd_and_flags = 0x03, .param = 0x02}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x0d},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x27},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x17},
            {.cmd_and_flags = 0x81, .param = 0x17},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    },
    {
        {
            {.cmd_and_flags = 0x35, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x2b},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x18},
            {.cmd_and_flags = 0xe1, .param = 0x28},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x28},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1a},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x18},
            {.cmd_and_flags = 0xe1, .param = 0x28},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x18},
            {.cmd_and_flags = 0x81, .param = 0x19},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x28},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x19},
            {.cmd_and_flags = 0x81, .param = 0x18},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x25},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x01},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1b},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    },
    {
        {
            {.cmd_and_flags = 0x35, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1c},
            {.cmd_and_flags = 0xe1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x34},
            {.cmd_and_flags = 0xa1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1d},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x34},
            {.cmd_and_flags = 0x81, .param = 0x1c},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0xc1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x34},
            {.cmd_and_flags = 0xa1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1d},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1e},
            {.cmd_and_flags = 0xe1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1f},
            {.cmd_and_flags = 0xe1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x1f},
            {.cmd_and_flags = 0xe1, .param = 0x20},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x03},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    },
    {
        {
            {.cmd_and_flags = 0x35, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x21},
            {.cmd_and_flags = 0xe1, .param = 0x2a},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x2a},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x22},
            {.cmd_and_flags = 0xc1, .param = 0x2a},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x81, .param = 0x13},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00},
            {.cmd_and_flags = 0x03, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        },
        {
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00},
            {.cmd_and_flags = 0x00, .param = 0x00}
        }
    }
};

s16 D_801C4948[] =
{
    128, 121, 114, 108, 103, 97, 92, 87,
    83, 78, 74, 70, 67, 63, 60, 57,
    54, 51, 48, 45, 43, 41, 39, 37,
    35, 33, 31, 29, 28, 26, 25, 24,
    22, 21, 20, 19, 18, 17, 16, 15,
    14, 14, 13, 12, 11, 11, 10, 10,
    9, 9, 8, 8, 7, 7, 6, 6,
    6, 5, 5, 5, 5, 4, 4, 4,
    4, 3, 3, 3, 3, 3, 2, 2,
    2, 2, 2, 2, 2, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0
};

s16 D_801C4A00[] =
{
    128, 121, 114, 108, 103, 97, 92, 87,
    83, 78, 74, 70, 67, 63, 60, 57,
    54, 51, 48, 45, 43, 41, 39, 37,
    35, 33, 31, 29, 28, 26, 25, 24,
    22, 21, 20, 19, 18, 17, 16, 15,
    14, 14, 13, 12, 11, 11, 10, 10,
    9, 9, 8, 8, 7, 7, 6, 6,
    6, 5, 5, 5, 5, 4, 4, 4,
    4, 3, 3, 3, 3, 3, 2, 2,
    2, 2, 2, 2, 2, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0
};

u8 PS1_Music_Vol[] =
{
   57,  98,  90,  77,  84, 101,  53,  57,  69,  65, 
  120,  98,  71,  30,  64,  45,  71,  65,  72,  70, 
   36,  65,  57,  78,  35,  90,  73,  71,  57,  71, 
   40,  65, 102,  73,  61,  22,  71,  50,  75,  40, 
   84,  78,  80,  58,   0,   0,  98, 102,  74,  49, 
   55,  90,  49,   0,   0,   0,   0,   0,   0,   0, 
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
    0,   1,   1,   1,   1,   1,   1,   1,   1,   1, 
    1,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
    0,   0
};

s32 D_801C4B28[] = {300, 900, 600, 1200};