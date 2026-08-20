// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionIdleDialogueSelectorComponent.generated.h"

/**
 * UAshenCompanionIdleDialogueSelectorComponent
 * Selects companion resting barks based on party trust and current region.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionIdleDialogueSelectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionIdleDialogueSelectorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FName SelectCompanionIdleBark(const FSoulStateVector& StateVector, float CompanionTrust, const FString& RegionID);
};
