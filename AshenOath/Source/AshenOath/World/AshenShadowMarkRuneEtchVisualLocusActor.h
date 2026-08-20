// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenShadowMarkRuneEtchVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShadowMarkEtchedSignature, FVector, ForearmLocation, float, GlowGlowIntensity);

/**
 * AAshenShadowMarkRuneEtchVisualLocusActor
 *
 * World Actor etching dark in-world runes on Kaelen's forearm during Crisis events (PRS-001 Combat Blueprint V5.0).
 */
UCLASS()
class ASHENOATH_API AAshenShadowMarkRuneEtchVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenShadowMarkRuneEtchVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShadowMarkEtch")
	void EtchShadowMarkRunes(float GlowIntensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ShadowMarkEtch|Events")
	FOnShadowMarkEtchedSignature OnShadowMarkEtched;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowMarkEtch")
	bool bIsRunesEtched = false;
};
