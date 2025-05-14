//
// Created by Papp Zsolt on 08.05.2025.
//

#ifndef LAB9_SONGCONTAINER_H
#define LAB9_SONGCONTAINER_H

#include <vector>
#include <string>
#include "song.h"

class SongContainer {
private:
    std::vector<Song> songs;

public:
    SongContainer(const std::string& filename);

    std::vector<Song> getSongs() const;
};



#endif //LAB9_SONGCONTAINER_H
