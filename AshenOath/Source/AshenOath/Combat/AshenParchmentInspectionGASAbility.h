// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenParchmentInspectionGASAbility.generated.h"

/**
 * UAshenParchmentInspectionGASAbility
 * Rest phase ability allowing Kaelen to review living journal notes and discuss tactical marginalia with companions.
 */
UCLASS()
class ASHENOATH_API UAshenParchmentInspectionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenParchmentInspectionGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Journal")
	bool InspectParchmentPage(AActor* InstigatorActor, FName BestiaryID);
};
