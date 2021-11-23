#include "DeleteLine.hpp"


void DeleteLine::execute(EditorModel& model) {
    cursorCol = model.cursorColumn();
    cursorLine = model.cursorLine();
    text = model.deleteLine();
}

void DeleteLine::undo(EditorModel& model){
    model.addTextLine(text, cursorCol, cursorLine);
    model.setPosition(cursorCol, cursorLine);

}