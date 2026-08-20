// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAdvancedCombatTrustAdapter.generated.h"

/**
 * UAshenAdvancedCombatTrustAdapter
 * Companions grant +0.05 trust approval when witnessing successful frame-accurate parry counters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAdvancedCombatTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAdvancedCombatTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float AwardParryTrustBonus(FName CompanionID);
};
