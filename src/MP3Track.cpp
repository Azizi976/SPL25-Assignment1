#include "MP3Track.h"
#include <iostream>
#include <cmath>
#include <algorithm>

MP3Track::MP3Track(const std::string& title, const std::vector<std::string>& artists, 
                   int duration, int bpm, int bitrate, bool has_tags)
    : AudioTrack(title, artists, duration, bpm), bitrate(bitrate), has_id3_tags(has_tags) {

    std::cout << "MP3Track created: " << bitrate << " kbps" << std::endl;
}

// ========== TODO: STUDENTS IMPLEMENT THESE VIRTUAL FUNCTIONS ==========

void MP3Track::load() {
    std::cout << "[MP3Track::load] Loading MP3: \"" << title
              << "\" at " << bitrate << " kbps...\n";

    // Implementation of MP3 loading with format-specific operations
    if (has_id3_tags == true) {
        std::cout << "  → Processing ID3 metadata: \n"
        << "Title: " << title << std::endl;
        std::cout << "Artists: [ ";
        for (const auto& artist : artists) {
            std::cout << artist << " "; 
        } 
        std::cout << "]" << std::endl;
        std::cout << "Duration: " << duration_seconds << "\n"
        << "Bpm: " << bpm << "\n"
        << "waveform_size: " << waveform_size << std::endl;
    } else {
        std::cout << "  → No ID3 tags found.\n";
    }
    
    std::cout << "  → Decoding MP3 frames...\n";
    std::cout << "  → Load complete.\n";
}

void MP3Track::analyze_beatgrid() {
     std::cout << "[MP3Track::analyze_beatgrid] Analyzing beat grid for: \"" << title << "\"\n";
    // TODO: Implement MP3-specific beat detection analysis
    // NOTE: Use exactly 2 spaces before each arrow (→) character

}

double MP3Track::get_quality_score() const {
    // TODO: Implement comprehensive quality scoring
    // NOTE: This method does NOT print anything

    return 0.0; // Replace with your implementation
}

PointerWrapper<AudioTrack> MP3Track::clone() const {
    // TODO: Implement polymorphic cloning
    return PointerWrapper<AudioTrack>(nullptr); // Replace with your implementation
}