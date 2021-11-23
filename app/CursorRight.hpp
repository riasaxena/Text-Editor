#include "Command.hpp"

class CursorRight : public Command 
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

};