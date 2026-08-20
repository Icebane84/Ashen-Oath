// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossArenaEnvironmentalPostProcessAdapter.generated.h"

/**
 * UAshenBossArenaEnvironmentalPostProcessAdapter
 * Radiant golden god-rays in Phase 1, crackling crimson scripture runes in Phase 2, shattered void eclipse in Phase 3.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossArenaEnvironmentalPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossArenaEnvironmentalPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyBossArenaPhasePostProcess(uint8 PhaseIndex);
};
