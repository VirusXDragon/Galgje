#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
    if (printTop)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();

    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}
void DrawHangman(int guessCount = 0)
{
    if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 4)
        PrintMessage("/  ", false, false);

    if (guessCount == 5)
        PrintMessage("/| ", false, false);

    if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 8)
        PrintMessage("/", false, false);

    if (guessCount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}
void PrintLetters(string input, char from, char to)
{
    string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);

}

bool PrintWordAndCheckWin(string word, string guessed)
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}

void PrintAvailableLetters(string taken)
{
    PrintMessage("Available letters");
    PrintLetters(taken, 'a', 'm');
    PrintLetters(taken, 'n', 'z');
}

string LoadRandomWord() {
    string returnValue = "";

    srand(time(NULL));
    string words[20] = {"school","life","dragon","brain","brawn","experimental","lifeless","supercalifragilisticoespialidoso","mansion","gladiator","fantasy","lion","goblin","query","anime","omaewamoushindeiru","generations","minecraft","mages","robots"};
    string *ptrwords = words;

    returnValue = ptrwords[(rand() % 20)];
    
    return returnValue;

}


int TriesLeft(string word, string guessed)
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}
int keuzemenu(){
    int keuze;
    cout << "1 cpu or 2 player\n";
    cin >> keuze;
    return keuze;
}

string zelfwoord() {
    string word = "";
    cout << "bedenk een woord\n";
    cin >> word;
    return word;
}

int playagain() {

    int x;
    cout << "nog een keer spelen.\n";
    cout << "kies 1 voor nog een keer spelen of kies 2 om te stoppen\n";
    cin >> x;

        return x;
}

//void wincheck(string words = "fiets") {
//    int a = 5;
//     a = words.length();
//    cout << "de lengte is: " << a;

    // system("pause");
   
    /*char array[a];
    strcpy(array, words.c_str());
    char array2[a];
    for (int x = 0; x < a; x++) {
        array2[x] = '_';
    }
}*/




int main() { 
   /* wincheck();*/
    string guesses;
    string wordToGuess;
   int x = keuzemenu();
   if (x == 1) wordToGuess = LoadRandomWord();
   if (x == 2) wordToGuess = zelfwoord();
    int tries = 0;
    bool win = false;
    do
    {
        system("cls");
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the word");
        win = PrintWordAndCheckWin(wordToGuess, guesses);

        
        
        if (win)
            break;

        char x;
        cout << ">"; cin >> x;

        if (guesses.find(x) == string::npos)
            guesses += x;

        tries = TriesLeft(wordToGuess, guesses);

    } while (tries < 10);

    if (win)
        PrintMessage("YOU WON!");
    else
        PrintMessage("GAME OVER");
    system("pause");

    system("cls");

    int y = playagain();
    if (y == 1) main();
    if (y == 2) exit(0);

    
    getchar();
  
    return 0;
}