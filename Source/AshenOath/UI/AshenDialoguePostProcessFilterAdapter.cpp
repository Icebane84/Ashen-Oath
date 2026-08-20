// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenDialoguePostProcessFilterAdapter.h"

UAshenDialoguePostProcessFilterAdapter::UAshenDialoguePostProcessFilterAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDialoguePostProcessFilterAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenDialoguePostProcessFilterAdapter::ApplyEmpathicDialogueVignette(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDialoguePostProcessFilterAdapter: Empathic dialogue vignette set to %s"), bActive ? TEXT("ACTIVE") : TEXT("INACTIVE"));
}
