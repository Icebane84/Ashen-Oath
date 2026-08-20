// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCartographicDialogueAdapter.h"

UAshenCartographicDialogueAdapter::UAshenCartographicDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCartographicDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCartographicDialogueAdapter::TriggerLandmarkBark(ECartographicPinType PinType)
{
	switch (PinType)
	{
	case ECartographicPinType::SanctuaryCampfire:
		UE_LOG(LogTemp, Warning, TEXT("UAshenCartographicDialogueAdapter: Serafina: \"A hearthstone ember burns ahead. We can rest here.\""));
		break;
	case ECartographicPinType::MemoryEcho:
		UE_LOG(LogTemp, Warning, TEXT("UAshenCartographicDialogueAdapter: Kaelen: \"I recognize this ruin... the past refuses to stay buried.\""));
		break;
	case ECartographicPinType::AlchemicalHarvest:
		UE_LOG(LogTemp, Log, TEXT("UAshenCartographicDialogueAdapter: Garrett: \"Ghostbloom cluster spotted. Cover me while I harvest.\""));
		break;
	case ECartographicPinType::AbyssalRift:
		UE_LOG(LogTemp, Error, TEXT("UAshenCartographicDialogueAdapter: Serafina: \"Careful! The compass needle is spinning—Null-Zone rift nearby!\""));
		break;
	}
}
