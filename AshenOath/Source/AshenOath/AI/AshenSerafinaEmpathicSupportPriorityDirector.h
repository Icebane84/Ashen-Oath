// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSerafinaEmpathicSupportPriorityDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmpathicTargetSelectedSignature, AActor*, TargetCompanionToHeal, float, UrgencyScore);

/**
 * UAshenSerafinaEmpathicSupportPriorityDirector
 *
 * AI Director instructing Serafina to prioritize healing whichever companion has highest spiritual stain (PRS-001 Serafina Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSerafinaEmpathicSupportPriorityDirector : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAIDirector")
	AActor* SelectHighPriorityEmpathicTarget(TArray<AActor*> PartyMembers, float KaelenStainLevel, float GarrettStainLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAIDirector|Events")
	FOnEmpathicTargetSelectedSignature OnEmpathicTargetSelected;
};
