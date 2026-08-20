// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenStanceBlendTreePhenotypeModulator.generated.h"

/**
 * UAshenStanceBlendTreePhenotypeModulator
 * Binds Kaelen's combat stance animation blend tree directly to FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStanceBlendTreePhenotypeModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenStanceBlendTreePhenotypeModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetStanceBlendWeight() const { return StanceBlendWeight; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float StanceBlendWeight = 0.5f;
};
