// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGarrettRelationalPhenotypeAdapter.generated.h"

/**
 * UAshenGarrettRelationalPhenotypeAdapter
 *
 * Maps GarrettTrust & Isolation to Garrett's AI formation distance and flank support frequency.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettRelationalPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettRelationalPhenotypeAdapter();

	/** Updates Garrett's formation distance from trust and isolation */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void UpdateGarrettBehavior(float GarrettTrust, float Isolation);

	/** Returns Garrett formation distance scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetFormationDistanceScalar() const { return FormationDistanceScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float FormationDistanceScalar = 1.0f;
};
