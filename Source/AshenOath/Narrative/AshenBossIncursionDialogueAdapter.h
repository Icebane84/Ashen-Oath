// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossIncursionDialogueAdapter.generated.h"

/**
 * UAshenBossIncursionDialogueAdapter
 * Manages companion combat dialogue and boss confrontation barks during phase transitions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossIncursionDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossIncursionDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerPhaseShiftBark(EBossPhaseState Phase);
};
