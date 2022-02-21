#include <vector>
#include <string>

using namespace::std;

class Phone{
    public:
        virtual void price() = 0;
        void ringtone(){
            cout << "ringing.." << endl;
        }
};

class Mobile:public Phone{
    public:
        void price(){
            cout << "they are exp" << endl;
        }
};

int ig_sum(int, int);
void printo(const char *asd);
void string_tester(void);
void jumble_game(void);
void vecto_demo(void);
void hangman(void);
void ref_demo(void);
void refDisplay(const vector<string>& vec);
void tictak();
void showBoard(const vector<char> &board);
int getInput(void);
void tictakv2(void);
void absChecker(void);