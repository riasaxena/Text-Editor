// EditorModel.hpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// The EditorModel class implements the "model" of BooEdit.  In other words, its
// job is to maintain the underlying data -- the current lines of text, where
// the cursor is supposed to be, etc. -- and provide operations that allow the
// EditorView to access that data, along with basic operations that allow the
// various Command objects to make the necessary changes when they're executed
// or undone.
//
// The member functions already declared in the EditorModel class are absolutely
// necessary for EditorView to work, so they cannot be removed or have their
// declarations changed (though you may need to implement them; see
// EditorModel.cpp).
//
// You will absolutely need to implement additional member functions, because I
// haven't declared any functions that change the editor's data (e.g., by
// inserting characters, moving the cursor), which you'll need in order to
// implement the various Command objects.  You may also need additional member
// functions that access the editor's data in ways not provided here.
//
// When adding member functions, focus on adding "primitive" tools that you
// might be able to use in multiple command implementations.  Don't just add
// one member function for each command; that's tying your design to the
// specifics of the commands you chose, which makes it more difficult to
// change your mind about which commands you want without having a cascading
// effect here.
//
// The EditorModel class is unaware of the concept of "undo"; it is the job of
// the Command objects to know what they need to do in order to undo a Command.
// This may mean that your Command objects will need to store information in
// member variables after execute() is finished, so that information will still
// be available at the time undo() is called.
//
// Note that the notion of "line number" and "column number" here is one-based,
// not zero-based, which means that the top left corner of the file is line 1
// column 1.  You can handle this however you'd like inside of your class, but
// the rest of BooEdit expects Editor objects to take and return one-based
// line and column numbers.

#ifndef EDITORMODEL_HPP
#define EDITORMODEL_HPP

#include <string>
#include <vector>



class EditorModel
{
public:
    // Initializes the editor model.  Initially, the cursor is on
    // line 1 column 1 and there should be one empty line of text
    // in the editor.
    EditorModel();

    // Returns the line number where the cursor currently should reside.
    int cursorLine() const;

    // Returns the column number where the cursor currently should reside.
    int cursorColumn() const;

    // Returns the number of lines of text currently in the editor.
    int lineCount() const;

    // Returns the text on the given line number.
    const std::string& line(int lineNumber) const;

    // Returns the error message that should be displayed currently.
    const std::string& currentErrorMessage() const;

    // Sets the error message that should be displayed currently.
    void setErrorMessage(const std::string& errorMessage);

    // Clears the error message that should be displayed currently.
    void clearErrorMessage();

    //additional public member functions

    //move cursor to the right
    const void moveCursorRight();

    //move cursor left
    const void moveCursorLeft();

    //move cursor up
    const void moveCursorUp();

    //move cursor down
    const void moveCursorDown();

    //set the cursor to the first column
    const void setCursorFirstColumn();

    //set the cursor to the end of the line
    const void setCursorToEnd();

    //insert a character in the text editor next to the current position of the cursor
    const void insertChar(char c);

    //when using the backspace command moves the line up to the previous line
    void moveLineBack(int lineNumber);

    //delete one character from the left of the cursor
    const char backspace(int lineNumber);

    //add a line
    void addLine();

    //delete a line
    const std::string deleteLine();

    //manually set the position of the cursor
    void setPosition(int cursorCol, int cursorLine);

    //manually add a line of text to the text editor
    void addTextLine(std::string text, int cursorCol, int cursorLine);

   

private:
    // Write declarations for any private member variables here.
    // Additionally, you can add any private member functions you'd like.
    int cursorLineNum;
    int cursorColumnNum;
    int numLines;
    std::string errorMsg;
    std::vector <std::string> lines;
};



#endif // EDITORMODEL_HPP

