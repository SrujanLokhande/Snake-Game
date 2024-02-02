#pragma once
#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <string>
#include <Windows.h>

class SoundPlayer
{
public:
    SoundPlayer() = delete;
    SoundPlayer(const std::string& filename);
    ~SoundPlayer();

    void Play();

private:
    std::wstring m_filepath;
};

#endif
