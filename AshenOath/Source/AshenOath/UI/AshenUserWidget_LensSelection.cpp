// AshenUserWidget_LensSelection.cpp
// Copyright Ashen Oath. All rights reserved.
#include "AshenUserWidget_LensSelection.h"
#include "AshenSoulConstellationSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UAshenUserWidget_LensSelection::NativeConstruct()
{
	Super::NativeConstruct();

	// Pre-fill selection with currently published PrimaryLens from Kernel
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				CurrentSelectedLens = Kernel->GetStateVector().PrimaryLens;
			}
		}
	}
}

void UAshenUserWidget_LensSelection::SelectLensOption(EInterpretiveLens Lens)
{
	CurrentSelectedLens = Lens;
	OnLensOptionHovered(Lens);
}

void UAshenUserWidget_LensSelection::ConfirmLensSelection()
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				Kernel->FinalizeIntegration(CurrentSelectedLens);
			}
		}
	}

	OnLensConfirmed.Broadcast(CurrentSelectedLens);
	RemoveFromParent();
}
