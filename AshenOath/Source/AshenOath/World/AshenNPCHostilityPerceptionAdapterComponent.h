// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCHostilityPerceptionAdapterComponent.generated.h"

/**
 * UAshenNPCHostilityPerceptionAdapterComponent
 * Dynamically modifies NPC guard awareness radius based on Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCHostilityPerceptionAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCHostilityPerceptionAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetGuardPerceptionRadiusScalar() const { return GuardPerceptionRadiusScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float GuardPerceptionRadiusScalar = 1.0f;
};
