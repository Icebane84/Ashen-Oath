// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanityCorruptedVFXComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityVFXTriggeredSignature, bool, bLowSanityActive, float, SmokeDensity);

/**
 * UAshenSanityCorruptedVFXComponent
 *
 * Spawns phantom silhouette particles & green/violet smoke plumes when player Sanity drops below 40%.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityCorruptedVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityCorruptedVFXComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanityVFX")
	void UpdateSanityVFX(float CurrentSanity, float MaxSanity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|SanityVFX")
	bool IsLowSanityVFXActive() const { return bLowSanityVFXActive; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityVFX")
	float LowSanityThreshold = 40.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanityVFX|Events")
	FOnSanityVFXTriggeredSignature OnSanityVFXTriggered;

private:
	bool bLowSanityVFXActive = false;
	float CurrentSmokeDensity = 0.0f;
};
