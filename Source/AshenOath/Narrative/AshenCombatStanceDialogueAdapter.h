// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStanceDialogueAdapter.generated.h"

/**
 * UAshenCombatStanceDialogueAdapter
 * Triggers companion tactical voice barks during high-intensity stance switches and flank executions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatStanceDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCombatStanceDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerStanceCombatBark(FName CompanionID, ECombatStance Stance, bool bFlankHit);
};
