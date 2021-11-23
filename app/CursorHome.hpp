#include "Command.hpp"

class CursorHome : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    int cursorCol;
    int cursorLine;

};