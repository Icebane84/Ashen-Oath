// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGASAttributeCostModulatorComponent.generated.h"

/**
 * UAshenGASAttributeCostModulatorComponent
 * Modulates stamina ability resource cost based on Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASAttributeCostModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASAttributeCostModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetStaminaCostMultiplier() const { return StaminaCostMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float StaminaCostMultiplier = 1.0f;
};
