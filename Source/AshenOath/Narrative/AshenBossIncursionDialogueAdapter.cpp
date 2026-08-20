// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenBossIncursionDialogueAdapter.h"

UAshenBossIncursionDialogueAdapter::UAshenBossIncursionDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossIncursionDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBossIncursionDialogueAdapter::TriggerPhaseShiftBark(EBossPhaseState Phase)
{
	switch (Phase)
	{
	case EBossPhaseState::Phase2_ChasmFracture:
		UE_LOG(LogTemp, Warning, TEXT("UAshenBossIncursionDialogueAdapter: Serafina: \"The ground is giving way! I'm weaving a bridge—move!\""));
		break;
	case EBossPhaseState::Phase3_ApexCataclysm:
		UE_LOG(LogTemp, Error, TEXT("UAshenBossIncursionDialogueAdapter: Garrett: \"Brace yourselves! The entire chamber is collapsing into the void!\""));
		break;
	case EBossPhaseState::Phase_StaggeredVulnerable:
		UE_LOG(LogTemp, Warning, TEXT("UAshenBossIncursionDialogueAdapter: Kaelen: \"Its guard is broken! Strike together—NOW!\""));
		break;
	case EBossPhaseState::Phase_Defeated:
		UE_LOG(LogTemp, Log, TEXT("UAshenBossIncursionDialogueAdapter: Serafina: \"It's over... the tether holds.\""));
		break;
	default:
		break;
	}
}
