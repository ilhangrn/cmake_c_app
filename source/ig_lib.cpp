#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <list>
#include "ig_lib.h"

using namespace std;

int ig_sum(int a, int b)
{
    return a + b;
}

void printo(const char *asd)
{
    cout << asd << endl;
}

void string_tester(void)
{
    string word1 = "Game ";
    string word2 = "is over ";
    string word3("new");
    string word4(3, '!');
    string result = word1 + word2 + word3 + word4;
    cout << result << endl;
    cout << "char count is : " << result.size() << endl;
    cout << "char count is : " << result.length() << endl;
    cout << "first char is : " << result[0] << endl;
    result[0] = 'L';
    cout << "it is changed : " << result << endl;
    for (int i = 0; i < result.size(); i++)
        cout << "every piece " << i << " : " << result[i] << endl;
    cout << "find over : " << result.find("over") << endl;
    cout << "find egg : " << ((result.find("egg") != string::npos) ? "true" : "false") << endl;
    result.erase(3, 1); // pos and count
    cout << "some are erased : " << result << endl;
    result.erase(3); // pos, erases after it
    cout << "go on erase : " << result << endl;
    result.erase();
    if (result.empty())
        cout << "it is empty" << endl;
}

void jumble_game(void)
{
    enum fields
    {
        WORD,
        HINT,
        NUM_FIELDS
    }; // start from zero
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
        {
            {"wall", "it is tough"},
            {"glass", "broke it"},
            {"labor", "important"},
            {"perma", "is fake"},
            {"jumble", "just a game"}};
    srand(static_cast<unsigned int>(time(0)));
    int choise = (rand() % NUM_WORDS);
    string theWord = WORDS[choise][WORD];
    string theHint = WORDS[choise][HINT];
    string guess;
    cout << "your guess" << endl;
    cin >> guess;
    while ((guess != theWord) && (guess != "exit"))
    {
        if (guess == "hint")
            cout << theHint;
        else
            cout << "try again";
        cout << "next guess : ";
        cin >> guess;
    }
    cout << "Thanks life" << endl;
}

void vecto_demo(void)
{
    vector<string> inventory;
    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;
    inventory.push_back("sword");
    inventory.push_back("gun");
    cout << "you have size was : " << inventory.size() << endl;
    inventory[0] = "axe";
    inventory.push_back("shield");
    inventory.push_back("smoke");
    for (int i = 0; i < inventory.size(); i++)
        cout << inventory[i] << " , ";
    cout << endl
         << "inv by iter : ";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    myIterator = inventory.begin();
    *myIterator = "big stone";

    cout << endl
         << "you changed first weapon : ";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << " , ";
    cout << endl;

    inventory.insert(inventory.begin(), "row");
    cout << endl
         << "find one more weapon : ";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << " , ";
    cout << endl;

    inventory.erase(inventory.begin() + 2);
    cout << endl
         << "losing some : ";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << " , ";
    cout << endl;

    inventory.pop_back();
    cout << "your cigarets is out" << endl;

    for (int i = 0; i < inventory.size(); i++)
        cout << inventory[i] << " , ";
    cout << endl;

    inventory.clear();
    cout << "they are stolen" << endl;
    if (inventory.empty())
        cout << "there is nothing" << endl;

    vector<int> pocket(10, 1);
    int poc_size = pocket.size();
    for (int i = 0; i < poc_size; i++)
        pocket.push_back(rand() % 10);
    cout << "in pocket: ";
    for (int i = 0; i < pocket.size(); i++)
        cout << pocket[i] << ",";
    cout << endl;

    vector<int>::const_iterator poc_iter;
    int find_money = 0;
    cout << "what do you want to find in your pocket:" << endl;
    // cin >> find_money;
    find_money = 5;
    poc_iter = find(pocket.begin(), pocket.end(), find_money);
    if (poc_iter != pocket.end())
        cout << "you got the money" << endl;
    else
        cout << "you don't have this" << endl;

    sort(pocket.begin(), pocket.end());
    for (poc_iter = pocket.begin(); poc_iter != pocket.end(); ++poc_iter)
        cout << *poc_iter << ",";
    cout << endl;

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(pocket.begin(), pocket.end());
    for (poc_iter = pocket.begin(); poc_iter != pocket.end(); ++poc_iter)
        cout << *poc_iter << ",";
    cout << endl;

    string wordi = "merhaba neler oldu";
    random_shuffle(wordi.begin(), wordi.end());
    cout << wordi << endl;

    cout << "pocket size :" << pocket.size() << endl;
    cout << "pocket cap :" << pocket.capacity() << endl;

    pocket.push_back(12);

    cout << "pocket pushed size :" << pocket.size() << endl;
    cout << "pocket pushed cap :" << pocket.capacity() << endl;

    pocket.reserve(45);

    cout << "pocket res size :" << pocket.size() << endl;
    cout << "pocket res cap :" << pocket.capacity() << endl;
}

