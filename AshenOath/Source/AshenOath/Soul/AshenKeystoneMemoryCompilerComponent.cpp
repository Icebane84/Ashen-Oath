// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenKeystoneMemoryCompilerComponent.h"

UAshenKeystoneMemoryCompilerComponent::UAshenKeystoneMemoryCompilerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CompiledMemories.Empty();
}
void UAshenKeystoneMemoryCompilerComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenKeystoneMemoryCompilerComponent::InvokeIntegration(FName MemoryID, EKeystoneInterpretiveLens Lens)
{
	FMemoryEchoRecord Record;
	Record.MemoryID = MemoryID;
	Record.SelectedLens = Lens;
	Record.bIsIntegrated = true;

	if (Lens == EKeystoneInterpretiveLens::Accountability)
	{
		Record.MemoryTitle = TEXT("Accountability: 'It was my weakness.'");
	}
	else if (Lens == EKeystoneInterpretiveLens::Grace)
	{
		Record.MemoryTitle = TEXT("Grace: 'We survived together.'");
	}
	else
	{
		Record.MemoryTitle = TEXT("Utility: 'Pain is a variable.'");
	}

	CompiledMemories.Add(Record);
	UE_LOG(LogTemp, Warning, TEXT("UAshenKeystoneMemoryCompilerComponent: COMPILED IDENTITY -> Memory [%s] integrated with lens: %s"),
		*MemoryID.ToString(), *Record.MemoryTitle);

	return true;
}
