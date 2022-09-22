// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Playing: " << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for (const auto &song: playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "===============================================" << std::endl;
    play_current_song(current_song);
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    char selection {};
    
    do {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);
        
        if (selection == 'F') {
            current_song = playlist.begin();
            play_current_song(*current_song);
        } else if (selection == 'N') {
            if (current_song != playlist.end()) {
                current_song++;
                if (current_song == playlist.end()) {
                    std::cout << "Reached the end of the playlist" << std::endl;
                    current_song--;
                } else {
                    play_current_song(*current_song);
                }
            } else {
                std::cout << "No songs in playlist" << std::endl;
            }
        } else if (selection == 'P') {
            if (current_song != playlist.begin()) {
                current_song--;
                play_current_song(*current_song);
            } else {
                std::cout << "You are at the start of the playlist" << std::endl;
            }
        } else if (selection == 'A') {
            std::string name;
            std::string artist;
            int rating;      
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter song name: ";
            std::getline(std::cin, name);
            std::cout << "Enter song artist: ";
            std::getline(std::cin, artist);
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;
            playlist.insert(current_song, Song{name, artist, rating});
            play_current_song(*current_song);
        } else if (selection == 'L') {
            display_playlist(playlist, *current_song);
        } else if (selection == 'Q') {
            std::cout << "Thanks for listening!" << std::endl;
        } else {
            std::cout << "Unknown selection, please try again" << std::endl;
        }
    } while (selection != 'Q');
    return 0;
}