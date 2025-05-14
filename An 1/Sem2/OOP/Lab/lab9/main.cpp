#include <iostream>
#include "SongContainer.h"
#include <algorithm>


int main() {
    try {
        SongContainer container("songs.txt");

        std::vector<Song> songs = container.getSongs();

        std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.getArtist () < b.getArtist();
        });

        for (const Song& song : songs) {
            std::cout << "Artist: " << song.getArtist() << std::endl;
            std::cout << "Title: " << song.getTitle() << std::endl;
            std::cout << "Words: ";
            for (const auto& word : song.getLyricsWords()) {
                std::cout << word << " ";
            }
            std::cout << "\n\n";


        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
