#include "ButtonCommand.h"

FButtonCommand::FButtonCommand()
	: TCommands()
{
}

FButtonCommand::~FButtonCommand()
{
}

void FButtonCommand::RegisterCommands()
{
#define LOCTEXT_NAMESPACE ""
	UI_COMMAND(LoadMeshID, "LoadMesh", "Load Mesh Data", EUserInterfaceActionType::Button, FInputChord());
#undef  LOCTEXT_NAMESPACE
}