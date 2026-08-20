// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenAtmosphericSanityModifierVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuarySanityModifierAppliedSignature, float, SanityDrainMultiplier, bool, bIsSanctuarySafeZone);

/**
 * AAshenAtmosphericSanityModifierVolume
 *
 * Volume modifying player sanity drain rate based on atmospheric corruption.
 */
UCLASS()
class ASHENOATH_API AAshenAtmosphericSanityModifierVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenAtmosphericSanityModifierVolume();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanityVolume")
	void EvaluateSanityDrainModifier(float CorruptionLevelPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanityVolume|Events")
	FOnSanctuarySanityModifierAppliedSignature OnSanityModifierEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SanityVolume")
	float CurrentDrainMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityVolume")
	bool bIsSanctuarySafeZone = false;
};
