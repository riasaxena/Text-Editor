#include "Command.hpp"

class Backspace : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    int cursorCol;
    int cursorLine;
    char deletedChar;

};