void hangman(void)
{
    cout << "hanging.." << endl
         << endl;
    vector<string> words;
    vector<string>::const_iterator wordIter;
    words.push_back("mankind");
    words.push_back("human");
    words.push_back("solitude");
    words.push_back("worry");
    words.push_back("letter");
    words.push_back("mangetic");
    words.push_back("learn");
    words.push_back("bookworm");
    words.push_back("academy");
    srand(static_cast<unsigned int>(time(0)));
    for (wordIter = words.begin(); wordIter != words.end(); ++wordIter)
        cout << *wordIter << endl;

    int randIndex = (rand() % words.size());
    string secret = words[randIndex];
    string secretBack = secret;
    int totalGuessRight = 10;
    int guessCount = 0;
    bool wordFound = false;
    int remainingRight = 10;
    int letterCount = secret.size();
    char letterGuess;

    string print_stars = string(letterCount, '*');

    while ((wordFound == false) && (remainingRight != 0))
    {
        cout << "remaining guess count : " << remainingRight << endl;
        cout << print_stars << endl;
        cout << "guess it : ";
        cin >> letterGuess;
        int letterIndex = 0;
        do
        {
            letterIndex = secret.find(letterGuess);
            if (letterIndex != string::npos)
            {
                cout << "nice! you found " << letterGuess << endl;
                secret[letterIndex] = '*';
                print_stars[letterIndex] = letterGuess;
            }
        } while (letterIndex != string::npos);

        if (print_stars.find('*') == string::npos)
            wordFound = true;
        cout << print_stars << endl;
        remainingRight--;
    }
    if (wordFound)
        cout << "Congrats you found : ";
    else
        cout << "sorry it was : ";
    cout << secretBack << endl;
}

void ref_demo(void)
{
    cout << "ref demo start" << endl;
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("gun");

    refDisplay(inventory);
}

void refDisplay(const vector<string> &vec)
{
    vector<string>::const_iterator myIter;
    for (myIter = vec.begin(); myIter != vec.end(); ++myIter)
        cout << *myIter << endl;
}

void tictak(void)
{
    vector<char> board(9, '*');
    vector<char> selectionBoard;
    vector<int> pcSelList;
    vector<int> userSelList;
    int winnerList [8][3] = {   {0,1,2},
                                {3,4,5},
                                {6,7,8},
                                {0,3,6},
                                {1,4,7},
                                {2,5,8},
                                {0,4,8},
                                {2,4,6}};

    int userSelection;
    int pcSelection;
    for (char c = '1'; c <= '9'; c++)
        selectionBoard.push_back(c);
    cout << "game start" << endl;
    int roundCount = 0;
    bool winner = false;
    while (roundCount < 5 && !winner)
    {
        // showBoard(board);
        cout << endl;
        showBoard(selectionBoard);
        userSelection = getInput() - 1;
        if (board[userSelection] == '*')
        {
            board[userSelection] = 'X';
            selectionBoard[userSelection] = 'X';
            userSelList.push_back(userSelection);
            if(roundCount < 4){
                srand(static_cast<unsigned int>(time(0)));
                do
                {
                    pcSelection = rand() % 9;
                } while (board[pcSelection] != '*');
                cout << "pc move 'O' to " << pcSelection + 1 << endl;
                board[pcSelection] = 'O';
                selectionBoard[pcSelection] = 'O';
                pcSelList.push_back(pcSelection);
            }
            roundCount++;
        }
        else
            cout << "not available, try again!" << endl;
        if(roundCount > 2){
            for(int i = 0 ; i < 8; i++){
                int userScore = 0;
                int pcScore = 0;
                for(int j = 0 ; j < 3; j++){
                    if(find(userSelList.begin(), userSelList.end(), winnerList[i][j]) != userSelList.end())
                        userScore++;
                    if(find(pcSelList.begin(), pcSelList.end(), winnerList[i][j]) != pcSelList.end())
                        pcScore++;
                }
                if(userScore == 3){
                    cout << "USER WINS" << endl;
                    winner = true;
                    break;
                }
                    
                else if(pcScore == 3){
                    winner = true;
                    cout << "PC WINS" << endl;
                    break;
                }  
            }
        }
    }
    cout << "end!" << endl;
}

void showBoard(const vector<char> &board)
{
    vector<char>::const_iterator myIter;
    int elCount = 0;
    cout << " | ";
    for (myIter = board.begin(); myIter != board.end(); ++myIter)
    {
        cout << *myIter << " | ";
        elCount++;
        if (elCount % 3 == 0)
        {
            cout << endl
                 << " ";
            for (int i = 0; i < 3; i++)
                cout << "----";
            if (elCount != 9)
                cout << endl
                     << " | ";
            else
                cout << endl;
        }
    }
}

int getInput(void)
{
    int inp;
    cout << "pick a place : ";
    cin >> inp;
    return inp;
}

void tictakv2(void){
    cout << "tik tak v2 start" << endl;
    int blabla = 0;
}

void absChecker(){
    Mobile p1;
    p1.price();
    p1.ringtone();
}