// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenGloomwoodStabilizationDirectorComponent.generated.h"

/**
 * UAshenGloomwoodStabilizationDirectorComponent
 * 
 * Coordinates Garrett's Gloomwood Sap Needle interventions, audio pitch depression (-12 semitones), and chemical bloodstream cooling.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGloomwoodStabilizationDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGloomwoodStabilizationDirectorComponent();

	/** Triggers needle injection and returns pitch depression semitones */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Blade|Gloomwood")
	float AdministerGloomwoodNeedle(EGloomwoodStabilizationTier Tier);

	/** Evaluates audio pitch offset in semitones [0.0 to -18.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Gloomwood")
	float EvaluateAudioPitchSemitones(bool bIsFrozen, EGloomwoodStabilizationTier Tier) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Gloomwood")
	bool CanAdministerNeedle() const { return NeedleInventoryCount > 0; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Blade|Gloomwood")
	int32 NeedleInventoryCount = 3;
};
