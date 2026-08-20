// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSerafinaDivineJudgmentAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDivineJudgmentExecutedSignature, AActor*, TargetEnemy, float, RadiantDamageDealt);

/**
 * UAshenSerafinaDivineJudgmentAbility
 *
 * Ability calling down radiant holy light beams onto corrupted targets (PRS-001 Serafina Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSerafinaDivineJudgmentAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAbilities")
	void ExecuteDivineJudgment(AActor* TargetEnemy, float BaseRadiantDamage = 250.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAbilities|Events")
	FOnDivineJudgmentExecutedSignature OnDivineJudgmentExecuted;
};
