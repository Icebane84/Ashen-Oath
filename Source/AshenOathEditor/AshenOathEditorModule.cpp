// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenOathEditorModule.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogAshenOathEditor, Log, All);

void FAshenOathEditorModule::StartupModule()
{
	UE_LOG(LogAshenOathEditor, Log, TEXT("AshenOathEditor Module Started Successfully. Tooling suite online."));
}

void FAshenOathEditorModule::ShutdownModule()
{
	UE_LOG(LogAshenOathEditor, Log, TEXT("AshenOathEditor Module Shutdown."));
}

IMPLEMENT_MODULE(FAshenOathEditorModule, AshenOathEditor)
