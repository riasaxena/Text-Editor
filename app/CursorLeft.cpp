#include "CursorLeft.hpp"
#include "EditorException.hpp"


void CursorLeft::execute(EditorModel& model) {
    model.moveCursorLeft();

    if (model.cursorColumn() < 1 ){
        model.moveCursorRight();
        
        throw EditorException("Already at beginning");
    }

}

void CursorLeft::undo(EditorModel& model){
    model.moveCursorRight();

}