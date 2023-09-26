#include "common.h"
#include "demo_9FD4.h"

//lui, hi/lo before jal
/* B3F8 8012FBF8 */
//void PS1_DoDemo(u8 *);                                 /* extern */

void PS1_FinishRecordingDemo(void) {
    if (record.is_recording != 0) {
        record.is_finished = 1;
        PS1_DoDemo(&record);
    }
}