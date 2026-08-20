// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenEcosystemSaveGameAdapter.generated.h"

/**
 * UAshenEcosystemSaveGameAdapter
 * Serializes mastered bestiary archetypes, historical TAM-001 consistency scores, and Star-Strider sanctuary encounters to SaveGame.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEcosystemSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEcosystemSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveEcosystemMetrics(float HistoricalConsistency, int32 MasteredBossesCount, bool bStarStriderDiscovered);
};
