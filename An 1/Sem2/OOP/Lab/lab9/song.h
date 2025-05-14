//
// Created by Papp Zsolt on 08.05.2025.
//

#ifndef LAB9_SONG_H
#define LAB9_SONG_H

#include <string>
#include <vector>


class Song{
protected:
    std::string artist;
    std::string title;

private:
    std::vector<std::string> lyricsWords;
    std::vector<std::string> processLyrics(const std::string& lyrics);

public:
    Song(const std::string& artist, const std::string& title, const std::string& lyrics);
    std::string getArtist() const;
    std::string getTitle() const;
    std::vector<std::string> getLyricsWords() const;


};

#endif //LAB9_SONG_H
