// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionBarkPhenotypeModulator.generated.h"

/**
 * UAshenCompanionBarkPhenotypeModulator
 *
 * Dynamically selects companion dialogue voice line tags based on derived FBehavioralProfile.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionBarkPhenotypeModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionBarkPhenotypeModulator();

	/** Selects dynamic voice bark tag based on profile */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FName SelectBarkTag(const FBehavioralProfile& Profile, FName BaseTag);
};
