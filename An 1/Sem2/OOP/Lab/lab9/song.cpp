//
// Created by Papp Zsolt on 08.05.2025.
//

#include "song.h"
#include <sstream>
#include <cctype>



Song::Song(const std::string& artist, const std::string& title, const std::string& lyrics)
        : artist(artist), title(title) {
    lyricsWords = processLyrics(lyrics);
}

std::string Song::getArtist() const {
    return artist;
}

std::string Song::getTitle() const {
    return title;
}

std::vector<std::string> Song::getLyricsWords() const {
    return lyricsWords;
}


std::vector<std::string> Song::processLyrics(const std::string& lyrics) {
    std::vector<std::string> words;
    std::string cleanedLyrics;

    for (char c : lyrics) {
        if (std::isalpha(c)) {
            cleanedLyrics += std::tolower(c);
        } else if (std::isspace(c)) {
            cleanedLyrics += ' ';
        }

    }

    std::stringstream ss(cleanedLyrics);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}



