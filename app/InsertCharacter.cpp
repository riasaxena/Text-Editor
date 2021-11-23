#include "InsertCharacter.hpp"



InsertCharacter::InsertCharacter(char c)
    : key{c}
{
}



void InsertCharacter::execute(EditorModel& model) {
    model.insertChar(key);
    

}

void InsertCharacter::undo(EditorModel& model){
    model.backspace(model.cursorLine());

}