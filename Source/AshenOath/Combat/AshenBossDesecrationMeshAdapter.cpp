// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBossDesecrationMeshAdapter.h"

UAshenBossDesecrationMeshAdapter::UAshenBossDesecrationMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	DesecrationVeinIntensity = 0.0f;
}
void UAshenBossDesecrationMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBossDesecrationMeshAdapter::UpdateBossDesecrationVisuals(EBossPhaseState Phase)
{
	switch (Phase)
	{
	case EBossPhaseState::Phase1_TacticalDuel:
		DesecrationVeinIntensity = 0.2f;
		break;
	case EBossPhaseState::Phase2_ChasmFracture:
		DesecrationVeinIntensity = 0.6f;
		break;
	case EBossPhaseState::Phase3_ApexCataclysm:
		DesecrationVeinIntensity = 1.0f;
		break;
	case EBossPhaseState::Phase_Defeated:
		DesecrationVeinIntensity = 0.0f;
		break;
	default:
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenBossDesecrationMeshAdapter: Boss Desecration Veins Intensity: %.2f (Phase %d)"),
		DesecrationVeinIntensity, static_cast<int32>(Phase));
}
