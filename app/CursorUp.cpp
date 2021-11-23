#include "CursorUp.hpp"
#include "EditorException.hpp"


void CursorUp::execute(EditorModel& model) {
    if(model.cursorLine() == 1){
        throw EditorException("Already at the top");

    } else {
        model.moveCursorUp();
    }
}

void CursorUp::undo(EditorModel& model){
    model.moveCursorDown();

}