#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToyPluginModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void AddToolBar(class FToolBarBuilder& InBuilder);

private:
	TSharedPtr<FExtender> Extender;
};