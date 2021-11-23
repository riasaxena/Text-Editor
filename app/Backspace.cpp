#include "Backspace.hpp"
#include "EditorException.hpp"


void Backspace::execute(EditorModel& model) {
    if (model.cursorColumn() == 1 && model.cursorLine() == 1){
        throw EditorException("Already at beginning");
    } else {
        cursorCol = model.cursorColumn();
        cursorLine = model.cursorLine();
        if(model.cursorColumn() == 1){
            model.moveLineBack(model.cursorLine());
        } else {
            deletedChar = model.backspace(model.cursorLine());
        }
    } 

}

void Backspace::undo(EditorModel& model){
    if(cursorCol == 1){
        model.addLine();
    }else{
        model.insertChar(deletedChar);

    }


}