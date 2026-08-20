// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTacticalPerkCompanionAIDirectorComponent.generated.h"

/**
 * UAshenTacticalPerkCompanionAIDirectorComponent
 * Modulates companion combat AI decision trees using unlocked frame perks (Garrett early weakpoint calls, Serafina auto-positioning for Sun-Pulse).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalPerkCompanionAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTacticalPerkCompanionAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void TriggerCompanionWeakpointCallout(FName CompanionID, FName MonsterID, bool bHasFramePerk);
};
