// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticHitStaggerDurationModulator.generated.h"

/**
 * UAshenDiegeticHitStaggerDurationModulator
 * Modulates player hit stagger recovery speed based on Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticHitStaggerDurationModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticHitStaggerDurationModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetStaggerDurationScalar() const { return StaggerDurationScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float StaggerDurationScalar = 1.0f;
};
