#include "CursorHome.hpp"


void CursorHome::execute(EditorModel& model) {
    cursorCol = model.cursorColumn();
    cursorLine = model.cursorLine();
    model.setCursorFirstColumn();

}

void CursorHome::undo(EditorModel& model){
    model.setPosition(cursorCol, cursorLine);

}