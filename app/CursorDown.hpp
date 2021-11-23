#include "Command.hpp"
class CursorDown : public Command 
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

};