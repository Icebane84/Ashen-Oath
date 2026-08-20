// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenLivingParchmentInkModulator.generated.h"

/**
 * UAshenLivingParchmentInkModulator
 * Modulates parchment shader scalar parameters: burnt soot vignette, ink bleed intensity, and dried tear water stain opacity based on journal perspective.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingParchmentInkModulator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingParchmentInkModulator();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	float CalculateSootVignette(EJournalPerspectiveType Perspective) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	float CalculateTearStainOpacity(EJournalPerspectiveType Perspective) const;
};
