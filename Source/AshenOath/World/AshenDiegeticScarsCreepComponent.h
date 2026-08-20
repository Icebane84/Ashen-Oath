// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticScarsCreepComponent.generated.h"

/**
 * UAshenDiegeticScarsCreepComponent
 * Binds battle scars emissive and depth morphs to Resolve and Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticScarsCreepComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticScarsCreepComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetScarEmissiveIntensity() const { return ScarEmissiveIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float ScarEmissiveIntensity = 0.0f;
};
