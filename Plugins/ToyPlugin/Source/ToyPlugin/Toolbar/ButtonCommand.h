#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class TOYPLUGIN_API FButtonCommand : public TCommands<FButtonCommand>
{
public:
	FButtonCommand();
	~FButtonCommand();

public:
	virtual void RegisterCommands() override;

private:
	void OnClicked();

public:
	TSharedPtr<FUICommandInfo> LoadMeshID;
	TSharedPtr<FUICommandList> LoadMeshCommand;
};
