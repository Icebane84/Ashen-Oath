// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryBattlePostProcessAdapter.generated.h"

/**
 * UAshenMemoryBattlePostProcessAdapter
 * Mindscape desaturation, chromatic fringing, and golden flash of clarity upon psychic echo resolution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBattlePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryBattlePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyMemoryBattlePostProcess(float Intensity, bool bVictoryFlash);
};
