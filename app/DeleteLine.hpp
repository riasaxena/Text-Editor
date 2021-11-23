#include "Command.hpp"
class DeleteLine : public Command 
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    std::string text;
    int cursorCol;
    int cursorLine;

};