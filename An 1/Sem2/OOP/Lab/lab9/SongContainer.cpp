#include "SongContainer.h"
#include <fstream>
#include <stdexcept>
#include <sstream>

SongContainer::SongContainer(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Failed to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string artist = line;

        if (!std::getline(file, line)) break;
        std::string title = line;

        if (!std::getline(file, line)) break;
        std::string lyrics = line;

        if (!std::getline(file,line)) break;

        songs.emplace_back(artist, title, lyrics);
    }

    file.close();
}

std::vector<Song> SongContainer::getSongs() const {
    return songs;
}
