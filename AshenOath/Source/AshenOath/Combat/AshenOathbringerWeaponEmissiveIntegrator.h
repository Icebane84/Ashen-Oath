// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenOathbringerWeaponEmissiveIntegrator.generated.h"

/**
 * UAshenOathbringerWeaponEmissiveIntegrator
 * Connects Oathbringer sword emissive resonance to Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerWeaponEmissiveIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerWeaponEmissiveIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetOathbringerEmissiveScalar() const { return OathbringerEmissiveScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float OathbringerEmissiveScalar = 0.0f;
};
