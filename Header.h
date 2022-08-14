// dllmain.cpp : Defines the entry point for the DLL application.
#pragma once

#ifdef NEXPLAYERDLL_EXPORTS
#	define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

enum class playState { paused = 0, playing };
int onPlayPauseTime;
int numPauseResumed;

//struct-like class

//class PausePlayTracker 
//{
//public:
//	playState state = playState::paused;

//};

//initial state is waiting
//playState state = playState::playing;
/*
typedef struct _PlayPauseTracker
{
	int onPlayPauseTime;
	int numPauseResumed;
} PlayPauseTracker;
*/

extern "C" EXPORT void OnPlayPause(int current_playback_time);
extern "C" EXPORT int GetNumberOfPlayPauseEvents();
extern "C" EXPORT int GetLastPlayPauseTimestamp();


