#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<time.h>
#include<cstdlib>
using namespace std;
void printMessage(string message,bool printTop=true,bool printBottom=true)
{
	if(printTop)
	{
		cout<<"+---------------------------------+"<<endl;
		cout<<"|";
	}
	else
	{
		cout<<"|";
	}
	bool front= true;
	for (int i=message.length();i<33;i++)
	{
		if(front)
		{
			message=" "+message;
		}
		else{
			message=message+" ";
		}
	front=!front;
	}
	cout<< message.c_str();
	if(printBottom)
	{
		cout<<"|"<<endl;
		cout<<"+---------------------------------+"<<endl;
	}
		else
	{
		cout<<"|"<<endl;
	}
}
void DrawHangman(int guessCount=0)
{
	if(guessCount>=1)
	{
		printMessage("|",false,false);
	}
	else
	{
		printMessage("",false,false);
	}
	if(guessCount>=2)
	{
		printMessage("|",false,false);
	}
	else
	{
		printMessage("",false,false);
	}
	if(guessCount>=3)
	{
		printMessage("O",false,false);
	}
	else
	{
		printMessage("",false,false);
	}
	if(guessCount==4)
	{
		printMessage("/  ",false,false);
	}
		if(guessCount==5)
	{
		printMessage("/| ",false,false);
	}
		if(guessCount>=6)
	{
		printMessage("/|\\",false,false);
	}
	else
	{
		printMessage("",false,false);	
	}
		if(guessCount>=7)
	{
		printMessage("|",false,false);
	}
	else
	{
		printMessage("",false,false);
	}
	if(guessCount==8)
	{
		printMessage("/ ",false,false);
	}
	if(guessCount>=9)
	{
		printMessage("/ \\",false,false);
	}
	
}
void printLetters(string input,char from,char to)
{
	string s;
	for(char i=from;i<=to;i++)
	{
		if(input.find(i) == string::npos)
		{
				s += i;
			s += " ";
		}
		else
		{
				s+="  ";
		}
		}
		printMessage(s,false,false);
	}
void printAvailableLetters(string taken)
	{
	printMessage("AVAILABLE LETTERS");
	printLetters(taken,'A','M');
	printLetters(taken,'N','Z');	
	}
	bool PrintWordandCheckWin(string word,string guessed)
	{
	bool won=true;
	string s;
	for(int i=0;i<word.length();i++)
	{
		if(guessed.find(word[i])==string::npos)
		{
			won=false;
			s+="_ ";
		}
		else
		{
			s+=word[i];
			s+=" ";
		}
		}
		printMessage(s,false,true);	
		return won;
	}
	string LoadRandomWord(string path)
	{
		int lineCount=0;
		string word;
		vector<string> v;
		ifstream reader(path.c_str());
		if(reader.is_open())
		{
			while(std::getline(reader,word))
			v.push_back(word);
			
			int randomline=rand() % v.size();
			
			word=v.at(randomline);
			reader.close();
		}
		return word;
	}
		int TriesLeft(string word,string guessed)
	{
		int error=0;
		for(int i=0;i<guessed.length(); i++)
		{
			if(word.find(guessed[i]) == string::npos)
			error++;
		}
		return error;
	}
	
int main()
{
	srand(time(0));
	string guesses;
	string wordToGuess;
	wordToGuess=LoadRandomWord("words.txt");
int tries=0;
bool win=false;
do{
system("cls");
printMessage("HANGMAN");
DrawHangman(tries);
printAvailableLetters(guesses);
printMessage("GUESS THE WORD");
win=PrintWordandCheckWin(wordToGuess,guesses);

if(win)
{
break;	
}

char x;
cout<<"-->";cin>>x;

if(guesses.find(x) == string::npos)
guesses += x;

tries = TriesLeft(wordToGuess,guesses);
}
while(tries<10);
if(win)
{
	printMessage("YOU WON");
}
else
{
	printMessage("GAME OVER");
}
getchar();
	return 0;
}
