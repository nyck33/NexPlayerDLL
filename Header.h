// dllmain.cpp : Defines the entry point for the DLL application.
#pragma once

#ifdef NEXPLAYERDLL_EXPORTS
#	define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

class PauseResumeTracker {

public:
	int onPlayPauseTime;
	int lastPauseResumed;
	int numPauseResumed;
	enum class playState { waiting = 0, paused, playing };
	playState state;

	void setLastPR(int timestamp) {
		lastPauseResumed = timestamp;
	}
	
	int getLastPR(){
		return lastPauseResumed;
	}
	
	void incrementNumPR() {
		if (numPauseResumed == NULL) {
			numPauseResumed = 0;
		}
		else {
			numPauseResumed++;
		}
	}
	
	int getNumPR() {
		return numPauseResumed;
	}

	//parameters/ return values for playState are ints
	//so they can be called in C#
	void setPlayState(int newState){
		//newState is 0/1/2
		state = static_cast<playState>(newState);
	}

	int getPlayState() {
		return static_cast<int>(state);
	}

	//int Foo(int a); //placeholder
};

extern "C" EXPORT PauseResumeTracker* createNewPauseResumeTracker();
extern "C" EXPORT void OnPlayPause(int current_playback_time);
extern "C" EXPORT int GetNubmerOfPlayPauseEvents();
extern "C" EXPORT int GetLastPlayPauseTimestamp();


