#include "ToyPlugin.h"
#include "LevelEditor.h"

#define LOCTEXT_NAMESPACE "FToyPluginModule"

void FToyPluginModule::StartupModule()
{
	UE_LOG(LogTemp, Error, TEXT("Startup Toy Plugin"));

	Extender = MakeShareable(new FExtender());

	
	FToolBarExtensionDelegate toolBarExtensionDelegate = FToolBarExtensionDelegate::CreateRaw(this, &FToyPluginModule::AddToolBar);
	
	Extender->AddToolBarExtension("Compile", EExtensionHook::Before, nullptr, toolBarExtensionDelegate);

	FLevelEditorModule& levelEditor =  FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	levelEditor.GetToolBarExtensibilityManager()->AddExtender()
}

void FToyPluginModule::ShutdownModule()
{
	UE_LOG(LogTemp, Error, TEXT("Shutdown Toy Plugin"));
}

void FToyPluginModule::AddToolBar(FToolBarBuilder& InBuilder)
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FToyPluginModule, ToyPlugin)