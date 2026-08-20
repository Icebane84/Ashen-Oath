// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGASAttributeRegenRateModulatorComponent.generated.h"

/**
 * UAshenGASAttributeRegenRateModulatorComponent
 * Modulates health and stamina regen speed based on IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASAttributeRegenRateModulatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASAttributeRegenRateModulatorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetRegenRateMultiplier() const { return RegenRateMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float RegenRateMultiplier = 1.0f;
};
