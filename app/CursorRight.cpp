#include "CursorRight.hpp"
#include "EditorException.hpp"


void CursorRight::execute(EditorModel& model) {
    if(model.cursorColumn() == ((model.line(model.cursorLine())).size() + 1)){
        throw EditorException("Already at the end");

    } else {
        model.moveCursorRight();
    }
}

void CursorRight::undo(EditorModel& model){
    model.moveCursorLeft();

}