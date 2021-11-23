#include "Command.hpp"

class CursorLeft : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

};