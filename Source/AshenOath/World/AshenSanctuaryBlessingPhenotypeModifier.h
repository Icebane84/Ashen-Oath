// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSanctuaryBlessingPhenotypeModifier.generated.h"

/**
 * UAshenSanctuaryBlessingPhenotypeModifier
 * Modulates Sanctuary Blessing potency based on FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryBlessingPhenotypeModifier : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryBlessingPhenotypeModifier();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanctuary")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanctuary")
	float GetBlessingPotency() const { return BlessingPotency; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Sanctuary")
	float BlessingPotency = 1.0f;
};
