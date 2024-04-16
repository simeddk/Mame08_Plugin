#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class TOYPLUGIN_API FButtonCommand : public TCommands<FButtonCommand>
{
public:
	FButtonCommand();
	~FButtonCommand();

protected:
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> LoadMeshID;
};
