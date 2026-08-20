// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenAlchemicalDialogueAdapter.h"

UAshenAlchemicalDialogueAdapter::UAshenAlchemicalDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenAlchemicalDialogueAdapter::TriggerAlchemicalBark(EAlchemicalMatrixType Type)
{
	switch (Type)
	{
	case EAlchemicalMatrixType::BurningSteelOil:
		UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalDialogueAdapter: Garrett: \"Blades are hot. Let's crack some armor.\""));
		break;
	case EAlchemicalMatrixType::GloomwoodDampener:
		UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalDialogueAdapter: Garrett: \"Keep him still! This dampener will cool his blood!\""));
		break;
	case EAlchemicalMatrixType::GhostbloomFlashFlare:
		UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalDialogueAdapter: Garrett: \"Eyes shut! Flare's going up!\""));
		break;
	default:
		break;
	}
}
