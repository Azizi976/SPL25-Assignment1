#include "MixingEngineService.h"
#include <iostream>
#include <memory>

MixingEngineService::MixingEngineService()
    : active_deck(0),
      auto_sync(false),
      bpm_tolerance(0)

{
    decks[0] = nullptr;
    decks[1] = nullptr;
    std::cout << "[MixingEngineService] Initialized with 2 empty decks" << std::endl;
}

// Implementing role of 3
MixingEngineService::~MixingEngineService()
{
    std::cout << "[MixingEngineService] Cleaning up decks..." << std::endl;
    for (AudioTrack *track : decks)
    {
        if (track)
        {
            delete track;
            track = nullptr;
        }
    }
}

MixingEngineService::MixingEngineService(const MixingEngineService &other)
    : active_deck(other.active_deck), auto_sync(other.auto_sync),
      bpm_tolerance(other.bpm_tolerance)
{
    for (int i = 0; i < 2; i++)
    {
        if (other.decks[i] == nullptr)
        {
            decks[i] = nullptr;
        }
        else
        {
            decks[i] = other.decks[i]->clone().release();
        }
    }
}

MixingEngineService &MixingEngineService::operator=(const MixingEngineService &other)
{
    // Check if other equals to the current element
    if (this == &other)
    {
        return *this;
    }

    // Updating the fields that are not pointers
    active_deck = other.active_deck;
    auto_sync = other.auto_sync;
    bpm_tolerance = other.bpm_tolerance;

    // Destroying the current track in decks
    for (AudioTrack *track : decks)
    {
        if (track)
        {
            delete track;
            track = nullptr;
        }
    }

    // Updating decks and releasing the raw pointer from PointerWrapper
    for (int i = 0; i < 2; i++)
    {
        if (other.decks[i] != nullptr)
        {
            decks[i] = other.decks[i]->clone().release();
        }
        decks[i] = nullptr;
    }
    return *this;
}

/**
 * @param track: Reference to the track to be loaded
 * @return: Index of the deck where track was loaded, or -1 on failure
 */
int MixingEngineService::loadTrackToDeck(const AudioTrack &track)
{
    std::cout << "\n=== Loading Track to Deck ===" << std::endl;

    // Wrapping the track in a PointerWrapper
    PointerWrapper<AudioTrack> track_clone = track.clone();

    // Check if the clone worked
    if (!track_clone)
    {
        std::cerr << "[ERROR] Track: \"" << track_clone->get_title() << "\" failed to clone" << std::endl;
        return -1;
    }

    // Identifing tartget deck
    int target_deck;
    if (active_deck == 1)
    {
        target_deck = 0;
    }
    else
    {
        target_deck = 1;
    }

    // Log output
    std::cout << "[Deck Switch] Target deck:" << target_deck << std::endl;

    // Deleting the track in target deck
    if (decks[target_deck])
    {
        delete decks[target_deck];
        decks[target_deck] = nullptr;
    }

    //Performing a track preparation on cloned track        
    track_clone->load();
    track_clone->analyze_beatgrid();

    //BPM Management
    if(auto_sync && decks[active_deck]){
        if(decks[active_deck]->get_bpm()> bpm_tolerance ){
            
        }
    }

    return -1; // Placeholder
}

/**
 * @brief Display current deck status
 */
void MixingEngineService::displayDeckStatus() const
{
    std::cout << "\n=== Deck Status ===\n";
    for (size_t i = 0; i < 2; ++i)
    {
        if (decks[i])
            std::cout << "Deck " << i << ": " << decks[i]->get_title() << "\n";
        else
            std::cout << "Deck " << i << ": [EMPTY]\n";
    }
    std::cout << "Active Deck: " << active_deck << "\n";
    std::cout << "===================\n";
}

/**
 * TODO: Implement can_mix_tracks method
 *
 * Check if two tracks can be mixed based on BPM difference.
 *
 * @param track: Track to check for mixing compatibility
 * @return: true if BPM difference <= tolerance, false otherwise
 */
bool MixingEngineService::can_mix_tracks(const PointerWrapper<AudioTrack> &track) const
{
    // Your implementation here
    return false; // Placeholder
}

/**
 * TODO: Implement sync_bpm method
 * @param track: Track to synchronize with active deck
 */
void MixingEngineService::sync_bpm(const PointerWrapper<AudioTrack> &track) const
{
    // Your implementation here
}
