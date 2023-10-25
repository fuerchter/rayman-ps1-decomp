#include "demo_B3F8.h"

/* B3F8 8012FBF8 */
/*? PS1_DoDemo(u8 *);
extern u8 D_801E5604;
extern s8 D_801E5606;*/

void PS1_FinishRecordingDemo(void)
{
    if (record.is_recording)
    {
        record.is_finished = true;
        PS1_DoDemo(&record);
    }
}