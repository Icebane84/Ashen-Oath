// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "AshenCompanionDisagreementPhenotypeIntegrator.generated.h"

/**
 * UAshenCompanionDisagreementPhenotypeIntegrator
 * Connects companion disagreement system to psychological imprint buffer.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDisagreementPhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionDisagreementPhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void RecordDisagreementImprint(FName CompanionID, float Severity);
};
