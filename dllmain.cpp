#include "pch.h"
//#include <utility>
//#include <limits.h>
#include "Header.h"

void PauseResumeTracker::setLastPR(int timestamp) {
    /*
    * transform int timestamp to int
    */
	lastPauseResumed = timestamp;
}

int PauseResumeTracker::getLastPR() {
	return lastPauseResumed;
}

void PauseResumeTracker::incrementNumPR() {
	if (numPauseResumed == NULL) {
		numPauseResumed = 0;
	}
	else {
		numPauseResumed++;
	}
}

int PauseResumeTracker::getNumPR() {
	return numPauseResumed;
}

//parameters/ return values for playState are ints
//so they can be called in C#
void PauseResumeTracker::setPlayState(int newState) {
	//newState is 0/1/2
	state = static_cast<playState>(newState);
}

int PauseResumeTracker::getPlayState() {
	return static_cast<int>(state);
}

//in lieu of constructor
EXPORT PauseResumeTracker* createNewPauseResumeTracker() {
    PauseResumeTracker* pauseResumeTracker = new PauseResumeTracker();
    pauseResumeTracker->setLastPR(0);
    pauseResumeTracker->incrementNumPR();
    pauseResumeTracker->setPlayState(0);
    
    return pauseResumeTracker;
}

EXPORT void OnPlayPause(PauseResumeTracker* instance, int current_playback_time) {
    /*timestamp of video time when player was last paused 
    / resumed
    */
    switch (instance->state) {
    case PauseResumeTracker::playState::waiting: {
        instance->setPlayState(2);
        instance->numPauseResumed++;
        instance->onPlayPauseTime = current_playback_time;
        break;
    }
    case PauseResumeTracker::playState::paused: {
        instance->setPlayState(2);
        instance->numPauseResumed++;
        instance->onPlayPauseTime = current_playback_time;
        break;
    }
    case PauseResumeTracker::playState::playing: {
        instance->setPlayState(1);
        instance->numPauseResumed++;
        instance->onPlayPauseTime = current_playback_time;
        break;
    }
        

    }

}

int GetNumberOfPlayPauseEvents(PauseResumeTracker* instance) {
    /*
    * return num times player has been paused / resumed
    state machine for paused, playing, 
    */
    
    return instance->getNumPR();
}

int GetLastPlayPauseTimestamp() {
    /*
    * return the last play
    */
    return 0;
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
