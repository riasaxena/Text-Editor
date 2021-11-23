#include "CursorEnd.hpp"


void CursorEnd::execute(EditorModel& model) {
    cursorCol = model.cursorColumn();
    cursorLine = model.cursorLine();
    model.setCursorToEnd();

}

void CursorEnd::undo(EditorModel& model){
    model.setPosition(cursorCol, cursorLine);

}