// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSpiritualStainVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpiritualStainLocusUpdatedSignature, float, ActiveStainDensity, bool, bIsCorrodingGeometry);

/**
 * AAshenSpiritualStainVisualLocusActor
 *
 * World Actor rendering spiritual corruption stains diegetically on level geometry.
 */
UCLASS()
class ASHENOATH_API AAshenSpiritualStainVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSpiritualStainVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|StainLocus")
	void UpdateStainDensity(float StainDensity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|StainLocus|Events")
	FOnSpiritualStainLocusUpdatedSignature OnStainLocusUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|StainLocus")
	float ActiveLocusStainDensity = 0.0f;
};
