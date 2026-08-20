// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenOathbringerRunicGlowVFXAnchorActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRunicGlowVFXTriggeredSignature, FVector, BladeLocation, float, GlowLuminance);

/**
 * AAshenOathbringerRunicGlowVFXAnchorActor
 *
 * World Actor rendering glowing runic light emissions along Oathbringer's blade edge (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API AAshenOathbringerRunicGlowVFXAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenOathbringerRunicGlowVFXAnchorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|RunicGlowVFX")
	void TriggerRunicGlowVFX(float Luminance = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|RunicGlowVFX|Events")
	FOnRunicGlowVFXTriggeredSignature OnRunicGlowTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|RunicGlowVFX")
	bool bIsGlowing = false;
};
