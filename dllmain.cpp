//pause time = resume time, start where paused
#include "pch.h"
#include "Header.h"

playState state = playState::playing;

EXPORT void OnPlayPause(int current_playback_time) {
    /*timestamp of video time when player was last paused 
    / resumed
    */
    //reset onPlayPauseTime to 0 if called in Start 
    //of Unity code
    if (current_playback_time == 0) {
        onPlayPauseTime = 0;
        numPauseResumed = 0;
        return;
    }
    switch (state) {
        
        case playState::paused: {
            state = playState::playing;
            numPauseResumed++;
            onPlayPauseTime = current_playback_time;
            break;
        }
        case playState::playing: {
            state = playState::paused;
            numPauseResumed++;
            onPlayPauseTime = current_playback_time;
            break;
        }
        

    }

}

//these two get called on Update()
int GetNumberOfPlayPauseEvents() {
    /*
    * return num times player has been paused / resumed
    state machine for paused, playing, 
    */
    
    return numPauseResumed;
}

int GetLastPlayPauseTimestamp() {
    /*
    * return the last pause resume time
    */
    return onPlayPauseTime;
}





/*
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
*/
