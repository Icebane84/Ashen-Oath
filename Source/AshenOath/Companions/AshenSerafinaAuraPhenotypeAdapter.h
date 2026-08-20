// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSerafinaAuraPhenotypeAdapter.generated.h"

/**
 * UAshenSerafinaAuraPhenotypeAdapter
 * Connects Serafina protective aura shielding frequency to SerafinaTrust and Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAuraPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAuraPhenotypeAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetShieldFrequency() const { return ShieldFrequency; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float ShieldFrequency = 1.0f;
};
