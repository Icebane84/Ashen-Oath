// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGarrettTripleComboFlankAdapterComponent.generated.h"

/**
 * UAshenGarrettTripleComboFlankAdapterComponent
 * Positions Garrett for 3-way synergy combo strikes based on Garrett Trust.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTripleComboFlankAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettTripleComboFlankAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companion")
	FVector ComputeFlankPosition(const FVector& TargetLocation, const FVector& KaelenLocation) const;

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companion")
	float GarrettTrustLevel = 0.5f;
};
