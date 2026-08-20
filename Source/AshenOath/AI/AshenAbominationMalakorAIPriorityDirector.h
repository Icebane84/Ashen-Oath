// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenAbominationMalakorAIPriorityDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMalakorAttackSelectedSignature, FName, SelectedAttackTag, float, AggressionRating);

/**
 * UAshenAbominationMalakorAIPriorityDirector
 *
 * AI Director driving Malakor's aggressive attack selection against Kaelen's Aegis stance (Where Light Fades Act 01).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenAbominationMalakorAIPriorityDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MalakorAI")
	FName SelectMalakorNextAttack(float KaelenPosturePercent, bool bIsAegisGuarding);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MalakorAI|Events")
	FOnMalakorAttackSelectedSignature OnAttackSelected;
};
