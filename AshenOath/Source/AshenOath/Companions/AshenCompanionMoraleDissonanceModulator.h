// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenCompanionMoraleDissonanceModulator.generated.h"

/**
 * UAshenCompanionMoraleDissonanceModulator
 * Modulates companion attack aggressiveness based on party morale state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionMoraleDissonanceModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionMoraleDissonanceModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetCompanionAggressionScalar() const { return CompanionAggressionScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float CompanionAggressionScalar = 1.0f;
};
