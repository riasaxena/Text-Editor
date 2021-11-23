#include "Command.hpp"

class NewLine : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

};