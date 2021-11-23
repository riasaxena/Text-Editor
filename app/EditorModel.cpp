// EditorModel.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "BooEditLog.hpp"


EditorModel::EditorModel()
    :cursorLineNum{1}, cursorColumnNum{1}, numLines{1}, errorMsg{""}
{
    lines.push_back("");
}


int EditorModel::cursorLine() const
{
    return cursorLineNum;
}


int EditorModel::cursorColumn() const
{
    return cursorColumnNum;
}


int EditorModel::lineCount() const
{
    return numLines;
    
}


const std::string& EditorModel::line(int lineNumber) const
{  

    return lines.at(lineNumber-1);
    
    
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMsg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    errorMsg = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errorMsg = "";


}

//additional member functions
const void EditorModel::moveCursorRight(){
    cursorColumnNum++;
}


const void EditorModel::moveCursorLeft(){
    cursorColumnNum--;
}

  
const void EditorModel::moveCursorUp(){
    if(cursorColumnNum > lines.at(cursorLineNum-2).size()){
        cursorColumnNum = lines.at(cursorLineNum-2).size() + 1;
    }
    cursorLineNum--;
}

 
const void EditorModel::moveCursorDown(){
    if(cursorColumnNum > lines.at(cursorLineNum).size()){
        cursorColumnNum = lines.at(cursorLineNum).size() + 1;;
    }
    cursorLineNum++;
}

const void EditorModel::setCursorFirstColumn(){
    cursorColumnNum = 1;
}

const void EditorModel::setCursorToEnd(){
    cursorColumnNum = line(cursorLineNum).size() + 1;
}

const void EditorModel::insertChar(char c){
    //take look at this
    if(cursorColumnNum == 1){
        (lines.at(cursorLineNum-1)).insert(0, 1, c);

    } else {
        (lines.at(cursorLineNum-1)).insert(cursorColumnNum-1,1, c);
    }
    
    cursorColumnNum++;
    

}


void EditorModel::moveLineBack(int lineNumber){

    int x = lines.at(cursorLineNum-2).size();
    lines.at(cursorLineNum-2) += lines.at(cursorLineNum-1);
    lines.erase(lines.begin() + cursorLineNum-1);
    cursorLineNum--;
    cursorColumnNum = x +1;
    numLines--;

}

const char EditorModel::backspace(int lineNumber){
    
    char a = lines.at(cursorLineNum-1).at(cursorColumnNum-2);
    lines.at(cursorLineNum-1).erase(cursorColumnNum-2, 1);
    cursorColumnNum--;
    return a;
    
}

void EditorModel::addLine(){
    numLines++;
    lines.push_back("");
    

    if(!(cursorColumnNum == lines.at(cursorLineNum-1).size()+1)){
        lines.insert(lines.begin() + cursorLineNum, 1,  (lines.at(cursorLineNum-1).substr(cursorColumnNum-1)));
        lines.at(cursorLineNum-1).erase(cursorColumnNum-1,lines.at(cursorLineNum-1).size());
    }
    cursorLineNum++;
    cursorColumnNum = 1;
    
}

const std::string EditorModel::deleteLine(){
    std::string s;
    if(numLines == 1){
        s = lines.at(0);
        lines.at(0) = "";
        cursorColumnNum = 1;
    } else {
        s = lines.at(cursorLineNum-1);
        if(lines.at(cursorLineNum-1).size() > lines.at(cursorLineNum-2).size()){
            lines.erase(lines.begin() + cursorLineNum-1);
            cursorColumnNum = lines.at(cursorLineNum-2).size()+1;
            
        } else {
            lines.erase(lines.begin() + cursorLineNum-1);
        }
        cursorLineNum--;
        numLines--;
        
    }
    return s;
}

void EditorModel::setPosition(int cursorCol, int cursorLine){
    cursorColumnNum = cursorCol;
    cursorLineNum = cursorLine;
}

void EditorModel::addTextLine(std::string text, int cursorCol, int cursorLine){

    if(cursorLine == 1){
        lines.insert(lines.begin(), text);
    } else {
        lines.push_back("");
        numLines++;
        lines.insert(lines.begin() + cursorLine-1, text);
    }
    
}




