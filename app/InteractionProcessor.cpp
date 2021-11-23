// InteractionProcessor.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <vector>


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();
    std::vector <Command*> commands;
    std::vector <Command*> redo;
    
  

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {

            for(Command* c: commands){
                delete c;
            }

            for(Command* c: redo){
                delete c;
            }
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if(commands.size() > 0 ){
                commands.at(commands.size()-1)->undo(model);
                redo.push_back(commands.at(commands.size()-1));
                commands.pop_back();
                view.refresh();

            }
            
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if(redo.size() > 0){
                redo.at(redo.size()-1)->execute(model);
                commands.push_back(redo.at(redo.size()-1));
                redo.pop_back();
                view.refresh();
            }
            
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
                
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }
            commands.push_back(command);
            view.refresh();

            
        }
    }
}

