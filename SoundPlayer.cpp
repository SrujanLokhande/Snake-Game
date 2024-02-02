#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(const std::string& filename)
{
    // Get the current directory
    wchar_t currentDir[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, currentDir);

    // Build the full file path
    std::wstring filepath_wide(filename.begin(), filename.end());
    m_filepath = currentDir;
    m_filepath += L"\\Sound\\";
    m_filepath += filepath_wide;
}

SoundPlayer::~SoundPlayer()
{

}

void SoundPlayer::Play()
{
    // Play the sound
    PlaySound(m_filepath.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}