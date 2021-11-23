#include "CursorDown.hpp"
#include "EditorException.hpp"


void CursorDown::execute(EditorModel& model) {
    if(model.lineCount() == model.cursorLine()){
        throw EditorException("Already at the bottom");

    } else {
        model.moveCursorDown();
    }
}

void CursorDown::undo(EditorModel& model){
    model.moveCursorUp();

}