#include "NewLine.hpp"


void NewLine::execute(EditorModel& model) {
    model.addLine();

}

void NewLine::undo(EditorModel& model){
    model.moveLineBack(model.cursorLine());

}