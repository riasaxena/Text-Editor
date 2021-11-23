#include "Command.hpp"
class CursorUp : public Command 
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

};