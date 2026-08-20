// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenFinisherImpactVFXAnchorActor.generated.h"

/**
 * AAshenFinisherImpactVFXAnchorActor
 * World VFX anchor driving stance-colored impact particle bursts during finishers.
 */
UCLASS()
class ASHENOATH_API AAshenFinisherImpactVFXAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenFinisherImpactVFXAnchorActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerFinisherImpactVFX(uint8 StanceEnum);
};
