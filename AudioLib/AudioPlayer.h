////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Plays audio files on Windows.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#pragma comment(lib, "Winmm.lib")
#include "pch.h"
#include <Windows.h>
#include <mmsystem.h>
#include <mciapi.h>

namespace audio_player {
	// Wrapper for mciSendString().
	inline MCIERROR mci_api(const std::wstring& arg) {
		return mciSendString(arg.c_str(), NULL, 0, NULL);
	}

	// Opens an MP3 audio file and set to the specified alias.
	inline MCIERROR audio_open(const std::wstring& mp3, const std::wstring& alias = L"mp3") {
		return mci_api(L"open \"" + mp3 + L"\" type mpegvideo alias " + alias);
	}

	// Plays the specified alias.
	inline MCIERROR audio_play(const std::wstring& alias = L"mp3", bool wait = true) {
		return mci_api(wait ? L"play " + alias + L" from 0 wait" : L"play " + alias + L" from 0");
	}
}	// namespace audio_player
