// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "CursorHome.hpp"
#include "InsertCharacter.hpp"
#include "CursorEnd.hpp"
#include "Backspace.hpp"
#include "NewLine.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "DeleteLine.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            
            case 'O':
            {
                Command* right = new CursorRight();
                return Interaction::command(right);
            }

            case 'U':
            {
                Command* left = new CursorLeft();
                return Interaction::command(left);
                

            }
            case 'Y':
            {
                Command* home = new CursorHome();
                return Interaction::command(home);

            }
            case 'P':
            {
                Command* end = new CursorEnd();
                return Interaction::command(end);
            }
            case 'H':
            {
                Command* backspace = new Backspace();
                return Interaction::command(backspace);
            }
            case 'J':
            {
                Command* newLine = new NewLine();
                return Interaction::command(newLine);
            }
            case 'M':
            {
                Command* nl = new NewLine();
                return Interaction::command(nl);
            }
            case 'I':
            {
                Command* up = new CursorUp();
                return Interaction::command(up);
            }
            case 'K':
            {
                Command* down = new CursorDown();
                return Interaction::command(down);
            }
            case 'D':
            {
                Command* deleteLine = new DeleteLine();
                return Interaction::command(deleteLine);
            }
            case 'Z':
            {
                return Interaction::undo();
            }
            case 'A':
            {
                return Interaction::redo();
            }


            }

        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            Command* insert = new InsertCharacter(keypress.code());
            return Interaction::command(insert);
        }
    }
}

