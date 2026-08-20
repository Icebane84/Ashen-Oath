// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticMemoryBattleAudioComponent.generated.h"

/**
 * UAshenDiegeticMemoryBattleAudioComponent
 * Diegetic audio component modulating battle stingers and echo voices.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticMemoryBattleAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticMemoryBattleAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerMemoryBattleStinger(int32 BattlePhase);
};
