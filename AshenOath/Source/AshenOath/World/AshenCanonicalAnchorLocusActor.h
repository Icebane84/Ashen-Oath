// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCanonicalAnchorLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCANLocusActivatedSignature, FName, CANID, float, ConflictIntensity);

/**
 * AAshenCanonicalAnchorLocusActor
 *
 * World Actor placing CAN anchor conflict loci in game levels.
 */
UCLASS()
class ASHENOATH_API AAshenCanonicalAnchorLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCanonicalAnchorLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANLocus")
	void ActivateCANLocus(float ConflictIntensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANLocus|Events")
	FOnCANLocusActivatedSignature OnCANLocusActivated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANLocus")
	bool bIsLocusActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|CANLocus")
	FName CANAnchorID;
};
