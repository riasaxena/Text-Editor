#include "Command.hpp"


class InsertCharacter : public Command 
{
public:
    InsertCharacter(char c);
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    char key;

};