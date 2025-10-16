#include <iostream> 
using namespace std;

class MediaPlayer { 
public:
    virtual ~MediaPlayer() = default;
    virtual void play(string audioType, string fileName) = 0;
}; 
 
class AdvancedMediaPlayer { 
public :
    virtual ~AdvancedMediaPlayer() = default;
    virtual void playVlc(string fileName) = 0;
    virtual void playMp4(string fileName) = 0;
}; 
 
class VlcPlayer : public AdvancedMediaPlayer { 
public:
    void playVlc(string fileName) override {
        cout << "Playing vlc file. Name : " + fileName << endl;
    }

    void playMp4(string fileName) override {}
}; 
 
class Mp4Player : public AdvancedMediaPlayer { 
public:
    void playVlc(string fileName) override {}

    void playMp4(string fileName) override {
        cout << "Playing mp4 file. Name : " + fileName << endl;
    }
}; 
 
class MediaAdapter : MediaPlayer { 
public:
    AdvancedMediaPlayer* advancedMusicPlayer = nullptr;

    explicit MediaAdapter(const string& audioType) {
        if (!audioType.compare("vlc")) {
            advancedMusicPlayer = new VlcPlayer();
        } else if (!audioType.compare("mp4")) {
            advancedMusicPlayer = new Mp4Player();
        }
    }
 
    void play(string audioType, string fileName) override {
        if (!audioType.compare("vlc")) {
            advancedMusicPlayer->playVlc(fileName);
        }
        else if (!audioType.compare("mp4")) {
            advancedMusicPlayer->playMp4(fileName);
        }
    }
}; 
 
class AudioPlayer : MediaPlayer {
public:
    MediaAdapter* mediaAdapter = nullptr;

    void play(string audioType, string fileName) override {
        if (!audioType.compare("mp3")) {
            cout << "Playing mp3 file. Name : " + fileName << endl;
        } else if (!audioType.compare("vlc") || !audioType.compare("mp4")) {
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, fileName);
        } else {
            cout << "Invalid media. : " + audioType + " format not supported" << endl;
        }
    };
};
 
int main() { 
    AudioPlayer* audioPlayer = new AudioPlayer();

    audioPlayer->play("mp3", "beyond the horizon.mp3");
    audioPlayer->play("mp4", "alone.mp4");
    audioPlayer->play("vlc", "far far away.vlc");
    audioPlayer->play("avi", "mind me.avi");

    return 0;
}
