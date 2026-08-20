// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenRadiantBeamVFXEmitterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRadiantBeamTriggeredSignature, FVector, TargetBeamLocation, float, BeamWidth);

/**
 * AAshenRadiantBeamVFXEmitterActor
 *
 * World Actor emitting divine beam visual & lighting effects from the sky (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API AAshenRadiantBeamVFXEmitterActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenRadiantBeamVFXEmitterActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BeamVFX")
	void TriggerRadiantBeamVFX(FVector TargetLocation, float Width = 200.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BeamVFX|Events")
	FOnRadiantBeamTriggeredSignature OnRadiantBeamTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BeamVFX")
	bool bIsBeamActive = false;
};
