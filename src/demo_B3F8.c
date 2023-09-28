#include "common.h"
#include "demo_B3F8.h"
#include "demo_9FD4.h"

/*INCLUDE_ASM("asm/nonmatchings/demo_B3F8", PS1_FinishRecordingDemo)*/

/* B3F8 8012FBF8 */
/*? PS1_DoDemo(u8 *);
extern u8 D_801E5604;
extern s8 D_801E5606;*/

void PS1_FinishRecordingDemo() {
    if (record.is_recording) {
        record.is_finished = TRUE;
        PS1_DoDemo(&record);
    }
}