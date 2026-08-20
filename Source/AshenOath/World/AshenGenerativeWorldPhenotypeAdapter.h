// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeWorldPhenotypeAdapter.generated.h"

/**
 * UAshenGenerativeWorldPhenotypeAdapter
 *
 * Maps Corruption & Resolve to atmospheric weather tension and fog density.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeWorldPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeWorldPhenotypeAdapter();

	/** Updates world weather tension scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void UpdateWorldTension(const FSoulStateVector& SoulState);

	/** Returns current weather tension scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetWeatherTensionScalar() const { return WeatherTensionScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float WeatherTensionScalar = 0.0f;
};
