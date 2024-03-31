#include <iostream>
#include <fstream>
#include <string>

class Songbook {
private:
    static const int MAX_SONGS = 200;
    int numSongs;
    std::string titles[MAX_SONGS];
    std::string artists[MAX_SONGS];
    std::string albums[MAX_SONGS];
    int releaseDays[MAX_SONGS];
    int releaseMonths[MAX_SONGS];
    int releaseYears[MAX_SONGS];

public:
    Songbook() : numSongs(0) {}

    void addSong(std::string title, std::string artist, std::string album, int day, int month, int year) {
        if (numSongs < MAX_SONGS) {
            titles[numSongs] = title;
            artists[numSongs] = artist;
            albums[numSongs] = album;
            releaseDays[numSongs] = day;
            releaseMonths[numSongs] = month;
            releaseYears[numSongs] = year;
            numSongs++;
        }
        else {
            std::cout << "�������� ����������" << std::endl;
        }
    }

    void modifySong(std::string title, std::string newTitle, std::string newArtist, std::string newAlbum, int newDay, int newMonth, int newYear) {
        for (int i = 0; i < numSongs; i++) {
            if (titles[i] == title) {
                titles[i] = newTitle;
                artists[i] = newArtist;
                albums[i] = newAlbum;
                releaseDays[i] = newDay;
                releaseMonths[i] = newMonth;
                releaseYears[i] = newYear;
                std::cout << "��������� ���������" << std::endl;
                return;
            }
        }
        std::cout << "����� �� �������" << std::endl;
    }

    void findSong(std::string title, std::string artist) {
        for (int i = 0; i < numSongs; i++) {
            if (titles[i] == title && artists[i] == artist) {
                std::cout << "����� �������:" << std::endl;
                std::cout << titles[i] << " ������������ " << artists[i] << std::endl;
                return;
            }
        }
        std::cout << "����� �� �������." << std::endl;
    }

    void displaySongsByArtist(std::string artist) {
        std::cout << "����� ����������� " << artist << ":" << std::endl;
        for (int i = 0; i < numSongs; i++) {
            if (artists[i] == artist) {
                std::cout << titles[i] << " ���������: " << artists[i] << ", ���� �������: " << releaseDays[i] << "/" << releaseMonths[i] << "/" << releaseYears[i] << std::endl;
            }
        }
    }

    int getNumSongs() {
        return numSongs;
    }

    void deleteSong(std::string title) {
        for (int i = 0; i < numSongs; i++) {
            if (titles[i] == title) {
                for (int j = i; j < numSongs - 1; j++) {
                    titles[j] = titles[j + 1];
                    artists[j] = artists[j + 1];
                    albums[j] = albums[j + 1];
                    releaseDays[j] = releaseDays[j + 1];
                    releaseMonths[j] = releaseMonths[j + 1];
                    releaseYears[j] = releaseYears[j + 1];
                }
                numSongs--;
                std::cout << "����� ������� �������." << std::endl;
                return;
            }
        }
        std::cout << "����� �� �������." << std::endl;
    }

    void saveToFile(std::string filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << numSongs << std::endl;
            for (int i = 0; i < numSongs; i++) {
                file << titles[i] << "|" << artists[i] << "|" << albums[i] << "|" << releaseDays[i] << "|" << releaseMonths[i] << "|" << releaseYears[i] << std::endl;
            }
            std::cout << "���������� �������." << std::endl;
            file.close();
        }
        else {
            std::cout << "���������� ������� ����" << std::endl;
        }
    }

    void loadFromFile(std::string filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> numSongs;
            file.ignore();
            for (int i = 0; i < numSongs; i++) {
                std::getline(file, titles[i], '|');
                std::getline(file, artists[i], '|');
                std::getline(file, albums[i], '|');
                file >> releaseDays[i] >> releaseMonths[i] >> releaseYears[i];
                file.ignore();
            }
            std::cout << "�������� ������ �������" << std::endl;
            file.close();
        }
        else {
            std::cout << "���������� ������� ����" << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Songbook mySongbook;

    mySongbook.addSong("����� 1", "����������� 1", "������ 1", 1, 1, 2023);
    mySongbook.addSong("����� 2", "����������� 2", "������ 2", 2, 2, 2024);

    mySongbook.displaySongsByArtist("����������� 1");
    mySongbook.findSong("����� 1", "����������� 1");

    mySongbook.saveToFile("songbook.txt");
    mySongbook.loadFromFile("songbook.txt");

    return 0;
}
